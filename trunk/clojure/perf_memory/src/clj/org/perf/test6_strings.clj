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


(ns org.perf.test6_strings
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

;; The following string functions are from clojure contrub:
;;

(defn re-partition
  "Splits the string into a lazy sequence of substrings, alternating
  between substrings that match the patthern and the substrings
  between the matches.  The sequence always starts with the substring
  before the first match, or an empty string if the beginning of the
  string matches.

  For example: (re-partition #\"[a-z]+\" \"abc123def\")

  Returns: (\"\" \"abc\" \"123\" \"def\")"
  [#^Pattern re string]
  (let [m (re-matcher re string)]
    ((fn step [prevend]
       (lazy-seq
        (if (.find m)
          (cons (.subSequence string prevend (.start m))
                (cons (re-groups m)
                      (step (+ (.start m) (count (.group m))))))
          (when (< prevend (.length string))
            (list (.subSequence string prevend (.length string)))))))
     0)))

(defn re-gsub 
  "Replaces all instances of 'pattern' in 'string' with
  'replacement'.  Like Ruby's 'String#gsub'.
  
  If (ifn? replacment) is true, the replacement is called with the
  match.
  "
  [#^java.util.regex.Pattern regex replacement #^String string]
  (if (ifn? replacement)
    (let [parts (vec (re-partition regex string))]
      (apply str
             (reduce (fn [parts match-idx]
                       (update-in parts [match-idx] replacement))
                     parts (range 1 (count parts) 2))))
    (.. regex (matcher string) (replaceAll replacement))))

(defn re-sub
  "Replaces the first instance of 'pattern' in 'string' with
  'replacement'.  Like Ruby's 'String#sub'.
  
  If (ifn? replacement) is true, the replacement is called with
  the match.
  "
  [#^Pattern regex replacement #^String string]
  (if (ifn? replacement)
    (let [m (re-matcher regex string)]
      (if (.find m)
        (str (.subSequence string 0 (.start m))
             (replacement (re-groups m))
             (.subSequence string (.end m) (.length string)))
        string))
    (.. regex (matcher string) (replaceFirst replacement))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn str-join
  "Returns a string of all elements in 'sequence', separated by
  'separator'.  Like Perl's 'join'."
  [separator sequence]
  (apply str (interpose separator sequence)))

(defn chop
  "Removes the last character of string."
  [s]
  (subs s 0 (dec (count s))))

(defn chomp
  "Removes all trailing newline \\n or return \\r characters from
  string.  Note: String.trim() is similar and faster."
  [s]
  (re-sub #"[\r\n]+$" "" s))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn build-split-str
  "Build a string that can separated by a '|' char"
  [sz n]
  ;;;
  (let [str-size (* 1 sz)
        buf-1 (StringBuffer. (* str-size n))]
    (dotimes [_ n]
        (let [b (random-string str-size)]
          (.append buf-1 (str b "|"))))
    (.append buf-1 "[END]")
    (.toString buf-1)))

(defn test-str-join
  "Test the clojure contrib join.  This join uses apply, interpose"
  []
  ;;;
  ;; 100x100 character string
  (let [a (build-split-str 100 100)
        b (.split a "\\|")]    
    (str-join "|" b)))

(defn test-str-join-2
  "Test the clojure contrib join.  This join uses apply, interpose"
  []
  ;;;
  ;; smaller data set
  (let [b ["my" "dog" "has" "some" "problems"]]
    (str-join "|" b)))

(defn test-gsub-1
  []
  ;;;
  (re-gsub #"XXX" "YYY" "ABC 123 UUU XXX END END"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn run-test
  "First string test.  Note: this test is used for the output of test3.txt"
  []
  ;;;;
  (println "Running Test [String operations 'join'] " *current-date*)
  (println (*memory-usage*))
  (dotimes [x 10]
      (println "i: " (* (+ 1 x) 10))
    (time 
     (dotimes [_ (* (+ 1 x) 10)]
         (test-str-join))))
  (println (*memory-usage*))
  (println "Smaller Test")
  (dotimes [x 6]
      (println "i: " (int (Math/pow 10.0 x)))
    (time 
     (dotimes [_ (int (Math/pow 10.0 x))]
         (test-str-join-2))))
  (println (*memory-usage*))

  ;; Test the gsub call
  (println "Test gsub")
  (dotimes [x 7]
      (println "i: " (int (Math/pow 10.0 x)))
    (time 
     (dotimes [_ (int (Math/pow 10.0 x))]
         (test-gsub-1))))
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