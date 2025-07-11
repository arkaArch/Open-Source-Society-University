;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname image-list-starter) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Design a data definition to represent a list of images.
;;
;; Design a function that consumes a list of rectangle-images and produces
;; a number that is the sum of the areas of each image.

(require 2htdp/image)

;; ListOfImage is one of:
;;   - empty
;;   - (cons Image ListOfImage)
;;interp. is a list of images.
(define LOI1 empty)
(define LOI2 (cons (circle 10 "solid" "red")
                   empty))

(define LON3 (cons (triangle 12 "solid" "black")
                   (cons (circle 10 "solid" "red")
                         empty)))

(define LON4 (cons (square 8 "solid" "blue")
                   (cons (triangle 12 "solid" "black")
                         (cons (circle 10 "solid" "red")
                               empty))))
  
#;
(define (fn-for-loi loi)
  (cond [(empty? loi) (...)]
        [else
         (... (first loi)
              (fn-for-loi (rest loi)))]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic-distinct: empty
;;   - compound: (cons Image ListOfImage)
;;   - self-reference: (rest loi) is ListOfImage
  


;; ListOfImages -> Number
;; produce sum of areas of images
(check-expect (sum-of-areas empty) 0)
(check-expect (sum-of-areas (cons (rectangle 12 10 "solid" "black") empty)) 120)
(check-expect (sum-of-areas (cons (rectangle 10 10 "solid" "black")
                                  (cons (rectangle 20 10 "solid" "black")
                                        (cons (rectangle 20 20 "solid" "black") empty)))) 700)

;(define (sum-of-areas loi) 0)  ; stub

(define (sum-of-areas loi)
  (cond [(empty? loi) 0]
        [else
         (+ (* (image-width (first loi))
               (image-height (first loi)))
              (sum-of-areas (rest loi)))]))