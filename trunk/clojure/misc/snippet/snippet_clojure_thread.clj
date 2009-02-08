;;
;; Simple Java Runnable thread in clojure
(proxy [Runnable] []
	   (run [] (println "Test")))