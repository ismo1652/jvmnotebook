;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... Brown <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-ns 'octane)

(import '(java.io BufferedReader LineNumberReader File FileInputStream
                  ObjectInputStream
                  FileNotFoundException IOException InputStreamReader Reader
                  ByteArrayOutputStream ObjectOutputStream FileOutputStream))
(import '(java.util ResourceBundle Vector))

(def  async-status-history)
(def  clear-buffer)
(def  styled-text)
(def  history-add-text)
(def  status-set-text)
(def  location-set-text)
(def  refresh-textarea)
(def  async-status-history)
(def  *memory-usage*)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Note: open file dialog is in octane_core_widgets.clj
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def  open-file)
(def  date-timel)
(def  get-file-state)
(def  cur-file-info (ref {:file-name nil :file-path nil :last-mod nil :line-num 0 :file-size 0
                                         :parent-dirname nil :writeable false :exists false}))
(defn set-file-info [nm pth mod-t n prnt w xsts sz]
  (dosync (commute cur-file-info assoc 
                   :file-name nm :file-path pth :last-mod mod-t :file-size sz
                       :line-num n :parent-dirname prnt :writeable w :exists xsts)))

(defn get-file-info-header []
  (when (and (not (nil? @cur-file-info)) (get-file-state))
    (. MessageFormat format 
       file-info-msg (to-array [(date-timel (@cur-file-info :last-mod)) (@cur-file-info :line-num)
                                (@cur-file-info :file-name) (@cur-file-info :parent-dirname)
                                (@cur-file-info :file-path) (@cur-file-info :file-size)
                                (*memory-usage*)]))))
      
(def  file-state             (ref {:open-state false}))
(defn get-file-state []      (@file-state :open-state))
(defn set-file-state [state] (dosync (commute file-state assoc :open-state state)))

(def  file-last-mod          (ref {:last-mod 0 :file-path nil}))
(defn get-file-last-mod  []  (@file-last-mod :last-mod))
(defn get-last-file-path []  (@file-last-mod :file-path))
(defn set-file-last-mod  [t name] (dosync (commute file-last-mod assoc :last-mod t :file-path name)))

(defn file-modified? [file]
  (let [mod-t  (. file lastModified)
        prev-t (get-file-last-mod)
        diff   (- mod-t prev-t)
        pth    (. file getAbsolutePath)]
    (when (> diff 0)
      (set-file-last-mod mod-t pth)
      true)))
                
(defn file-monitor-loop [file]
  (let [delay-t (prop-int resources-core-sys "Octane_Sys_filemonitor_delay")
        enable-file-mon (prop-bool resources-win-opts "file_monitor_enabled")
        pth    (. file getAbsolutePath)]
    (when enable-file-mon
      (.start  (new Thread (fn []
                               (while (not (. shell isDisposed))
                                      (Thread/sleep delay-t)
                                      (when (file-modified? file)
                                        ;; Reload the file as it grows and refresh
                                        ;; the file.
                                        (open-file pth true)))))))))

;;**************************************
;; File Utilities
;;**************************************
(defn open-file-util [file file-path]
  #^{:doc "Use java oriented approach for loading a file into memory"}
  
  ;; Java oriented approach for opening file
  (let [stream (new FileInputStream file-path)
        instr (new LineNumberReader (new InputStreamReader stream))
        ;; Use type hints to ensure a character type.
        readBuffer #^"[C" (make-array (. Character TYPE) 2048)
        buf (new StringBuffer)]
    (loop [n (. instr read readBuffer)]
      (when (> n 0)
        (. buf append readBuffer 0 n)
        (recur (. instr read readBuffer))))
    ;; File info data has been collected, set some of the file properties
    (set-file-info (. file  getName) (. file  getAbsolutePath) 
                   (. file  lastModified) (. instr getLineNumber) (. file  getParent)
                   (. file  canWrite) (. file  exists) (. file  length))
    (. instr close)
    (. buf toString)))

(defn serialize-object-1 [obj path]
  (let [fos (new FileOutputStream path)
            oos (new ObjectOutputStream fos)]
    (try (.writeObject oos obj)
         (finally (.close oos)))))

(defn deserialize-object-1 [path]
  (let [fis (new FileInputStream path)
            ins (new ObjectInputStream fis)]
    (try (.readObject ins)
         (finally (.close ins)))))

(defn serialize-object [obj path]
  (try (serialize-object-1 obj path)
       (catch Exception e
         (println "WARN <serialize-object>: Could not serialize file: "  path " error=" e))))

(defn deserialize-object [path]
  (try (deserialize-object-1 path)
       (catch Exception e
         (println "WARN <deserialize-object>: Could not load serialized file: "  path " error=" e)))) 
       
(def  recent-file-table            (ref {:file-table nil}))
(defn get-recent-file-table []     (@recent-file-table :file-table))
(defn set-recent-file-table [tabl] (dosync (commute recent-file-table assoc :file-table tabl)))

(defn save-file-list []
  (let [obj (get-recent-file-table)]
    (when obj
      (serialize-object obj *recent-file-list*))))

(defn load-file-list []
  (let [obj (deserialize-object *recent-file-list*)]    
    (if (nil? obj)
      (set-recent-file-table (new Hashtable))
      (set-recent-file-table obj)))
  (get-recent-file-table))

(defn add-recent-file [file]
  (let [name (. file getName)
             path (. file getAbsolutePath)
             rec-tabl (get-recent-file-table)]
    (when rec-tabl
      (. rec-tabl put name path)
      rec-tabl)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Open the directory dialog and utilities
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn format-has-val [bval c] (if bval c "-"))

(defn format-isdir-name [name is-d] (if is-d (str "<" name ">") name))

(defn format-dir-file [file]
  (let [is-d (format-has-val (. file isDirectory)   "d")
             can-r (format-has-val (. file canRead) "r")
             can-w (format-has-val (. file canRead) "w")
             len   (. file length)
             name  (format-isdir-name (. file getName) (. file isDirectory))
             lmod  (. file lastModified)]
    ;; Use the format syntax to get fixed width columns
    (str (apply format "%3s %15s  %25s  %s" (list (str is-d can-r can-w) len (get-dir-date lmod) name)) *newline*)))
             
(defn open-directory [path]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  ;; Open the directory and then store the contents
  ;; in the main buffer
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (async-status-history display (str "Opening directory => " path *newline*))
  (let [file-dir (new File path)]
    (when (. file-dir exists)
      ;; Set the open directory global
      (set-directory-open path)      
      (location-set-text path)
      (clear-buffer buffer-1)      
      ;; ADD the file path as the fist line.
      (. buffer-1 append (str "<< Current Directory: " path *newline*))
      (doseq [fil (. file-dir listFiles)]
          (let [] (. buffer-1 append (format-dir-file fil))))
      (. styled-text setText (. buffer-1 toString)))))             

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Location Bar and Utilities
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn open-file-or-dir [name]
  ;; Check if the file exists, open the file or directory
  (let [file  (new File name)]
    (if (not (. file exists))
      (async-status-history display (str "File does not exist => " name))
      (if (. file isDirectory)
        (open-directory (. file getAbsolutePath))
        (open-file (. file getAbsolutePath) true)))))

(def location-text-listener
     ;; Use (. box addListener SWT/Traverse location-text-listener)
     ;; to add the action listener.
     (proxy [Listener] []
            (handleEvent [event]
                         (when (= (. event detail) SWT/TRAVERSE_RETURN)
                           (async-status-history display (str "Opening from location bar " (. location-bar getText)))
                           (open-file-or-dir (. location-bar getText))))))
                                        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;