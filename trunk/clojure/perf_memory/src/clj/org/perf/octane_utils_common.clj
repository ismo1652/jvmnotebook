
(ns org.perf.octane_utils_common
	(:import (java.util Date)
			 (java.nio CharBuffer)
			 (java.text SimpleDateFormat)
			 (java.lang Runtime)
			 (java.text SimpleDateFormat)
             (java.nio.channels FileChannel FileChannel$MapMode)
			 (java.io InputStreamReader FileInputStream BufferedReader File FilenameFilter)
			 (java.util.regex Pattern)
			 (java.nio CharBuffer MappedByteBuffer)
			 (java.nio.channels FileChannel)
			 (java.nio.charset Charset)
			 (java.nio.charset CharsetDecoder)
			 (java.util.regex Matcher)
			 (java.util.regex Pattern)
			 (java.util.regex PatternSyntaxException)
			 (java.nio ByteBuffer)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn prev-exit [] (. System (exit 0)))

(defn exit [] (System/exit 1))

(defn clear-buffer [buf] (.setLength #^StringBuffer buf 0))

(defn length [s] (count s))

(defn date-time [] (str (new java.util.Date)))

(defn date-timel [l] (str (new java.util.Date (long l))))

(defn file-exists? [path] (let [file (File. #^String path)] (. file exists)))

(defn octane-pattern [s flags] (. Pattern compile s flags))

(defn octane-pattern_ [s] (. Pattern compile s))

(defn octane-trim [s] (when s (.trim #^String s)))

(defn octane-safe-pattern [s flags] 
  (when s    
    (try (. Pattern compile s flags)
         (catch Exception e nil))))         

(defn floor [d] (. Math floor d))

(defn println-obj [o] (println o) o)

(defn parse-long [str]
  (try (Long/parseLong str) 
       (catch NumberFormatException nfe 0)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def  *megabytes*      (* 1024.0 1024.0))
(def  *java-runtime*   (. Runtime getRuntime))

(defn *free-memory-b*  [] (. #^Runtime *java-runtime* freeMemory))
(defn *total-memory-b* [] (. #^Runtime *java-runtime* totalMemory))
(defn *max-memory-b*   [] (. #^Runtime *java-runtime* maxMemory))
(defn *used-memory-b*  [] (- (*total-memory-b*) (*free-memory-b*)))

;; Note: used memory == total memory - free memory
(defn *free-memory-m*  [] (int (floor (/ (*free-memory-b*)  *megabytes*))))
(defn *total-memory-m* [] (int (floor (/ (*total-memory-b*) *megabytes*))))
(defn *max-memory-m*   [] (int (floor (/ (*max-memory-b*)   *megabytes*))))
(defn *used-memory-m*  [] (int (floor (/ (*used-memory-b*)  *megabytes*))))

(defn *file-size-m*    [file-size] (/ file-size  *megabytes*))

(defn *memory-usage* []
  (str "(used:" (*used-memory-m*) "M/" (*free-memory-m*) "M [" (*total-memory-m*) "M," (*max-memory-m*) "M ])"))

;; Long timestamp for 2072, for min/max comparisons
(def *timestamp-long-max* 3239375951040)

(def  *dir-date-format*         (new SimpleDateFormat "MM-dd-yyyy hh:mm.ss a"))
(def  *simple-date-format*      (new SimpleDateFormat "MM/dd/yyyy"))
(def  *simple-date-format-t*    (new SimpleDateFormat "MM/dd/yyyy HH:mm:ss"))
(def  *simple-date-format-pack* (new SimpleDateFormat "MMddyyyy"))
(def  *current-date*            (.format *simple-date-format* (new Date)))

;; For Regex Patterns, Flags may include CASE_INSENSITIVE, MULTILINE, DOTALL, UNICODE_CASE, and CANON_EQ
;; Establish the charset and decoder, used with grep functionality.
(def *util-regex-line-pattern* (. Pattern compile ".*\\r?\\n"))
(def *util-iso-8859-charset*   (. Charset forName "ISO-8859-15"))
(def *util-charset-decoder*    (. *util-iso-8859-charset* newDecoder))

(defn util-get-char-buf-decoder
  "Get java nio character buffer from decoder"
  [doc]
  (let [dummy1 (. *util-charset-decoder* reset)
			   ;; BugFix/Hack, adding newline to end of document
			   char-buf (. *util-charset-decoder* decode 
						   (. ByteBuffer wrap (. (str doc \newline) getBytes)))]
    char-buf))

;; Example sysout date format = '2/12/09 13:11:12:784 EST'
(def  *sysout-date-format* (new SimpleDateFormat "MM/dd/yy HH:mm:ss:SSS z"))
(defn get-dir-date [l]  (.format #^SimpleDateFormat *dir-date-format* #^java.util.Date (java.util.Date. (long l))))

(defmacro when-try_ [body]
  `(try ~body
        (catch Exception ~'e
               (println "ERR <when-try> " ~'e)
               nil)))

(defmacro proc-time [expr]
  `(let [start# (. System (nanoTime))
                ret#     ~expr
                res-t#   (/ (double (- (. System (nanoTime)) start#)) 1000000.0)
                str-res# (str "Elapsed time: " res-t# " msecs")]
     {:return ret# :time-text str-res# :timed res-t#}))

(defn pprint-list
  "Simple pretty print a list"
  [lst]
  ;;;;;;;;;;
  (doseq [x lst]
	  (let []
		(println "<Begin Element>")
		(println x)
		(println "<End Element>" \newline))))


(defn parse-timestamp-date
  "Return the long representation for the timestamp"
  [str-date]
  ;;;;;;;;;;;;;;;  
  (let [sdf (new SimpleDateFormat "MMM d HH:mm:ss yyyy")]
	(try (. (. sdf parse str-date) getTime)
		 (catch Exception e (println "Warn: invalid date format =>" str-date)
				str-date))))

(defn parse-basic-date
  "Return the long representation for the timestamp"
  [date-format-obj str-date]
  ;;;;;;;;;;;;;;;
  (try (. (. date-format-obj parse str-date) getTime)
       (catch Exception e (println "Warn: invalid date format => " str-date)
              str-date)))

(defn parse-sysout-date
  "Return the long representation for system out timestamp"
  [str-date]
  ;;;;;;;;;;;
  (when-try_  (.getTime (.parse *sysout-date-format* str-date))))

(defn flatten [x]
  (let [s? #(instance? clojure.lang.Sequential %)] 
	(filter (complement s?) (tree-seq s? seq x))))

(defn keyword-frequency [col]
  (reduce (fn [counts x] (merge-with + counts {x 1})) {} col))

(defn clean-split
 "Split based on 'string-split', then trim each element and remove empty
 members and return that sequence"
 [str str-split]
 ;;;;;;;;;;;;;;;;;
 (remove empty? (map #(.trim %) (.split str str-split))))

(defn octane-new-by-name
  "Constructs a Java object whose class is specified by a String."
  [class-name & args]
  (clojure.lang.Reflector/invokeConstructor
   (clojure.lang.RT/classForName class-name)
   (into-array Object args)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn random-string_
  "Generate a random string of characters"
  [#^java.util.Random random n]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (let [buf (StringBuffer. (+ n 16))]
    (dotimes [_ n]
        (.append buf (char (+ 97 (.nextInt random 26)))))
    (.toString buf)))

(defn random-string
  "Generate a random string of characters"
  [n]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (random-string_ (java.util.Random.) n))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;