;;;
;;; Simple http behavior test
;;; With clojure
;;;
;;; Import the http libraries
;;;

(import '(java.net HttpURLConnection))
(import '(org.spirit.loadtest LoadTestManager))


(def run-http-test (fn [] 
	(prn "Running")
	;; Call the static connect URL method 
	(let [x 
		(. LoadTestManager 
			(connectURL "http://localhost:9080/testwebapp/index.jsp" :f))]
		(prn (aget x 1)))
	(prn "Done")))

(time (run-http-test))
