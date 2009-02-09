;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ... Brown:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, Botnode.com, ... Brown
;;; http://www.opensource.org/licenses/bsd-license.php

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; are permitted provided that the following conditions are met:

;;;    * Redistributions of source code must retain the above copyright notice,
;;;    this list of conditions and the following disclaimer.
;;;    * Redistributions in binary form must reproduce the above copyright notice,
;;;    this list of conditions and the following disclaimer in the documentation
;;;    and/or other materials provided with the distribution.
;;;    * Neither the name of the Botnode.com (... Brown) nor
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