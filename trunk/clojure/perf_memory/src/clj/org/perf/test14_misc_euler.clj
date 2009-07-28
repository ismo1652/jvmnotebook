;;
;; Running with Clojure 1.0 under Windows XP
;; As of 7/15/2009
;; 
;; Following code taken verbatim from stackoverflow:
;; Slow version:
;;
;; http://stackoverflow.com/questions/960980/fast-prime-number-generation-in-clojure
;;
;; From user:
;; http://stackoverflow.com/users/18189/mbcook
;;
;; [ BEGIN QUOTE ]
;; I've been working on solving Project Euler problems in Clojure to get better, 
;; and I've already run into prime number generation a couple of times. 
;; My problem is that it is just taking way too long. I was hoping someone 
;; could help me find an efficient way to do this in a Clojure-y way.
;;
;; When I first did this, I brute-forced it. That was easy to do. 
;; But calculating 10001 prime numbers took 2 minutes this way on a Xeon 2.33GHz, 
;; too long for the rules, and too long in general. Here was the algorithm:
;; [ END QUOTE ]
;;

(ns org.perf.test14_misc_euler
	(:use org.perf.octane_utils_common)
	(:import (java.util Date)
             (java.io File)
             (java.util.regex Pattern)))

;; By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
;; we can see that the 6^(th) prime is 13.
;; What is the 10001^(st) prime number?


(defn next-prime-slow
    "Find the next prime number, checking against our already existing list"
    ([sofar guess]
     (if (not-any? #(zero? (mod guess %)) sofar)
       guess                         ; Then we have a prime
       (recur sofar (+ guess 2)))))  ; Try again

(defn find-primes-slow
    "Finds prime numbers, slowly"
    ([] (find-primes-slow 10001 [2 3]))   ; How many we need, initial prime seeds
    ([needed sofar]
     (if (<= needed (count sofar))
       sofar                         ; Found enough, we're done
       (recur needed (concat sofar [(next-prime-slow sofar (last sofar))])))))

(defn clean-sieve
    "Clean the sieve of what we know isn't prime based"
    [seeds-left sieve]
    (if (zero? (count seeds-left))
      sieve              ; Nothing left to filter the list against
      (recur
       (rest seeds-left)    ; The numbers we haven't checked against
       (filter #(> (mod % (first seeds-left)) 0) sieve)))) ; Filter out multiples

(defn self-clean-sieve  ; This seems to be REALLY slow
    "Remove the stuff in the sieve that isn't prime based on it's self"
    ([sieve]
     (self-clean-sieve (rest sieve) (take 1 sieve)))
    ([sieve clean]
        (if (zero? (count sieve))
          clean
          (let [cleaned (filter #(> (mod % (last clean)) 0) sieve)]
            (recur (rest cleaned) (into clean [(first cleaned)]))))))

;;
;; We are trying to target finding the
;; '10001th' prime.
;; Normally we can do , less than 1000
;; 1000 == 6949
(defn find-primes
    "Finds prime numbers, hopefully faster"
    ([] (find-primes 1000 [2]))
    ([needed seeds]
     (if (>= (count seeds) needed)
       seeds        ; We have enough
       (recur       ; Recalculate
        needed
        (into
         seeds    ; Stuff we've already found
            (let [start (last seeds)
                  end-range (+ start needed)]   ; NOTE HERE
              (reverse                                                                                        
               (self-clean-sieve
                (clean-sieve seeds (range (inc start) end-range))))))))))

(defn sieve-faster [n]
  (let [n (int n)]
    "Returns a list of all primes from 2 to n"
    (let [root (int (Math/round (Math/floor (Math/sqrt n))))]
      (loop [i (int 3)
             a (int-array n)
             result (list 2)]
        (if (>= i n)
          (reverse result)
          (recur (+ i (int 2))
                 (if (< i root)
                   (loop [arr a
                          inc (+ i i)
                          j (* i i)]
                     (if (>= j n)
                       arr
                       (recur (do (aset arr j (int 1)) arr)
                              inc
                              (+ j inc))))
                   a)
                 (if (zero? (aget a i))
                   (conj result i)
                   result)))))))

(defn run-test
  []
  ;;;;
  (println "Running Test" *current-date*)
  (println (*memory-usage*))
  (time (let [a (last (find-primes))]
          (println "Prime : " a)))
  ;; We know what the target prime is, 
  ;; just use that value for our seive-faster
  ;; function.  104750
  ;; The new approach is a lot faster.
  (time (let [a (last (sieve-faster 104750))]
          (println "Prime-2 : " a)))
  (println (*memory-usage*))
  (println "Done"))
      
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn run-cool-down
  "Allow a little time to see if JVM garbage collects.
 This may not have any effect"
  []
  ;;;
  (println "Performing simple garbage collection cooldown")
  (println (*memory-usage*))
  (Thread/sleep 120)
  (println (*memory-usage*))
  (Thread/sleep 120))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
(defn main [& args]
  (try (run-test)
       (run-cool-down)
	   (catch Exception e
			  (println "ERR at <Main [1]>: " e)
              (.printStackTrace e)
			  (exit))))

(main)                        
;; End of Script