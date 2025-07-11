;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname largest-starter) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Design a function that consumes a list of numbers and produces the largest number 
;; in the list. You may assume that all numbers in the list are greater than 0. If
;; the list is empty, produce 0.

;; ListOfNumber is one of:
;;  - empty
;;  - (cons Number ListOfNumber)
;; interp. a list of numbers
(define LON1 empty)
(define LON2 (cons 60 (cons 42 empty)))
#;
(define (fn-for-lon lon)
  (cond [(empty? lon) (...)]
        [else
         (... (first lon)
              (fn-for-lon (rest lon)))]))

;; Template rules used:
;;  - one of: 2 cases
;;  - atomic distinct: empty
;;  - compound: (cons Number ListOfNumber)
;;  - self-reference: (rest lon) is ListOfNumber



;; ListOfNumber -> Number
;; produce lagest number of the list, 0 for an empty list
(check-expect (largest empty) 0)
(check-expect (largest (cons 34 empty)) 34)
(check-expect (largest (cons 34 (cons 43 (cons 12 empty)))) 43)

; (define (largest lon) 0)  ;stub

(define (largest lon)
  (cond [(empty? lon) 0]
        [else
         (if (> (first lon) (largest (rest lon))) (first lon)
            (largest (rest lon)))]))