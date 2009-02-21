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

(def *filename*        "README")
(def *my-file*         (new File *filename*))
(def *search-regex*    "(Author|Octane)")

(defn search-regex []
  (let [file-data (open-file-util *my-file* *filename*)
				  terms *search-regex*]
	(println "Found Search Term At:")
	(println (doc-filter-regex file-data terms))))

(defn script-main 
  "This is a function comment for the script-main function."
  []
  ;;;;
  (println "Running Example Search (1), octane version=" *OCTANE_VERSION*)
  (search-regex)
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