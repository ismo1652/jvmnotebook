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


(ns org.perf.test12_vars
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

(defn large-object-create
  []
  ;;;;;;;
  ;; Random use of 'let' and large object create test
  (let [func (fn []
                 (let [a (org.node.perf.bean.LargeObject.)]
                   (let [b (org.node.perf.bean.LargeObject.)]
                     (let [c (org.node.perf.bean.LargeObject.)]
                       (let [d (org.node.perf.bean.LargeObject.)]
                         (let [e (org.node.perf.bean.LargeObject.)]
                           (let [f (org.node.perf.bean.LargeObject.)]
                             (let [g (org.node.perf.bean.LargeObject.)]
                               (let [h (org.node.perf.bean.LargeObject.)]
                                 (let [i (org.node.perf.bean.LargeObject.)]
                                   (let [j (org.node.perf.bean.LargeObject.)]
                                     (str (.toString a)
                                          (.toString b)
                                          (.toString c)
                                          (.toString d)
                                          (.toString e)
                                          (.toString f)
                                          (.toString g)
                                          (.toString h)
                                          (.toString i)
                                          (.toString j)))))))))))))]
    (func)))


(defn med-object-create
  []
  ;;;;;;;
  ;; Random use of 'let' and large object create test
  (let [func (fn []
                 (let [a (org.node.perf.bean.MediumObject.)]
                   (let [b (org.node.perf.bean.MediumObject.)]
                     (let [c (org.node.perf.bean.MediumObject.)]
                       (let [d (org.node.perf.bean.MediumObject.)]
                         (let [e (org.node.perf.bean.MediumObject.)]
                           (let [f (org.node.perf.bean.MediumObject.)]
                             (let [g (org.node.perf.bean.MediumObject.)]
                               (let [h (org.node.perf.bean.MediumObject.)]
                                 (let [i (org.node.perf.bean.MediumObject.)]
                                   (let [j (org.node.perf.bean.MediumObject.)]
                                     (str (.toString a)
                                          (.toString b)
                                          (.toString c)
                                          (.toString d)
                                          (.toString e)
                                          (.toString f)
                                          (.toString g)
                                          (.toString h)
                                          (.toString i)
                                          (.toString j)))))))))))))]
    (func)))


(defn sm-object-create
  []
  ;;;;;;;
  ;; Random use of 'let' and large object create test
  (let [func (fn []
                 (let [a (org.node.perf.bean.SmallObject.)]
                   (let [b (org.node.perf.bean.SmallObject.)]
                     (let [c (org.node.perf.bean.SmallObject.)]
                       (let [d (org.node.perf.bean.SmallObject.)]
                         (let [e (org.node.perf.bean.SmallObject.)]
                           (let [f (org.node.perf.bean.SmallObject.)]
                             (let [g (org.node.perf.bean.SmallObject.)]
                               (let [h (org.node.perf.bean.SmallObject.)]
                                 (let [i (org.node.perf.bean.SmallObject.)]
                                   (let [j (org.node.perf.bean.SmallObject.)]
                                     (str (.toString a)
                                          (.toString b)
                                          (.toString c)
                                          (.toString d)
                                          (.toString e)
                                          (.toString f)
                                          (.toString g)
                                          (.toString h)
                                          (.toString i)
                                          (.toString j)))))))))))))]
    (func)))

(defn run-test-3
  []
  ;;;
  (println "Running Test [] " *current-date*)
  (println (*memory-usage*))
  (time (let [a (for [_ (range 1e5)] (random-string 20))]
          (println (first a) "|" (count a ))))
  (time (let [a (for [_ (range 2e3)] (org.node.perf.bean.TinyObject.))]
          (println (first a) "|" (count a ))))
  (println (*memory-usage*)))

(defn run-test-4
  []
  ;;;
  (println "Running Test [] " *current-date*)
  (println (*memory-usage*))

  (time (let [a (for [_ (range 1e5)] (random-string 20))]
          (println (first a) "|" (count a ))))
  (println "Using array list")
  (time (let [b (let [a (java.util.ArrayList. 100)]
                  (dotimes [_ 1e5]
                      (.add a (random-string 20)))
                  a)]
          (println (first b) "|" (count b)))))
  
(defn run-test-2
  []
  ;;;
  (println "Running Test [] " *current-date*)
  (println (*memory-usage*))
  (time (let [a (for [_ (range 1e2)] (random-string 10))]
          (println (first a) "|" (count a ))))
  (time (let [a (for [_ (range 1e2)] (org.node.perf.bean.SmallObject.))]
          (println (first a) "|" (count a ))))
  (time (let [a (for [_ (range 1e2)] (org.node.perf.bean.MediumObject.))]
          (println (first a) "|" (count a ))))
  (time (let [a (for [_ (range 1e2)] (org.node.perf.bean.LargeObject.))]
          (println (first a) "|" (count a ))))
  (println (*memory-usage*)))

(defn run-test
  []
  ;;;;
  (println "Running Test [] " *current-date*)
  (println (*memory-usage*))
  ;; We have to take care, the objects are large
  (time (dotimes [_ 4]
            ;; Sleep 100 ms, wait for GC
            (Thread/sleep 100)
          (dotimes [_ 14]
              (large-object-create))))
  (println (*memory-usage*))
  ;; We have to take care, the objects are large
  (time (dotimes [_ 4]
            ;; Sleep 100 ms, wait for GC
            (Thread/sleep 40)
          (dotimes [_ 10]
              (med-object-create))))
  (println (*memory-usage*))
  ;; We have to take care, the objects are large
  (time (dotimes [_ 4]
            ;; Sleep 100 ms, wait for GC
            (Thread/sleep 40)
          (dotimes [_ 30]      
              (sm-object-create))))
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
  (try (run-test-4)
       (run-cool-down)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script