;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Description: Example Octane/Clojure Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;; Note: use CTRL-D or CTRL-C to exit out of the REPL clojure command line
;; prompt

(ns scripts.advanced_jar
	(:use    octane.toolkit.octane_version
			 octane.toolkit.octane_utils
			 octane.toolkit.octane_jar_viewer)
	(:import (java.util Date)
			 (java.io File)
			 (java.io InputStreamReader 
					  FileInputStream BufferedReader File FilenameFilter)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def jar-filename-filter
	 (proxy [FilenameFilter] []
			(accept [dir-file name]
					(if name
					  (.endsWith name  ".jar")
					  false))))

(defn parse-jars-in-dir
  "Loop through all the files in the current directory and print the contents"
  [#^java.io.File file]
  ;;;;;;;;;;;;;;;;;;;;;;
  (doseq [cur-fil (.listFiles file jar-filename-filter)]
	  (println "Printing jar file contents : ( " (.getAbsolutePath cur-fil) ")")
	(println (open-jar-file-str (.getAbsolutePath cur-fil)))))

(defn view-jar-file
  "This is a function comment, open the jar file"
  [#^java.lang.String filename]
  (let [file-dir (new File filename)
				 path (.getAbsolutePath file-dir)]
	(if (.isDirectory file-dir)
	  (do (println "Attempting to load jar dir =>" path)
		  (parse-jars-in-dir file-dir))
	  (do (println "Invalid Directory (not a directory) =>" path)))))
				 		
(defn parse-args []
  (let [args *command-line-args*]
	(println "Args : " args)
    (if args
      (when (> (count args) 0)
        ;; Open the file if it exists
        (if (not (file-exists? (first args)))
          (println "WARN: Invalid directory argument =>" (first args))
		  (view-jar-file (first args))))
	  (println "ERROR: Invalid Arguments, the first argument should be a directory"))))

(defn script-main 
  "This is a function comment for the script-main function.
 The function does not have any arguments"
  [& args]
  ;;;;
  (println "Running Jar Main Directory Reader, octane version=" *OCTANE_VERSION*)
  (parse-args)
  (println "Done at " (str (new Date)))
  (exit))

(println *command-line-args*)
;; Invoke Script Main, and exit on exceptions
(try (script-main *command-line-args*)
	 (catch Exception e
			(.printStackTrace e)
			(exit)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;