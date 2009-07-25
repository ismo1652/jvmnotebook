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

(ns org.perf.test13_wide_find
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

;; http://clj-me.blogspot.com/2008/06/widefinder-2-in-clojure-naive-port-from.html
;; Christophe Grand
;; Source for widefinder from Mr Grand
;;
;; Originally based on Ruby
;; http://wikis.sun.com/display/WideFinder/The+Benchmark#TheBenchmark-WF2Benchmark
;;
(def u-hits)
(def u-bytes)
(def s404s)
(def clients)
(def refs)

(defmacro acc [h k v]
  `(set! ~h (assoc ~h ~k (+ (get ~h ~k 0) ~v))))

(defn top [n h]
  (take n (sort #(- (val %2) (val %1)) h)))

(defn record [client u bytes ref]
  (acc u-bytes u bytes)
  (when (re-matches #"^/ongoing/When/\\d\\d\\dx/\\d\\d\\d\\d/\\d\\d/\\d\\d/[^ .]+$" u)
    (acc u-hits u 1)
    (acc clients client 1)
    (when-not (or (= ref "\"-\"") (re-find #"^\"http://www.tbray.org/ongoing/" ref)
                  (acc refs (subs ref 1 (dec (count ref))) 1)))))

;;(defn printf [#^String fmt & args]
;;  (let [f (java.util.Formatter. *out*)]
;;    (.format f (. java.util.Locale ENGLISH) fmt (to-array args))))

(defn report
  ([label hash] (report label hash false))
  ([label hash shrink]
   (println (str "Top " label ":"))
   (let [fmt (if shrink " %9.1fM: %s\n" " %10d: %s\n")]
     (doseq [key val]
         (top 10 hash)
       (let [key (if (< 60 (count key)) (str (subs key 0 60) "...") key)
             val (if shrink (/ val 1024 1024) val)]
         (printf fmt val key))))))

(defn run-wide-finder
  [strm]
  ;;
  (binding [u-hits {} u-bytes {} s404s {} clients {} refs {}]
    (doseq [line (-> strm (java.io.InputStreamReader.)
                     java.io.BufferedReader. line-seq)]
        (let [f (.split line "\\s+")]
          (when (= "\"GET" (get f 5))
            (let [[client u status byt ref] (map #(get f %) [0 6 8 9 10])]
              (cond
               (= "200" status) (record client u (Integer/parseInt byt) ref)
               (= "304" status) (record client u 0 ref)
               (= "404" status) (acc s404s u 1))))))
    (print (count u-hits) "resources," (count s404s) "404s," (count clients) "clients\n\n")))
    
  ;; Not printing the reports but the wide finder code is executed
  ;; (report "URIs by hit" u-hits)))
  ;;(report "URIs by bytes" u-bytes true)
  ;;(report "404s" s404s)
  ;;(report "client addresses" clients)
  ;;(report "referrers" refs)))

(defn run-wide-finder-in
  []
  ;;
  (run-wide-finder (. System in)))

(defn run-wide-finder-file
  []
  ;;
  (let [a (java.io.FileInputStream. "input/o10k.ap")]
    (run-wide-finder a)))

(defn run-test
  []
  ;;;;
  (println "Running Test [] " *current-date*)
  (println (*memory-usage*))
  (dotimes [_ 3]
      (time (run-wide-finder-file)))
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