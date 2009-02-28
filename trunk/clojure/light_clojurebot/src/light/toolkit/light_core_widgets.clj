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

(ns light.toolkit.light_core_widgets
	(:use    light.toolkit.light_utils
			 light.toolkit.public_objects
			 light.toolkit.light_config
			 light.toolkit.light_main_constants
			 light.toolkit.light_gui_utils)
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

(defn create-all-tabs []
  (create-tab-1)
  (create-tab-2)
  (create-tab-3))

(def status-arm-listener
     (proxy [Listener] [] (handleEvent [event])))

(defn create-status-bar []
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (. status-bar setLayoutData gd)
    (. status-bar addListener SWT/Arm status-arm-listener)))
    
(defn create-file-menu 
  "Add accelator CTRL + O, for OPEN MENU"
  [disp sh]
  ;;;;;;;;;;
  ;; Note change in 'doto' call, dot needed.
  (let [bar  (. sh getMenuBar)
        menu (new Menu bar)]
	(doto (new MenuItem menu (. SWT PUSH))
	  (. setText (. resources-win getString "Exit_menuitem"))
	  (. setAccelerator (+ SWT/MOD1 (int \Q)))
	  (. addSelectionListener
		 (proxy [SelectionAdapter] []
		   (widgetSelected [evt] (exit) println "Exiting"))))
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

(defn create-search-menu 
  "Add accelator CTRL + O, for FIND FILE"
  [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar (. sh getMenuBar)
            menu (new Menu bar)
            item (new MenuItem menu (. SWT PUSH))
            regex-item (new MenuItem menu (. SWT PUSH))]	
    (doto item
      (. setText (. resources-win getString "Find_menuitem"))
	  (. setAccelerator (+ SWT/MOD1 (int \F))))
    menu))

(defn add-buffer-menuitems [menu]
  (doto (new MenuItem menu (. SWT CASCADE))
	(. setText (res-win-str "Swap_buffer_to_second_menuitem"))
	(. setAccelerator SWT/F4)
	(. addSelectionListener swap-buffer-to-listener))
  (doto (new MenuItem menu (. SWT CASCADE))
	(. setText (res-win-str "Swap_buffer_from_second_menuitem"))
	(. setAccelerator SWT/F3)
	(. addSelectionListener swap-buffer-from-listener))
  (new MenuItem menu SWT/SEPARATOR))

(defn create-menu-bar [disp sh]
  (let [bar (new Menu sh (. SWT BAR))]
    (. sh setMenuBar bar)
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;; Build the Main Window Menu Bar
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    (doto (new MenuItem bar (. SWT CASCADE))
      (. setText (. resources-win getString "File_menuitem"))
      (. setMenu (create-file-menu disp sh)))
    (doto (new MenuItem bar (. SWT CASCADE))
      (. setText (. resources-win getString "Help_menu_title"))
      (. setMenu (create-help-menu disp sh)))
    (doto (new MenuItem bar (. SWT CASCADE))
      (. setText (. resources-win getString "Search_menu_title"))
      (. setMenu (create-search-menu disp sh)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      