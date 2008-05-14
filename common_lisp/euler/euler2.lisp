;;**********************************************
;; Author: Berlin Brown <berlin dot brown @ gmail.com>
;; Overview: Euler Example Number Two
;; Target Environment: Clisp/Sbcl
;; Date: 5/13/2008
;; Euler Problem (2):
;; --------------
;; Each new term in the Fibonacci sequence is generated 
;; by adding the previous two terms. By starting with 
;; 1 and 2, the first 10 terms will be:
;;
;; 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
;; 
;; Find the sum of all the even-valued terms in the 
;; sequence which do not exceed four million
;;
;; References:
;; [1] http://www.lispworks.com/documentation/HyperSpec/Front/X_Master.htm
;;
;;**********************************************

(defun sum-euler ()
  (+ (loop for x from 0 to 10 by 3 sum x)))

(defun fib (n)
  "Simple Generate Fibonacci Number"
  (if (< n 2)
    n
    (+ (fib (- n 1)) 
	   (fib (- n 2)))))

(defun euler2 ()
  (let ((e (sum-euler)))
	(format t "-->~a~%" (fib 12))
	(format t "sum euler: ~a~%" (sum-euler))))

(defun main ()
  (format t "INFO: Running Project Euler~%") 
  (euler2)
  (format t "INFO: Done~%"))

(main)

;; End of File

