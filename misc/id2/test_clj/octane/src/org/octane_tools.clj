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

(def *process-map*)
(def add-main-text-nc)

(defn run-codegen-build-xml []
   (add-main-text *codegen-templ-build-xml*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Process Launch Utilities
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn get-process [proc-atom-str]
  ;; Where proc-str equals E.g. 'cat', 'cut'
  ;; Check if this a win32, is so use that particular process.
  ;; And then check for other oses and default to the linux system
  (cond
   *is-windows* (*process-map* (keyword (str "win"  "-" proc-atom-str)))
   *is-linux*   (*process-map* (keyword (str "unix" "-" proc-atom-str)))
   :else        (*process-map* (keyword (str "unix" "-" proc-atom-str)))))


(defn build-findgrep-arr [cmd cur-dir wildcard grep-args]
  ;; Complex approach for building the arguments to 'find'
  (let [grp (get-process "grep")
			fst [cmd cur-dir "-name" (str "'" wildcard "'") ]
			more (if grep-args 
				   (conj fst "-exec" grp "-Hn" (str "'" grep-args "'") "{}" "\\;") 
				   fst)
			s (apply str (interpose " " more))]
	{:array more :text s}))

(defn start-findgrep-cmd [cur-dir wildcard grep-args]
  (let [fnd-proc (get-process "find")
				 proc-data (build-findgrep-arr fnd-proc cur-dir wildcard grep-args)
				 process-line (when fnd-proc     (into-array ["find" "-name" "\\'*.java\\'"]))
				 process-bld  (when process-line (when-try (new ProcessBuilder process-line)))
				 process      (when process-bld  (when-try (. process-bld start)))]
	(when process
	  (history-add-text (str "Invoking find/grep command => " (proc-data :text) *newline*))
	  (let [istream (. process getInputStream)
					ireader   (new InputStreamReader istream)
					bufreader (new BufferedReader ireader)]
		;; First clear the main text buffer
		(clear-buffer buffer-1)
		(async-call display (status-set-text "Begin find search"))
		(let [proc-time-info (proc-time (loop [line (. bufreader readLine)]
										  (when line
											(async-call display (add-main-text-nc line))
											(recur (. bufreader readLine)))))
							 msg (str "<<Completed find search>> " (proc-time-info :time-text))]
		  (async-call display (add-main-text-nc msg))
		  (async-call display (status-set-text msg)))))))

(defn start-findgrep-thread []
  (let [t (proxy [Runnable] []
				 (run []
					  (start-findgrep-cmd "." "*.java" nil)))] t))

(defn start-findgrep-proc []
  (. (new Thread (start-findgrep-thread)) start))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;