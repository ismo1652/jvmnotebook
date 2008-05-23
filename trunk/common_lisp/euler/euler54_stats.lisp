;;**********************************************
;; Author: Berlin Brown <berlin dot brown @ gmail.com>
;; Overview: Euler Example Number 54 (neophyte version)
;; Target Environment: Common Lisp -> Clisp/Sbcl 
;; Date: 5/19/2008
;; --------------
;; Helper module for collecting game statistics.
;;
;; See:
;; http://projecteuler.net/index.php?section=problems&id=54
;;
;; References:
;; [1] http://www.lispworks.com/documentation/HyperSpec/Front/X_Master.htm
;; [2] http://www.unixuser.org/~euske/doc/cl/loop.html
;; [4] http://cl-cookbook.sourceforge.net/strings.html
;;**********************************************
			 
(defun main ()
  (format t "INFO: Running Project Euler~%")
  ;;(print (card-value #\3))
  (let* ((hand "5H 5C 6S 7S KD")
		 (pairs (find-pairs (get-hands hand)))
		 (pairs-lst (hash-table->list pairs)))
	(print (quicksort pairs-lst)))
  (format t "~%INFO: Done~%"))
(main)

;; End of Script