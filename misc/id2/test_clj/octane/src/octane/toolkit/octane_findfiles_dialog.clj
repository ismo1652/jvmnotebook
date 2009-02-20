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

(ns octane.toolkit.octane_findfiles_dialog
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

(def *findfiles-style* (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE 1))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Create the Widgets
;; Will be positioned on order of creation
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def *findfiles-shell*        (new Shell *shell* *findfiles-style*))
(def findfiles-label          (new Label *findfiles-shell* SWT/LEFT))
(def findfiles-filter-box     (new Text  *findfiles-shell* SWT/BORDER))

(def ff-location-label         (new Label *findfiles-shell* SWT/LEFT))
(def ff-location-box           (new Text  *findfiles-shell* SWT/BORDER))

(def ff-wildcard-label         (new Label *findfiles-shell* SWT/LEFT))
(def ff-wildcard-box           (new Text  *findfiles-shell* SWT/BORDER))

(def regex-findfiles-label     (new Label  *findfiles-shell* SWT/LEFT))
(def regex-ff-check-box        (new Button *findfiles-shell* SWT/CHECK))
(def casesens-findfiles-label  (new Label  *findfiles-shell* SWT/LEFT))
(def casesens-ff-check-box     (new Button *findfiles-shell* SWT/CHECK))

(def findfiles-composite      (new Composite *findfiles-shell* SWT/NONE))
(def findfiles-find-button    (new Button findfiles-composite SWT/PUSH))
(def findfiles-close-button   (new Button findfiles-composite SWT/PUSH))
(def findfiles-status-label   (new Label *findfiles-shell* (bit-or SWT/LEFT (bit-or SWT/BORDER 1))))

(defn create-findfiles-grid-layout []
  (let [gridLayout (new GridLayout)]
    (set! (. gridLayout marginHeight)  8)
    (set! (. gridLayout marginWidth)  10)
    (set! (. gridLayout numColumns) 2) gridLayout))

(defn findfiles-label-set-text
  "Helper function to set the search label text"
  []
  ;;;
  (. findfiles-label setText (prop-str resources-win "Search_for_label"))
  (. regex-findfiles-label setText "Regular Expressions:")
  (. casesens-findfiles-label setText "Case Sensitive:")
  (. findfiles-status-label setText (str "Find in Files Dialog Opened - " (date-time)))
  (. ff-location-label setText "Find Directory:")
  (. ff-wildcard-label setText "File Name Patterns:")
  (. ff-wildcard-box   setText "*.*"))

(def findfiles-on-close-listener
     (proxy [SelectionListener][]
            (widgetSelected [event]
                            (set! (. event doit) false)
                            (. *findfiles-shell* setVisible false))
            (widgetDefaultSelected [event]
                                   (set! (. event doit) false)
                                   (. *findfiles-shell* setVisible false))))

(def on-findfiles-dir-func (fn [d] false))

(def on-findfiles-file-func
     ;; Return lambda function, on file handler
     (fn [file]
         (let [filename (. file getAbsolutePath)
               disp    (. *findfiles-shell* getDisplay)
               term    (get-sync-call disp (. findfiles-filter-box getText))]
           (doc-file-loop-handler filename
                                  (fn [line line-num]
                                      ;; Lambda function for on find string
                                      ;; Update the display with the 'grep' information.
                                      (when (simple-grep? line term)
                                        (async-call *display*
                                                    (add-main-text-nc
                                                     (str filename ": line " line-num ": " (.trim line))))))))))

(defn findfiles-find-handler
  "When the user selects the find next button, invoke this find next handler.
 Search the main buffer for the term in the 'find' box."
  [event]
  ;;;;;;;;;;;;
  (let [disp    (. *findfiles-shell* getDisplay)
        term    (get-sync-call disp (. findfiles-filter-box getText))
        cur-dir "."]
    (if (and disp term cur-dir (> (length cur-dir) 0) (> (length term) 0))
	  (let [tstart (. System currentTimeMillis)]
		;; Establish the directory and file functions.
        (async-status-history *display* (str "Begin Find File Search For => " term " at "(date-time)))
		(let [dir-func  on-findfiles-dir-func
			  file-func on-findfiles-file-func]
          (traverse-directory (new File ".") dir-func file-func))
		(let [tend (. System currentTimeMillis)
				   diff (- tend tstart)]
		  (async-status-history *display* (str "End Find File Search, process time => " diff " ms"))))
      (do
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ;; Err:
        ;; Send status error message, could not find
        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        (if (not term) 
          (async-call disp (. findfiles-status-label setText "Invalid Search Term (empty)"))
          (async-call disp (. findfiles-status-label setText "Invalid Search Term (empty)")))
        (if (not cur-dir)
          (async-call disp (. findfiles-status-label setText "Invalid Directory (empty)"))
          (async-call disp (. findfiles-status-label setText "Invalid Directory (empty)")))))))

