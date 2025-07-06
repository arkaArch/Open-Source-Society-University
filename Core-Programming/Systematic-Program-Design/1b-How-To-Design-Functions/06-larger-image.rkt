;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname 06-larger-image) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
;; PROBLEM:
; Design a function that consumes two images and produces true if the first is larger than the second.

;; Image Image -> Boolean
;; produces true if both width and height of first image is larger than the second image.

(check-expect (larger-img? (rectangle 12 11 "solid" "green") (rectangle 11 10 "solid" "green")) #t)
(check-expect (larger-img? (rectangle 10 13 "solid" "green") (rectangle 12 10 "solid" "green")) #f)
(check-expect (larger-img? (rectangle 10 13 "solid" "green") (rectangle 10 10 "solid" "green")) #f)
(check-expect (larger-img? (rectangle 15 10 "solid" "green") (rectangle 10 13 "solid" "green")) #f)
(check-expect (larger-img? (rectangle 10 13 "solid" "green") (rectangle 15 15 "solid" "green")) #f)
(check-expect (larger-img? (rectangle 10 15 "solid" "green") (rectangle 10 13 "solid" "green")) #f)
(check-expect (larger-img? (rectangle 15 10 "solid" "green") (rectangle 10 10 "solid" "green")) #f)
(check-expect (larger-img? (rectangle 10 13 "solid" "green") (rectangle 15 13 "solid" "green")) #f)
(check-expect (larger-img? (rectangle 10 13 "solid" "green") (rectangle 10 13 "solid" "green")) #f)

; (define (larger-img? img1 img2) #f)    ;stub

; (define (larger-img? img1 img2)    ;template
;    (... img1 img2))

(define (larger-img? img1 img2)
  (and (> (image-width img1) (image-width img2))
       (> (image-height img1) (image-height img2))))
