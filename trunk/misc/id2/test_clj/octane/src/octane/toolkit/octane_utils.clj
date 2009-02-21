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
;;; See for regex: http://java.sun.com/j2se/1.4.2/docs/api/java/util/regex/Pattern.html
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns octane.toolkit.octane_utils
	(:use    octane.toolkit.public_objects
			 octane.toolkit.octane_main_constants)
	(:import (java.util Date)
			 (java.nio CharBuffer)
			 (java.text SimpleDateFormat)
			 (java.lang Runtime)
			 (java.text SimpleDateFormat)
             (java.nio.channels FileChannel FileChannel$MapMode)
			 (java.io InputStreamReader FileInputStream BufferedReader File FilenameFilter)
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

(defn octane-safe-pattern [s flags] 
  (when s    
    (try (. Pattern compile s flags)
         (catch Exception e nil))))         

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
(defn col-vec-yllw []  (. colors-vec get 6))
(defn col-vec-blk  []  (. colors-vec get 7))

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

(defn doc-filter-regex
  "Return a string document with only the lines of interest"
  [doc regex-filter]
  ;;;;;;;;;;;;;;;;;;;
  (let [res-buffer (new StringBuffer 1024)
				   bit-pattr (bit-or Pattern/MULTILINE (bit-or Pattern/CASE_INSENSITIVE 1))
				   p     (octane-pattern (str "^.*" regex-filter ".*$") bit-pattr)
				   cbuff (. CharBuffer wrap doc)
				   m     (. p matcher cbuff)]
	(loop [fnd? (. m find)]
	  (when fnd?
		(. res-buffer append (str (. m group) *newline*))
		(recur (. m find))))
	;; Return the buffer string
	(. res-buffer toString)))

(defn flatten [x]
  (let [s? #(instance? clojure.lang.Sequential %)] 
	(filter (complement s?) (tree-seq s? seq x))))

(defn keyword-frequency [col]
  (reduce (fn [counts x] (merge-with + counts {x 1})) {} col))

(defn simple-grep-regex?
  "Determine if the text is found"
  [doc regex-str]
  ;;;;;;;;;;;;
  (let [pattr (octane-safe-pattern regex-str
                                   (bit-or Pattern/CASE_INSENSITIVE (bit-or Pattern/DOTALL 1)))
        dummy1  (. *charset-decoder* reset)
        pattr-m (. pattr matcher doc)]
    (. pattr-m find)))

(defn simple-grep?
  "Determine if the text is found"
  [doc term]
  ;;;;;;;;;;;;;;;;;;;;
  (simple-grep-regex? doc (str term)))

(defn new-find-next-matcher
  "Create a new regex matcher for use with 'find-next'"
  [doc regex-str-term]
  ;;;;;;;;;;;;;;;
  (let [flags     (bit-or Pattern/CASE_INSENSITIVE (bit-or Pattern/DOTALL Pattern/MULTILINE))
        pattr     (octane-safe-pattern regex-str-term flags)
        char-buf  (get-char-buf-decoder doc)
        m-pattr   (. pattr matcher char-buf)]
    m-pattr))

(defn doc-loop-handler
  "Loop through all the lines in a file and invoke the given handler
 function.   Where 'my-func' takes one parameter, the current line string."
  [doc my-func]
  ;;;;;;;;;;;;;;;
  (let [char-buf2 (get-char-buf-decoder doc)
        lm (. *regex-line-pattern* matcher char-buf2)]
    ;; Loop till end of file/document detected
    (loop [srch-res (. lm find)]
      (when srch-res
        (my-func (. lm group))
        (recur (. lm find))))))

(defn doc-file-loop-handler
  "Loop through all the lines in a file and invoke the given handler
 function.   Where 'my-func' takes two parameters, the current line string and line number."
  [filename my-func]
  ;;;;;;;;;;;;;;;;;;;;
  (let [fis (new FileInputStream (new File filename))
        fc  (. fis getChannel)
        sz  (. fc size)
        bb  (. fc map FileChannel$MapMode/READ_ONLY 0 sz)
        cb  (. *charset-decoder* decode bb)
        lm  (. *regex-line-pattern* matcher cb)]
    ;; Loop till end of file/document detected
    (loop [srch-res? (. lm find) line-no 0]
      (when srch-res?
        (my-func (. lm group) line-no)
        (recur (. lm find) (+ line-no 1))))))

(defn doc-file-grep
  "Loop through all the lines in a file and search for the term."
  [filename term]
  ;;;;;;;;;;;;;;;;;;;;
  (let [buf (new StringBuffer)]
    (doc-file-loop-handler filename 
                           (fn [line line-num]               
                               (when (simple-grep? line term)
                                 (. buf append (str filename ": line " line-num ": " line)))))
    (. buf toString)))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Directory File Traversal
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defn create-filename-filter [cur-file-obj ext]
  (proxy [FilenameFilter] []
		 (accept [dir-file name]
				 (if (and name ext)	   
				   (. (str name) endsWith (str ext))
                   false))))

(defn traverse-accept-files [cur-file-obj full-ext]
  (if (and cur-file-obj (. cur-file-obj isFile))
    (let [name (. cur-file-obj getName)]
      (. name endsWith (str full-ext)))
    false))

(defn traverse-directory 
  "Recursively search the directory"
  [f-cur-obj func-on-dir func-on-file]
  ;;;;;;;;;;;;;;
  (when f-cur-obj
	(if (. f-cur-obj isFile)
	  (when (and func-on-file (traverse-accept-files f-cur-obj ".clj"))
        (func-on-file f-cur-obj))
	  (let [files (. f-cur-obj listFiles)]
		;; Current file is a directory
		(when func-on-dir (func-on-dir f-cur-obj))
		(doseq [file files]
			(traverse-directory file func-on-dir func-on-file))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;