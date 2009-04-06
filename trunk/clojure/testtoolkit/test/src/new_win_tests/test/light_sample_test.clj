
;; Make sure that the 'classes' directory exists
(ns test.light_sample_test
    (:import (junit.framework Assert))
	(:gen-class
     :methods [[testDog [] void]]
	 :extends junit.framework.TestCase))

(defn -init [_] ())

(defn -testDog [_]
  (println "Welcome to Light")
  (Assert/fail "Test not implemented"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

