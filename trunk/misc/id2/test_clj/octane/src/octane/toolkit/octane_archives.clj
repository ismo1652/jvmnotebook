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
     octane.toolkit.octane_file_utils)
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
     (java.io FileInputStream InputStream )     
     (java.util.zip ZipInputStream InflaterInputStream)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn open-archive-has-file?
  "Open an archive file and determine if there is only one entry"
  [infile]
  ;;;;;;;;;;;;
  (try (let [zin (new ZipInputStream (new FileInputStream infile))]
         (loop [entry (. zin getNextEntry)
                ctr   0]
           (println "-->" ctr  " --->" entry)
           (when entry
             (println "-->" ctr)
             (recur (. zin getNextEntry) (+ ctr 1))))
         (. zin close))
       (catch Exception e (. e printStackTrace))))

(defn open-compressed-has-file?
  "Open an archive file and determine if there is only one entry"
  [infile]
  ;;;;;;;;;;;;
  (try (let [zin (new InflaterInputStream (new FileInputStream infile))]
         (loop [entry (. zin getNextEntry)
                ctr   0]
           (println "-->" ctr  " --->" entry)
           (when entry
             (println "-->" ctr)
             (recur (. zin getNextEntry) (+ ctr 1))))
         (. zin close))
       (catch Exception e (. e printStackTrace))))
                  
(defn open-archive-file-handler
  "Open the archive file.   Open the file  in the main buffer if only ONE text file exists.
 If more than one exists than just list the entries."
  [disp file path]
  ;;;;;;;;;;;;;;;;;
  (open-archive-has-file? file))
  
(def open-archive-file-listener
     ;; Open the archive file.   Open the file  in the main buffer if only ONE text file exists.
     ;; If more than one exists than just list the entries."  
     ;;;;;;;
     (proxy [SelectionAdapter] []
            (widgetSelected [e] (simple-dialog-open-file
                                 *display* open-archive-file-handler  *zip-wildcard-seq* ))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;