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

(ns octane.toolkit.octane_file_database
	(:use    octane.toolkit.octane_utils
			 octane.toolkit.public_objects
			 octane.toolkit.octane_config
			 octane.toolkit.octane_main_constants
			 octane.toolkit.octane_file_utils
			 octane.toolkit.octane_gui_utils
			 octane.toolkit.octane_tools)
	(:import (java.util Date)
			 (org.eclipse.swt SWT)
			 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
			 (org.eclipse.swt.widgets Label Menu MenuItem Control Listener)
			 (org.eclipse.swt.widgets FileDialog MessageBox TableItem Button
									  Composite Table TableColumn)
			 (org.eclipse.swt.custom LineStyleEvent StyledText
									 LineStyleListener StyleRange)
			 (org.eclipse.swt.graphics Color RGB FontData Font)
			 (org.eclipse.swt.layout GridData GridLayout RowLayout RowData)
			 (org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
									 SelectionEvent ShellAdapter ShellEvent)
			 (org.eclipse.swt.widgets FileDialog DirectoryDialog MessageBox Composite)
			 (org.eclipse.swt SWT)
			 (org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem)
			 (java.util ResourceBundle Vector Hashtable)))

(def  load-default-database)

(def  database-shell      (new Shell *shell* *database-win-style*))
(def  db-location-box     (new Text database-shell SWT/BORDER))
(def  db-file-table       (new Table database-shell (bit-or SWT/SINGLE (bit-or SWT/BORDER SWT/FULL_SELECTION))))
(def  db-search-box       (new Text database-shell SWT/BORDER))
(def  db-button-comp      (new Composite database-shell SWT/NONE))
(def  db-totext-button    (new Button db-button-comp SWT/PUSH))
(def  db-filternm-button  (new Button db-button-comp SWT/PUSH))
(def  db-filtergrp-button (new Button db-button-comp SWT/PUSH))
(def  db-filtersrv-button (new Button db-button-comp SWT/PUSH))
(def  db-win-close-button (new Button db-button-comp SWT/PUSH))

;; Five table columns, loaded from database configuration file.
(def  table-col-names ["Name" "Path" "Group" "Server" "Description"])

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Proxy Helper for Database Buttons
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn db-loc-bar []
  (. db-location-box getText))

(defn format-db-table []
  ;; Format the db table to text and add to the buffer
  (when  db-file-table 
    (let [items  (. db-file-table getItems)
          col-ct (. db-file-table getColumnCount)]
      (when items
        ;; Iterate through the items and append to the buffer
        (let [buf (new StringBuffer)]
          (doseq [item items]
              ;; Pretty format the table text line
              (. buf append
                 (str (apply format "%40s %60s %20s %20s %20s\n" 
                             (list (. item getText 0) (. item getText 1) (. item getText 2)
                                   (. item getText 3) (. item getText 4))))))
          (add-text-buffer *styled-text* buffer-1 (. buf toString)))))))

(defn format-db-button-listener []
  (proxy [SelectionListener][]
         (widgetSelected [e] (format-db-table))
         (widgetDefaultSelected [e] (format-db-table))))

(defn create-db-grid-layout []
  (let [gridLayout (new GridLayout)]
    (set! (. gridLayout numColumns) 1)
    gridLayout))

(defn add-table-item [item-seq]
  (let [item (new TableItem db-file-table SWT/NONE)]
    (. item setText (into-array item-seq))))

(defn table-select-listener []
  (proxy [SelectionAdapter][]
         (widgetDefaultSelected 
          [event]
          (let [items (. db-file-table getSelection)]                                  
            (when (> (count items) 0)                      
              ;; We can extract the open path
              ;; straight from the table item data.
              (let [item (first items)
                         db-path (. item getText 1)]
                (let [cmd-line-repl (simple-term-searchrepl (db-loc-bar) db-path)]
                  (if cmd-line-repl
                    (let []
                      (history-add-textln(str *newline* "Database screen, command-line search replace: " db-path " -> " cmd-line-repl *newline*))
                      (open-file-or-dir cmd-line-repl))
                    (open-file-or-dir db-path)))))))))

