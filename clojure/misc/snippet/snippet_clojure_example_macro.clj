;; Example macro clojure
(defmacro when-try [body]
  `(try ~body
		(catch Exception ~'e
			   (println "ERR <when-try> " ~'e)
			   (history-add-textln (str "ERR <when-try> " ~'e *newline*))
			   nil)))