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

(import '(java.io BufferedReader File FileInputStream
                  FileNotFoundException IOException InputStreamReader Reader))
(import '(java.util ResourceBundle Vector Hashtable))
(import '(org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem))
(import '(java.util HashMap))

(def styled-text)
(def dialog-open-file)
(def history-add-text)
(def exit)
(def add-recent-buffer-menu)
(def create-database-window)

(def recent-menu-state   (new HashMap))
(def recent-buffer-state (new HashMap))

(def  buffer-menu-state        (ref {:menu-state nil}))
(defn get-buffer-menu-state [] (@buffer-menu-state :menu-state))
(defn set-buffer-menu-state [menu] (dosync (commute buffer-menu-state assoc :menu-state menu)))

(defn shell-display-loop [disp sh dispose? msg]  
  (loop [] (if (. sh (isDisposed))
			 (if dispose? (. disp dispose) (println msg))
			 (let []
			   (when (not (. disp (readAndDispatch)))
				 (. disp (sleep)))
			   (recur)))))

(defn display-error [msg]
  (doto (new MessageBox shell SWT/ICON_ERROR)
	(. setMessage msg)
	(. open)))

(defn init-colors []  
  ;; Orange highlight color = 250, 209, 132
  ;; Light grey for default text.
  (let [disp (. Display getDefault)]
	(. colors-vec addElement (new Color disp orange-sel-color))
	(. colors-vec addElement (new Color disp lightgrey-color))))

(defn create-tab-1 []
  (. tab-area-1 setText    tab-1-title)
  (. tab-area-1 setControl styled-text))

(defn create-tab-2 []
  (. tab-area-2 setText    tab-2-title)
  (. tab-area-2 setControl tab-text-2))

(defn create-tab-3 []
  (. tab-area-3 setText    tab-3-title)
  (. tab-area-3 setControl tab-text-3))

(defn create-tab-4 []
  (. tab-area-4 setText    tab-4-title)
  (. tab-area-4 setControl tab-text-4))

(defn create-all-tabs []
  (create-tab-1)
  (create-tab-2)
  (create-tab-3)
  (create-tab-4))

(def status-arm-listener
     (proxy [Listener] []
            (handleEvent [event])))

(defn create-status-bar []
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (. status-bar setLayoutData gd)
    (. status-bar addListener SWT/Arm status-arm-listener)))

(defn status-set-text [text]
  (. status-bar setText text)
  (. status-bar update))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; File and Menu Utilities
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def recent-menu-listener
	 (proxy [SelectionAdapter] []
			(widgetSelected [evt]
							(let [widg (. evt widget)
									   w-data (. recent-menu-state get widg)]
							  (when w-data
								(let [path (w-data :path)]
								  (open-file path false)))))))

(def recent-buffer-listener
	 (proxy [SelectionAdapter] []
			(widgetSelected [evt]
							(let [widg (. evt widget)
									   w-data (. recent-buffer-state get widg)]
							  (when w-data
								(let [path (w-data :path)]
								  (open-file path false)))))))

(defn on-file-open [file]
  ;; Use the file instance for further operations
  (set-file-state true)
  (let [info-txt (get-file-info-header)]
	(when info-txt (history-add-text info-txt)))		  
  (file-monitor-loop file)
  (let [rec-tabl (add-recent-file file)]
	;; reuse the hashtable datastructure to add to the recent buffer
	;; list.
	(add-recent-buffer-menu rec-tabl file))
  (save-file-list))

(defn open-file-listener [file-str-data]
  (proxy [Runnable] []
		 (run []
			  (clear-buffer buffer-1)
			  (. buffer-1 append file-str-data)
			  (. styled-text setText (. buffer-1 toString))
			  ;; Attempt to set cursor to the end
			  ;; when refresh is enabled.
			  (when (prop-bool resources-win-opts "file_monitor_enabled")
				(. styled-text setSelection (. styled-text getCharCount))))))

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
		  (on-file-open file)
          ;; Check for file last modified
		  (. disp asyncExec (open-file-listener file-str-data)))))))

(defn dialog-open-file []
  (. fileDialog setFilterExtensions (into-array *openfile-wildcard-seq*))
  (open-file (. fileDialog open) false))

