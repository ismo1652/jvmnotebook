;;; Copyright (c) Berlin Brown:. All rights reserved.
;;;
;;; http://www.java2s.com/Code/Java/SWT-JFace-Eclipse/SWTMenuExample.htm
;;; -------------------------------------------------------
(import '(org.eclipse.swt.widgets Display Shell Text Widget))
(import '(org.eclipse.swt.widgets Label Menu MenuItem Control))
(import '(org.eclipse.swt.widgets FileDialog MessageBox))

(import '(org.eclipse.swt.custom LineStyleEvent StyledText
                                 LineStyleListener StyleRange))

(import '(org.eclipse.swt.layout GridData GridLayout))
(import '(org.eclipse.swt SWT))
(import '(org.eclipse.swt.events 
          SelectionAdapter SelectionEvent ShellAdapter ShellEvent))

(import '(java.io BufferedReader File FileInputStream
                  FileNotFoundException
                  IOException InputStreamReader Reader))
(import '(java.text MessageFormat))
(import '(java.util ResourceBundle))

;;**************************************
;; Begin Routines
;;**************************************

(def display    (new Display))
(def shell      (new Shell display))
(def resources  (ResourceBundle/getBundle "octane_main"))

;; Hard code the style to avoid calling bitwise operator
;; SWT.BORDER | SWT.MULTI | SWT.V_SCROLL | SWT.H_SCROLL
(def text-style 2818)

(defn exit [] (. System (exit 0)))

(def shell-close-listener
     (proxy [ShellAdapter] [] 
            (shellClosed [evt]
                         (exit))))

;;**************************************
;; Line Style Class Definition
;;**************************************

;; Event.detail line start offset (input) Event.text line text (input)
;; LineStyleEvent.styles Enumeration of StyleRanges, need to be in order.
;; (output) LineStyleEvent.background line background color (output)
(def line-style
     (proxy [LineStyleListener] []
            (lineGetStyle [event] (print "test"))))
     
;;**************************************
;; Continue
;;**************************************

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
      (. addLineStyleListener line-style)
      (. setEditable false)
      (. setBackground bg))))

(defn create-file-menu [disp sh]
  (prn "huh")
  ;; Note change in 'doto' call, dot needed.
  (let [bar    (. sh getMenuBar)
        menu   (new Menu bar)
        item   (new MenuItem menu (. SWT PUSH))]
    (prn menu)
    (doto item
      (. setText (. resources getString "Open_menuitem"))
      (. addSelectionListener (proxy [SelectionAdapter] [] 
                                     (widgetSelected [evt]
                                                     prn "yoa"))))
    (prn menu)
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
  (let [layout (new GridLayout)]
    (set! (. layout numColumns) 1)
    (doto sh
      (. setText (. resources getString "Window_title"))
      (. setLayout layout)
      (. addShellListener (proxy [ShellAdapter] [] 
                                 (shellClosed [evt]
                                              (exit)))))))
  
(defn simple-swt [disp sh]
  (create-menu-bar disp sh)
  (create-shell disp sh)
  (create-styled-text-area sh)
  (doto sh    
    (. setSize 640 480)
    (. (open)))
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
(let [o (new Object)] 
  (locking o (. o (wait))))

;;; End of Script