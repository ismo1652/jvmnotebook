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

(def *search-style* (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE 1))))

(def search-shell       (new Shell shell *search-style*))
(def search-label       (new Label search-shell SWT/LEFT))
(def search-filter-box  (new Text search-shell SWT/BORDER))
(def search-composite   (new Composite search-shell SWT/NONE))
(def search-find-button (new Button search-composite SWT/PUSH))

(defn create-search-grid-layout []
  (let [gridLayout (new GridLayout)]
	(set! (. gridLayout numColumns) 2) gridLayout))

(defn init-search-helper [sh]
  (let [gd-textbox (new GridData GridData/FILL_HORIZONTAL)
				   gd-composite (new GridData GridData/HORIZONTAL_ALIGN_FILL)
				   layout (new GridLayout)
				   gd-find (new GridData GridData/HORIZONTAL_ALIGN_END)]	
	(. search-label setText (prop-str resources-win "Search_for_label"))
	(set! (. gd-textbox widthHint) 200)
	(. search-filter-box setLayoutData gd-textbox)
	(set! (. gd-composite horizontalSpan) 2)
	(. search-composite setLayoutData gd-composite)
	(set! (. layout numColumns) 2)
	(set! (. layout makeColumnsEqualWidth) true)
	(. search-composite setLayout layout)
	(. search-find-button setText "Find")
	(. search-find-button setLayoutData gd-find)
	(. search-find-button setEnabled true)))

(defn
    #^{:doc "Initialize the file database SWT window, set the size add all components"}
	create-search-dialog [parent-sh]
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	(history-add-text "Opening search screen (Search -> Find)")
	(let [layout (create-search-grid-layout)]
	  (. search-shell setText (. resources-win getString "Find_dialog_title"))
	  (init-search-helper search-shell)
	  (. search-shell setLayout layout)
	  (. search-shell addShellListener
		 (proxy [ShellAdapter][]
				(shellClosed [event]
							 (set! (. event doit) false)
							 (. search-shell setVisible false))))
	  (. search-shell pack)
	  (. search-shell open)
	  (. search-shell setVisible true)
	  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	  ;; Enter display/shell loop for this window
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	  (let [disp (. search-shell getDisplay)]
		(shell-display-loop disp search-shell false "Search shell disposed"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Additional Search Utilities
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def findgrep-listener
	 (proxy [SelectionAdapter] []
			(widgetSelected [event]
							;; With the async call, set the agent value
							;; based on the search box value							
							(. display syncExec 
							   (proxy [Runnable] []
									  (run [] 
										   (let [val (. search-box getText)]
											 (send *search-text-state* (fn [_] val))))))
							(let [widg-str (str (. event widget))]
							  (. (new Thread
									  (start-findgrep-thread widg-str @*search-text-state* true)) start)))))
												   
(defn add-findgrep-options [menu]
  ;; Run non lazy sequence operation
  (doseq [menu-key [{:name "FindGrep_grep_menuitem"   :proc findgrep-listener }
                    {:name "FindGrep_15min_menuitem"  :proc findgrep-listener }
                    {:name "FindGrep_2hrs_menuitem"   :proc findgrep-listener }
                    {:name "FindGrep_java_menuitem"   :proc findgrep-listener }  
                    {:name "FindGrep_logs_menuitem"   :proc findgrep-listener }
                    {:name "Findfiles_60min_menuitem" :proc findgrep-listener }
					{:name "FindGrep_clj_menuitem"    :proc findgrep-listener } ]]
      (let [mitem (create-menu-item menu (menu-key :name) (menu-key :proc))]
		;; Menu item created, now associate the widget with the global 'ref'
		(set-findgrep-widg-state (keyword (menu-key :name)) (str mitem))
		(println (get-findgrep-widg-state (keyword (menu-key :name)))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	  