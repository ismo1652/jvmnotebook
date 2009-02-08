;; Example macro clojure
(defmacro when-try [body]
  `(try ~body
		(catch Exception ~'e
			   (println "ERR <when-try> " ~'e)
			   (history-add-textln (str "ERR <when-try> " ~'e *newline*))
			   nil)))
--------------

FAQ:
(defmacro async-call [display &  body]  ...in this code, what is the purpose of the '*&'
it binds body to a stream of the remaining arguments
async-call receives one argument, bound to display, and then N arguments in a list, bound to body

Define the required parameter first, yes, and then you can have a & 
before the last parameter to gobble the rest into a seq

(defmacro m [& a b]
 `(println ~a))

(defn main []
        (println "Running")
        (m 1 2)
        (println (macroexpand `(m 1 2)))

        (println "Done"))

(try (main) (catch Exception e (println e)))

(. System exit 1)
