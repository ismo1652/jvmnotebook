;;; -------------------------------------------------------
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
;;; -------------------------------------------------------

(in-ns 'org.octane)

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
  (. MessageFormat format hist-header-msg (to-array [(date-time)
                                                     *octane-install-dir* 
                                                     *work-path*
                                                     *system-os-name*
                                                     ])))

(def win-size-width    880)
(def win-size-height   750)

(def *db-size-width*   600)
(def *db-size-height*  360)

(def *search-size-width*  460)
(def *search-size-height* 290)

(def *regex-size-width*  620)
(def *regex-size-height* 370)

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

(def *database-win-style* (bit-or SWT/CLOSE (bit-or SWT/BORDER (bit-or SWT/TITLE SWT/MIN))))

(def *openfile-wildcard-seq* ["*.*" "*.log"
                              "*.Mon" "*.Tues" "*.Wed" "*.Thu" "*.Fri"])

(def *prop-main-database* "Main_database_config")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;