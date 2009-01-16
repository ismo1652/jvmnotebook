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
;;; Also see: 
;;; http://help.eclipse.org/stable/nftopic/org.eclipse.platform.doc.isv/reference/api/index.html
;;; -------------------------------------------------------

(ns org.octane
    (load "octane_config")
    (load "swt_imports")
    (load "octane_main_constants")
    (load "public_objects")
    (load "octane_file_utils")
    (load "octane_utils")
	(load "octane_core_widgets"))

(import '(java.io BufferedReader File FileInputStream
                  FileNotFoundException IOException InputStreamReader Reader))
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
(def history-add-text)

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
				   all-bold (new StyleRange lo l nil bg   SWT/BOLD)
				   light    (new StyleRange lo l fgl nil  SWT/NORMAL)]
    (println (str lo " | " l))
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

(defn open-file [name quiet]
  (when name
    (when (not quiet)
      (history-add-text (str "Loading file => " name "\n"))
      (status-set-text  (str "Loading file => " name)))
	(let [file (new File name)]
	  (if (not (. file exists))
		(display-error "File does not exist")
		(let [disp (. styled-text getDisplay)
				   file-str-data (open-file-util file (. file getPath))]
          ;; Set the file state opened, and start monitor loop
          (set-file-state true)
          (let [info-txt (get-file-info-header)]
            (when info-txt (history-add-text info-txt)))
          (file-monitor-loop file)
          ;; Check for file last modified
		  (. disp asyncExec
			 (proxy [Runnable] []
					(run []
						 (clear-buffer buffer-1)
						 (. buffer-1 append file-str-data)
						 (. styled-text setText (. buffer-1 toString))))))))))

(defn dialog-open-file []
  (. fileDialog setFilterExtensions (into-array *openfile-wildcard-seq*))
  (open-file (. fileDialog open) false))

(defn refresh-textarea []
  (let [disp (. styled-text getDisplay)]			 
	(. disp asyncExec
	   (proxy [Runnable] []
			  (run [] (. styled-text setText (. buffer-1 toString)))))))

(defn history-add-text [text]
  (println text)
  (. buffer-3 append text)
  (let [disp (. tab-text-3 getDisplay)]
	(. disp asyncExec
	   (proxy [Runnable] []
			  (run [] (. tab-text-3 setText (. buffer-3 toString)))))))

;;**************************************
;; Continue
;;**************************************

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

(defn create-file-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar    (. sh getMenuBar)
        menu   (new Menu bar)
        item   (new MenuItem menu (. SWT PUSH))
		item-exit (new MenuItem menu (. SWT PUSH))]
    (doto item
	  ;; Open File
      (. setText (. resources-win getString "Open_menuitem"))
      (. addSelectionListener 
		 (proxy [SelectionAdapter] [] 
				(widgetSelected [evt]
								(dialog-open-file)
								println "Opening File"))))
	(doto item-exit
	  (. setText (. resources-win getString "Exit_menuitem"))
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
      (. setText (. resources-win getString "File_menuitem"))
      (. setMenu (create-file-menu disp sh)))))
        
(defn create-shell [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [layout (create-grid-layout)]
    (doto sh
      (. setText (. resources-win getString "Window_title"))
      (. setLayout layout)
      (. addShellListener (proxy [ShellAdapter] [] 
                                 (shellClosed [evt]
                                              (exit)))))))

(defn init-gui-helper [disp sh]
    (create-all-tabs)
    (create-menu-bar disp sh)
    (create-shell    disp sh)
    (init-colors)
    (history-add-text (get-hist-header))
    (status-set-text  (str "Octane GUI loaded " (date-time))))

(defn
  #^{:doc "Initialize the SWT window, set the size add all components"}
  create-gui-window [disp sh]
  
  ;; Set the tab folder and items with the main text area
  ;; and other SWT oriented inits.
  (init-gui-helper disp sh)
  ;; Modify already created objects
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (. search-box addListener SWT/Traverse find-text-listener)
    (. search-box setLayoutData gd))
  (create-status-bar)
  (. sh setSize win-size-width win-size-height)
  (. sh (open))
  (loop [] (if (. sh (isDisposed))
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