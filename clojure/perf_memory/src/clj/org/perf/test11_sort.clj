;;
;; Running with Clojure 1.0 under Windows XP
;; As of 7/15/2009
;; 
;; Copyright message for clojure contrib code:

;; From clojure contrib:
;; clojure-contrib / src / clojure / contrib / str_utils.clj
;; http://github.com/richhickey/clojure-contrib/blob/6fea921c91d453c750586c960ec92caacf4fa5e6/src/clojure/contrib/str_utils.clj
;;
;; Copyright (c) Stuart Sierra, 2008. All rights reserved.  The use
;; and distribution terms for this software are covered by the Eclipse
;; Public License 1.0 (http://opensource.org/licenses/eclipse-1.0.php)
;; which can be found in the file epl-v10.html at the root of this
;; distribution.  By using this software in any fashion, you are
;; agreeing to be bound by the terms of this license.  You must not
;; remove this notice, or any other, from this software.


(ns org.perf.test11_sort
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))



;;
;; Most sort algorithms from:
;; http://rosettacode.org/wiki/Quicksort#Clojure

(defn qsort 
  "Quick sort from rosetta code:
 http://rosettacode.org/wiki/Quicksort#Clojure"
  [[pvt & rs]]
  (if pvt
    `(~@(qsort (filter #(<  % pvt) rs))
      ~pvt 
      ~@(qsort (filter #(>= % pvt) rs)))))

(defn qsort-2 [[pivot & xs]]
  (when pivot
    (let [smaller #(< % pivot)]
      (lazy-cat (qsort-2 (filter smaller xs))
                [pivot]
                (qsort-2 (remove smaller xs))))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 (defn merge* [left right]
   (cond (nil? left) right
         (nil? right) left
         true (let [[l & *left] left
                    [r & *right] right]
                (if (<= l r) (cons l (merge* *left right))
                    (cons r (merge* left *right))))))
 
 (defn merge-sort [L]
   (let [[l & *L] L]
     (if (nil? *L) 
       L
       (let [[left right] (split-at (/ (count L) 2) L)]
         (merge* (merge-sort left) (merge-sort right))))))

(def random (java.util.Random. (System/currentTimeMillis)))

(defn run-test-2
  []
  ;;;;
  (println "Running Test [Quick Sort] " *current-date*)
  (println (*memory-usage*))
  (println (merge-sort [ 4 5 23 1 35 3 ]))
  (println "Run quick sort First")
  (dotimes [x 4]
      (println "i: " (int (Math/pow 10.0 x)))
    (time (count (qsort (for [_ (range (int (Math/pow 10.0 x))) ] (.nextInt random))))))
  (println (*memory-usage*))

  (println "Merge Sort")
  (dotimes [x 4]
      (println "i: " (int (Math/pow 10.0 x)))
    (time (count (merge-sort (for [_ (range (int (Math/pow 10.0 x))) ] (.nextInt random))))))
  (println (*memory-usage*))
  ;; Note merge sort stack overflow error at 3000
  (time (count (merge-sort (for [_ (range 2200) ] (.nextInt random)))))
  (println "Done"))

(defn run-test
  []
  ;;;;
  (println "Running Test [Quick Sort] " *current-date*)
  (println (*memory-usage*))
  (println (qsort-2 [ 4 5 23 1 35 3 ]))
  (println (qsort [ 4 5 23 1 35 3 ]))
  (dotimes [x 5]
      (println "i: " (int (Math/pow 10.0 x)))
    (time (count (qsort (for [_ (range (int (Math/pow 10.0 x))) ] (.nextInt random))))))
  (println "Second Quick Sort")
  (dotimes [x 5]
      (println "i: " (int (Math/pow 10.0 x)))
    (time (count (qsort-2 (for [_ (range (int (Math/pow 10.0 x))) ] (.nextInt random))))))
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
  (try (run-test-2)
       (run-cool-down)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script