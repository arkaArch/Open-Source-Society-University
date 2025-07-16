;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 01-natural-numbers) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Natural is one of:
;;   - 0
;;   - (add1 Natural)
;; interp. a natural number
(define N0 0)          ;0
(define N1 (add1 N0))  ;1
(define N2 (add1 N1))  ;2

(define (fn-for-natural n)
  (cond [(zero? n) (...)]
        [else
         (... n                              ; template rules don't put this in
              ;                              ; but it seems to be used a lot so
              ;                              ; we added it.
              (fn-for-natural (sub1 n)))]))

;; Template rules used:
;;   - one of: two cases
;;   - atomic distinc: 0
;;   - compound: (add1 Natural)
;;   - self-reference: (sub1 n) is Natural


;; PROBLEM (A):
;; Design a function that consumes Natural number n and produces the sum of all the
;; naturals in [0, n].

;; Natural -> Natural
;; produces sum of naturals in [0, n]
(check-expect (sum 0) 0)
(check-expect (sum 2) (+ 2 1 0))
(check-expect (sum 3) (+ 3 2 1 0))

;(define (sum n) 0)  ;stub
;; <Templates from Natural>

(define (sum n)
  (cond [(zero? n) 0]
        [else
         (+ n
            (sum (sub1 n)))]))



;; PROBLEM (B):
;; Design a function that consumes Natural number n and produces a list of all the
;; naturals of the form (cons (cons n-1 ... empty)) not including 0

;; Natural -> ListOfNatural
;; produce (cons n (cons n-1 ... empty)), not including 0
(check-expect (to-list 0) empty)
(check-expect (to-list 1) (cons 1 empty))
(check-expect (to-list 2) (cons 2 (cons 1 empty)))

;(define (to-list n) empty)  ; stub
; <Templates from Natural>

(define (to-list n)
  (cond [(zero? n) empty]
        [else
         (cons n
               (to-list (sub1 n)))]))


;; PROBLEM (C):
;; Design a function that consumes Natural number n and produces the factorial of n

;; Natural -> Natural
;; produces factorial of n
(check-expect (factorial 0) 1)
(check-expect (factorial 1) (* 1 1))
(check-expect (factorial 3) (* 3 2 1))

;(define (factorial n) 0)  ; stub
; <Templates from Natural>

(define (factorial n)
  (cond [(zero? n) 1]
        [else
         (* n
            (factorial (sub1 n)))]))



;; PROBLEM (D):
;; Design a function called list-from-to that takes in two numbers, the first greater than or
;; equal to the sencond, and produces a list of each number from the first to the second.

;; Natural Natural -> ListOfNatural
;; produces a list of each number from first to the second
(check-expect (list-from-to 5 5) (cons 5 empty))
(check-expect (list-from-to 9 8) (cons 9 (cons 8 empty)))
(check-expect (list-from-to 10 8) (cons 10 (cons 9 (cons 8 empty))))

;(define (list-from-to n) empty)  ;stub
;; <Took temaplates from Natural>

(define (list-from-to n1 n2)
  (cond [(zero? (- n1 n2)) (cons n1 empty)]
        [else
         (cons n1
               (list-from-to (sub1 n1) n2))]))