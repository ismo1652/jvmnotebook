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

(ns org.perf.test8_collection
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

;; by Stuart Sierra, http://stuartsierra.com/
;; last updated March 2, 2009
; clojure contrib seq code by Stuart Sierra

(defn indexed
  "Returns a lazy sequence of [index, item] pairs, where items come
  from 's' and indexes count up from zero.

  (indexed '(a b c d))  =>  ([0 a] [1 b] [2 c] [3 d])"
  [s]
  (map vector (iterate inc 0) s))

;; group-by written by Rich Hickey;
;; see http://paste.lisp.org/display/64190
(defn group-by 
  "Returns a sorted map of the elements of coll keyed by the result of
  f on each element. The value at each key will be a vector of the
  corresponding elements, in the order they appeared in coll."
  [f coll]
  ;;;;;;;;;
  (reduce
   (fn [ret x]
     (let [k (f x)]
       (assoc ret k (conj (get ret k []) x))))
   (sorted-map) coll))

(defn frequencies
  "Returns a map from distinct items in coll to the number of times
  they appear."
  [coll]
  ;;;;;;;;;
  (reduce (fn [counts x]
              (assoc counts x (inc (get counts x 0))))
          {} coll))

(defn run-test-3
  []
  ;;;;
  ;; Test of simple building list

  ;; Build a small list
  ;; call the operations many time
  (println (*memory-usage*))
  (time (dotimes [_ 1e2]
            (count (loop [a () i 1e4] 
                     (if (= i 0) a (recur (conj a "a") (- i 1)))))))
  (println (*memory-usage*))
  (println "Larger list")
  (time (dotimes [_ 1e1]
            (count (loop [a () i 1e6]
                     (if (= i 0) a (recur (conj a "a") (- i 1)))))))
  (println (*memory-usage*)))

;; <blbrown_win> ,(group-by (comp #(.toString %) class) [1 2 "three" :four])
;; <clojurebot> {"class clojure.lang.Keyword" [:four], "class java.lang.Integer" [1 2], "class java.lang.String" ["three"]}

(defn run-test-2
  []
  ;;;;
  (dotimes [x 5]
      (println "i: " (int (Math/pow 10.0 x)))
    (time
     (dotimes [_ (int (Math/pow 10.0 x))]
         (let [a (for [_ (range 1000)] (random-string 3))]
           (group-by (comp #(.toString %) class) [1 2 "three" :four]))))))

(defn run-test
  []
  ;;;;
  (println (*memory-usage*))
  (dotimes [x 4]
      (println "i: " (int (Math/pow 10.0 x)))
    (time
     (dotimes [_ (int (Math/pow 10.0 x))]
         (let [a (for [_ (range 1000)] (random-string 3))]
           (frequencies a)))))
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
  (try (run-test-3)
       (run-cool-down)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script