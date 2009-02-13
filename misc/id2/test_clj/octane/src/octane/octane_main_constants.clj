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
;;; -------------------------------------------------------

(in-ns 'octane)

(import '(org.eclipse.swt.graphics Color RGB))
(import '(org.eclipse.swt SWT))

(import '(java.text MessageFormat))

(def date-time)

;; The on application load header message is used
;;
(def hist-header-msg
"************************************************************
* Octane Log Viewer Init
* Running on system environment : {3}
* Launched at {0}
* Install Directory : {1}
* Work Path : {2}
************************************************************
")

(def file-info-msg
"------------------------------------------------------------
- File Info Properties#
- File Name : {2}
- Absolute Path : {4}
- Parent Directory : {3}
- Last Modified : {0}
- Number of Lines : {1}
- File Size : {5} bytes
- Memory : {6}
------------------------------------------------------------
")

;; Note: the work path may be set automatically by 'octane-config' get install directory.
(def *newline* "\n")

(def *recent-file-list* (str *work-path* "/" "_sHIKXx1_recent.ser"))

(defn get-hist-header []
  (. MessageFormat format hist-header-msg 
     (to-array [(date-time)
                *octane-install-dir* *work-path* *system-os-name* ])))

(def win-size-width       880)
(def win-size-height      750)

(def *db-size-width*      700)
(def *db-size-height*     460)
(def *db-col-size*        130)

(def *search-size-width*  460)
(def *search-size-height* 290)

(def *regex-size-width*   620)
(def *regex-size-height*  370)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; RGB colors used when setting the color scheme for a text area.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def orange-sel-color (new RGB 250 209 132))
(def lightgrey-color  (new RGB 100 100 100))
(def red-color        (new RGB 255 0     0))
(def green-color      (new RGB 18  152  14))
(def white-color      (new RGB 255 255 255))
(def cyan-sel-color   (new RGB 64  224 208))
(def dark-blue-color  (new RGB 34  38  167))

(def tab-1-title      "Main Buffer View")
(def tab-2-title      "Secondary Buffer View")
(def tab-3-title      "History Console")
(def tab-4-title      "Command Console")

;; Hard code the style to avoid calling bitwise operator
;; SWT.BORDER | SWT.MULTI | SWT.V_SCROLL | SWT.H_SCROLL
(def swt-text-style (bit-or SWT/BORDER 
                            (bit-or SWT/MULTI 
                                    (bit-or SWT/H_SCROLL
                                            (bit-or SWT/V_SCROLL 1)))))

(def *database-win-style*   (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE SWT/MIN))))
(def *database-text-button* "Format Database View")
(def *database-name-button* "Filter Name")
(def *database-grp-button*  "Filter Group")
(def *database-serv-button* "Filter Server")

(def *openfile-wildcard-seq* ["*.*" "*.log" "*.olog" "*.octlog"
                              "*.Mon" "*.Tues" "*.Wed" "*.Thu" "*.Fri"])

(def *prop-main-database* "Main_database_config")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;