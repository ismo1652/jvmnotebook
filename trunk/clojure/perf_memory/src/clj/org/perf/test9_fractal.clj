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

(ns org.perf.test9_fractal
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

;; http://www.mail-archive.com/felix-language@lists.sourceforge.net/msg01977.html
;; http://groups.google.com/group/comp.lang.functional/browse_frm/thread/99b8230c078d9b44


(def runs 1)
;; Need to change max iterations
;; to match the java version
;;(def max_iterations 99888)
(def max_iterations 2200)

(defn iter [ci cr]
  (let [max_iter (int max_iterations)
        ci (double ci)
        cr (double cr)]
    (loop [zi (double ci) zr (double cr) i (int 1)]
      (if (<= i max_iter)
        (let [zr2 (* zr zr)   zi2 (* zi zi)]
          (if (<= (+ zr2 zi2) (double 4.0))
            (recur (+ (* (* zr zi) (double 2.0)) ci)
                   (+ (- zr2 zi2) cr)
                   (inc i))
                  i))
        0))))

;; only replaced 'print' and 'do'

(defn mand [n]
  (doseq [y (range -39 39)]
    (when (= 1 n) (do "\n"))
    (doseq [x (range -39 39)]
      (let [i (iter (/ x 40.0) (- (/ y 40.0) 0.5))]
        (when (= 1 n) (do (if (= 0 i) "*" " ")))))))

(defn time-mand []
  (time
   (doseq [i (range 1 (inc runs))]
     (mand i))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
(defn main [& args]
  (try (time-mand)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script