(defn create-recent-menu-items [menu]
  ;; The recent items are a deserialized hashtable
  (let [file-table (load-file-list)
				   file-seq (when file-table (seq (. file-table entrySet)))]
	(when file-seq
	  (doseq [i file-seq]
		  ((fn [entry]
			  (let [fname (. entry getKey)
						  fval (. entry getValue)
						  item-rec (new MenuItem menu (. SWT PUSH))
						  rec-tabl (get-recent-file-table)
						  rec-path (. rec-tabl get fname)]
				(. item-rec setText fname)
				(. item-rec addSelectionListener recent-menu-listener)
				(. recent-menu-state put item-rec {:widget item-rec :path rec-path})))
			  i)))))

(defn add-recent-buffer-menu [tabl-obj file]
  (try (let [menu (get-buffer-menu-state)
				  name (. file getName)
				  path (. tabl-obj get name)
			 rec-buf-item (new MenuItem menu (. SWT PUSH))]
		 (. rec-buf-item setText name)
		 (. rec-buf-item addSelectionListener recent-buffer-listener)
		 (. recent-buffer-state put rec-buf-item {:widget rec-buf-item :path path}))
	   (catch Exception e
			  (println "ERR: add-recent-buffer-menu" e))))
	
(defn create-file-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar    (. sh getMenuBar)
        menu   (new Menu bar)
        item   (new MenuItem menu (. SWT PUSH))]
    (doto item
	  ;; Open File
      (. setText (. resources-win getString "Open_menuitem"))
      (. addSelectionListener 
		 (proxy [SelectionAdapter] []
				(widgetSelected [evt]
								(dialog-open-file)
								println "Opening File"))))
	;; Create the recent file menu 
	(new MenuItem menu SWT/SEPARATOR)
	(create-recent-menu-items menu)	
	(new MenuItem menu SWT/SEPARATOR)
	;; Create exit menu item last.
	(let [item-exit (new MenuItem menu (. SWT PUSH))]
	  (doto item-exit
		(. setText (. resources-win getString "Exit_menuitem"))
		(. addSelectionListener 
		   (proxy [SelectionAdapter] []
				  (widgetSelected [evt]								  
								(exit) println "Exiting")))))
    menu))

(defn create-about-messagebox [sh]
  (let [msgbox (new MessageBox sh SWT/NONE)
			   about1 (. resources-win getString "About_1")
			   about2 (. resources-win getString "About_2")]
	(. msgbox setText about1)
	(. msgbox setMessage about2)
	(. msgbox open)
	msgbox))
	
(defn create-help-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar (. sh getMenuBar)
			menu (new Menu bar)
			item (new MenuItem menu (. SWT PUSH))]
	(doto item
	  (. setText (. resources-win getString "About_menuitem"))
	  (. addSelectionListener
		 (proxy [SelectionAdapter] []
				(widgetSelected [event]
								(create-about-messagebox sh)))))
	menu))

(defn create-tools-menu [disp sh]
  ;; Note change in 'doto' call, dot needed.
  (let [bar (. sh getMenuBar)
			menu (new Menu bar)
			item (new MenuItem menu (. SWT PUSH))]
	(doto item
	  (. setText (. resources-win getString "Database_viewer_menuitem"))
	  (. addSelectionListener
		 (proxy [SelectionAdapter] []
				(widgetSelected [event]
								(create-database-window shell)))))
	menu))

(defn create-menu-bar [disp sh]
  (let [bar  (new Menu sh (. SWT BAR))
        item (new MenuItem bar (. SWT CASCADE))
		search-item (new MenuItem bar (. SWT CASCADE))
		recent-buffers (new MenuItem bar (. SWT CASCADE))
		tools-item (new MenuItem bar (. SWT CASCADE))
		help-item (new MenuItem bar (. SWT CASCADE))]		
    (. sh setMenuBar bar)
    (doto item
      (. setText (. resources-win getString "File_menuitem"))
      (. setMenu (create-file-menu disp sh)))
	(doto help-item
	  (. setText (. resources-win getString "Help_menu_title"))
	  (. setMenu (create-help-menu disp sh)))
	(doto search-item
	  (. setText (. resources-win getString "Search_menu_title")))
	(doto tools-item
	  (. setText (. resources-win getString "Tools_menu_title"))
	  (. setMenu (create-tools-menu disp sh)))
	(let [buf-menu (new Menu bar)]
	  (doto recent-buffers
		(. setText (. resources-win getString "RecentBuffers_menu_title"))
		(. setMenu buf-menu))
	  (set-buffer-menu-state buf-menu))))
	  

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	  	  
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	  