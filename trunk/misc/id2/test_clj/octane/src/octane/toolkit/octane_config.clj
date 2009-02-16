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

(ns octane.toolkit.octane_config)

(import '(java.util ResourceBundle Vector))
(import '(java.io File))

(def *name-separator* (. File separator))
(def *work-path-1*    (str "conf" *name-separator* "sys"  *name-separator* "_work"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; System property keys
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def *sys-prop-install-dir* "octane.install.dir")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Resource Files
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def resources-win      (ResourceBundle/getBundle "octane_win"))
(def resources-core-sys (ResourceBundle/getBundle "octane_core_sys"))
(def resources-win-opts (ResourceBundle/getBundle "octane_win_options"))
(def resources-user     (ResourceBundle/getBundle "octane_user"))

(defn prop-core-sys [key]      (. resources-core-sys getString key))
(defn prop-core-sys-int [key]  (. Integer parseInt (prop-core-sys key)))
(defn prop-core-sys-bool [key] (. Boolean parseBoolean (prop-core-sys key)))

(defn prop-str  [res key] (. res getString key))
(defn prop-int  [res key] (. Integer parseInt (prop-str res key)))
(defn prop-bool [res key] (. Boolean parseBoolean (prop-str res key)))

(defn res-win-str [key]   (. resources-win getString key))

(defn get-install-dir-1 []  
  ;; The install directory is set by the 'octane.install.dir' property key
  ;; If this value is empty, attempt to use the current working directory
  (try (let [f  (new File (str (. System getProperty *sys-prop-install-dir*) *name-separator*))
             e? (. f exists)
             w? (. f canWrite)]
         (if (not (and e? w?))
           (throw (Error. (str "Invalid install directory =>" (. f getAbsolutePath))))
           (. f getAbsolutePath)))
       (catch Exception e (println "WARN <get-install-dir>: unexpected error opening install dir =>" e))))

(defn get-install-dir []
  (if-let [path (get-install-dir-1)]
      path
    (let [f    (new File ".")
          cnf  (new File (str "." *name-separator* *work-path-1*))]
      ;; Also mkdir the configuration/work directories
      (println "INFO: creating work directories =>" (. cnf getAbsolutePath))
      (. cnf mkdirs)
      (. f getAbsolutePath))))

(def *octane-install-dir* (get-install-dir))

(def *work-path* (str *octane-install-dir* *name-separator* *work-path-1*))

(def *SYS_INSTALL_DIR* "_SYS_INSTALL_DIR_")

(defn system-var-install-dir
  "Replace an instance of the system property within a given string"
  [str]
  ;;;;;;;
  (when str
	(. str replaceAll *SYS_INSTALL_DIR* *octane-install-dir*)))

(defn system-variable
  "Replace an instance of the system property within a given string"
  [var str]
  ;;;;;;;
  (when str (. str replaceAll var *octane-install-dir*)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; External Application Constants
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def *system-os-name* (. (. System getProperty "os.name") toLowerCase))

(def *is-linux*   (> (. *system-os-name* indexOf "linux")   -1))
(def *is-windows* (> (. *system-os-name* indexOf "windows") -1))

(def *win-tools-dir* (str *name-separator* "tools" *name-separator* "unxutils" *name-separator* 
                          "usr" *name-separator* "local" *name-separator* "wbin" *name-separator*))

;; Note: only invoke the manager when the OS is windows.
(def *win-explorer-exe* "explorer.exe")

(def *win-cat*    (str *octane-install-dir* *win-tools-dir* "octane_cat.exe"))
(def *win-cut*    (str *octane-install-dir* *win-tools-dir* "octane_cut.exe"))
(def *win-diff3*  (str *octane-install-dir* *win-tools-dir* "octane_diff3.exe"))
(def *win-diff*   (str *octane-install-dir* *win-tools-dir* "octane_diff.exe"))
(def *win-egrep*  (str *octane-install-dir* *win-tools-dir* "octane_egrep.exe"))
(def *win-find*   (str *octane-install-dir* *win-tools-dir* "octane_find.exe"))
(def *win-gawk*   (str *octane-install-dir* *win-tools-dir* "octane_gawk.exe"))
(def *win-grep*   (str *octane-install-dir* *win-tools-dir* "octane_grep.exe"))
(def *win-ls*     (str *octane-install-dir* *win-tools-dir* "octane_ls.exe"))
(def *win-patch*  (str *octane-install-dir* *win-tools-dir* "octane_patch.exe"))
(def *win-sed*    (str *octane-install-dir* *win-tools-dir* "octane_sed.exe"))
(def *win-touch*  (str *octane-install-dir* *win-tools-dir* "octane_touch.exe"))
(def *win-wc*     (str *octane-install-dir* *win-tools-dir* "octane_wc.exe"))
(def *win-xargs*  (str *octane-install-dir* *win-tools-dir* "octane_xargs.exe"))

(def *unix-cat*     "cat")
(def *unix-cut*     "cut")
(def *unix-diff3*   "diff3")
(def *unix-diff*    "diff")
(def *unix-egrep*   "egrep")
(def *unix-find*    "find")
(def *unix-gawk*    "gawk")
(def *unix-grep*    "grep")
(def *unix-ls*      "ls")
(def *unix-patch*   "patch")
(def *unix-sed*     "sed")
(def *unix-touch*   "touch")
(def *unix-wc*      "wc")
(def *unix-xargs*   "xargs")

;; Main data structure for holding the external search processes
(def *process-map* {
 :unix-cat   *unix-cat*   :win-cat    *win-cat*
 :unix-cut   *unix-cut*   :win-cut    *win-cut*
 :unix-diff3 *unix-diff3* :win-dif3   *win-diff3*
 :unix-diff  *unix-diff*  :win-diff   *win-diff*
 :unix-egrep *unix-egrep* :win-egrep  *win-egrep*
 :unix-find  *unix-find*  :win-find   *win-find*
 :unix-gawk  *unix-gawk*  :win-gawk   *win-gawk*
 :unix-grep  *unix-grep*  :win-grep   *win-grep*
 :unix-ls    *unix-ls*    :win-ls     *win-ls*
 :unix-patch *unix-patch* :win-patch  *win-patch*
 :unix-sed   *unix-sed*   :win-sed    *win-sed*
 :unix-touch *unix-touch* :win-touch  *win-touch*
 :unix-wc    *unix-wc*    :win-wc     *win-wc*
 :unix-xargs *unix-xargs* :win-xargs  *win-xargs*
})

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End Application Constants
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;