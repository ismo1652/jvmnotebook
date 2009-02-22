;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;;
;;;
;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... Brown <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns octane.toolkit.octane_batch_search
	(:use
	 octane.toolkit.octane_utils
	 octane.toolkit.public_objects
	 octane.toolkit.octane_gui_utils
	 octane.toolkit.octane_config
	 octane.toolkit.octane_tools)
	(:import 
	 (java.io File)
	 (org.eclipse.swt SWT)
	 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
	 (org.eclipse.swt.widgets FileDialog MessageBox TableItem Button
							  Composite Table TableColumn)
	 (org.eclipse.swt.layout GridData GridLayout RowLayout RowData)
	 (org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
							 SelectionEvent ShellAdapter ShellEvent)
	 (org.eclipse.swt.widgets Label Menu MenuItem Control Listener)))

(def *batch-search-style* (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE 1))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Create the Widgets
;; Will be positioned on order of creation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def *batch-search-shell*        (new Shell *shell* *batch-search-style*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Layout:
;; (1) Find Text Box
;; (2) Date Box
;; (3) Search Term Replace
;; (4) Server Selection
;; (5) Filename Pattern
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def *batch-find-label*       (new Label *batch-search-shell* SWT/LEFT))
(def *batch-find-box*         (new Text  *batch-search-shell* SWT/BORDER))

(def *batch-date-label*       (new Label *batch-search-shell* SWT/LEFT))
(def *batch-termrepl-box*     (new Text  *batch-search-shell* SWT/BORDER))

(def *batch-term-label*       (new Label *batch-search-shell* SWT/LEFT))
(def *batch-term-box*         (new Text  *batch-search-shell* SWT/BORDER))

(def *batch-server-label*     (new Label *batch-search-shell* SWT/LEFT))
(def *batch-server-box*       (new Text  *batch-search-shell* SWT/BORDER))

(def *batch-pattern-label*    (new Label *batch-search-shell* SWT/LEFT))
(def *batch-pattern-box*      (new Text  *batch-search-shell* SWT/BORDER))

(def *regex-batch-label*      (new Label  *batch-search-shell* SWT/LEFT))
(def *regex-batch-check-box*  (new Button *batch-search-shell* SWT/CHECK))

(def *casesens-batch-label*     (new Label  *batch-search-shell* SWT/LEFT))
(def *casesens-batch-check-box* (new Button *batch-search-shell* SWT/CHECK))

(def *batch-composite*          (new Composite *batch-search-shell* SWT/NONE))
(def *batch-find-button*        (new Button    *batch-composite* SWT/PUSH))
(def *batch-close-button*       (new Button    *batch-composite* SWT/PUSH))
(def *batch-status-label*       (new Label     *batch-search-shell* (bit-or SWT/LEFT (bit-or SWT/BORDER 1))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn create-batch-grid-layout []
  (let [gridLayout (new GridLayout)]
    (set! (. gridLayout marginHeight)  8)
    (set! (. gridLayout marginWidth)  10)
    (set! (. gridLayout numColumns) 2) gridLayout))


(def uncompress-on-close-listener
     (proxy [SelectionListener][]
            (widgetSelected [event]
                            (set! (. event doit) false)
                            (. *batch-search-shell* setVisible false))
            (widgetDefaultSelected [event]
                                   (set! (. event doit) false)
                                   (. *batch-search-shell* setVisible false))))

(defn uncompress-label-set-text
  "Helper function to set the search label text"
  []
  ;;;
  (. *batch-find-label*       setText (prop-str resources-win "Search_for_label"))
  (. *batch-date-label*       setText (prop-str resources-win "Uncompress_Search_date_label"))
  (. *batch-term-label*       setText (prop-str resources-win "Uncompress_Search_termrepl_label"))
  (. *batch-server-label*     setText (prop-str resources-win "Uncompress_Search_path_label"))
  (. *batch-pattern-label*    setText (prop-str resources-win "Dialog_Search_ext_label"))
  (. *regex-batch-label*      setText (prop-str resources-win "Dialog_Search_regex_label"))
  (. *casesens-batch-label*   setText (prop-str resources-win "Dialog_Search_case_label")))

(defn init-uncompress-buttons
  "Set the default properties for the search buttons"
  []
  ;; Set the composite buttons
  (let [rowd-find (new RowData 130 24)]
    (. *batch-find-button*   setText "Search Archives")
    (. *batch-find-button*   setLayoutData rowd-find)
    (. *batch-find-button*   setEnabled true)
    ;;(. *batch-find-button*   addSelectionListener findfiles-find-next-listener)
    (. *batch-close-button*  setText "Close")
    (. *batch-close-button*  setLayoutData rowd-find)
    (. *batch-close-button*  setEnabled true)
    (. *batch-close-button*  addSelectionListener uncompress-on-close-listener)))

(defn init-uncompress-textbox
  [#^GridData gd]
  ;;;;;;;;;;;;;;;  
  (. *batch-find-box* setLayoutData gd)
  (let [gd-text (new GridData SWT/FILL SWT/NONE true false)]
	(. *batch-termrepl-box* setLayoutData gd-text)
	(. *batch-term-box* setLayoutData gd-text)
	(. *batch-server-box* setLayoutData gd-text)
	(. *batch-pattern-box* setLayoutData gd-text)))

(defn init-uncompress-search-helper
  "Create the layout and place with the widgets for the search box"
  [sh]
  ;;;;;;;;;
  (let [gd-textbox (new GridData GridData/FILL_HORIZONTAL)
				   gd-composite   (new GridData SWT/NONE)
				   gd-status-bar  (new GridData SWT/FILL SWT/FILL true false 2 1)
				   comp-layout    (new RowLayout)]
	(uncompress-label-set-text)
	(set! (. gd-textbox widthHint) 220)
	(. *batch-status-label* setLayoutData gd-status-bar)
	(init-uncompress-textbox gd-textbox)
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Set the button composite widget
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    (set! (. gd-composite horizontalSpan) 2)
    ;; verticalAlignment specifies how controls will be positioned vertically within a cell
    (set! (. gd-composite horizontalAlignment) SWT/LEFT)
    (. *batch-composite* setLayoutData gd-composite)
    ;; Position the buttons a couple of pixels away.
    (set! (. comp-layout marginTop)  4)
    (set! (. comp-layout marginLeft) 2)
    (. *batch-composite* setLayout comp-layout)	
	(init-uncompress-buttons)))
  
(defn create-batchfind-dialog 
  "Initialize the file database SWT window, set the size add all components"
  []
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  (history-add-textln "Opening batch uncompress screen (Search -> Open New Find in Files)")
  (let [layout (create-batch-grid-layout)]
	(. *batch-search-shell* setText "Batch Uncompress and Find")
	(init-uncompress-search-helper *batch-search-shell*)
	(. *batch-search-shell* setLayout layout)
	(. *batch-search-shell* addShellListener
	   (proxy [ShellAdapter][]
			  (shellClosed [event]
						   (set! (. event doit) false)
						   (. *batch-search-shell* setVisible false))))
	(. *batch-search-shell* pack)
	(. *batch-search-shell* open)
	(. *batch-search-shell* setVisible true)
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Enter display/shell loop for this window
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	(let [disp (. *batch-search-shell* getDisplay)]
	  (shell-display-loop disp *batch-search-shell* false "Search shell disposed"))))

(def uncompress-search-listener
     (proxy [SelectionAdapter] []
			;; Open the find files dialog
			(widgetSelected [event] (create-batchfind-dialog))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      