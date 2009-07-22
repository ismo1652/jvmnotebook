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

(ns org.perf.test3_strings
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)))

(defn str-split-refl [s regex]
      (vec (. s split regex)))

(defn str-split-fast [#^String s regex]
      (vec (. s split regex)))

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

(defn build-split-str
  [sz n]
  ;;;
  (let [str-size (* 1 sz)
        buf-1 (StringBuffer. (* str-size n))]
    (dotimes [_ n]
        (let [b (random-string str-size)]
          (.append buf-1 (str b "|"))))
    (.append buf-1 "[END]")
    (.toString buf-1)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn build-test-sort-list-small
  "See: 'for' 'List comprehension. Takes a vector of one or more 
 binding-form/collection-expr pairs, each followed by zero or more modifiers, 
 and yields a lazy sequence of evaluations of expr.'"
  [n]
  ;;;;;
  (for [x (range n)]
    (random-string 100)))

(defn build-test-sort-list-big
  "See: 'for' 'List comprehension. Takes a vector of one or more 
 binding-form/collection-expr pairs, each followed by zero or more modifiers, 
 and yields a lazy sequence of evaluations of expr.'"
  [n]
  ;;;;;
  ;; Build a collection of strings
  ;; each string will have 100k of data
  (for [x (range n)]
    (random-string 100000)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn with-loop-test-str-put-1
  "Test the hash/key 'put'.  Use a tiny data value"
  [n]
  ;;;
  (loop [data {}
         i    0]
    (if (< i n)
      ;; Perform operation:
      ;; (println "debug: " data)
      ;; Associate the keyword with the some 'data value'
      (recur (assoc data (keyword (random-string 80)) "test-tiny-data")
             (+ i 1))
      data)))

(defn with-loop-test-str-put-2
  "Test the hash/key 'put'.  Use a medium size data value and 
 medium size key"
  [n]
  ;;;
  (loop [data {}
         i    0]
    (if (< i n)
      ;; Perform operation:
      ;; (println "debug: " data)
      ;; Associate the keyword with the some 'data value'
      (recur (assoc data (keyword (random-string 500)) (random-string 500))
             (+ i 1))
      data)))

(defn with-loop-test-str-put-3
  "Test the hash/key 'put'.  Use a large size data value and 
large size key.  Est 10k as the key"
  [n]
  ;;;
  (loop [data {}
         i    0]
    (if (< i n)
      ;; Perform operation:
      ;; (println "debug: " data)
      ;; Associate the keyword with the some 'data value'
      (recur (assoc data (keyword (random-string 10000)) (random-string 10000))
             (+ i 1))
      data)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn test-split-refl
  "Test the java split call"
  [n sz arr-sz]
  ;;;
  (let [str (build-split-str sz arr-sz)]
    (dotimes [_ n]
        (str-split-refl str "|"))))

(defn test-split-fast
  "Test the java split call"
  [n sz arr-sz]
  ;;;
  (let [str (build-split-str sz arr-sz)]
    (dotimes [_ n]
        (str-split-fast str "|"))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn run-test-4
  "Fourth string/map test.  Note: this test is used for the output of test3d.txt"
  []
  (println "Running Test [test string split and other str utils] " *current-date*)
  (println "Note: mostly a test of 'map'")
  (time (dotimes [_ 1e6]
            (map (fn [x] (.toUpperCase x)) (.split "Dasher Dancer Prancer" " "))))
  (println "Similar call using 'for'")
  (time (dotimes [_ 1e6]
            (for [x (.split "Dasher Dancer Prancer" " ")] (.toUpperCase x))))
  (println "Similar call using 'for'[2]")
  ;; See if there are any differences with this 'let' expression
  (time (dotimes [_ 1e6]
            (for [x (.split "Dasher Dancer Prancer" " ")] 
              (let [func (fn [y] (.toUpperCase x))]
                (func x))))))

(defn run-test-3
  "Third string test.  Note: this test is used for the output of test3c.txt"
  []
  ;;;;
  (println "Running Test [test string split and other str utils] " *current-date*)
  (println (*memory-usage*))
  ;; Test the reflection split, 100 iterations (str 100, array to split == 100)
  (time (test-split-refl 1e2 100 100))
  ;; Test the reflection split, 1000 iterations (str 100, array to split == 100)
  (time (test-split-refl 1e3 100 100))
  ;; Test the reflection split, 2000 iterations (str 100, array to split == 100)
  (time (test-split-refl 2000 100 100))
  ;;;;;;;;;;;;
  (println "Now run without the reflection call !")
  
  ;; Test the reflection split, 100 iterations (str 100, array to split == 100)
  (time (test-split-fast 1e2 100 100))
  ;; Test the reflection split, 1000 iterations (str 100, array to split == 100)
  (time (test-split-fast 1e3 100 100))
  ;; Test the reflection split, 2000 iterations (str 100, array to split == 100)
  (time (test-split-fast 2000 100 100))
  
  (println (*memory-usage*))
  (println "Done"))

(defn run-test-2
  "Second string test.  Note: this test is used for the output of test3b.txt"
  []
  ;;;;
  (println "Running Test [test string split and other str utils] " *current-date*)
  (println (*memory-usage*))
  (time (let [data (with-loop-test-str-put-1 1e4)]
          (println "Size of hash : " (count data))))
  (println (*memory-usage*))
  (time (let [data (with-loop-test-str-put-2 1e4)]
          (println "Size of hash : " (count data))))
  (println (*memory-usage*))
  (time (let [data (with-loop-test-str-put-3 1e2)]
          (println "Size of hash : " (count data))))
  (println (*memory-usage*))
  (println "Done"))
       
(defn run-test
  "First string test.  Note: this test is used for the output of test3.txt"
  []
  ;;;;
  (println "Running Test [test string split and other str utils] " *current-date*)
  (println (*memory-usage*))
  ;; 1. Build a list
  ;; 2. Print the size of the list
  ;; 3. Then sort the list and then print the first element of the list.
  ;; Use the 'small list'
  (time (let [lst (build-test-sort-list-small 1e4)]
          (println (count lst))
          (println (first lst))
          (let [z (sort lst)]
            (println (count z))
            (println (first z)))))
  ;; Now, perform the same 'for' test but use 'large string data'
  (println (*memory-usage*))
  (time (let [lst (build-test-sort-list-big 100)]
          (println (count lst))
          ;; To avoid printing the large string, just
          ;; print the count
          (println (count (first lst)))
          (let [z (sort lst)]
            (println (count z))
            ;; To avoid printing the large string, just
            ;; print the count
            (println (count (first z))))))
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
  (try (run-test-4)
       (run-cool-down)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script