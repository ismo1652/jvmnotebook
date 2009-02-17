;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns test.OctaneUtilsTest
    (:import (junit.framework Assert))   
	(:use
	 octane.toolkit.octane_config
	 octane.toolkit.octane_utils)
	(:gen-class
	 :extends junit.framework.TestCase
     :methods
	 [    
	  [ test_replace_sys_prop [] void ]
	  [ test_doc_filter_regex [] void ]
	  ]))

(defn -init [_] ()) 

(def example-doc "lkjdlfjslkdjflksjdfs
lksjdklfjslkdjfklsjd 123 abc
lksjdklfslkdjflks 123
lkljdfljsdf
  filter
kjsldjfs abc
srevle
servlet 
12312 90i121
Dogs cats meat abc  123
dog cat 123 baby
chickens 123")

(defn -test_doc_filter_regex [_]
  (let [doc example-doc]
	(doc-filter-regex doc "(123|abc)")))
	
(defn -test_replace_sys_prop [_]
  (Assert/assertNotNull *octane-install-dir*)
  (Assert/assertEquals "/usr/local/projects/octane/dogs/cats" 
					   (system-var-install-dir "_SYS_INSTALL_DIR_/dogs/cats"))
  (Assert/assertEquals "/usr/local/projects/octane/dogs/cats" 
					   (system-variable "_SYS_INSTALL_DIR_/dogs/cats" *SYS_INSTALL_DIR* *octane-install-dir*)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

