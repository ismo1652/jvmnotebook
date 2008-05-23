;;**********************************************
;; Author: Berlin Brown <berlin dot brown @ gmail.com>
;; Overview: Euler Example Number 54 (neophyte version)
;; Target Environment: Common Lisp -> Clisp/Sbcl 
;; Date: 5/19/2008
;; --------------
;;
;; The file, poker.txt, contains one-thousand random 
;; hands dealt to two players. Each line of the file 
;; contains ten cards (separated by a single space): 
;; the first five are player one's cards and the 
;; last five are player two's cards. You can assume 
;; that all hands are valid (no invalid characters or repeated cards), 
;; each player's hand is in no specific order, 
;; and in each hand there is a clear winner.
;; 
;; How many hands does player one win?
;;
;; See:
;; http://projecteuler.net/index.php?section=problems&id=54
;;
;; References:
;; [1] http://www.lispworks.com/documentation/HyperSpec/Front/X_Master.htm
;; [2] http://www.unixuser.org/~euske/doc/cl/loop.html
;; [4] http://cl-cookbook.sourceforge.net/strings.html
;;**********************************************

(defconstant *card-values* "23456789TJQKA")

;; A hand consists of a list tuple (VALUE/SUIT strings)

(defun quicksort (lis)
  "Quicksort algorithm from: http://swisspig.net/r/post/blog-200603301157"
  (if (null lis) 
	  nil
	  (let* ((z (car lis)) (x (second z))
			 (r (cdr lis))
			 (fn (lambda (a) (< (second a) x))))
		(append (quicksort (remove-if-not fn r))
				(list z)
				(quicksort (remove-if fn r))))))

(defun split (string delim)
   "Returns a list of substrings of string
divided by ONE space each.
Note: Two consecutive spaces will be seen as
if there were an empty string between them. E.g. #\Space"
   (loop for i = 0 then (1+ j)
          as j = (position delim string :start i)
          collect (subseq string i j)
          while j))

(defun hash-table->list (my-hash)
  "Convert the hashtable to a list ((key val) (key val))"
  (loop for key being the hash-keys of my-hash
	 using (hash-value value)
	 collect (list key value)))

(defun card-value (c)
  "Look up the card value based on the index in the string"
  (1+ (position c *card-values* :test #'equal)))

(defun higher-hand (player1 player2)
  "Determine which player has the higher hand")

(defun get-value (hand)
  "Get the value of a hand"
  (first hand))

(defun get-suit (hand)
  "Get the suit of a hand"
  (second hand))

(defun get-hands (str)
  "Convert the string hand data structure into the value/suit structure.
 E.g. convert 5H 5C 6S 7S KD into:
 ((5 H) (5 C)..."
  (loop for hand in (split str #\Space)
	 collect (list (char hand 0) (char hand 1))))

(defun score-pair (score-tabl hand)
  "Simple data structure to keep track of pairs"
  (let ((s (gethash (get-value hand) score-tabl)))
	(if s
		(setf (gethash 
			   (get-value hand) score-tabl) (1+ s))
		(setf (gethash 
			   (get-value hand) score-tabl) 1))))
  
(defun find-pairs (hand-lst)
  (let ((score-tabl (make-hash-table :test 'equal)))
	(loop for hand in hand-lst
	   do (score-pair score-tabl hand))
	score-tabl))

(defun process-hand (line)
  (let* ((hand line)
		 (pairs (find-pairs (get-hands hand)))
		 (pairs-lst (hash-table->list pairs)))
	(print (quicksort pairs-lst))))
  
(defun determine-poker-winners (filename)
  "Example filename = ./poker.txt"
  (with-open-file (stream filename)
	(do ((line (read-line stream nil)
			   (read-line stream nil)))
        ((null line))
	  (process-hand line))))
			 
(defun main ()
  (format t "INFO: Running Project Euler~%")
  ;;(print (card-value #\3))
  (let* ((hand "5H 5C 6S 7S KD")
		 (pairs (find-pairs (get-hands hand)))
		 (pairs-lst (hash-table->list pairs)))
	(print (quicksort pairs-lst)))

  ;; Driver test
  (determine-poker-winners "./poker.txt")
  (format t "~%INFO: Done~%"))
(main)

;; End of Script