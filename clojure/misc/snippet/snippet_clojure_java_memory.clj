;; Find JVM memory with clojure
(def  *megabytes*      (* 1024.0 1024.0))
(def  *java-runtime*   (. Runtime getRuntime))

(defn *free-memory-b*  [] (. *java-runtime* freeMemory))
(defn *total-memory-b* [] (. *java-runtime* totalMemory))
(defn *max-memory-b*   [] (. *java-runtime* maxMemory))
(defn *used-memory-b*  [] (- (*total-memory-b*) (*free-memory-b*)))

;; Note: used memory == total memory - free memory
(defn *free-memory-m*  [] (int (floor (/ (*free-memory-b*)  *megabytes*))))
(defn *total-memory-m* [] (int (floor (/ (*total-memory-b*) *megabytes*))))
(defn *max-memory-m*   [] (int (floor (/ (*max-memory-b*)   *megabytes*))))
(defn *used-memory-m*  [] (int (floor (/ (*used-memory-b*)  *megabytes*))))

(defn *memory-usage* []
  (str "(" (*used-memory-m*) "M/" 
	   (*free-memory-m*) "M [" (*total-memory-m*) "M," (*max-memory-m*) "M ])"))

(def  *dir-date-format* (new SimpleDateFormat "MM-dd-yyyy hh:mm.ss a"))
(defn get-dir-date [l]  (. *dir-date-format* format (new Date l)))
