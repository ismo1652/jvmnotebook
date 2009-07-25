;;
;; Running with Clojure 1.0 under Windows XP
;; As of 7/15/2009
;; 


(ns org.perf.test4_euler
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)))

;; Most of the following examples are taken verbatim from
;; http://clojure-euler.wikispaces.com/Problem+001
;; Thanks developers!
;;
;; I tried to take the cleanest looking examples (least amount code, most readable).
;;
;; Euler 1 Problems
;; Add all the natural numbers below one thousand that are multiples of 3 or 5.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn euler-1-1
  "Euler problem 1 - 1 using 'reduce and filter'
 On filter:  Returns a lazy sequence of the items in coll for which (pred item) returns true. pred must be free of side-effects.
 On reduce: eturns the result of applying f to the first 2 items in coll, then applying f to that result and the 3rd item, etc"
  []
  ;;;;
  (reduce + (filter #(or (zero? (rem % 3))
                         (zero? (rem % 5)))
                    (range 1000))))

(defn euler-1-2
  "Euler problem 1 - 2 using 'reduce', lambda syntax and other 
 math functions
 On '#' lambda : Anonymous function literal (#()) 
            '%'Represents an optional argument to an unnamed function."
  []
  ;;;;;
  (reduce #(if (or (zero? (rem %2 3)) (zero? (rem %2 5)))
             (+ %1 %2)
             %1)
          (range 1000)))

(defn run-test
  "First string test.  Note: this test is used for the output of test3.txt"
  []
  ;;;;
  (println "Running Test [Euler 1] " *current-date*)
  (println (*memory-usage*)) 
  ;; Just print the result
  (println (euler-1-1))
  (println (euler-1-2))
  (println (*memory-usage*))
  ;; incrementally increase tests
  (dotimes [x 10]
      (println "i: " (* (+ 1 x) 100))
    (time 
     (dotimes [_ (* (+ 1 x) 100)]
         (euler-1-1))))
  (println "Second version of euler - 1")
  (dotimes [x 12]
      (println "i: " (* (+ 1 x) 100))
    (time 
     (dotimes [_ (* (+ 1 x) 100)]
         (euler-1-2))))
  (println (*memory-usage*))
  (println "Done"))
      
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn run-cool-down
  "Allow a little time to see if JVM garbage collects.
 This may not have any effect"
  []
  ;;;
  (println "Performing simple garbage collection cooldown")
  (println (*memory-usage*))
  (Thread/sleep 120)
  (println (*memory-usage*))
  (Thread/sleep 120))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
(defn main [& args]
  (try (run-test)
       (run-cool-down)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script