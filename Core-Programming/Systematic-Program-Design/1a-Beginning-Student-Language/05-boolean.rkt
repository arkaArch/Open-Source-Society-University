#lang racket
(require 2htdp/image)

(define WIDTH 120)
(define HEIGHT 100)

(> WIDTH HEIGHT)        ; #t: true
(<= WIDTH HEIGHT)       ; #f: false

(string=? "foo" "bar")  ; #f

; "Predicates" are primitives or functions that produce a boolean value.
; Example: =, >, string=?

(define I1 (rectangle 10 20 "solid" "red"))
(define I2 (rectangle 20 15 "solid" "red"))

(> (image-width I2) (image-width I1))  ; (20 > 10) -> #t

; We can write conditions with 'if' statement like:
; (if <expression::condition> <expression::true answer> <expression::false answer>)
(if (> (image-width I1) (image-height I1)) "wide" "tall")    ; "tall"
(if (> (image-width I2) (image-height I2)) "wide" "tall")    ; "image"

(or (< 2 1) (> 3 2) (= 4 4))    ; #t
(and (< 2 3) (> 3 2) (= 4 4))   ; #t
(not (< 2 1))                   ; #t


; Produces the larger of two given numbers
(define (larger a b) 
  (if (> a b) a b))

(larger 8 5)    ; 8
(larger 2 5)    ; 5
