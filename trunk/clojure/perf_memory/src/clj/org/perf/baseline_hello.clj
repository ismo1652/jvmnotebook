;;
;; Running with Clojure 1.0 under Windows XP
;; As of 7/15/2009
;; baseline_hello.clj
;; 
;; Some examples from gnuvince:
;; http://gnuvince.wordpress.com/2009/05/11/clojure-performance-tips/
;;
;; Test Output (as of 7/15/2009):
;; time ./test1.bat
;; -----------------
;; Running Test
;; "Elapsed time: 62.733081 msecs"
;; "Elapsed time: 16.471244 msecs"
;; real    0m1.511s
;; user    0m0.015s
;; sys     0m0.031s
;; -----------------

(ns org.perf.baseline_hello
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)))

(def some-var 10)

(defn var-test-slow
  "Simple test of locals to vars"
  []
  ;;;;;
  (println "[INFO Var Test]")
  (time (dotimes [_ 1e7] (* some-var 3.2))))

(let [my-var some-var]
  (defn var-test-fast
    "Simple test of locals to vars"
    []
    (println "[INFO Var Test]")
    (time (dotimes [_ 1e7] (* my-var 3.2)))))

(let [my-var some-var]
  (defn var-test-faster
    "Simple test of locals to vars"
    []
    (println "[INFO Var Test]")
    (time (let [x 10]
            (dotimes [_ 1e7] (* x 3.2))))))

(defn run-test
  " Application Entry Point"
  []
  ;;;;
  (println "Running Test" *current-date*)
  (println "[1] START APP -- " (*memory-usage*))  
  ;; Test the slower case
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
  (println "[2] ^^^^ AFTER FIRST SLOW CASE -- " (*memory-usage*))
  ;; Slower case using anonymous function
  (time (dotimes [_ 1e6] 
            (let [f (fn [x] (* 2.2 4.1 x))]
              (f 5.4))))
  (println "[3] ^^^^ AFTER SLOW CASE WITH ANON : " (*memory-usage*))
  ;; The performance fix, binary arithmetic operation
  (time (dotimes [_ 1e6] (* 2.2 (* 4.1 5.4))))
  ;;;;;;;;;;;;;;;;;;;;;;;;;
  (println "[4] ^^^^ AFTER FAST CASE : " (*memory-usage*))
  ;;;;; Continue to 'var' tests
  (var-test-slow)
  (println (*memory-usage*))
  (var-test-fast)
  (println (*memory-usage*))
  (var-test-faster)
  (println (*memory-usage*))
  (println "Done"))

(defn main [& args]
  (try (run-test)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script