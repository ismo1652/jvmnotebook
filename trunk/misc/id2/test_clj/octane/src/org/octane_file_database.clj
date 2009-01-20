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

(def  load-default-database)

(def  database-shell (new Shell shell *database-win-style*))
(def  db-filter-box  (new Text database-shell SWT/BORDER))
(def  db-file-table  (new Table database-shell (bit-or SWT/SINGLE (bit-or SWT/BORDER SWT/FULL_SELECTION))))
(def  db-search-box  (new Text database-shell SWT/BORDER))

;; Five table columns, loaded from database configuration file.
(def  table-col-names ["Name" "Path" "Group" "Server" "Description"])

(defn create-db-grid-layout []
  (let [gridLayout (new GridLayout)]
	(set! (. gridLayout numColumns) 1)
	gridLayout))

(defn add-table-item [item-seq]
  (let [item (new TableItem db-file-table SWT/NONE)]
	(. item setText (into-array item-seq))))

(defn table-select-listener []
  (proxy [SelectionAdapter][]
		 (widgetDefaultSelected [event]
								(let [items (. db-file-table getSelection)]								  
								  (when (> (count items) 0)
									;; We can extract the open path
									;; straight from the table item data.
									(let [item (first items)
											   db-path (. item getText 1)]									  
									  (open-file db-path true)))))))

(defn
  #^{:doc "Create the database viewer table"}
  create-database-table [db-sh]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  (. db-file-table setHeaderVisible true)  
  (. db-file-table addSelectionListener (table-select-listener))
  ;; Add the table column headers
  (let [gd (new GridData SWT/FILL SWT/FILL true true)]
	(doseq [t table-col-names]
		(let [column (new TableColumn db-file-table SWT/NONE)]
		  (. column setText t)
		  (. column setWidth 110)))
	(. db-file-table setLayoutData gd)))

(defn init-database-helper [sh]
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
	(. db-filter-box setLayoutData gd)
	(. db-search-box setLayoutData gd))
  (. db-search-box setText "ppooo0000000000000000000")
  (create-database-table sh))
        
(defn
    #^{:doc "Initialize the file database SWT window, set the size add all components"}
	create-database-window [parent-sh]
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	(history-add-text "Opening file database screen (Tools -> Database Viewer)")
	(let [layout (create-db-grid-layout)]
	  (. database-shell setText (. resources-win getString "Database_title"))
	  (init-database-helper database-shell)
	  (. database-shell setLayout layout)
	  (. database-shell setSize *db-size-width* *db-size-height*)
	  (. database-shell addShellListener
		 (proxy [ShellAdapter][]
				(shellClosed [event]
							 (set! (. event doit) false)
							 (. database-shell setVisible false))))
	  (. database-shell open)
	  (. database-shell setVisible true)
	  ;; Load the XML database
	  (load-default-database)
	  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	  ;; Enter display/shell loop for this window
      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	  (let [disp (. database-shell getDisplay)]
		(shell-display-loop disp database-shell false "Database shell disposed"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; XML Database processing
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn add-items-db-view [file-content]
  (let [tmp-db-obj (new Hashtable)]
	(doseq [xml-file file-content]
		(let [x-tag (xml-file :tag)
					x-content (xml-file :content)]	   
		  (cond
		   (= ":file_name"   (str x-tag))
		   (. tmp-db-obj put ":file_name" (.. (str (first x-content)) trim))
		   (= ":file_path"   (str x-tag))
		   (. tmp-db-obj put ":file_path" (.. (str (first x-content)) trim))
		   (= ":file_group"  (str x-tag))
		   (. tmp-db-obj put ":file_group" (.. (str (first x-content)) trim))
		   (= ":file_server" (str x-tag))
		   (. tmp-db-obj put ":file_server" (.. (str (first x-content)) trim))
		   (= ":file_descr"  (str x-tag))
		   (. tmp-db-obj put ":file_descr" (.. (str (first x-content)) trim)))))
	;; Build a sequence to populate the database viewer		
	(let [tab-seq [(. tmp-db-obj get ":file_name")
				   (. tmp-db-obj get ":file_path")
				   (. tmp-db-obj get ":file_group")
				   (. tmp-db-obj get ":file_server")
				   (. tmp-db-obj get ":file_descr")]]
	  (add-table-item tab-seq))))
		  
(defn loop-db-files [xml-content]
  (doseq [xml-file xml-content]
	  (let [x-tag (xml-file :tag)
				  x-content (xml-file :content)]
		(when (= ":db_file" (str x-tag))
		  (add-items-db-view x-content)))))

(defn load-default-database []
  (let [db-filename (prop-str resources-user "database")
					xml-data (clojure.xml/parse db-filename)]
	(when xml-data
	  (let [root (xml-data :content)]
		;; Root contains a list of tags
		(doseq [root-set root]
			(let [root-tag (root-set :tag)
						   root-content (root-set :content)]
			  (when (= ":file_set" (str root-tag))
				(loop-db-files root-content))))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	  