;;; -------------------------------------------------------
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
;;; -------------------------------------------------------

(in-ns 'org.octane)

(import '(org.eclipse.swt.widgets FileDialog MessageBox Composite))
(import '(org.eclipse.swt SWT))
(import '(org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem))
(import '(java.util ResourceBundle Vector))

(def tab-folder)

(def swt-tabtext-style (bit-or SWT/BORDER 
							   (bit-or SWT/MULTI 
									   (bit-or SWT/H_SCROLL
											   (bit-or SWT/V_SCROLL 1)))))

(def colors-vec  (new Vector))
(def buffer-1    (new StringBuffer 4096))
(def buffer-2    (new StringBuffer 4096))
(def buffer-3    (new StringBuffer 4096))

(def display     (new Display))
(def shell       (new Shell display))

(def fileDialog  (new FileDialog shell, SWT/CLOSE))

(def tab-folder  (new TabFolder shell SWT/NULL))
(def tab-area-1  (new TabItem tab-folder SWT/NULL))
(def tab-area-2  (new TabItem tab-folder SWT/NULL))
(def tab-area-3  (new TabItem tab-folder SWT/NULL))
(def tab-area-4  (new TabItem tab-folder SWT/NULL))

(def search-box  (new Text shell SWT/BORDER))

(def tab-text-2  (new Text tab-folder swt-tabtext-style))
(def tab-text-3  (new Text tab-folder swt-tabtext-style))
(def tab-text-4  (new Text tab-folder swt-tabtext-style))

(def status-bar  (new Label shell SWT/BORDER))

;;; End of Script