#lang racket
(require 2htdp/image)

; Define functions
(define (bulb size color)
  (circle size "solid" color))

(above (bulb 10 "red")
       (bulb 15 "green")
       (bulb 20 (string-append "yel" "low")))
; In function evaluation
; first reduce operands to values(called the argument) like primitive calls
; Then replace function call by body of function

; Lets see an proper example step by step to understand
; evaluation of function with evaluation of primitives
(define (foo a b)
  (+ (* 3 a) b (* b a)))
(foo (+ 1 1) 4)
; It evaluates like:
; 1. foo(2 4)
; 2. (+ (* 3 2) 4 (* 4 2))
; 3. (+ 6 4 (* 4 2))  ; since primitive calls evaluates from left to right
; 4. (+ 6 4 8)  ; since primitive calls evaluates from inside to outside
; 5. 18
