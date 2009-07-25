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


(ns org.perf.test7_math
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

;; Math author: "Mark Engelberg"

;; Some routines from math library:
;; http://github.com/richhickey/clojure-contrib/blob/6fea921c91d453c750586c960ec92caacf4fa5e6/src/clojure/contrib/math.clj
;; clojure-contrib / src / clojure / contrib / math.clj
;;
;;; math.clj: math functions that deal intelligently with the various
;;; types in Clojure's numeric tower, as well as math functions
;;; commonly found in Scheme implementations.

;; by Mark Engelberg (mark.engelberg@gmail.com)
;; January 17, 2009

(defn gcd 
  "(gcd a b) returns the greatest common divisor of a and b" 
  [a b]
  ;;;;;;;;;
  (if (or (not (integer? a)) (not (integer? b)))
    (throw (IllegalArgumentException. "gcd requires two integers"))  
    (loop [a (Math/abs a) b (Math/abs b)]
      (if (zero? b) a,
	  (recur b (mod a b))))))

(defn lcm
  "(lcm a b) returns the least common multiple of a and b"
  [a b]
  (when (or (not (integer? a)) (not (integer? b)))
    (throw (IllegalArgumentException. "lcm requires two integers")))
  (cond (zero? a) 0
        (zero? b) 0
        :else (Math/abs (* b (quot a (gcd a b))))))

; Length of integer in binary, used as helper function for sqrt.
(defmulti #^{:private true} integer-length class)
(defmethod integer-length java.lang.Integer [n]
  (count (Integer/toBinaryString n)))
(defmethod integer-length java.lang.Long [n]
  (count (Long/toBinaryString n)))
(defmethod integer-length java.math.BigInteger [n]
  (count (. n toString 2)))


;; Produces the largest integer less than or equal to the square root of n
;; Input n must be a non-negative integer
(defn- integer-sqrt [n]
  (cond
   (> n 24)
   (let [n-len (integer-length n)]
     (loop [init-value (if (even? n-len)
			 (bit-shift-left 1 (bit-shift-right n-len 1))
			 (bit-shift-left 2 (bit-shift-right n-len 1)))]
       (let [iterated-value (bit-shift-right (+ init-value (quot n init-value)) 1)]
	 (if (>= iterated-value init-value)
	   init-value
	   (recur iterated-value)))))
   (> n 15) 4
   (> n  8) 3
   (> n  3) 2
   (> n  0) 1
   (> n -1) 0))

(defn exact-integer-sqrt "(exact-integer-sqrt n) expects a non-negative integer n, and returns [s r] where n = s^2+r and n < (s+1)^2.  In other words, it returns the floor of the square root and the 'remainder'.
For example, (exact-integer-sqrt 15) is [3 6] because 15 = 3^2+6."
  [n]
  (if (or (not (integer? n)) (neg? n))
    (throw (IllegalArgumentException. "exact-integer-sqrt requires a non-negative integer"))
    (let [isqrt (integer-sqrt n),
	  error (- n (* isqrt isqrt))]
      [isqrt error])))

(defmulti #^{:arglists '([n])
	     :doc "Square root, but returns exact number if possible."}
  sqrt class)
(defmethod sqrt ::integer [n]
  (if (neg? n) Double/NaN
      (let [isqrt (integer-sqrt n),
	    error (- n (* isqrt isqrt))]
	(if (zero? error) isqrt
	    (Math/sqrt n)))))

(defmethod sqrt clojure.lang.Ratio [n]
  (if (neg? n) Double/NaN
      (let [numerator (.numerator n),
	    denominator (.denominator n),
	    sqrtnum (sqrt numerator)]
	(if (float? sqrtnum)
	  (Math/sqrt n)
	  (let [sqrtden (sqrt denominator)]
	    (if (float? sqrtnum)
	      (Math/sqrt n)
	      (/ sqrtnum sqrtden)))))))

(defmethod sqrt java.math.BigDecimal [n]
  (if (neg? n) Double/NaN
      (let [frac (rationalize n),
	    sqrtfrac (sqrt frac)]
	(if (ratio? sqrtfrac)
	  (/ (BigDecimal. (.numerator sqrtfrac))
	     (BigDecimal. (.denominator sqrtfrac)))
	  sqrtfrac))))

(defmethod sqrt :default [n]
  (Math/sqrt n))

;; Euler problem
;; What is the smallest number divisible by each of the numbers 1 to 20?
;; http://clojure-euler.wikispaces.com/Problem+005
(defn euler-5-1
  []
  (reduce #(lcm %1 %2) (range 1 21)))

;; Example value:  http://www43.wolframalpha.com/input/?i=sqrt+123456789000000000

(defn run-test
  []
  ;;;;
  (println (*memory-usage*))
  (time (dotimes [_ 1e4]
              (sqrt (new BigDecimal 1234567890777777000000.0))))
  (println (euler-5-1))
  ;; Euler 5
  (println "Euler 5 ")
  (dotimes [x 5]
      (println "i: " (int (Math/pow 10.0 x)))
    (time 
     (dotimes [_ (int (Math/pow 10.0 x))]
         (euler-5-1))))
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