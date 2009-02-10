;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;;
;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... Brown <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-ns 'org.octane)

(defmacro async-call [disp & body]
  `(. ~disp asyncExec (proxy [Runnable] []
							 (run [] ~@body))))

(defn add-text-buffer [text-field buffer str-data]
	 (clear-buffer buffer)
	 (. buffer append str-data)
	 (. text-field setText (. buffer toString)))

(defn add-main-text [str-data]
  (add-text-buffer styled-text buffer-1 str-data))

(defn async-add-text [disp text-field buffer str-data]
  ;; For example, text-field = styled-text
  (async-call disp (add-text-buffer text-field buffer str-data)))

(defn add-main-text-nc [line]
  ;; Add the main text without clearing the core buffer
  ;; Note 'buffer-1' and styled-text used as 
  ;; GUI components. (NC = no clear)
  (try (let [buffer buffer-1
					text-gui styled-text]
		 (. buffer append (str line *newline*))
		 (. text-gui setText (. buffer toString)))
	   ;; Attempt to redraw and update
	   ;;(. text-gui redraw)
	   ;;(. text-gui update)
	   ;; Set the caret position to the end
	   ;;(. text-gui setSelection (. text-gui getCharCount)))
	   (catch Exception e (println e))))

(defn create-menu-item [menu res-menuitem proxy-body]
  (let [menu-item (new MenuItem menu (. SWT PUSH))]
	(doto menu-item
	  (. setText (. resources-win getString res-menuitem))
	  (. addSelectionListener proxy-body))
	menu-item))

(defn async-status-text [disp msg]
  (async-call disp (status-set-text msg)))

(defn async-status-history [disp msg]
  ;; Set the status bar and history
  (async-call disp (status-set-text msg))
  (async-call disp (history-add-text (str msg *newline*))))

(defn start-process [proc-args-lst buffer]
  ;; Example usage: (start-process [ "explorer.exe" ] buffer-1)
  (try
   (let [process-line (into-array proc-args-lst)
         process-bld  (when process-line (when-try (new ProcessBuilder process-line)))
         process      (when process-bld  (when-try (. process-bld start)))]
     (when process
       (async-status-history display (str "Invoking process => " proc-args-lst *newline*))
       ;; Wrap the request within a thread.
       (let [proc-thread
             (proxy [Runnable][]
                    (run []
                         (let [istream   (. process getInputStream)
                               ireader   (new InputStreamReader istream)
                               bufreader (new BufferedReader ireader)]
                           ;; First clear the main text buffer
                           (clear-buffer buffer)
                           (let [proc-time-info (proc-time (loop [line (. bufreader readLine)]
                                                             (when line
                                                               (async-call display (add-main-text-nc line))
                                                               (recur (. bufreader readLine)))))
                                 msg (str "<<Completed process>> " (proc-time-info :time-text))]
                             (async-call display (add-main-text-nc msg))
                             (async-call display (status-set-text msg))))))]
         ;; Launch the process thread
         (. (new Thread proc-thread) start))))
   (catch Exception e (. e printStackTrace))))
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;