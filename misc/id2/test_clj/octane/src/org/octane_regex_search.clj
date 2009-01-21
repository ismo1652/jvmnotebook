;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-ns 'org.octane)

(def *regex-style* (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE 1))))

(def regex-shell       (new Shell shell *regex-style*))
(def regex-label       (new Label regex-shell SWT/LEFT))
(def regex-filter-box  (new Text  regex-shell SWT/BORDER))

(defn create-regex-grid-layout []
  (let [gridLayout (new GridLayout)]
	(set! (. gridLayout numColumns) 1) gridLayout))

(defn init-regex-helper [sh])

(defn
    #^{:doc "Initialize the file database SWT window, set the size add all components"}
	create-regex-window []
    ;;;;;;;;;;;;;;;;;;;;;;

	(history-add-text "Opening regex tool (Search -> Regex Search Tool)")
	(let [layout (create-regex-grid-layout)]
	  (. regex-shell setText (. resources-win getString "Find_dialog_title"))
	  (init-regex-helper regex-shell)
	  (. regex-shell setLayout layout)
	  (. regex-shell addShellListener
		 (proxy [ShellAdapter][]
				(shellClosed [event]
							 (set! (. event doit) false)
							 (. regex-shell setVisible false))))
	  (. regex-shell setSize *regex-size-width* *regex-size-height*)
	  (. regex-shell open)
	  (. regex-shell setVisible true)
	  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	  ;; Enter display/shell loop for this window
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	  (let [disp (. regex-shell getDisplay)]
		(shell-display-loop disp regex-shell false "Regex tool shell disposed"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	  