;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns test.OctaneUtilsTest
    (:import (junit.framework Assert))   
	(:use
	 octane.toolkit.octane_config)
	(:gen-class
	 :extends junit.framework.TestCase
     :methods
	 [    
	  [ test_replace_sys_prop [] void ]
	  ]))

(defn -init [_] ()) 
	
(defn -test_replace_sys_prop [_]
  (Assert/assertNotNull *octane-install-dir*)
  (Assert/assertEquals "/usr/local/projects/octane/dogs/cats" 
					   (system-var-install-dir "_SYS_INSTALL_DIR_/dogs/cats"))
  (Assert/assertEquals "/usr/local/projects/octane/dogs/cats" 
					   (system-variable *SYS_INSTALL_DIR* "_SYS_INSTALL_DIR_/dogs/cats")))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

