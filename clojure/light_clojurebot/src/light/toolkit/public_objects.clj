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
;;; Contact:  ... <... dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/light_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns light.toolkit.public_objects
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

(def tab-folder)

(def swt-textarea-style (bit-or SWT/BORDER (bit-or SWT/MULTI (bit-or SWT/H_SCROLL SWT/V_SCROLL))))

(def swt-tabtext-style (bit-or SWT/BORDER (bit-or SWT/MULTI (bit-or SWT/H_SCROLL SWT/V_SCROLL))))
                                                          
(def colors-vec  (new Vector))
(def buffer-1    (new StringBuffer 4096))
(def buffer-2    (new StringBuffer 4096))
(def buffer-3    (new StringBuffer 4096))

(defn col-vec-bg   []  (. colors-vec get 0))
(defn col-vec-grey []  (. colors-vec get 1))
(defn col-vec-red  []  (. colors-vec get 2))
(defn col-vec-cy   []  (. colors-vec get 3))
(defn col-vec-drkb []  (. colors-vec get 4))
(defn col-vec-wht  []  (. colors-vec get 5))
(defn col-vec-yllw []  (. colors-vec get 6))
(defn col-vec-blk  []  (. colors-vec get 7))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main Display, there is only one constant instance
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def *display*   (new Display))
(def *shell*     (new Shell *display*))

(defn styled-text-font [] (new Font (. *shell* getDisplay) "Courier New" 9 SWT/NORMAL))

(def fileDialog  (new FileDialog *shell* SWT/CLOSE))
(def directory-dialog  (new DirectoryDialog *shell* SWT/CLOSE))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Creation of main GUI components (order of instantiation is important here)
;; Including main tabs, location bar and search box.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def location-bar (new Text *shell* SWT/BORDER))
(def tab-folder   (new TabFolder *shell* SWT/NULL))
(def tab-area-1   (new TabItem tab-folder SWT/NULL))
(def tab-area-2   (new TabItem tab-folder SWT/NULL))
(def tab-area-3   (new TabItem tab-folder SWT/NULL))
(def search-box   (new Text *shell* SWT/BORDER))

;; Tab-text-2 is associated with the secondary text area
(def tab-text-2   (new Text tab-folder swt-tabtext-style))
(def tab-text-3   (new Text tab-folder swt-tabtext-style))
(def tab-text-4   (new Text tab-folder swt-tabtext-style))

(def status-bar   (new Label *shell* SWT/BORDER))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Create the styled text area
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn create-styled-text-area
  " The styled text area is the main(first tab) text area on the window.  Most
 text will get displayed in this text area.  The text area is also attached to a tab. 
 @see light_main_window.clj"
  [sh]
  ;;;;;;;;;;;;;;;;;;;;
  (let [text (new StyledText sh swt-textarea-style)
			 gd-tab (new GridData GridData/FILL GridData/FILL true true)
			 disp (Display/getDefault)
			 bg   (. disp (getSystemColor SWT/COLOR_WHITE))]
    (. tab-folder setLayoutData gd-tab)
    (doto text
      (. setLayoutData gd-tab)
      (. setFont (styled-text-font))
      (. setEditable false)
      (. setBackground bg))
    text))

(def *styled-text* (create-styled-text-area tab-folder))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;