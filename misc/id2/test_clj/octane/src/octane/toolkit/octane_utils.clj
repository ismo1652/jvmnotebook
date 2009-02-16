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

(ns octane.toolkit.octane_utils
	(:use    octane.toolkit.public_objects
			 octane.toolkit.octane_main_constants)
	(:import (java.util Date)
			 (java.text SimpleDateFormat)
			 (java.lang Runtime)
			 (java.text SimpleDateFormat)
			 (java.io InputStreamReader BufferedReader File)
			 (java.util.regex Pattern)))

(def history-add-text)
(def history-add-textln)	

(defn exit [] (. System (exit 0)))

(defn clear-buffer [buf] (. buf setLength 0))

(defn length [s] (count s))

(defn date-time [] (str (new java.util.Date)))

(defn date-timel [l] (str (new java.util.Date l))) 

(defn file-exists? [path] (let [file (new File path)] (. file exists)))

(defn octane-pattern [s flags] (. Pattern compile s flags))

(defn octane-pattern_ [s] (. Pattern compile s))

(defn add-select-style [styles-vec cur-style] (. styles-vec addElement cur-style))

(defn floor [d] (. Math floor d))

(defn println-obj [o] (println o) o)

(defn parse-long [str]
  (try (Long/parseLong str) 
       (catch NumberFormatException nfe 0)))

(defn col-vec-bg   []  (. colors-vec get 0))
(defn col-vec-grey []  (. colors-vec get 1))
(defn col-vec-red  []  (. colors-vec get 2))
(defn col-vec-cy   []  (. colors-vec get 3))
(defn col-vec-drkb []  (. colors-vec get 4))
(defn col-vec-wht  []  (. colors-vec get 5))

(def  *megabytes*      (* 1024.0 1024.0))
(def  *java-runtime*   (. Runtime getRuntime))

(defn *free-memory-b*  [] (. *java-runtime* freeMemory))
(defn *total-memory-b* [] (. *java-runtime* totalMemory))
(defn *max-memory-b*   [] (. *java-runtime* maxMemory))
(defn *used-memory-b*  [] (- (*total-memory-b*) (*free-memory-b*)))

;; Note: used memory == total memory - free memory
(defn *free-memory-m*  [] (int (floor (/ (*free-memory-b*)  *megabytes*))))
(defn *total-memory-m* [] (int (floor (/ (*total-memory-b*) *megabytes*))))
(defn *max-memory-m*   [] (int (floor (/ (*max-memory-b*)   *megabytes*))))
(defn *used-memory-m*  [] (int (floor (/ (*used-memory-b*)  *megabytes*))))

(defn *memory-usage* []
  (str "(" (*used-memory-m*) "M/" (*free-memory-m*) "M [" (*total-memory-m*) "M," (*max-memory-m*) "M ])"))

(def  *dir-date-format* (new SimpleDateFormat "MM-dd-yyyy hh:mm.ss a"))
(defn get-dir-date [l]  (. *dir-date-format* format (new Date l)))

(defmacro when-try [body]
  `(try ~body
        (catch Exception ~'e
               (println "ERR <when-try> " ~'e)
			   (try (history-add-textln (str "ERR <when-try> " ~'e *newline*))
					(catch Exception ~'e2 (println "ERR2 <when-try>")))
               nil)))

(defmacro proc-time [expr]
  `(let [start# (. System (nanoTime))
                ret#     ~expr
                res-t#   (/ (double (- (. System (nanoTime)) start#)) 1000000.0)
                str-res# (str "Elapsed time: " res-t# " msecs")]
     {:return ret# :time-text str-res# :timed res-t#}))


(defn simple-term-searchrepl [cmd-line, str-data]
  ;; Search and replace in the following format - " abc , 123 ; uuu , ggg"
  ;; Note: fix hack against lisp, (string buffer)
  (if (not (and cmd-line (> (length cmd-line) 1)))
    nil
    (let [splt (. cmd-line split ";")
               buf (new StringBuffer)]
      (. buf append str-data)
      (doseq [i splt]
          (let [for-repl (. i split ",")
                         f (. (first for-repl) trim)
                         s (. (second for-repl) trim)
                         cur-data (. buf toString)]            
            (. buf setLength 0)
            (. buf append (. cur-data replaceAll f s))))
      (. buf toString))))

(defn history-add-text [text]
  (println text)
  (. buffer-3 append text)
  (let [disp (. tab-text-3 getDisplay)]
    (. disp asyncExec
       (proxy [Runnable] []
              (run [] (. tab-text-3 setText (. buffer-3 toString)))))))

(defn history-add-textln [text] (history-add-text (str text *newline*)))

(defn pprint-list
  "Simple pretty print a list"
  [lst]
  ;;;;;;;;;;
  (doseq [x lst]
	  (let []
		(println "<Begin Element>")
		(println x)
		(println "<End Element>" \newline))))

(defn parse-timestamp-date
  "Return the long representation for the timestamp"
  [str-date]
  ;;;;;;;;;;;;;;;  
  (let [sdf (new SimpleDateFormat "MMM d HH:mm:ss yyyy")]
	(try (. (. sdf parse str-date) getTime)
		 (catch Exception e (println "Warn: invalid date format =>" str-date)
				str-date))))


  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;