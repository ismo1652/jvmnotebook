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

(ns octane.toolkit.octane_analytics
	(:use    octane.toolkit.octane_utils
			 octane.toolkit.public_objects
			 octane.toolkit.octane_config
			 octane.toolkit.octane_main_constants
			 octane.toolkit.octane_file_utils
			 octane.toolkit.octane_gui_utils)
	(:import 			 
	 (java.util Date)
	 (java.io File BufferedReader)
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Function Implementations
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def *request-log-regex*
	 "([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3})\\s-\\s(\\S*?)\\s-\\s\\[(.*?)\\]\\s\\\"(.*?)\\\"\\s([0-9]{3})")

(def *query-log-regex--*
	 "\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|.*$")

(def *query-log-regex*
	 "\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?)\\s\\|\\s(\\S*?).*$")

(defn build-request-list [pttr all-lines]
  (let [m (. pttr matcher (first all-lines))]
	(when (. m find)
	  (let [ip (. m group 1)
			   uid    (. m group 2)
			   tstamp (. m group 3)
			   req    (. m group 4)
			   status (. m group 5)]
		(list ip uid req status)))))

(defn build-queryregex-list [all-lines]
  (let [pattr (octane-pattern_ *query-log-regex*)
			  m (. pattr matcher (first all-lines))]
	(when (. m find)
	  (let [app (. m group 1)
				query (. m group 2)
				func  (. m group 3)]
		(list app query func)))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn request-frequency
  "Analyze the lines of the request log and return a map of keyword frequency statistics"
  [doc-str]
  ;;;;;;;;;;;;;;;;;;;
  (keyword-frequency
   (flatten
	(loop [all-lines (seq (.split doc-str *newline*)) prev-list ()]
	  (if all-lines
		(let [pattr (octane-pattern_ *request-log-regex*)
					res (when-let [lst (build-request-list pattr all-lines)]
								  (cons lst prev-list))]
		  (recur (rest all-lines) (if res res prev-list)))
		prev-list)))))

(defn analytics-quick-sysout-handler 
  "This function is used with the simple dialog file opener, when the dialog
 opener is invoked, this handler function will get invoked with the path of the
 file to open"
  [my-disp file path] 
  ;;;;;;;;;;;;;;;;  
  (if (not (. file exists)) (display-error "File does not exist")
	  (let [file-str-data (open-file-util file (. file getPath))
						  filter-data (doc-filter-regex file-str-data "Servlet|Filter")]
		(. my-disp asyncExec (proxy [Runnable] []
									(run [] (add-main-text filter-data)))))))

(defn analytics-reqlog-stats  
  [file-str-data]
  ;;;;;;;;;;;;;;;;;;
  (let [req-map (request-frequency file-str-data)
				buf (new StringBuffer)]
	(doseq [req-data req-map]
		(. buf append (str req-data \newline)))
	(. buf toString)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Query Regex Helpers
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn query-frequency
  "Analyze the lines of the request log and return a map of keyword frequency statistics"
  [doc-str]
  ;;;;;;;;;;;;;;;;;;;
  (keyword-frequency
   (flatten
	(loop [all-lines (seq (.split doc-str *newline*)) prev-list ()]
	  (if all-lines
		(let [res (when-let [lst (build-queryregex-list all-lines)]
							(cons lst prev-list))]
		  (recur (rest all-lines) (if res res prev-list)))
		prev-list)))))

(defn analytics-query-stats  
  [file-str-data]
  ;;;;;;;;;;;;;;;;;;
  (let [my-map (query-frequency file-str-data) buf (new StringBuffer)]
	(doseq [my-data my-map]
		(. buf append (str my-data \newline)))
	(. buf toString)))

(defn analytics-query-handler
  "This function is used with the simple dialog file opener, when the dialog
 opener is invoked, this handler function will get invoked with the path of the
 file to open"
  [my-disp file path] 
  ;;;;;;;;;;;;;;;;  
  (if (not (. file exists)) (display-error "File does not exist")
	  (let [file-str-data (open-file-util file (. file getPath))
						  filter-data ( analytics-query-stats file-str-data)]
		(. my-disp asyncExec (proxy [Runnable] []
									(run [] (add-main-text filter-data)))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn analytics-reqlog-stats-handler
  "This function is used with the simple dialog file opener, when the dialog
 opener is invoked, this handler function will get invoked with the path of the
 file to open.  Open the file and apply the regex expression.  Collect statistics on
 what is found within the regex group on each particular line in the file."
  [my-disp file path] 
  ;;;;;;;;;;;;;;;;  
  (if (not (. file exists)) (display-error "File does not exist")
	  (let [file-str-data (open-file-util file (. file getPath))
						  req-stats (analytics-reqlog-stats file-str-data)]
		(. my-disp asyncExec (proxy [Runnable] []
									(run [] (add-main-text req-stats)))))))

(defn add-analytics-menuitems [menu]
  (let [ quick-sysout-item (new MenuItem menu (. SWT CASCADE))
						   req-log-item   (new MenuItem menu (. SWT CASCADE))
						   query-log-item (new MenuItem menu (. SWT CASCADE))]
	(doto quick-sysout-item
	  (. setText (res-win-str "Analytics_quickfilter_sysout_menuitem"))
	  (. addSelectionListener
		 (proxy [SelectionAdapter] []
				(widgetSelected [e] 
								(simple-dialog-open-file 
								 *display* analytics-quick-sysout-handler
								 *sysout-wildcard-seq*)))))
	(doto req-log-item
	  (. setText (res-win-str "Analytics_reqlog_stats_menuitem"))
	  (. addSelectionListener
		 (proxy [SelectionAdapter] []
				(widgetSelected [e] 
								(simple-dialog-open-file 
								 *display* analytics-reqlog-stats-handler
								 *sysout-wildcard-seq*)))))
	(doto query-log-item
	   (. setText (res-win-str "Analytics_query_stats_menuitem"))
	   (. addSelectionListener
		 (proxy [SelectionAdapter] []
				(widgetSelected [e] 
								(simple-dialog-open-file 
								 *display* analytics-query-handler
								 *sysout-wildcard-seq*)))))))
;;;;;;;;;;;;;;;;;;;;;;;
	;; End of Function add menu items //->
;;;;;;;;;;;;;;;;;;;;;;;

(defn create-analytics-menu
  "Build the analytics menu items"
  [disp sh]
  ;;;;;;;;;;;;;;
  (let [bar (. sh getMenuBar)
			menu (new Menu bar)]
	(add-analytics-menuitems menu)
    menu))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;