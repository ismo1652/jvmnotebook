;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

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

(ns light.toolkit.light_version)

(def *MAJOR_VERSION*
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 ;; Edit the Major Version
     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	 
	 0
     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 )

(def *MINOR_VERSION*
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 ;; Edit the minor version
     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	 
	 2
     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 )

(def *DATE_STR_VERSION*
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 ;; Edit the date string version
	 ;; YYYYmmdd
     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	 
	 "20090228"
     ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	 )

(def *LIGHT_VERSION* (str  *MAJOR_VERSION* "." *MINOR_VERSION* "." *DATE_STR_VERSION*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      