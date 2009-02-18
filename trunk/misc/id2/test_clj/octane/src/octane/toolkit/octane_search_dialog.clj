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

(ns octane.toolkit.octane_search_dialog
	(:use
	 octane.toolkit.octane_utils
	 octane.toolkit.public_objects
	 octane.toolkit.octane_gui_utils
	 octane.toolkit.octane_config
	 octane.toolkit.octane_tools)
	(:import 
	 (org.eclipse.swt SWT)
	 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
	 (org.eclipse.swt.widgets FileDialog MessageBox TableItem Button
							  Composite Table TableColumn)
	 (org.eclipse.swt.layout GridData GridLayout RowLayout RowData)
	 (org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
							 SelectionEvent ShellAdapter ShellEvent)
	 (org.eclipse.swt.widgets Label Menu MenuItem Control Listener)))

(def *search-style* (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE 1))))

(def search-shell        (new Shell *shell* *search-style*))
(def search-label        (new Label search-shell SWT/LEFT))
(def search-filter-box   (new Text search-shell SWT/BORDER))
(def search-composite    (new Composite search-shell SWT/NONE))
(def search-find-button  (new Button search-composite SWT/PUSH))
(def search-close-button (new Button search-composite SWT/PUSH))

(defn create-search-grid-layout []
  (let [gridLayout (new GridLayout)]
    (set! (. gridLayout marginHeight)  8)
    (set! (. gridLayout marginWidth)  10)
    (set! (. gridLayout numColumns) 2) gridLayout))

(defn init-search-helper
  "Create the layout and place with the widgets for the search box"
  [sh]
  ;;;;;
  (let [gd-textbox (new GridData GridData/FILL_HORIZONTAL)
        gd-composite (new GridData GridData/HORIZONTAL_ALIGN_FILL)
        comp-layout  (new RowLayout)
        rowd-find    (new RowData 98 26)]
    (. search-label setText (prop-str resources-win "Search_for_label"))
    (set! (. gd-textbox widthHint) 200)
    (. search-filter-box setLayoutData gd-textbox)
    ;; Set the button composite widget
    (set! (. gd-composite horizontalSpan) 2)
    (. search-composite setLayoutData gd-composite)
    ;; Position the buttons a couple of pixels away.
    (set! (. comp-layout marginTop)  12)
    (set! (. comp-layout marginLeft) 28)
    (. search-composite setLayout comp-layout)
    ;; Set the composite buttons
    (. search-find-button setText "Find Next")
    (. search-find-button setLayoutData rowd-find)
    (. search-find-button setEnabled true)
    (. search-close-button setText "Close")
    (. search-close-button setLayoutData rowd-find)
    (. search-close-button setEnabled true)))

(defn
    #^{:doc "Initialize the file database SWT window, set the size add all components"}
    create-search-dialog [parent-sh]
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    (history-add-text "Opening search screen (Search -> Find)")
    (let [layout (create-search-grid-layout)]
      (. search-shell setText (. resources-win getString "Find_dialog_title"))
      (init-search-helper search-shell)
      (. search-shell setLayout layout)
      (. search-shell addShellListener
         (proxy [ShellAdapter][]
                (shellClosed [event]
                             (set! (. event doit) false)
                             (. search-shell setVisible false))))
      (. search-shell pack)
      (. search-shell open)
      (. search-shell setVisible true)
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      ;; Enter display/shell loop for this window
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
      (let [disp (. search-shell getDisplay)]
        (shell-display-loop disp search-shell false "Search shell disposed"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Additional Search Utilities
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def findgrep-listener
     (proxy [SelectionAdapter] []
            (widgetSelected [event]
                            ;; With the async call, set the agent value
                            ;; based on the search box value                            
                            (. *display* syncExec 
                               (proxy [Runnable] []
                                      (run [] 
                                           (let [val (. search-box getText)]
                                             (send *search-text-state* (fn [_] val))))))
                            (let [widg-str (str (. event widget))]
                              (. (new Thread
                                      (start-findgrep-thread widg-str @*search-text-state* true)) start)))))
                                                   
(defn add-findgrep-options [menu]
  ;; Run non lazy sequence operation
  (doseq [menu-key [{:name "FindGrep_grep_menuitem"   :proc findgrep-listener }
                    {:name "FindGrep_15min_menuitem"  :proc findgrep-listener }
                    {:name "FindGrep_2hrs_menuitem"   :proc findgrep-listener }
                    {:name "FindGrep_java_menuitem"   :proc findgrep-listener }  
                    {:name "FindGrep_logs_menuitem"   :proc findgrep-listener }
                    {:name "Findfiles_60min_menuitem" :proc findgrep-listener }
                    {:name "FindGrep_clj_menuitem"    :proc findgrep-listener } ]]
      (let [mitem (create-menu-item menu (menu-key :name) (menu-key :proc))]
        ;; Menu item created, now associate the widget with the global 'ref'
        (set-findgrep-widg-state (keyword (menu-key :name)) (str mitem))
        (println (get-findgrep-widg-state (keyword (menu-key :name)))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      