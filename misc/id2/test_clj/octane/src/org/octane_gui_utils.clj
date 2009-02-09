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

(in-ns 'org.octane)

(defmacro async-call [disp & body]
  `(. ~disp asyncExec (proxy [Runnable] []
							 (run [] ~@body))))

(defn add-text-buffer [text-field buffer str-data]
	 (clear-buffer buffer)
	 (. buffer append str-data)
	 (. text-field setText (. buffer toString)))

(defn add-main-text [str-data]
  (add-text-buffer styled-text buffer-1 str-data))

(defn add-main-text-nc [line]
  ;; Add the main text without clearing the core buffer
  ;; Note 'buffer-1' and styled-text used as 
  ;; GUI components
  (try (let [buffer buffer-1
					text-gui styled-text]
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
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;