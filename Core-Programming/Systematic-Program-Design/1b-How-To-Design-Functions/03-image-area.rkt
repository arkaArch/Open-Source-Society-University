;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname 03-image-area) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Design a function called image-area that consumes an image and produces the area of that image.
(require 2htdp/image)

;; Image -> Natural
;; Produce area(in pixels) of an image.

(check-expect (image-area (rectangle 2 3 "solid" "green")) 6)
(check-expect (image-area (rectangle 4.5 3.3 "solid" "green")) 12)    ; Since pixels are natural number

; (define (image-area img) 0)    ;stub

; (define (image-area img)    ;template
;   (... img))

(define (image-area img)
  (* (image-width img) (image-height img)))
