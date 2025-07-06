;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname 04-is-image-tall) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

; Design a function that consumes an image and determines whether the image is tall

;; Image -> Boolean
;; Produce true if the image is tall(height is greater than width)
(check-expect (tall? (rectangle 2 6 "solid" "green")) #t)
(check-expect (tall? (rectangle 9 6 "solid" "green")) #f)
(check-expect (tall? (rectangle 5 5 "solid" "green")) #f)

; (define (tall? img) #f)    ;stub

; (define (tall? img)    ; Template
;   (...img))             

(define (tall? img)
  (> (image-height img) (image-width img)))
