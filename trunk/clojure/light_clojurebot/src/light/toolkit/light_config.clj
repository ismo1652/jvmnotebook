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

(ns light.toolkit.light_config)

(import '(java.util ResourceBundle Vector))
(import '(java.io File))

(def *name-separator* (. File separator))
(def *work-path-1*    (str "conf" *name-separator* "sys"  *name-separator* "_work"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; System property keys
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def *sys-prop-install-dir* "light.install.dir")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Resource Files
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(def resources-win      (ResourceBundle/getBundle "light_win"))
(def resources-core-sys (ResourceBundle/getBundle "light_core_sys"))
(def resources-user     (ResourceBundle/getBundle "light_user"))

(defn prop-core-sys [key]      (. resources-core-sys getString key))
(defn prop-core-sys-int [key]  (. Integer parseInt (prop-core-sys key)))
(defn prop-core-sys-bool [key] (. Boolean parseBoolean (prop-core-sys key)))

(defn prop-str  [res key] (. res getString key))
(defn prop-int  [res key] (. Integer parseInt (prop-str res key)))
(defn prop-bool [res key] (. Boolean parseBoolean (prop-str res key)))

(defn res-win-str [key]   (. resources-win getString key))

(defn get-install-dir-1 []  
  ;; The install directory is set by the 'light.install.dir' property key
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

(def *light-install-dir* (get-install-dir))

(def *work-path* (str *light-install-dir* *name-separator* *work-path-1*))

(def *SYS_INSTALL_DIR* "_SYS_INSTALL_DIR_")

(defn system-var-install-dir
  "Replace an instance of the system property within a given string"
  [str]
  ;;;;;;;
  (when str (. str replaceAll *SYS_INSTALL_DIR* *light-install-dir*)))

(defn system-variable
  "Replace an instance of the system property within a given string"
  [str var to]
  ;;;;;;;
  (when str (. str replaceAll var to)))

(defn user-variable [key]
  (system-var-install-dir (prop-str resources-user key)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; External Application Constants
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def *system-os-name* (. (. System getProperty "os.name") toLowerCase))

(def *is-linux*   (> (. *system-os-name* indexOf "linux")   -1))
(def *is-windows* (> (. *system-os-name* indexOf "windows") -1))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End Application Constants
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;