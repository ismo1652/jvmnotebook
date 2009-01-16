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

(import '(java.io BufferedReader LineNumberReader File FileInputStream
                  FileNotFoundException IOException InputStreamReader Reader))
(import '(java.util ResourceBundle Vector))

(def open-file)
(def get-file-state)

(def  cur-file-info (ref {:file-name nil :file-path nil :last-mod nil :line-num 0 :file-size 0
                                         :parent-dirname nil :writeable false :exists false}))
(defn set-file-info [nm pth mod-t n prnt w xsts sz]
  (dosync (commute cur-file-info assoc 
                   :file-name nm :file-path pth :last-mod mod-t :file-size sz
                       :line-num n :parent-dirname prnt :writeable w :exists xsts)))

(defn get-file-info-header []
  (when (and (not (nil? @cur-file-info)) (get-file-state))
    (. MessageFormat format 
       file-info-msg (to-array [(@cur-file-info :last-mod)  (@cur-file-info :line-num)
                                (@cur-file-info :file-name) (@cur-file-info :parent-dirname)
                                (@cur-file-info :file-path) (@cur-file-info :file-size)]))))
      
(def  file-state             (ref {:open-state false}))
(defn get-file-state []      (@file-state :open-state))
(defn set-file-state [state] (dosync (commute file-state assoc :open-state state)))

(def  file-last-mod          (ref {:last-mod 0 :file-path nil}))
(defn get-file-last-mod  []  (@file-last-mod :last-mod))
(defn get-last-file-path []  (@file-last-mod :file-path))
(defn set-file-last-mod  [t name] (dosync (commute file-last-mod assoc :last-mod t :file-path name)))

(defn file-modified? [file]
  (let [mod-t  (. file lastModified)
        prev-t (get-file-last-mod)
        diff   (- mod-t prev-t)
        pth    (. file getAbsolutePath)]
    (when (> diff 0)
      (set-file-last-mod mod-t pth)
      true)))
                
(defn file-monitor-loop [file]
  (let [delay-t (prop-int resources-core-sys "Octane_Sys_filemonitor_delay")
        enable-file-mon (prop-bool resources-win-opts "file_monitor_enabled")
        pth    (. file getAbsolutePath)]
    (when enable-file-mon
      (.start  (new Thread (fn []
                               (while (not (. shell isDisposed))
                                      (Thread/sleep delay-t)
                                      (when (file-modified? file)
                                        ;; Reload the file as it grows and refresh
                                        ;; the file.
                                        (open-file pth true)))))))))

;;**************************************
;; File Utilities
;;**************************************
(defn
  #^{:doc "Use java oriented approach for loading a file into memory"}
  open-file-util [file file-path]
  ;; Java oriented approach for opening file
  (let [stream (new FileInputStream file-path)
        instr (new LineNumberReader (new InputStreamReader stream))
        ;; Use type hints to ensure a character type.
        readBuffer #^"[C" (make-array (. Character TYPE) 2048)
        buf (new StringBuffer)]
	(loop [n (. instr read readBuffer)]
	  (when (> n 0)
		(. buf append readBuffer 0 n)
		(recur (. instr read readBuffer))))
    ;; File info data has been collected, set some of the file properties
    (set-file-info (. file  getName) (. file  getAbsolutePath) 
                   (. file  lastModified) (. instr getLineNumber) (. file  getParent)
                   (. file  canWrite) (. file  exists) (. file  length))
	(. instr close)
	(. buf toString)))

;;; End of Script