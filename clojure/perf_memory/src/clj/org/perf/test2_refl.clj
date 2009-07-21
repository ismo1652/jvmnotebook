;;
;; Running with Clojure 1.0 under Windows XP
;; As of 7/15/2009
;; baseline_hello.clj
;; 
;; Some examples from gnuvince:
;; http://gnuvince.wordpress.com/2009/05/11/clojure-performance-tips/
;; And Sergio
;; http://devlog.bigmonachus.org/2009/03/performance-tips-for-clojure.html
;;
;; Test Output (as of 7/15/2009):
;; time ./test2.bat
;; -----------------

;; -----------------

(ns org.perf.test2_refl
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)))

(defn str-split-refl [s regex]
      (vec (. s split regex)))

(defn str-split-fast [#^String s regex]
      (vec (. s split regex)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn my-str-join
  "Returns a string of all elements in 'sequence', separated by
  'separator'.  Like Perl's 'join'. From clojure_contrib_str: "
  [separator sequence]
  ;;;;;;;;;;;;;;;;;;;;;;
  (apply str (interpose separator sequence)))

(defn build-big-str
  []
  ;;;
  (let [str-size (* 1 1024)
        n        1024
        buf-1 (StringBuffer. (* str-size n))
        buf-2 (StringBuffer.)]    
  (dotimes [_ n]
      (let [b (random-string str-size)]
        (.append buf-1 (str b "|"))))
  (.toString buf-1)))
        
(defn run-test
  " Application Entry Point"
  []
  ;;;;
  (println "Running Test [test string split and other str utils] " *current-date*)
  (println (*memory-usage*))
  (let [data (build-big-str)]
    (println "Number of chars in str : " (count data)))
  (println (*memory-usage*))
  (println "Done"))

(defn run-cool-down
  "Allow a little time to see if JVM garbage collects.
 This may not have any effect"
  []
  ;;;
  (println (*memory-usage*))
  (Thread/sleep 100)
  (println (*memory-usage*))
  (Thread/sleep 80))
 
(defn main [& args]
  (try (run-test)
       (run-cool-down)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script