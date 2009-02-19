;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;;
;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... Brown <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns octane.toolkit.octane_gui_utils
	(:use    octane.toolkit.octane_utils
			 octane.toolkit.public_objects
			 octane.toolkit.octane_main_constants
			 octane.toolkit.octane_config)
	(:import (java.util Date)
			 (java.io InputStreamReader BufferedReader File)
			 (org.eclipse.swt SWT)
			 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
			 (org.eclipse.swt.graphics Color RGB FontData Font)
			 (org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
									 SelectionEvent ShellAdapter ShellEvent)
			 (org.eclipse.swt.widgets MessageBox Label Menu MenuItem Control Listener)))

(def status-set-text)

(defn display-error [msg]
  (doto (new MessageBox *shell* SWT/ICON_ERROR)
    (. setMessage msg)
    (. open)))

(defmacro async-call 
  "Asynchronous execute call.  Create a proxy Runnable object and then execute the 
 body code"
  [disp & body]
  ;;;;;;;;;;;;;;
  `(. ~disp asyncExec (proxy [Runnable] [] (run [] ~@body))))

(defmacro get-sync-call 
  "Synchronous execute call.  Create a proxy Runnable object and then execute the 
 body code"
  [disp & body]
  ;;;;;;;;;;;;;;
  `(let [val-res# (ref nil)]
     (. ~disp syncExec (proxy [Runnable] [] (run [] (dosync (ref-set val-res# ~@body)))))
     (. Thread sleep 50)
     (deref val-res#)))

(defn add-text-buffer [text-field buffer str-data]
     (clear-buffer buffer)
     (. buffer append str-data)
     (. text-field setText (. buffer toString)))

(defn add-main-text [str-data]
  (add-text-buffer *styled-text* buffer-1 str-data))

(defn async-add-text [disp text-field buffer str-data]
  ;; For example, text-field = styled-text
  (async-call disp (add-text-buffer text-field buffer str-data)))

(defn add-main-text-nc [line]
  ;; Add the main text without clearing the core buffer
  ;; Note 'buffer-1' and styled-text used as 
  ;; GUI components. (NC = no clear)
  (try (let [buffer buffer-1
                    text-gui *styled-text*]
         (. buffer append (str line *newline*))
         (. text-gui setText (. buffer toString)))
       ;; Attempt to redraw and update
       ;;(. text-gui redraw)
       ;;(. text-gui update)
       ;; Set the caret position to the end
       ;;(. text-gui setSelection (. text-gui getCharCount)))
       (catch Exception e (println e))))

(defn create-menu-item [menu res-menuitem proxy-body]
  (let [menu-item (new MenuItem menu (. SWT PUSH))]
    (doto menu-item
      (. setText (. resources-win getString res-menuitem))
      (. addSelectionListener proxy-body))
    menu-item))

(defn async-status-text [disp msg]
  (async-call disp (status-set-text msg)))

(defn async-status-history [disp msg]
  ;; Set the status bar and history
  (async-call disp (status-set-text msg))
  (async-call disp (history-add-text (str msg *newline*))))

(defn start-process [proc-args-lst buffer]
  ;; Example usage: (start-process [ "explorer.exe" ] buffer-1)
  (try
   (let [process-line (into-array proc-args-lst)
         process-bld  (when process-line (when-try (new ProcessBuilder process-line)))
         process      (when process-bld  (when-try (. process-bld start)))]
     (when process
       (async-status-history *display* (str "Invoking process => " proc-args-lst *newline*))
       ;; Wrap the request within a thread.
       (let [proc-thread
             (proxy [Runnable][]
                    (run []
                         (let [istream   (. process getInputStream)
                               ireader   (new InputStreamReader istream)
                               bufreader (new BufferedReader ireader)]
                           ;; First clear the main text buffer
                           (clear-buffer buffer)
                           (let [proc-time-info (proc-time (loop [line (. bufreader readLine)]
                                                             (when line
                                                               (async-call *display* (add-main-text-nc line))
                                                               (recur (. bufreader readLine)))))
                                 msg (str "<<Completed process>> " (proc-time-info :time-text))]
                             (async-call *display* (add-main-text-nc msg))
                             (async-call *display* (status-set-text msg))))))]
         ;; Launch the process thread
         (. (new Thread proc-thread) start))))
   (catch Exception e (. e printStackTrace))))

(defn status-set-text [text]
  (. status-bar setText text)
  (. status-bar update))

(defn location-set-text [text]
  (. location-bar setText text)
  (. location-bar update))


(defn shell-display-loop [disp sh dispose? msg]  
  (loop [] (if (. sh (isDisposed))
             (if dispose? (. disp dispose) (println msg))
             (let []
               (when (not (. disp (readAndDispatch)))
                 (. disp (sleep)))
               (recur)))))


(defn create-about-messagebox [sh]
  (let [msgbox (new MessageBox sh SWT/NONE)
               about1 (. resources-win getString "About_1")
               about2 (. resources-win getString "About_2")]
    (. msgbox setText about1)
    (. msgbox setMessage about2)
    (. msgbox open)
    msgbox))

(defn init-colors []  
  ;; Orange highlight color = 250, 209, 132
  ;; Light grey for default text.
  (let [disp (. Display getDefault)]
    (doto colors-vec
    (. addElement (new Color disp orange-sel-color))
    (. addElement (new Color disp lightgrey-color))
    (. addElement (new Color disp red-color))
    (. addElement (new Color disp cyan-sel-color))
    (. addElement (new Color disp dark-blue-color))
    (. addElement (new Color disp white-color))
	(. addElement (new Color disp yellow-color))
	(. addElement (new Color disp black-color)))))

(defn refresh-textarea []
  (. *styled-text* redraw)
  (. *styled-text* update))

(defn shell-close-adapter 
  " Create a proxy object used with a SWT widget 'addShellListener'"
  [cur-shell]
  ;;;;;;;;;;;;;
  (proxy [ShellAdapter][]
		 (shellClosed [event]
					  (set! (. event doit) false)
					  (. cur-shell setVisible false))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;