(defn findfiles-find-thread
  "When the user selects the find next button, invoke this find next handler.
 Search the main buffer for the term in the 'find' box."
  [event]
  ;;;;;;;;;;;;
  (let [prox (proxy [Runnable][] (run [] (findfiles-find-handler event)))]
    (. (new Thread prox) start)))

(def findfiles-find-next-listener
     (proxy [SelectionListener][]
            (widgetSelected [event] (findfiles-find-thread event))
            (widgetDefaultSelected [event] (findfiles-find-thread event))))

(defn init-findfiles-buttons
  "Set the default properties for the search buttons"
  []
  ;; Set the composite buttons
  (let [rowd-find (new RowData 98 24)]
    (. findfiles-find-button  setText "Find in Files")
    (. findfiles-find-button  setLayoutData rowd-find)
    (. findfiles-find-button  setEnabled true)
    (. findfiles-find-button  addSelectionListener findfiles-find-next-listener)
    (. findfiles-close-button setText "Close")
    (. findfiles-close-button setLayoutData rowd-find)
    (. findfiles-close-button setEnabled true)
    (. findfiles-close-button addSelectionListener findfiles-on-close-listener)))

(defn init-findfiles-helper
  "Create the layout and place with the widgets for the search box
 Notes On Grid Data (useful for search widgets):
 GridData(int horizontalAlignment, int verticalAlignment, boolean grabExcessHorizontalSpace, 
               boolean grabExcessVerticalSpace, int horizontalSpan, int verticalSpan)"
  [sh]
  ;;;;;
  (let [gd-textbox (new GridData GridData/FILL_HORIZONTAL)
        gd-composite   (new GridData SWT/NONE)
        gd-status-bar  (new GridData SWT/FILL SWT/FILL true false 2 1)
        comp-layout    (new RowLayout)]
    (findfiles-label-set-text)
    (set! (. gd-textbox widthHint) 200)
    (. findfiles-filter-box setLayoutData gd-textbox)
    (. findfiles-status-label setLayoutData gd-status-bar)
	(. ff-location-box setLayoutData (new GridData SWT/FILL SWT/NONE true false))
	(. ff-wildcard-box setLayoutData (new GridData SWT/FILL SWT/NONE true false))
    ;; Set the button composite widget
    (set! (. gd-composite horizontalSpan) 2)
    ;; verticalAlignment specifies how controls will be positioned vertically within a cell
    (set! (. gd-composite horizontalAlignment) SWT/LEFT)
    (. findfiles-composite setLayoutData gd-composite)
    ;; Position the buttons a couple of pixels away.
    (set! (. comp-layout marginTop)  4)
    (set! (. comp-layout marginLeft) 2)
    (. findfiles-composite setLayout comp-layout)    
    (init-findfiles-buttons)))
			  
;;;;;;;;;;;;;;;;;;;;
;; End of Function
;;;;;;;;;;;;;;;;;;;;

(defn create-findfiles-dialog 
  "Initialize the file database SWT window, set the size add all components"
  [parent-sh]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  (history-add-text "Opening find files screen (Search -> Open New Find in Files)")
  (let [layout (create-findfiles-grid-layout)]
	(. *findfiles-shell* setText "Find in Files")
	(init-findfiles-helper *findfiles-shell*)
	(. *findfiles-shell* setLayout layout)
	(. *findfiles-shell* addShellListener
	   (proxy [ShellAdapter][]
			  (shellClosed [event]
						   (set! (. event doit) false)
						   (. *findfiles-shell* setVisible false))))
	(. *findfiles-shell* pack)
	(. *findfiles-shell* open)
	(. *findfiles-shell* setVisible true)
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Enter display/shell loop for this window
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	(let [disp (. *findfiles-shell* getDisplay)]
	  (shell-display-loop disp *findfiles-shell* false "Search shell disposed"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;