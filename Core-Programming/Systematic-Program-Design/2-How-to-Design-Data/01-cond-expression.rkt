;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname 01-cond-expression) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

(define IMG1 (rectangle 20 10 "solid" "red"))
(define IMG2 (rectangle 20 20 "solid" "red"))
(define IMG3 (rectangle 10 20 "solid" "red"))

;; Image -> String
;; produce shape of image, one of "tall", "wide", "square"
(check-expect (aspect-ratio IMG1) "wide")
(check-expect (aspect-ratio IMG2) "square")
(check-expect (aspect-ratio IMG3) "tall")

;(define (aspect-ratio img) "")    ;stub

;(define (aspect-ratio img)    ;template
;  (... img))

#;
(define (aspect-ratio img)
  (if (> (image-width img) (image-height img)) "wide"
      (if (< (image-width img) (image-height img)) "tall"
      "square")))

;Cond: is a multi-armed conditional.
;It can have any number of cases all at same level
(define (aspect-ratio img)
  (cond [(> (image-width img) (image-height img)) "wide"]
        [(< (image-width img) (image-height img)) "tall"]
        [else "square"]))
;But '()' and '[]' are equivalent, but by convention we use
;[] around question/answer pairs in cond. This makes the cond
;easier to read
