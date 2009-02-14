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

(ns octane.toolkit.octane_core_widgets
	(:use    octane.toolkit.octane_utils
			 octane.toolkit.public_objects
			 octane.toolkit.octane_config
			 octane.toolkit.octane_main_constants
			 octane.toolkit.octane_file_utils
			 octane.toolkit.octane_gui_utils
			 octane.toolkit.octane_tools
			 octane.toolkit.octane_file_database
			 octane.toolkit.octane_graphs
			 octane.toolkit.octane_search_dialog
			 octane.toolkit.octane_regex_search)
	(:import (java.util Date)
			 (org.eclipse.swt SWT)
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
			 (java.util ResourceBundle Vector Hashtable)))

(import '(java.io BufferedReader File FileInputStream
                  FileNotFoundException IOException InputStreamReader Reader))
(import '(java.util ResourceBundle Vector Hashtable))
(import '(org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem))
(import '(java.util HashMap))

(defn create-tab-1 []
  (. tab-area-1 setText    tab-1-title)
  (. tab-area-1 setControl *styled-text*))

(defn create-tab-2 []
  (. tab-area-2 setText    tab-2-title)
  (. tab-area-2 setControl tab-text-2)
  (. tab-text-2 setFont    (styled-text-font)))

(defn create-tab-3 []
  (. tab-area-3 setText    tab-3-title)
  (. tab-area-3 setControl tab-text-3)
  (. tab-text-3 setFont    (styled-text-font)))

(defn create-tab-4 []
  (. tab-area-4 setText    tab-4-title)
  (. tab-area-4 setControl tab-text-4)
  (. tab-text-4 setFont    (styled-text-font)))

(defn create-all-tabs []
  (create-tab-1)
  (create-tab-2)
  (create-tab-3)
  (create-tab-4))

(def status-arm-listener
     (proxy [Listener] [] (handleEvent [event])))

(defn create-status-bar []
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (. status-bar setLayoutData gd)
    (. status-bar addListener SWT/Arm status-arm-listener)))
    
(defn create-file-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar       (. sh getMenuBar)
        menu      (new Menu bar)
        item      (new MenuItem menu (. SWT PUSH))
        dir-item  (new MenuItem menu (. SWT PUSH))
        run-expl  (new MenuItem menu (. SWT PUSH))]
    (doto item
      ;;;;;;;;;;;;;;;;;;;;;
      ;; Open File Menu Option
      ;;;;;;;;;;;;;;;;;;;;;
      (. setText (. resources-win getString "Open_menuitem"))
      (. addSelectionListener 
         (proxy [SelectionAdapter] []
                (widgetSelected [e] (dialog-open-file)
                                println "Opening File"))))
    (doto dir-item
      ;; Open the directory dialog box
      (. setText (. resources-win getString "Opendir_menuitem"))
      (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [e] (dialog-open-dir)))))

    (doto run-expl      
      ;; Win explorer option
      ;; see octane_tools.clj for the file manager launcher
      (. setText (. resources-win getString "Filemanager_menuitem"))
      (. addSelectionListener 
         (proxy [SelectionAdapter] []
                (widgetSelected [e] (start-filemanager-proc)))))
      
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;; Create the recent file menu options
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    (new MenuItem menu SWT/SEPARATOR)
    (create-recent-menu-items menu)    
    (new MenuItem menu SWT/SEPARATOR)
    ;; Create exit menu item last.
    (let [item-exit (new MenuItem menu (. SWT PUSH))]
      (doto item-exit
        (. setText (. resources-win getString "Exit_menuitem"))
        (. addSelectionListener 
           (proxy [SelectionAdapter] []
                  (widgetSelected [evt] (exit) println "Exiting")))))
    menu))
    
(defn create-help-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar (. sh getMenuBar)
            menu (new Menu bar)
            item (new MenuItem menu (. SWT PUSH))]
    (doto item
      (. setText (. resources-win getString "About_menuitem"))
      (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [event] (create-about-messagebox sh)))))
    menu))

(defn create-tools-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar (. sh getMenuBar)
            menu (new Menu bar)
            item (new MenuItem menu (. SWT PUSH))
            code-gen-item (new MenuItem menu (. SWT PUSH))]
    (doto item
      (. setText (. resources-win getString "Database_viewer_menuitem"))
      (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [event] (create-database-window *shell* true)))))
    (doto code-gen-item
      (. setText (. resources-win getString "Codegen_buildxml_menuitem"))
      (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [event] (run-codegen-build-xml)))))
    menu))

(defn create-search-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar (. sh getMenuBar)
            menu (new Menu bar)
            item (new MenuItem menu (. SWT PUSH))
            regex-item (new MenuItem menu (. SWT PUSH))]
    (doto item
      (. setText (. resources-win getString "Find_menuitem"))
      (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [event] (create-search-dialog sh)))))
    (doto regex-item
      (. setText (. resources-win getString "Regextool_menuitem"))
      (. addSelectionListener
         (proxy [SelectionAdapter] []
                (widgetSelected [event] (create-regex-window)))))
    ;; Add the 'find/grep' menu items
    (add-findgrep-options menu)
    menu))

(defn create-menu-bar [disp sh]
  (let [bar  (new Menu sh (. SWT BAR))
        item (new MenuItem bar (. SWT CASCADE))
        search-item    (new MenuItem bar (. SWT CASCADE))
        recent-buffers (new MenuItem bar (. SWT CASCADE))
        tools-item     (new MenuItem bar (. SWT CASCADE))
        analytics-item (new MenuItem bar (. SWT CASCADE))
        graphs-item    (new MenuItem bar (. SWT CASCADE))
        help-item      (new MenuItem bar (. SWT CASCADE))]        
    (. sh setMenuBar bar)
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;; Build the Main Window Menu Bar
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    (doto item
      (. setText (. resources-win getString "File_menuitem"))
      (. setMenu (create-file-menu disp sh)))
    (doto help-item
      (. setText (. resources-win getString "Help_menu_title"))
      (. setMenu (create-help-menu disp sh)))
    (doto search-item
      (. setText (. resources-win getString "Search_menu_title"))
      (. setMenu (create-search-menu disp sh)))
    (doto tools-item
      (. setText (. resources-win getString "Tools_menu_title"))
      (. setMenu (create-tools-menu disp sh)))
    (doto analytics-item
      (. setText (. resources-win getString "Analytics_menu_title")))
    (doto graphs-item
      (. setText (. resources-win getString "Graphs_menu_title"))
      (. setMenu (create-graphs-menu disp sh)))
    (let [buf-menu (new Menu bar)]
      (doto recent-buffers
        (. setText (. resources-win getString "RecentBuffers_menu_title"))
        (. setMenu buf-menu))
      (set-buffer-menu-state buf-menu))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      