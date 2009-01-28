;; [Copyright Berlin Brown, BSD License] One line SWT GUI lisp application (on the next line). Dev refactoring time = 5 minutes
(ns org.octane) (import '(org.eclipse.swt SWT)) (import '(org.eclipse.swt.widgets Display Shell Text Widget)) (import '(org.eclipse.swt.widgets Label Menu MenuItem Control Listener)) (import '(org.eclipse.swt.widgets FileDialog MessageBox Composite)) (import '(org.eclipse.swt.custom LineStyleEvent StyledText LineStyleListener StyleRange)) (import '(org.eclipse.swt.graphics Color RGB)) (import '(org.eclipse.swt.layout GridData GridLayout RowLayout)) (import '(org.eclipse.swt.events VerifyListener SelectionAdapter SelectionEvent ShellAdapter ShellEvent)) (import '(java.io BufferedReader File FileInputStream FileNotFoundException IOException InputStreamReader Reader)) (import '(java.text MessageFormat)) (import '(java.util ResourceBundle Vector)) (def length) (def search-box) (def search-keyword) (def clear-buffer) (def refresh-textarea) (def text-style 2818) (def colors-vec (new Vector)) (def buffer-1 (new StringBuffer 2048)) (defn init-colors []   (let [disp (. Display getDefault)] (. colors-vec addElement (new Color disp (new RGB 250 209 132))) (. colors-vec addElement (new Color disp (new RGB 100 100 100)))))	(defn add-select-style [styles-vec cur-style] (. styles-vec addElement cur-style))

(defn search-term? [] (if (> (length (. search-box getText)) 2) true false))

(defn style-handler [event]
  (let [styles-vec (new Vector)
line (. event lineText)
lo   (. event lineOffset)
len  (. (. event lineText) length)
l    (+ lo len)
bg   (. colors-vec get 0)
fgl  (. colors-vec get 1)
all-bold (new StyleRange lo len nil bg   SWT/BOLD)
light    (new StyleRange lo len fgl nil  SWT/NORMAL)] (when (search-term?) (if (search-keyword (. search-box getText) line) (add-select-style styles-vec all-bold) (add-select-style styles-vec light))) (let [arr (make-array StyleRange (. styles-vec size))] (set! (. event styles) arr) (. styles-vec copyInto (. event styles)))))

(defn search-keyword [keyword line] (not (nil? (re-seq (re-pattern keyword) line))))
	  
(def style-listener (proxy [LineStyleListener] [] (lineGetStyle [event] (style-handler event))))

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
(def search-box  (new Text shell SWT/BORDER))

(defn exit [] 
  (. System (exit 0)))

(def shell-close-listener
     (proxy [ShellAdapter] [] 
            (shellClosed [evt] (exit))))

(defn display-error [msg]
  (doto (new MessageBox shell SWT/ICON_ERROR)
	(. setMessage msg)
	(. open)))

(defn 
  #^{:doc "Use java oriented approach for loading a file into memory"}
  open-file-util [file file-path]
  (let [stream (new FileInputStream file-path)
			   instr (new BufferedReader (new InputStreamReader stream))
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


(defn clear-buffer [buf]
  (. buf setLength 0))

(defn length [s] (if (seq s) (+ 1 (length (rest s))) 0))

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
    menu)) (defn create-menu-bar [disp sh] (let [bar (new Menu sh (. SWT BAR)) item (new MenuItem bar (. SWT CASCADE))] (. sh setMenuBar bar) (doto item (. setText (. resources getString "File_menuitem")) (. setMenu (create-file-menu disp sh))))) (defn create-shell [disp sh] (let [layout (create-grid-layout)] (doto sh (. setText (. resources getString "Window_title")) (. setLayout layout) (. addShellListener (proxy [ShellAdapter] []  (shellClosed [evt] (exit))))))) (defn simple-swt [disp sh] (create-menu-bar disp sh) (create-shell disp sh) (init-colors) (let [gd (new GridData SWT/FILL SWT/FILL true false)] (. search-box addListener SWT/Traverse find-text-listener) (. search-box setLayoutData gd)) (. sh setSize 880 700) (. sh (open)) (loop [] (if (. shell (isDisposed)) (. disp (dispose)) (let [] (if (not (. disp (readAndDispatch))) (. disp (sleep))) (recur))))) (defn main [] (println "Running") (simple-swt display shell)) (main) (let [o (new Object)] (locking o (. o (wait))))

