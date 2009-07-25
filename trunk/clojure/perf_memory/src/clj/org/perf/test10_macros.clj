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

(ns org.perf.test10_macros
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

(defmacro try-catch
  [& body]
  `(try
    ~@body
     (catch Exception e#
            (do (.printStackTrace e#)
                (println e#)))))

(defn test-exception-depth
  []
  ;;;
  (try (do
         (try (do 
                (try (do "Test-5"
                         (Math/pow (Math/pow 10.0 10.0) 2))
                     (catch Exception e (.printStackTrace e))))))
       (catch Exception e (.printStackTrace e))))
       
(defn run-test
  []
  ;;;
  (try-catch (try-catch (println "Test")))
  (println (macroexpand 
            `(try-catch (try-catch (try-catch (try-catch (println "Test-2")))))))
  (println "Test Exception and Macros")
  (time (dotimes [_ 1e7]
             (try-catch (try-catch (try-catch (try-catch (do "Test-2")))))))
  (time (dotimes [_ 1e7]
            (do "Test-2")))
  (time (dotimes [_ 1e7]
            (try (do "Test-2"
                     (Math/pow (Math/pow 10.0 10.0) 2))
                 (catch Exception e (.printStackTrace e)))))
  (println "Higher Stack Depth")
  (time (dotimes [_ 1e7]
            (test-exception-depth))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
(defn main [& args]
  (try (run-test)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script