;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname cartesian-starter) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; PROBLEM: In interactive games it is often useful to be able to determine the distance between two points on 
; the screen. We can describe those points using Cartesian coordinates as four numbers: x1, y1 and x2, y2.

;; Number Number Number Number -> Number
;; Produce cartesian distance between two points (x1, y1) and (x2, y2)
(check-expect (distance 3 0 0 4) 5)

; As for inexact numbers, it is morally wrong to compare them for plain equality.
; Instead one tests whether they are both within a small interval.
; (check-within expression expected-expression delta)
; Checks whether the value of the expression is structurally equal to the value produced by the expected-expression.
; Every number in the first expression must be within delta of the corresponding number in the second expression.
(check-within (distance 1 0 0 1) (sqrt 2) .00001)

; (define (distance x1 y1 x2 y2) 0)    ;stub

; (define (distance x1 y1 x2 y2)    ;template
;   (... x1 y1 x2 y2))

(define (distance x1 y1 x2 y2)
  (sqrt (+ (sqr (- x2 x1))
           (sqr (- y2 y1)))))
