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

(ns octane.toolkit.octane_tools
	(:use    octane.toolkit.octane_utils
			 octane.toolkit.public_objects
			 octane.toolkit.octane_config
			 octane.toolkit.octane_gui_utils
			 octane.toolkit.octane_templates
			 octane.toolkit.octane_codegen_templates
			 octane.toolkit.octane_main_constants)
	(:import (java.io BufferedReader File FileInputStream
					  FileNotFoundException IOException InputStreamReader Reader)
			 (java.util ResourceBundle Vector Hashtable)
			 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
			 (java.util HashMap)))

(defn run-codegen-build-xml []
   (add-main-text *codegen-templ-build-xml*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Process Launch Utilities
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def *search-text-state* (agent nil))

(defn get-process [proc-atom-str]
  ;; Where proc-str equals E.g. 'cat', 'cut'
  ;; Check if this a win32, is so use that particular process.
  ;; And then check for other oses and default to the linux system
  (cond
   *is-windows* (*process-map* (keyword (str "win"  "-" proc-atom-str)))
   *is-linux*   (*process-map* (keyword (str "unix" "-" proc-atom-str)))
   :else        (*process-map* (keyword (str "unix" "-" proc-atom-str)))))


(defn build-findgrep-arr [cmd cur-dir wildcard grep-args]
  ;; Complex approach for building the arguments to 'find'
  (let [grp (get-process "grep")
            fst [cmd cur-dir "-name" (str "" wildcard "") ]
            more (if grep-args 
                   (conj fst "-exec" grp "-Hn" (str "" grep-args "") "{}" ";") 
                   fst)
            s (apply str (interpose " " more))]
    {:array more :text s}))

(defn start-findgrep-cmd [cur-dir wildcard grep-args]
  (let [fnd-proc (get-process "find")
                 proc-data (build-findgrep-arr fnd-proc cur-dir wildcard grep-args)
                 process-line (when fnd-proc     (into-array (proc-data :array)))
                 process-bld  (when process-line (when-try (new ProcessBuilder process-line)))
                 process      (when process-bld  (when-try (. process-bld start)))]
    (when process
      (history-add-text (str "Invoking find/grep command => " (proc-data :text) *newline*))
      (let [istream (. process getInputStream)
                    ireader   (new InputStreamReader istream)
                    bufreader (new BufferedReader ireader)]
        ;; First clear the main text buffer
        (clear-buffer buffer-1)
        (async-call *display* (status-set-text "Begin find search"))
        (let [proc-time-info (proc-time (loop [line (. bufreader readLine)]
                                          (when line
                                            (async-call *display* (add-main-text-nc line))
                                            (recur (. bufreader readLine)))))
                             msg (str "<<Completed find search>> " (proc-time-info :time-text))]
          (async-call *display* (add-main-text-nc msg))
          (async-call *display* (status-set-text msg)))))))

(defn start-findgrep-thread-java [widget]
  (proxy [Runnable] []
         (run [] (start-findgrep-cmd "." "*.java" nil))))

(defn run-findgrep-widget [obj-inst search-str]
  ;; We don't have access to the keyword, have to compare with the
  ;; actual object (string)
  ;; TODO: fix the following code
  (if (and search-str (> (length search-str) 1))
    (let [obj (str obj-inst)
              cur-dir (get-current-dir)]
      (cond (= obj (get-findgrep-helper      :FindGrep_grep_menuitem))
            (start-findgrep-cmd cur-dir "*.*"    search-str)
            (= obj (get-findgrep-helper      :FindGrep_15min_menuitem))
            (start-findgrep-cmd cur-dir "*.*"    search-str)
            (= obj (get-findgrep-helper      :FindGrep_2hrs_menuitem))
            (start-findgrep-cmd cur-dir "*.*"    search-str)
            (= obj (get-findgrep-helper      :FindGrep_java_menuitem))
            (start-findgrep-cmd cur-dir "*.java" search-str)
            (= obj (get-findgrep-helper      :FindGrep_clj_menuitem))
            (start-findgrep-cmd cur-dir "*.clj"  search-str)
            (= obj (get-findgrep-helper      :FindGrep_logs_menuitem))
            (start-findgrep-cmd cur-dir "*.log"  search-str)))
    (async-status-history *display* (str "Invalid Search Text at " (date-time)))))
    
(defn start-findgrep-thread [widget search-str delay?]
  ;; See octane_tools findgrep-listener for when this function
  ;; gets invoked.
  (proxy [Runnable] []
         (run [] (run-findgrep-widget widget search-str))))

(defn start-filemanager-proc []
  ;; Open the explorer if the directory is available
  (let [loc-text (. location-bar getText)]
    (let [file (new File loc-text)]
      (if (not (. file exists))
        (async-status-history *display* (str "File does not exist => " loc-text))
        (when (and (. file isDirectory) *is-windows*)
          (start-process [ *win-explorer-exe* (. file getAbsolutePath) ] buffer-1))))))
          
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;