(defn
  #^{:doc "Create the database viewer table"}
  create-database-table [db-sh]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  (. db-file-table setHeaderVisible true)  
  (. db-file-table addSelectionListener (table-select-listener))
  ;; Add the table column headers
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  ;; GridData = (int horizontalAlignment, int verticalAlignment, 
  ;;        boolean grabExcessHorizontalSpace, boolean grabExcessVerticalSpace) 
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (let [gd (new GridData SWT/FILL SWT/FILL true true)]
    (doseq [t table-col-names]
        (let [column (new TableColumn db-file-table SWT/NONE)]
          (. column setText  t)
          (. column setWidth *db-col-size*)))
    (. db-file-table setLayoutData gd)))

(def db-on-close-listener
     (proxy [SelectionListener][]
            (widgetSelected [event]
                            (set! (. event doit) false)
                            (. database-shell setVisible false))
            (widgetDefaultSelected [event]
                                   (set! (. event doit) false)
                                   (. database-shell setVisible false))))

(defn init-buttons-composite [sh]
  (let [comp db-button-comp
        gd-comp       (new GridData)
        gd-button     (new RowData *db-button-width* *db-button-height*)
        gd-med-button (new RowData *db-bttn-med-width* *db-button-height*)]
    (. comp setLayoutData gd-comp)
    (. comp setLayout (new RowLayout))
    (doto db-totext-button    (. setText *database-text-button*) (. setLayoutData gd-button))
    (doto db-filternm-button  (. setText *database-name-button*) (. setLayoutData gd-med-button))
    (doto db-filtersrv-button (. setText *database-grp-button*)  (. setLayoutData gd-button))
    (doto db-filtergrp-button (. setText *database-serv-button*) (. setLayoutData gd-med-button))
    (doto db-win-close-button (. setText *database-quit-button*) (. setLayoutData gd-med-button)
          (. addSelectionListener  db-on-close-listener))))

(defn init-database-helper [sh]
  (let [gd (new GridData SWT/FILL SWT/FILL true false)]
    (init-buttons-composite sh)
    (. db-location-box setLayoutData gd)
    (. db-location-box setText "term1 , term2 ; term3 , term4")
    (. db-search-box setLayoutData gd)   
    (. db-search-box setText "XXXXXXXXXXXXXX")
    (. db-totext-button addSelectionListener (format-db-button-listener))
    (create-database-table sh)))

(defn
    #^{:doc "Initialize the file database SWT window, set the size add all components"}
    create-database-window [parent-sh open-win?]
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    (history-add-textln "Opening file database screen (Tools -> Database Viewer)")
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
      (if open-win? (let []
                      (. database-shell open)
                      (. database-shell setVisible open-win?))
          (. database-shell setVisible true))
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

(defn try-open-db-file
  "Attempt to open database XML file."
  [db-filename db-path]
  ;;;;;;;;;;;;;;
  ;; Strange BUG: why is 'file://' needed.
  (try (let [xml-data (clojure.xml/parse (str "file:///" db-path))]
         xml-data)
       (catch Exception e
              ;; Build error message and return nil.
              (let [err-buf (new StringBuffer)]
                (. err-buf append
                   (str "ERR: while opening DB file : " (. e getMessage)
                        *newline* "ERR: DB-Filename => " db-filename *newline* "ERR: path => " db-path))
                (history-add-textln (. err-buf toString)))
              nil)))
      
(defn load-default-database []
  (let [db-filename (prop-str resources-user *prop-main-database*)
        db-path  (str *octane-install-dir* *name-separator* db-filename)
        xml-data (try-open-db-file db-filename db-path)]
    (when xml-data
      (history-add-textln (str "Adding main file database data, path=>" db-path))
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