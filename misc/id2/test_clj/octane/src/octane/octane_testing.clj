;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... Brown <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-ns 'octane)

(import '(java.io BufferedOutputStream PrintWriter))

(defn print-test-case [test-name]
  (. MessageFormat format *simple-testcase* (to-array [test-name])))

(defn main-generate-testgen []
  ;; Auto generate the test cases for JUnit
  (println "<INFO main-generate-test gen main> " (date-time))
  (try (let [filename (str "test" *name-separator* "_work" *name-separator* "OctaneTestGen.clj")
             fos      (new FileOutputStream filename)
             bos      (new BufferedOutputStream fos)
             pw       (new PrintWriter bos)]
         ;; First, write the header
         (. pw print (str *header-testgen* *newline*))         
         ;;(doseq [pub-func-arr (ns-publics 'octane)] 
         ;;    (let [pub-func (first pub-func-arr)]
         ;;     (. pw print (print-test-case pub-func))))
         (. pw println *footer-testcase*)
         (. pw flush)
         (doto fos (. flush) (. close)))
       (catch Exception e
              (. e printStackTrace))
       (finally
        (println "<INFO main-generate-testgen> : completed. " (date-time))
        (exit))))

(defn main-generate-test-cases []
  ;; Auto generate the test cases for JUnit
  (println "<INFO main-generate-test-cases> : Code generating test cases. " (date-time))
  (try (let [filename (str "test" *name-separator* "_work" *name-separator* "OctaneFullTest.clj")
             fos      (new FileOutputStream filename)
             bos      (new BufferedOutputStream fos)
             pw       (new PrintWriter bos)]
         ;; First, write the header
         (. pw print (str *header-testcase* *newline*))
         (doseq [pub-func-arr (ns-publics 'octane)] 
             (let [pub-func (first pub-func-arr)]
               (. pw print (print-test-case pub-func))))
         (. pw println *footer-testcase*)
         (. pw flush)
         (doto fos (. flush) (. close)))
       (catch Exception e
              (. e printStackTrace))
       (finally
        (println "<INFO main-generate-test-cases> : completed. " (date-time))
        (exit))))
          
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;