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

(ns octane.toolkit.octane_jar_viewer
	(:use octane.toolkit.octane_main_constants
			 octane.toolkit.octane_config
			 octane.toolkit.public_objects octane.toolkit.octane_utils
			 octane.toolkit.octane_gui_utils
			 octane.toolkit.ws_garbage_collection
			 octane.toolkit.octane_file_utils)
	(:import
     (java.util.jar JarFile)
     (java.util.jar JarInputStream)
     (java.util.zip ZipEntry)
	 (java.util Date)
	 (org.eclipse.swt.graphics Color RGB)
	 (org.eclipse.swt SWT)
	 (java.text MessageFormat)
	 (java.util HashMap)
	 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
	 (org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
							 SelectionEvent ShellAdapter ShellEvent)
	 (org.eclipse.swt.widgets Label Menu MenuItem Control Listener)	 
	 (org.eclipse.swt.layout FillLayout)
	 (org.jfree.chart ChartFactory JFreeChart)
	 (org.jfree.chart.axis DateAxis)
	 (org.jfree.chart.plot XYPlot)
	 (org.jfree.chart.renderer.xy XYItemRenderer)
	 (org.jfree.chart.renderer.xy XYLineAndShapeRenderer)
	 (org.jfree.data.time Month Second TimeSeries TimeSeriesCollection)
	 (org.jfree.data.xy XYDataset)
	 (org.jfree.experimental.chart.swt ChartComposite)
	 (org.jfree.ui RectangleInsets)))

(defn open-jar-file-str
  "Open the jar files and read the contents, return a string"
  [file]
  ;;;;;;;;;;;
  (let [jar-file (new JarFile file)
        buf (new StringBuffer)]
    (when-let [entries (. jar-file entries)]
        (loop [entry (. entries nextElement)]
          (when (and entry (. entries hasMoreElements))
            (let [name (. entry getName)]
              (. buf append (str name \newline)))
            (recur (. entries nextElement)))))
    (. buf toString)))

(defn open-jar-file
  "Open the jar files and read the contents, return a string"
  [file]
  ;;;;;;;;;;;
  (when-let [listing (open-jar-file-str file)]
      (async-status-history
       *display* (str "Opening jar file => " file *newline*))
    (clear-buffer buffer-1)
    (add-main-text-nc (str "<<< Opening jar file : " file " >>>"))
    (async-call *display* (add-main-text-nc listing))))

(def open-jar-file-handler
     ;; Where file-handler takes the following arguments : <DISPLAY> <FILE> <PATH>
     (fn [disp file path]
         (let [jar-thread (proxy [Runnable] [] 
                                 (run []
                                      (try (open-jar-file file)
                                           (catch Exception e
                                                  (. e printStackTrace)))))]
           (. (new Thread jar-thread) start))))

(defn jar-viewer-handler
  "Invoke the simple dialog handler and handle the jar file"
  []
  ;;;;;;;;;;;;
  (simple-dialog-open-file *display* open-jar-file-handler *jar-wildcard-seq*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;