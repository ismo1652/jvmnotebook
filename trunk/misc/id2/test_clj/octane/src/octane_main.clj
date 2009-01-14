;;; -------------------------------------------------------
;;; Copyright (c) Berlin Brown:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, Botnode.com, Berlin Brown
;;; http://www.opensource.org/licenses/bsd-license.php

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; are permitted provided that the following conditions are met:

;;;    * Redistributions of source code must retain the above copyright notice,
;;;    this list of conditions and the following disclaimer.
;;;    * Redistributions in binary form must reproduce the above copyright notice,
;;;    this list of conditions and the following disclaimer in the documentation
;;;    and/or other materials provided with the distribution.
;;;    * Neither the name of the Botnode.com (Berlin Brown) nor
;;;    the names of its contributors may be used to endorse or promote
;;;    products derived from this software without specific prior written permission.

;;; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;;; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;;; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;;; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
;;; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
;;; EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
;;; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
;;; PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
;;; LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
;;; NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;;; SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;;
;;;
;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  Berlin Brown <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;; -------------------------------------------------------

(ns org.octane
    (load "octane_main_constants")
    (load "public_objects")
    (load "octane_utils"))

(import '(org.eclipse.swt SWT))
(import '(org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem))
(import '(org.eclipse.swt.widgets Label Menu MenuItem Control Listener))
(import '(org.eclipse.swt.widgets FileDialog MessageBox Composite))

(import '(org.eclipse.swt.custom LineStyleEvent StyledText
                                 LineStyleListener StyleRange))

(import '(org.eclipse.swt.graphics Color RGB))
(import '(org.eclipse.swt.layout GridData GridLayout RowLayout))
(import '(org.eclipse.swt.events VerifyListener
          SelectionAdapter SelectionEvent ShellAdapter ShellEvent))

(import '(java.io BufferedReader File FileInputStream
                  FileNotFoundException IOException InputStreamReader Reader))
(import '(java.text MessageFormat))
(import '(java.util ResourceBundle Vector))

;;**************************************
;; Begin Routines
;;**************************************
(def length)
(def search-box)
(def search-keyword)
(def clear-buffer)
(def refresh-textarea)
(def create-styled-text-area)

(defn init-colors []  
  ;; Orange highlight color = 250, 209, 132
  ;; Light grey for default text.
  (let [disp (. Display getDefault)]
	(. colors-vec addElement (new Color disp orange-sel-color))
	(. colors-vec addElement (new Color disp lightgrey-color))))

(defn add-select-style [styles-vec cur-style]
  ;; Set the event styles
  (. styles-vec addElement cur-style))

(defn search-term? []
  (if (> (length (. search-box getText)) 2) true false))

(defn style-handler [event]
  (let [styles-vec (new Vector)
				   line (. event lineText)
				   lo   (. event lineOffset)
				   len  (. line length)
				   l    (+ lo len)
				   bg   (. colors-vec get 0)
				   fgl  (. colors-vec get 1)
				   all-bold (new StyleRange lo len nil bg   SWT/BOLD)
				   light    (new StyleRange lo len fgl nil  SWT/NORMAL)]
	;; Add the event styles if needed   
    (when (search-term?)
      (if (search-keyword (. search-box getText) line)
        (add-select-style styles-vec all-bold)
		(add-select-style styles-vec light)))
	;; Associate the even style with the display
	(let [arr (make-array StyleRange (. styles-vec size))]
	  (set! (. event styles) arr)
	  (. styles-vec copyInto (. event styles)))))

(defn search-keyword [keyword line]
  (not (nil? (re-seq (re-pattern keyword) line))))
	  
;; Event.detail line start offset (input) Event.text line text (input)
;; LineStyleEvent.styles Enumeration of StyleRanges, need to be in order.
;; (output) LineStyleEvent.background line background color (output)
(def style-listener
     (proxy [LineStyleListener] []
            (lineGetStyle [event] (style-handler event))))

(defn create-styled-text-area [sh]
  (let [text (new StyledText sh swt-text-style)
        spec (new GridData GridData/FILL GridData/FILL true true)
        disp (Display/getDefault)
        bg   (. disp (getSystemColor SWT/COLOR_WHITE))]
	(. tab-folder setLayoutData spec)
    (doto text    
      (. setLayoutData spec)
      (. addLineStyleListener style-listener)
      (. setEditable false)
      (. setBackground bg))
	text))

(def styled-text (create-styled-text-area tab-folder))

(def shell-close-listener
     (proxy [ShellAdapter] [] 
            (shellClosed [evt] (exit))))

;;**************************************
;; File Utilities
;;**************************************

(defn display-error [msg]
  (doto (new MessageBox shell SWT/ICON_ERROR)
	(. setMessage msg)
	(. open)))

(defn 
  #^{:doc "Use java oriented approach for loading a file into memory"}
  open-file-util [file file-path]
  ;; Java oriented approach for opening file
  (let [stream (new FileInputStream file-path)
			   instr (new BufferedReader (new InputStreamReader stream))
			   ;; Use type hints to ensure a character type.
			   readBuffer #^"[C" (make-array (. Character TYPE) 2048)
			   buf (new StringBuffer)]
	(loop [n (. instr read readBuffer)]
	  (when (> n 0)
		(. buf append readBuffer 0 n) 
		(recur (. instr read readBuffer))))
	(. instr close)
	(. buf toString)))

(defn open-file [name]
  (when name
	(println (str "Opening File: " name))
	(let [file (new File name)]
	  (if (not (. file exists))
		(display-error "File does not exist")
		(let [disp (. styled-text getDisplay)
				   file-str-data (open-file-util file (. file getPath))]
		  (. disp asyncExec
			 (proxy [Runnable] []
					(run []
						 (clear-buffer buffer-1)
						 (. buffer-1 append file-str-data)
						 (. styled-text setText (. buffer-1 toString))))))))))

(defn dialog-open-file []
  (. fileDialog setFilterExtensions (into-array ["*.*", "*.log"]))
  (open-file (. fileDialog open)))

(defn refresh-textarea []
  (let [disp (. styled-text getDisplay)]			 
	(. disp asyncExec
	   (proxy [Runnable] []
			  (run [] (. styled-text setText (. buffer-1 toString)))))))

;;**************************************
;; Continue
;;**************************************
(def find-text-listener
     (proxy [Listener] []
            (handleEvent [event]
                         (when (= (. event detail) SWT/TRAVERSE_RETURN)
                           (println (. search-box getText))
						   (refresh-textarea)))))
						   
(defn create-grid-layout []
  (let [gridLayout (new GridLayout)]
	(set! (. gridLayout numColumns) 1)
	gridLayout))

(defn create-file-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar    (. sh getMenuBar)
        menu   (new Menu bar)
        item   (new MenuItem menu (. SWT PUSH))
		item-exit (new MenuItem menu (. SWT PUSH))]
    (doto item
	  ;; Open File
      (. setText (. resources getString "Open_menuitem"))
      (. addSelectionListener 
		 (proxy [SelectionAdapter] [] 
				(widgetSelected [evt]
								(dialog-open-file)
								println "Opening File"))))
	(doto item-exit
	  (. setText (. resources getString "Exit_menuitem"))
	  (. addSelectionListener 
		 (proxy [SelectionAdapter] []
				(widgetSelected [evt]
								(exit) println "Exiting"))))	
	  ;; Exit 
    menu))

(defn create-menu-bar [disp sh]
  (let [bar (new Menu sh (. SWT BAR))
        item (new MenuItem bar (. SWT CASCADE))]
    (. sh setMenuBar bar)
    (doto item
      (. setText (. resources getString "File_menuitem"))
      (. setMenu (create-file-menu disp sh)))))
        
(defn create-shell [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [layout (create-grid-layout)]
    (doto sh
      (. setText (. resources getString "Window_title"))
      (. setLayout layout)
      (. addShellListener (proxy [ShellAdapter] [] 
                                 (shellClosed [evt]
                                              (exit)))))))

(defn 
  #^{:doc "Initialize the SWT window, set the size add all components"}
  create-gui-window [disp sh]
  
  ;; Set the tab folder and items with the main text area
  (. tab-area-1 setText    tab-1-title)
  (. tab-area-1 setControl styled-text)
  (create-menu-bar disp sh)
  (create-shell disp sh)
  (init-colors)
  ;; Modify already created objects
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (. search-box addListener SWT/Traverse find-text-listener)
    (. search-box setLayoutData gd))
  (. sh setSize win-size-width win-size-height)
  (. sh (open))
  (loop [] (if (. shell (isDisposed))
             (. disp (dispose))
             (let [] (if (not (. disp (readAndDispatch)))
                       (. disp (sleep)))
                  (recur)))))

;;**************************************
;; Main Entry Point
;**************************************
(defn main []
  (println "Running")
  (create-gui-window display shell))

(main)

;;**************************************
;; Lock the thread on this file, to wait until the frame is closed.
;;**************************************
(let [o (new Object)] (locking o (. o (wait))))

;;; End of Script