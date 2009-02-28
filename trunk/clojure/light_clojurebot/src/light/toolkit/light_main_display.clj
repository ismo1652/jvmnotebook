;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns light.toolkit.light_main_window
	(:use    light.toolkit.light_utils
			 light.toolkit.light_config
			 light.toolkit.light_core_widgets
			 light.toolkit.light_gui_utils
			 light.toolkit.light_main_constants
			 light.toolkit.light_utils
			 light.toolkit.public_objects)
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn create-shell)

(defn init-gui-helper [disp sh]
  (create-all-tabs)
  (create-menu-bar disp sh)
  (create-shell    disp sh)
  (init-color-vec-colors)
  (history-add-text (get-hist-header))
  (status-set-text  (str "Light GUI loaded " (date-time) " " (*memory-usage*))))

(defn create-shell [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [layout (create-grid-layout 1)]
    (doto sh
      (. setText (. resources-win getString "Window_title"))
      (. setLayout layout)
      (. addShellListener (proxy [ShellAdapter] []
							(shellClosed [evt] (exit)))))))

(defn create-gui-window 
  "Initialize the SWT window, set the size add all components"
  [disp sh]
  ;;;;;;;;;;;;
  
  ;; Set the tab folder and items with the main text area
  ;; and other SWT oriented inits.
  (init-gui-helper disp sh)
  ;; Modify already created objects
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (. search-box setLayoutData gd)
    (. location-bar setLayoutData gd))
  (create-status-bar)
  ;; Final init, set the window size and then open
  (doto sh
    (. setSize win-size-width win-size-height)
    (. open))
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
  (println "Launching Light Text Viewer...")
  (create-gui-window *display* *shell*)
  (let [o (new Object)] (locking o (. o (wait)))))

(defn script-main [& args]
  (try (main-1)
	   (catch Exception e
		 (println "ERR at <Main>: " e)
		 (println (get-hist-header))
		 (exit))))

;;(script-main)
(main-1)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
