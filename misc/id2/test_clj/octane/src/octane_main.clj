;;; Copyright (c) Berlin Brown:. All rights reserved.
;;;
;;; http://www.java2s.com/Code/Java/SWT-JFace-Eclipse/SWTMenuExample.htm
;;; -------------------------------------------------------
(import '(org.eclipse.swt.widgets Display Shell Text Widget))
(import '(org.eclipse.swt.widgets Label Menu MenuItem Control))
(import '(org.eclipse.swt.widgets FileDialog MessageBox Composite))

(import '(org.eclipse.swt.custom LineStyleEvent StyledText
                                 LineStyleListener StyleRange))

(import '(org.eclipse.swt.graphics Color RGB))
(import '(org.eclipse.swt.layout GridData GridLayout RowLayout))
(import '(org.eclipse.swt SWT))
(import '(org.eclipse.swt.events 
          SelectionAdapter SelectionEvent ShellAdapter ShellEvent))

(import '(java.io BufferedReader File FileInputStream
                  FileNotFoundException
                  IOException InputStreamReader Reader))
(import '(java.text MessageFormat))
(import '(java.util ResourceBundle Vector))

;;**************************************
;; Begin Routines
;;**************************************

;; Hard code the style to avoid calling bitwise operator
;; SWT.BORDER | SWT.MULTI | SWT.V_SCROLL | SWT.H_SCROLL
(def text-style 2818)
(def colors-vec (new Vector))

(defn init-colors []  
  ;; Orange highlight color = 250, 209, 132
  (let [disp (. Display getDefault)]
	(. colors-vec addElement (new Color disp (new RGB 250 209 132)))))

(defn search-keyword [keyword line]
  (not (nil? (re-seq #"[0-9]+" line))))

(defn add-select-style [styles-vec cur-style]
  ;; Set the event styles
  (. styles-vec addElement cur-style))

(defn style-handler [event]
  (let [styles-vec (new Vector)
				   line (. event lineText)
				   lo   (. event lineOffset)
				   len  (. (. event lineText) length)
				   l    (+ lo len)
				   bg   (. colors-vec get 0)
				   all-bold (new StyleRange lo len nil bg SWT/BOLD)]   
	;; Add the event styles if needed
	(when (search-keyword "IBM" line)
	  (add-select-style styles-vec all-bold))
	;; Associate the even style with the display
	(let [arr (make-array StyleRange (. styles-vec size))]
	  (set! (. event styles) arr)
	  (. styles-vec copyInto (. event styles)))))
	  

;; Event.detail line start offset (input) Event.text line text (input)
;; LineStyleEvent.styles Enumeration of StyleRanges, need to be in order.
;; (output) LineStyleEvent.background line background color (output)
(def style-listener
     (proxy 
	  [LineStyleListener] []
	  (lineGetStyle [event] (style-handler event))))

(defn create-styled-text-area [sh]
  (let [text (new StyledText sh text-style)
        spec (new GridData)
        disp (Display/getDefault)
        bg   (. disp (getSystemColor SWT/COLOR_WHITE))]
    (set! (. spec horizontalAlignment)       GridData/FILL)
    (set! (. spec grabExcessHorizontalSpace) true)
    (set! (. spec verticalAlignment)         GridData/FILL)
    (set! (. spec grabExcessVerticalSpace)   true)
    (doto text    
      (. setLayoutData spec)
      (. addLineStyleListener style-listener)
      (. setEditable false)
      (. setBackground bg))
	text))


(def display    (new Display))
(def shell      (new Shell display))
(def resources  (ResourceBundle/getBundle "octane_main"))
(def fileDialog (new FileDialog shell, SWT/CLOSE))

(def styled-text (create-styled-text-area shell))
(def search-box (new Text shell SWT/BORDER))

(defn exit [] 
  (. System (exit 0)))

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

(defn open-file-util [file file-path]
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
					(run [] (. styled-text setText file-str-data))))
		  )))))

(defn dialog-open-file []
  (. fileDialog setFilterExtensions (into-array ["*.*"]))
  (open-file (. fileDialog open)))

     
;;**************************************
;; Continue
;;**************************************

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
								(exit)
								println "Exiting"))))
	
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

(defn simple-swt [disp sh]
  (create-menu-bar disp sh)
  (create-shell disp sh)
  (init-colors)
  (. sh setSize 880 680)
  (. sh (open))
  (loop [] (if (. shell (isDisposed))
             (. disp (dispose))
             (let [] (if (not (. disp (readAndDispatch)))
                       (. disp (sleep)))
                  (recur)))))

;;**************************************
;; Main Entry Point
;;**************************************

(defn main []
  (println "Running")
  (simple-swt display shell))

(main)

;;**************************************
;; Lock the thread on this file, to wait until the frame is closed.
;;**************************************
(let [o (new Object)] (locking o (. o (wait))))

;;; End of Script