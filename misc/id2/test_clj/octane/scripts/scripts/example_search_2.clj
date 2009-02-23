;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Description: Example Octane/Clojure Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;; Note: use CTRL-D or CTRL-C to exit out of the REPL clojure command line
;; prompt

(ns scripts.example_search_1
	(:use    octane.toolkit.octane_version
			 octane.toolkit.octane_utils
			 octane.toolkit.octane_file_utils)
	(:import (java.util Date)
			 (java.io File)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def *filename*        "test/docs/virtual_drive/out_090212131210.txt")
(def *my-file*         (new File *filename*))
(def *search-regex*    "(Servlet)")

(defn get-log-terms-println   
  "Example, print the lines in the file, using 'doc-loop-handler'"
  [filename term-regex]
  ;;;
  (let [file (new File filename)
			 file-data (open-file-util file filename)]
	(let [my-doc (doc-filter-regex file-data term-regex)]
	  ;; Use doc loop/line handler to print all the lines
	  ;; where 'fn' defines an anonymous function (function without a name).
	  (doc-loop-handler my-doc (fn [line] (print "LINE: " line))))))

(defn search-get-log-terms []
  (doseq [log-struct (get-log-search-terms *filename* *search-regex*)]
	  (println "**** (new element) ****")
	(println  log-struct)))

(defn script-main
  "This is a function comment for the script-main function."
  []
  ;;;;
  (println "Running Example Search (2), octane version=" *OCTANE_VERSION*)
  (get-log-terms-println *filename* *search-regex*)
  ;; Print the same data converted to a list of timestamp/lines of interest
  (search-get-log-terms)
  (println "Done at " (str (new Date)))
  (exit))

;; Invoke Script Main, and exit on exceptions
(try (script-main)
	 (catch Exception e
			(.printStackTrace e)
			(exit)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;