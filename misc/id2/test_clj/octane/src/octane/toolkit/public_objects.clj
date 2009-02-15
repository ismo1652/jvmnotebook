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
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns octane.toolkit.public_objects
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

(def swt-textarea-style (bit-or SWT/BORDER 
								(bit-or SWT/MULTI 
                                    (bit-or SWT/H_SCROLL
                                            (bit-or SWT/V_SCROLL 1)))))

(def swt-tabtext-style (bit-or SWT/BORDER 
                               (bit-or SWT/MULTI 
                                       (bit-or SWT/H_SCROLL
                                               (bit-or SWT/V_SCROLL 1)))))

(def colors-vec  (new Vector))
(def buffer-1    (new StringBuffer 4096))
(def buffer-2    (new StringBuffer 4096))
(def buffer-3    (new StringBuffer 4096))

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
(def tab-area-4   (new TabItem tab-folder SWT/NULL))
(def search-box   (new Text *shell* SWT/BORDER))

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
 @see octane_main_window.clj"
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

;;;;;;;;;;;;;;;;;
;; Keep the state on when a directory/open has been set
;;;;;;;;;;;;;;;;;
(def  *directory-open-state*    (ref nil))
(defn get-directory-open []     (deref *directory-open-state*))
(defn set-directory-open [path] (dosync (ref-set *directory-open-state* path)))

(def  *curfile-open-state*    (ref nil))
(defn get-curfile-open []     (deref *curfile-open-state*))
(defn set-curfile-open [path] (dosync (ref-set *curfile-open-state* path)))

(defn get-current-dir [] 
  (if (get-directory-open) (get-directory-open) "."))

(defn get-current-dirquote [] 
  (if (get-directory-open) (str "'" (get-directory-open) "'") "."))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Find Grep Widgets
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Use ref for public findgrep widgets, and dynamic keyword
;; Note, the widgets must be loaded at runtime.

(def  *findgrep-def-state*  (ref {:FindGrep_grep_menuitem   nil}))
(def  *findgrep-15m-state*  (ref {:FindGrep_15min_menuitem  nil}))
(def  *findgrep-2hr-state*  (ref {:FindGrep_2hrs_menuitem   nil}))
(def  *findgrep-jav-state*  (ref {:FindGrep_java_menuitem   nil}))
(def  *findgrep-log-state*  (ref {:FindGrep_logs_menuitem   nil}))
(def  *findgrep-60m-state*  (ref {:Findfiles_60min_menuitem nil}))
(def  *findgrep-clj-state*  (ref {:FindGrep_clj_menuitem    nil}))

(defn findgrep-widg-state [fkey]
  (cond (= fkey :FindGrep_grep_menuitem)   *findgrep-def-state*
        (= fkey :FindGrep_15min_menuitem)  *findgrep-15m-state*
        (= fkey :FindGrep_2hrs_menuitem)   *findgrep-2hr-state*
        (= fkey :FindGrep_java_menuitem)   *findgrep-jav-state* 
        (= fkey :FindGrep_logs_menuitem)   *findgrep-log-state*
        (= fkey :Findfiles_60min_menuitem) *findgrep-60m-state*
        (= fkey :FindGrep_clj_menuitem)    *findgrep-clj-state*))

(defn get-findgrep-widg-state [fkey]      (deref  (findgrep-widg-state fkey)))
(defn set-findgrep-widg-state [fkey widg] (dosync (commute (findgrep-widg-state fkey) assoc fkey widg)))

(defn get-findgrep-helper [key] 
  ((get-findgrep-widg-state key) key))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;