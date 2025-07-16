;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname 05-concentric-circles) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM: 
;; Design a function that consumes a natural number n and a color c, and produces n 
;; concentric circles of the given color.

(require 2htdp/image)

;; Natural String -> Image
;; produce n concentric circle of a color
(check-expect (concentric-circles 0 "black") empty-image)
(check-expect (concentric-circles 1 "black") (overlay (circle 10 "outline" "black")
                                                      empty-image))
(check-expect (concentric-circles 3 "blue") (overlay (circle 30 "outline" "blue")
                                                     (circle 20 "outline" "blue")
                                                     (circle 10 "outline" "blue")
                                                     empty-image))

;(define (concentric-circles n c) empty-image)  ;stub

(define (concentric-circles n c)
  (cond [(zero? n) empty-image]
        [else
         (overlay
          (circle (* n 10) "outline" c)
          (concentric-circles (sub1 n) c))]))

(concentric-circles 5 "blue")