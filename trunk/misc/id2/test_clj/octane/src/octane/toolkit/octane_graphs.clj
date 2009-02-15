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
			 octane.toolkit.octane_gui_utils)
	(:import 			 
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Time Series Creation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(defn create-timegc-chart
  "Create a time series chart with the given dataset."
  [dataset]
  ;;;;;;;;;;
  (let [chart (. ChartFactory createTimeSeriesChart
				 "Legal & General Unit Trust Prices"  ;; title
				 "Date"                               ;; x-axis label
				 "Price Per Unit"                     ;; y-axis label
				 dataset                              ;; data
				 true                                 ;; create legend?
				 true                                 ;; generate tooltips?
				 false)                               ;; generate URLs?
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

(defn create-graphs-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar (. sh getMenuBar)
        menu (new Menu bar)]
	(add-graph-menuitems menu)
    menu))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Graph Window Creation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn create-graph-gc-window
    "Initialize the file database SWT window, set the size add all components"
    []
    ;;;;;;;;;;;;;;;;;;;;;;;;;
	(history-add-textln "Opening GC graph ()")

	(doto *graph-gc-shell*
	  (. setSize *graph-size-width* *graph-size-height*)
	  (. setLayout (new FillLayout))
	  (. addShellListener (shell-close-adapter *graph-gc-shell*)))
	
	(let [chart (create-timegc-chart nil)
				frame (new ChartComposite *graph-gc-shell* SWT/NONE chart true)]
	  (doto frame
        (. setDisplayToolTips true)
        (. setHorizontalAxisTrace false)
        (. setVerticalAxisTrace false)))

	;; Open the graph window
	(doto *graph-gc-shell*
	  (. open)
	  (. setVisible true))

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Enter display/shell loop for this window
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	(let [disp (. *graph-gc-shell* getDisplay)]
	  (shell-display-loop disp *graph-gc-shell* false "Graph GC shell disposed")))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;