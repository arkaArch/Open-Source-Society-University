;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname 04-odd-from-n) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:  
;; Design a function called odd-from-n that consumes a natural number n, and produces a list of all 
;; the odd numbers from n down to 1.

;; Natural -> ListOfNatural
;; produce a list of the odd numbers between n and 1
(check-expect (odd-from-n 0) empty)
(check-expect (odd-from-n 7) (list 7 5 3 1))
(check-expect (odd-from-n 8) (list 7 5 3 1))

;(define (odd-from-n n) empty)

(define (odd-from-n n)
  (cond [(zero? n) empty]
        [else
         (if (odd? n)
             (cons n (odd-from-n (sub1 n)))
             (odd-from-n (sub1 n)))]))

