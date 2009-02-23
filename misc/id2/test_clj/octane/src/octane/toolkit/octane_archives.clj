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
;;; See the eclipse documentation:
;;; http://help.eclipse.org/stable/nftopic/org.eclipse.platform.doc.isv/reference/api/index.html
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns octane.toolkit.octane_archives
	(:use
     octane.toolkit.octane_main_constants
	 octane.toolkit.octane_utils
	 octane.toolkit.public_objects
	 octane.toolkit.octane_gui_utils
	 octane.toolkit.octane_config
     octane.toolkit.octane_file_utils
	 octane.toolkit.octane_jar_viewer)
	(:import 
	 (java.io File)
	 (org.eclipse.swt SWT)
	 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
	 (org.eclipse.swt.widgets FileDialog MessageBox TableItem Button
							  Composite Table TableColumn)
	 (org.eclipse.swt.layout GridData GridLayout RowLayout RowData)
	 (org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
							 SelectionEvent ShellAdapter ShellEvent)
	 (org.eclipse.swt.widgets Label Menu MenuItem Control Listener)
     (com.octane.util.zip UncompressInputStream)
     (java.io FileInputStream InputStream ByteArrayOutputStream)     
     (java.util.zip ZipInputStream InflaterInputStream)
	 (java.io InputStreamReader 
			  FileInputStream BufferedReader File FilenameFilter)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn open-archive-has-file?
  "Open an archive file and determine if there is only one entry"
  [infile]
  ;;;;;;;;;;;;
  (try (let [zin (new ZipInputStream (new FileInputStream infile))]
         (loop [entry (. zin getNextEntry)
                ctr   0]
           (when entry
             (recur (. zin getNextEntry) (+ ctr 1))))
         (. zin close))
       (catch Exception e (. e printStackTrace))))

(defn open-compressed-file
  "Open an archive file and LZC unix compressed .Z extension"
  [infile]
  ;;;;;;;;;;;;
  (try (let [zin (new UncompressInputStream (new FileInputStream infile))
				  bbuf #^"[B" (make-array (. Byte TYPE) 20480)
				  bout (new ByteArrayOutputStream 20480)]
		 (loop [got (. zin read bbuf)
					tot 0]		  
		   (when (> got 0)
			 (. bout write bbuf, 0 got)
			 (recur (. zin read bbuf) (+ tot 1))))
		 ;; With the byte array outputstream
		 ;; Convert the bytes to string
		 (. bout flush)
		 (. zin close)
		 (new String (. bout toByteArray)))
       (catch Exception e 
			  (. e printStackTrace)
			  nil)))

(defn stream-compressed-file
  "Open an archive file and LZC unix compressed .Z extension"
  [infile #^java.io.OutputStream out]
  ;;;;;;;;;;;;
  (try (let [zin (new UncompressInputStream (new FileInputStream infile))
				 bbuf #^"[B" (make-array (. Byte TYPE) 20480)]
		 (loop [got (. zin read bbuf)
					tot 0]
		   (when (> got 0)
			 (. out write bbuf, 0 got)
			 (recur (. zin read bbuf) (+ tot 1))))
		 ;; With the byte array outputstream
		 ;; Convert the bytes to string
		 (. out flush)
		 (. zin close)
		 (. out close))
       (catch Exception e
			  (. e printStackTrace)
			  nil)))

(defn win-open-compressed-file
  "Open an archive file and LZC unix compressed .Z extension"
  [infile]
  ;;;;;;;;;;;;
  (let [data (open-compressed-file infile)]
	(async-status-history *display* (str "Open LZC (unix compressed) file => " infile *newline*))
	(async-add-main-text data)))

(defn check-archive-handler
  "Determine the archive type based on the extension and handle accordingly"
  [disp file path]
  ;;;;;;;;;;;;;;;;;
  (cond (. path endsWith ".Z")   (win-open-compressed-file file)
		(. path endsWith ".jar") (open-jar-file file)
		(. path endsWith ".zip") (println "Not implemented")
		:default                 (println "Not implemented")))
		                  
(defn open-archive-file-handler
  "Open the archive file.   Open the file  in the main buffer if only ONE text file exists.
 If more than one exists than just list the entries."
  [disp file path]
  ;;;;;;;;;;;;;;;;;
  (check-archive-handler disp file path))
  
(def open-archive-file-listener
     ;; Open the archive file.   Open the file  in the main buffer if only ONE text file exists.
     ;; If more than one exists than just list the entries."  
     ;;;;;;;
     (proxy [SelectionAdapter] []
            (widgetSelected [e] (simple-dialog-open-file
                                 *display* open-archive-file-handler  *zip-wildcard-seq* ))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Archive Directory Handlers
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def uncompress-filename-filter
	 (proxy [FilenameFilter] []
			(accept [dir-file name]
					(if name
					  (.endsWith name  ".Z")
					  false))))

(defn zfiles-dir-handler
  "zfile-func takes two arguments, the input 'file' object, the output tmp directory"
  [file-path zfile-func tmp-dir]
  (let [file (new File file-path)]
	(doseq [cur-fil (.listFiles file uncompress-filename-filter)]
		(zfile-func cur-fil tmp-dir))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;