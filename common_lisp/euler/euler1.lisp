;;**********************************************
;; Author: Berlin Brown <berlin dot brown @ gmail.com>
;; Overview: Euler Example Number One
;; Target Environment: Clisp/Sbcl
;; Date: 5/13/2008
;; Euler Problem:
;; --------------
;; If we list all the natural numbers below 10 
;; that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
;; The sum of these multiples is 23.
;;
;; Find the sum of all the multiples of 3 or 5 below 1000.
;;
;; References:
;; [1] http://www.lispworks.com/documentation/HyperSpec/Front/X_Master.htm
;;**********************************************

(defun accum (val max lst)
  (if (<= val max)
    (accum (+ 1 val) max 
           (cons val lst))
    lst))
(defun multiple-three-five (lst)
  (let ((new-lst '()))
    (dolist (val lst new-lst)
      (when (and
             (> val 0)
             (or (= (mod val 3) 0)               
                 (= (mod val 5) 0)))
          (push val new-lst)))))
  
(defun euler1 ()
  (let* ((acc-lst (accum 0 9 ()))
         (new-lst (multiple-three-five acc-lst)))
    (format t "Sum=~a~%" (+ new-lst))))
  
(defun main ()
  (format t "INFO: Running Project Euler~%")
  (euler1)
  (format t "INFO: Done~%"))

(main)

;; End of File

