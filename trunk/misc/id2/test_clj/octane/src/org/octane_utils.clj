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

(import '(java.lang Runtime))

(defn exit [] (. System (exit 0)))

(defn clear-buffer [buf] (. buf setLength 0))

(defn length [s] (count s))

(defn date-time [] (str (new java.util.Date)))

(defn date-timel [l] (str (new java.util.Date l))) 

(defn file-exists? [path] (let [file (new File path)] (. file exists)))

(defn octane-pattern [s flags] (. Pattern compile s flags))

(defn octane-pattern_ [s] (. Pattern compile s))

(defn add-select-style [styles-vec cur-style] (. styles-vec addElement cur-style))

(defn floor [d] (. Math floor d))

(defn col-vec-bg []    (. colors-vec get 0))
(defn col-vec-grey []  (. colors-vec get 1))
(defn col-vec-red []   (. colors-vec get 2))
(defn col-vec-cy   []  (. colors-vec get 3))
(defn col-vec-drkb []  (. colors-vec get 4))
(defn col-vec-wht  []  (. colors-vec get 5))

(def  *megabytes*      (* 1024.0 1024.0))
(def  *java-runtime*   (. Runtime getRuntime))

(defn *free-memory-b*  [] (. *java-runtime* freeMemory))
(defn *total-memory-b* [] (. *java-runtime* totalMemory))
(defn *max-memory-b*   [] (. *java-runtime* maxMemory))
(defn *used-memory-b*  [] (- (*total-memory-b*) (*free-memory-b*)))

;; Note: used memory == total memory - free memory
(defn *free-memory-m*  [] (int (floor (/ (*free-memory-b*)  *megabytes*))))
(defn *total-memory-m* [] (int (floor (/ (*total-memory-b*) *megabytes*))))
(defn *max-memory-m*   [] (int (floor (/ (*max-memory-b*)   *megabytes*))))
(defn *used-memory-m*  [] (int (floor (/ (*used-memory-b*)  *megabytes*))))

(defn *memory-usage* []
  (str "(" (*used-memory-m*) "M/" 
	   (*free-memory-m*) "M [" (*total-memory-m*) "M," (*max-memory-m*) "M ])"))

;;; End of Script