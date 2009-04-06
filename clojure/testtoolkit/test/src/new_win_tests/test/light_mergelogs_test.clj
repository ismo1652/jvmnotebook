
;; Make sure that the 'classes' directory exists
(ns test.light_mergelogs_test
    (:import (junit.framework Assert)
             (java.io ByteArrayInputStream InputStreamReader)
             (java.io LineNumberReader)
             (java.util.regex Pattern))
	(:gen-class
     :methods [[testDriverPatternMatch [] void]]
	 :extends junit.framework.TestCase))

(defn -init [_] ())

(def *test-max-detect-lines* 6)

;;;;;;;;;;;;;;;;;;;;
(defn octane-pattern [s flags] (. Pattern compile s flags))

(defn octane-pattern_ [s] (. Pattern compile s))

(def *test-pattern-log4j*       "^(.*),.* \\[(.*)\\] \\S* .*$")
(def *test-new-pattern-log4j*   (octane-pattern_ *test-pattern-log4j*))       

;; (.*),.* \[(.*)\] \S* .*
(def line-log4j       "2009-03-30 10:43:02,629 DEBUG [sdfsd - XXXXX] (com.x [419]:570) - tes - returning XINF")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def system-log-example "
skldfjsdkjksdk;fjksdf
sdfjkkjfffjjjjfjjfjjj
2009-03-30 10:43:02,629 DEBUG [sdfsd - XXXXX] (com.x [419]:570) - tes - returning XINF
2009-03-30 10:43:02,629 DEBUG [sdfsd - XXXXX] (com.x [419]:570) - tes - returning XINF
")

(defn detect-log-line
  "Determine the type of log file based on this line"
  [line num]
  ;;;;;;;;;;;;
  (let [log4j? (.find (.matcher *test-new-pattern-log4j* line))]
    (cond log4j? :log4j)))

(defn detect-log-file
  "Determine the log file type"
  [stream max-num run-fn]
  ;;;;;;;;;;;;;;;;;;
  (let [reader (LineNumberReader. (InputStreamReader. stream))]
    (loop [line (.readLine reader) 
           line-num (.getLineNumber reader)]
      (when line 
        (run-fn line line-num))
      (if (or (empty? line) (> line-num max-num))
        (run-fn line line-num)
        (recur (.readLine reader)
               (.getLineNumber reader))))))

(defn detect-log-file-str
  "Determine the log file type"
  [str max-num run-fn]
  ;;;;;;;;;;;;;;;;;;
  (let [strm (ByteArrayInputStream. (.getBytes str))]
    (detect-log-file strm max-num run-fn)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn -testDriverPatternMatch [_]
  (Assert/assertTrue (.find (.matcher *test-new-pattern-log4j* line-log4j)))
  (Assert/assertFalse (.find (.matcher *test-new-pattern-log4j* "Sdfskdfsjdlfsjd;"))))
  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

