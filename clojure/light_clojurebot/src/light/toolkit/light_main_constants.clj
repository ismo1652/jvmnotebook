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

(ns light.toolkit.light_main_constants
  (:use  light.toolkit.light_utils
		 light.toolkit.light_config
		 light.toolkit.light_version)	
  (:import  (org.eclipse.swt.graphics Color RGB)
			(org.eclipse.swt SWT)
              (java.text MessageFormat)
              (java.util.regex Pattern)
              (java.nio CharBuffer MappedByteBuffer)
              (java.nio.channels FileChannel)
              (java.nio.charset Charset)
              (java.nio.charset CharsetDecoder)
              (java.util.regex Matcher)
              (java.util.regex Pattern)
              (java.util.regex PatternSyntaxException)
              (java.nio ByteBuffer)))

;; The on application load header message 
(def hist-header-msg
"
************************************************************
* Light Log Viewer Init
* Version: {4}
* Running on system environment : {3}
* Launched at {0}
* Install Directory : {1}
* Work Path : {2}

-----------
Quick Keys:
------------
CTRL - O = Invoke Open File Dialog
CTRL - D = Database File Viewer
CTRL - E = Open the Windows Explorer File Manager
CTRL - J = Open the Jar File Viewer
CTRL - Z = Open a Unix Compressed Z File
CTRL - F = Invoke the Find Dialog (Search within Main Buffer)
CTRL - G = Invoke Find in Files Dialog
CTRL - U = Search Acrchive Files By Date
F4       = Swap FROM the main buffer to the secondary buffer
F3       = Swap FROM the secondary buffer to the main buffer

************************************************************
")

(def simple-file-info-msg
"File Info Properties:
File Name : {2}
Absolute Path : {4}
Parent Directory : {3}
Last Modified : {0}
Number of Lines : {1}
File Size : {5} bytes
File Size (MB): {7} MB
Memory after load : {6}
---------------------------------------------------------------------------------------------")

(def file-info-msg
"
------------------------------------------------------------
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

(def *about-version-msg*
"Light Text Viewer

Version: {0}

{1}

Light is text viewer application for
viewing and searching through plain text documents.  
It also contains graph and charting utilities.

At least Java Runtime 1.5 is required")

(def  *about-version*
	 (. MessageFormat format *about-version-msg*
		(to-array [*LIGHT_VERSION* (. resources-win getString "About_2")])))

;; Note: the work path may be set automatically by 'light-config' get install directory.
(def *newline* "\n")

(def *recent-file-list* (str *work-path* "/" "_sHIKXx1_recent.ser"))

(defn get-hist-header []
  (. MessageFormat format hist-header-msg
     (to-array [(str (new java.util.Date))
                *light-install-dir* *work-path* *system-os-name* *LIGHT_VERSION*])))

(def win-size-width       880)
(def win-size-height      750)

(def *db-size-width*      760)
(def *db-size-height*     510)
(def *db-col-size*        130)

(def *db-button-width*    150)
(def *db-bttn-med-width*  130)
(def *db-button-height*    28)

(def *search-size-width*  460)
(def *search-size-height* 290)

(def *regex-size-width*   620)
(def *regex-size-height*  370)

(def *graph-size-width*   700)
(def *graph-size-height*  600)

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
(def yellow-color     (new RGB 255 255   0))
(def black-color      (new RGB 10  10   10))

(def tab-1-title      "Main Buffer View")
(def tab-2-title      "Secondary Buffer View")
(def tab-3-title      "History Console")
(def tab-4-title      "Command Console")

;; Hard code the style to avoid calling bitwise operator
;; SWT.BORDER | SWT.MULTI | SWT.V_SCROLL | SWT.H_SCROLL
(def swt-text-style (bit-or SWT/BORDER 
                            (bit-or SWT/MULTI 
                                    (bit-or SWT/H_SCROLL SWT/V_SCROLL))))

(def *database-win-style*   (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE SWT/MIN))))
(def *database-text-button* "Format Database View")
(def *database-name-button* "Filter Name")
(def *database-grp-button*  "Filter Group")
(def *database-serv-button* "Filter Server")
(def *database-quit-button* "Exit")

(def *openfile-wildcard-seq* ["*.*" "*.log" "*.olog" "*.ologs" "*.octlog"
                              "*.Mon" "*.Tue" "*.Wed" "*.Thu" "*.Fri"])
(def *sysout-wildcard-seq*   ["*.log" "*.Mon" "*.Tue" "*.Wed" "*.Thu" "*.Fri" "*.*"])

(def *jar-wildcard-seq*      ["*.jar" "*.zip" "*.*"])

(def *zip-wildcard-seq*      [ "*.Z" "*.zip" "*.jar" "*.*" ])

(def *prop-main-database* "Main_database_config")

;; For Regex Patterns, Flags may include CASE_INSENSITIVE, MULTILINE, DOTALL, UNICODE_CASE, and CANON_EQ
;; Establish the charset and decoder, used with grep functionality.
(def *regex-line-pattern* (. Pattern compile ".*\\r?\\n"))
(def *iso-8859-charset*   (. Charset forName "ISO-8859-15"))
(def *charset-decoder*    (. *iso-8859-charset* newDecoder))

(defn get-char-buf-decoder
  "Get java nio character buffer from decoder"
  [doc]
  ;;;;;;;;;;;
  (let [dummy1 (. *charset-decoder* reset)
		;; BugFix/Hack, adding newline to end of document
		char-buf (. *charset-decoder* decode (. ByteBuffer wrap (. (str doc \newline) getBytes)))]
    char-buf))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;