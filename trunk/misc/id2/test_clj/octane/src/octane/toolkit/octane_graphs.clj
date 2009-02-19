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

(ns octane.toolkit.octane_graphs
	(:use    octane.toolkit.octane_main_constants
			 octane.toolkit.octane_config
			 octane.toolkit.public_objects
			 octane.toolkit.octane_utils
			 octane.toolkit.octane_gui_utils
             octane.toolkit.octane_file_utils
			 octane.toolkit.ws_garbage_collection)
	
	(:import 			 
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


(def *graph-style* (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE 1))))

(def *graph-gc-shell* (new Shell *shell* *graph-style*))

(def create-graph-gc-window)
(def graph-gc-byfile-window)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Time Series Creation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn create-timegc-dataset
  "Load the XML file with the garbage collection data and create a dataset"
  [filename]
  ;;;;;;;;;;
  (let [ts-free (new TimeSeries "Free Bytes (After GC)" Second)
				ts-total (new TimeSeries "Total Bytes (After GC)" Second)
				dataset  (new TimeSeriesCollection)
				raw-data (simple-parse-gc-file filename)]
	(doseq [mem-struct raw-data]
		(let [tstamp (mem-struct :timestamp)
					 date-stamp (new Date tstamp)
					 sec-stamp  (new Second date-stamp)
					 free  ((mem-struct :memory) :freebytes)
					 total ((mem-struct :memory) :totalbytes)]
		  (. ts-free  addOrUpdate sec-stamp (parse-long (str free)))
		  (. ts-total addOrUpdate sec-stamp (parse-long (str total)))))
	(. dataset addSeries ts-free)
	(. dataset addSeries ts-total)
	dataset))

(defn create-timegc-chart
  "Create a time series chart with the given dataset."
  [dataset]
  ;;;;;;;;;;
  (let [chart (. ChartFactory createTimeSeriesChart
				 "Native-Stderr Garbage Collection"  ;; title
				 "Timestamp"                         ;; x-axis label
				 "Memory Bytes"                      ;; y-axis label
				 dataset                             ;; data
				 true                                ;; create legend?
				 true                                ;; generate tooltips?
				 false)                              ;; generate URLs?
			  plot (. chart getPlot)]
	(doto plot
	  (. setBackgroundPaint     java.awt.Color/white)
	  (. setDomainGridlinePaint java.awt.Color/lightGray)
	  (. setRangeGridlinePaint  java.awt.Color/lightGray)
	  (. setAxisOffset (new RectangleInsets 5.0 5.0 5.0 5.0))
	  (. setDomainCrosshairVisible true)
	  (. setRangeCrosshairVisible true))
	chart))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Graph Menu Creation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn add-graph-menuitems [menu]
  (let [ sysout-item (new MenuItem menu (. SWT CASCADE))
         syserr-item  (new MenuItem menu (. SWT CASCADE))
         gc-item      (new MenuItem menu (. SWT CASCADE))
         gc-time-item (new MenuItem menu (. SWT CASCADE))
         req-item     (new MenuItem menu (. SWT CASCADE))
         errs-item    (new MenuItem menu (. SWT CASCADE))
         query-item   (new MenuItem menu (. SWT CASCADE)) ]
	(doto sysout-item
	  (. setText (res-win-str "Graphs_sysout_menuitem")))
	(doto syserr-item
	  (. setText (res-win-str "Graphs_syserr_menuitem")))
	(doto gc-item
	  (. setText (res-win-str "Graphs_gctime_menuitem"))
	  (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [e] (create-graph-gc-window)))))
	(doto gc-time-item
	  (. setText (res-win-str "Graphs_gctimems_menuitem")))
	(doto req-item
	  (. setText (res-win-str "Graphs_req_menuitem")))
	(doto errs-item
	  (. setText (res-win-str "Graphs_errs_menuitem")))
	(doto query-item
	  (. setText (res-win-str "Graphs_query_menuitem")))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Graph Menu Creation (Open file to launch graph)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn add-graph-file-menuitems [menu]
  (new MenuItem menu SWT/SEPARATOR)
  (let [ sysout-item (new MenuItem menu (. SWT CASCADE))
         syserr-item  (new MenuItem menu (. SWT CASCADE))
         gc-item      (new MenuItem menu (. SWT CASCADE))
         req-item     (new MenuItem menu (. SWT CASCADE))
         query-item   (new MenuItem menu (. SWT CASCADE)) ]
	(doto sysout-item
	  (. setText (res-win-str "Graphs_sysout_file_menuitem")))
	(doto syserr-item
	  (. setText (res-win-str "Graphs_syserr_file_menuitem")))
	(doto gc-item
	  (. setText (res-win-str "Graphs_gctime_file_menuitem"))
	  (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [e] (graph-gc-byfile-window)))))
	(doto req-item
	  (. setText (res-win-str "Graphs_req_file_menuitem")))
	(doto query-item
	  (. setText (res-win-str "Graphs_query_file_menuitem")))))

(defn create-graphs-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar  (. sh getMenuBar)
        menu (new Menu bar)]
	(add-graph-menuitems menu)
    (add-graph-file-menuitems menu)
    menu))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Graph Window Creation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn safe-create-dataset
  "Create a dataset object based on information from file"
  [gc-filename]
  ;;;;;;;;;;;;;
  (try (create-timegc-dataset gc-filename)
       (catch Exception e
              (history-add-textln
               (str "ERR: create gc dataset file => " gc-filename \newline "ERR: " (. e getMessage)))
              nil)))

(defn create-graph-gc-file
    "Initialize the file database SWT window, set the size add all components"
    [filename]
    ;;;;;;;;;;;;;;;;;;;;;;;;;
	(doto *graph-gc-shell*
	  (. setSize *graph-size-width* *graph-size-height*)
	  (. setLayout (new FillLayout))
	  (. addShellListener (shell-close-adapter *graph-gc-shell*)))
	(let [gc-filename filename
          dataset (safe-create-dataset gc-filename)
          chart   (create-timegc-chart dataset)
          frame   (new ChartComposite *graph-gc-shell* SWT/NONE chart true)]
	  (doto frame
        (. setDisplayToolTips     true)
        (. setHorizontalAxisTrace false)
        (. setVerticalAxisTrace   false)))
	;; Open the graph window
	(doto *graph-gc-shell*
	  (. open) (. setVisible true))
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Enter display/shell loop for this window
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	(let [disp (. *graph-gc-shell* getDisplay)]
	  (shell-display-loop disp *graph-gc-shell* false "Graph GC shell disposed")))

(defn create-graph-gc-window
    "Initialize the file database SWT window, set the size add all components"
    []
    ;;;;;;;;;;;;;;;;;;;;;;;;;
	(history-add-textln 
	 (str "Opening GC graph (), gc-file => " (user-variable "Graphs_gctime_logs")))
    (create-graph-gc-file (user-variable "Graphs_gctime_logs")))

(def graph-gc-byfile-handler
     (fn [disp file path] 
         ;; Handler for the graph garbage collection by file
         (when file
           (history-add-textln (str "Opening GC graph by file (), gc-file => " (. file getAbsolutePath)))
           (create-graph-gc-file (. file getAbsolutePath)))))

(defn graph-gc-byfile-window
    "Initialize the file database SWT window, set the size add all components"
    []
    ;;;;;;;;;;;;;;;;;;;;;;;;;
    (simple-dialog-open-file 
     (. *graph-gc-shell* getDisplay) graph-gc-byfile-handler *sysout-wildcard-seq*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;