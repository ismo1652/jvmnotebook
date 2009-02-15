;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;;
;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.
;;;
;;; Clojure version: Clojure release 20081217

;;; Key Functions: simple-swt create-file-menu
;;; Also see: 
;;; http://help.eclipse.org/stable/nftopic/org.eclipse.platform.doc.isv/reference/api/index.html
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns octane.toolkit.octane_main_window
	(:use    octane.toolkit.octane_utils
			 octane.toolkit.octane_analytics
			 octane.toolkit.octane_codegen_templates
			 octane.toolkit.octane_config
			 octane.toolkit.octane_core_widgets
			 octane.toolkit.octane_file_database
			 octane.toolkit.octane_file_utils
			 octane.toolkit.octane_graphs
			 octane.toolkit.octane_gui_utils
			 octane.toolkit.octane_main_constants
			 octane.toolkit.octane_regex_search
			 octane.toolkit.octane_search_dialog
			 octane.toolkit.octane_templates
			 octane.toolkit.octane_testing
			 octane.toolkit.octane_tools
			 octane.toolkit.octane_utils
			 octane.toolkit.public_objects)
	(:import (org.eclipse.swt SWT)
			 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
			 (org.eclipse.swt.widgets Label Menu MenuItem Control Listener)
			 (org.eclipse.swt.widgets FileDialog MessageBox TableItem Button
									  Composite Table TableColumn)
			 (org.eclipse.swt.custom LineStyleEvent StyledText
									 LineStyleListener StyleRange)
			 (org.eclipse.swt.graphics Color RGB FontData Font)
			 (org.eclipse.swt.layout GridData GridLayout RowLayout RowData)
			 (org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
									 SelectionEvent ShellAdapter ShellEvent)
			 (org.eclipse.swt.widgets FileDialog DirectoryDialog MessageBox Composite)
			 (org.eclipse.swt SWT)
			 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
			 (java.util ResourceBundle Vector Hashtable)
			 (java.util.regex Pattern)))

;;**************************************
;; Begin Routines
;;**************************************
(def search-keyword)

(defn search-term? [] (if (> (length (. search-box getText)) 2) true false))

(defn srchbox-get-text [] (str (. search-box getText)))

(defn main-match-style [keyword line lo]
  (let [m (regex-match-group keyword line)]
    (when m
      (let [pt1 (+ lo (. m start))
            pt2 (+ lo (. m end))
            len (- pt2 pt1)
            styl-tok (new StyleRange pt1 len (col-vec-wht) (col-vec-drkb) SWT/BOLD)]
        styl-tok))))

(defn style-keyword-match [styles-vec line l-offset sty-on-sel sty-fail]
  (when (search-term?)
    (if (search-keyword (srchbox-get-text) line)
      (let [dummy1 (add-select-style styles-vec sty-on-sel)]
        (when-let [fnd-style (main-match-style (srchbox-get-text) line l-offset)]
                  ;; Check if Match found, so add the style range
                  (add-select-style styles-vec fnd-style)))
      (add-select-style styles-vec sty-fail))))

(defn style-handler [event]
  (let [styles-vec (new Vector)
                   line (. event lineText)
                   lo   (. event lineOffset)
                   len  (. line length)
                   bg   (. colors-vec get 0)
                   fgl  (. colors-vec get 1)
                   all-bold (new StyleRange lo len nil bg   SWT/BOLD)
                   light    (new StyleRange lo len fgl nil  SWT/NORMAL)]
    ;; Add the event styles if needed   
    (style-keyword-match styles-vec line lo all-bold light)
    ;; Associate the even style with the display
    (let [arr (make-array StyleRange (. styles-vec size))]
      (set! (. event styles) arr)
      (. styles-vec copyInto (. event styles)))))

(defn search-keyword [keyword line]
  (re-seq (octane-pattern keyword Pattern/CASE_INSENSITIVE) line))
      
;; Event.detail line start offset (input) Event.text line text (input)
;; LineStyleEvent.styles Enumeration of StyleRanges, need to be in order.
;; (output) LineStyleEvent.background line background color (output)
(def text-style-listener
     (proxy [LineStyleListener] []
            (lineGetStyle [event] (style-handler event))))

(def shell-close-listener
     (proxy [ShellAdapter] [] 
            (shellClosed [evt] (exit))))

(defn refresh-textarea-deprecated []
  (let [disp (. *styled-text* getDisplay)]             
    (. disp asyncExec
       (proxy [Runnable] []
              (run [] (. *styled-text* setText (. buffer-1 toString)))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Continue
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def find-text-listener
     (proxy [Listener] []
            (handleEvent [event]
                         (when (= (. event detail) SWT/TRAVERSE_RETURN)
                           (history-add-text (str "Searching for " (. search-box getText) "\n"))
                           (refresh-textarea)))))
                           
(defn create-grid-layout []
  (let [gridLayout (new GridLayout)]
    (set! (. gridLayout numColumns) 1)
    gridLayout))
        
(defn create-shell [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [layout (create-grid-layout)]
    (doto sh
      (. setText (. resources-win getString "Window_title"))
      (. setLayout layout)
      (. addShellListener (proxy [ShellAdapter] []
                                 (shellClosed [evt] (exit)))))))

(defn init-gui-helper [disp sh]
  (create-all-tabs)
  (create-menu-bar disp sh)
  (create-shell    disp sh)
  (init-colors)
  (history-add-text (get-hist-header))
  (status-set-text  (str "Octane GUI loaded " (date-time) " " (*memory-usage*))))

(defn 
  #^{:doc "Initialize the SWT window, set the size add all components"}
  create-gui-window [disp sh]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;
  
  ;; Set the tab folder and items with the main text area
  ;; and other SWT oriented inits.
  (init-gui-helper disp sh)
  ;; Modify already created objects
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (. search-box addListener SWT/Traverse find-text-listener)
    (. search-box setLayoutData gd)
    (. location-bar setLayoutData gd)
    (. location-bar addListener SWT/Traverse location-text-listener))
  (create-status-bar)
  ;; Final init, set the window size and then open
  (doto sh
    (. setSize win-size-width win-size-height)
    (. open))
  (parse-system-args)
  ;; Debug
  (loop [] (if (. sh (isDisposed))
             (. disp (dispose))
             (let [] (when (not (. disp (readAndDispatch)))
                       (. disp (sleep)))
                  (recur)))))

;;**************************************
;; Application Main Entry Point
;**************************************
(defn main-1 
  " Application Entry Point, launch the main window and wait for events"
  []
  ;;;;

  (println "Launching Octane Text Viewer...")
  (create-gui-window *display* *shell*)
  (let [o (new Object)] (locking o (. o (wait)))))

(defn -main [& args]
  (try (main-1)
	   (catch Exception e
			  (println "ERR at <Main>: " e)
			  (exit))))

(-main)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      
