;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Description: Example Octane/Clojure Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;; Note: use CTRL-D or CTRL-C to exit out of the REPL clojure command line
;; prompt

(ns scripts.archive_search
	(:use    octane.toolkit.octane_version
			 octane.toolkit.octane_main_constants
			 octane.toolkit.octane_utils
			 octane.toolkit.octane_config
			 octane.toolkit.octane_file_utils
			 octane.toolkit.octane_archives)
	(:import (java.util Date)
			 (java.io FileOutputStream)))

(def *my-date-str*       "02/10/2009")
(def *z-file-directory*  "test/docs/virtual_drive")

(defn create-tmp-dirs--
  "Function is not used, use as an example for more complex
 Java oriented file manipulation scripts"
  []
  (when (create-temp-work-dirp)
	(let [tmp-work (prop-core-sys "Octane_Sys_largefile_work")
				   date-file *simple-date-format*
				   date-pack    *simple-date-format-pack*
				   tmp-date     (when-try (.parse date-file *my-date-str*))
				   tmp-date-str (when-try (.format date-pack tmp-date))]
	  ;; Create the date work directory
	  (create-temp-work-dir 
	   (str tmp-work *name-separator* "archives" *name-separator* tmp-date-str)))))

(def stream-zfile
	 (fn [file tmp-dir]
		 (println "Streaming uncompressed file to tmp directory")
		 ;; Create the output stream object.
		 (let [fname (str tmp-dir *name-separator* (.getName file) ".log")
					 fos (new FileOutputStream fname)]
		   (stream-compressed-file file fos)
		   (println "Done Streaming file =>" fname))))
		   
(defn script-main 
  "This is a function comment for the script-main function."
  []
  ;;;;
  (println "Running Archive Search Main, octane version=" *OCTANE_VERSION*)
  (let [tmp-dir (create-archive-work-dir *my-date-str*)]
	(zfiles-dir-handler *z-file-directory* stream-zfile tmp-dir))
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