;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname 03-decreasing-image) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:  
;; Design a function called decreasing-image that consumes a Natural n and produces an image of all the numbers 
;; from n to 0 side by side. 

(require 2htdp/image)

(define TEXT-SIZE 20)
(define TEXT-COLOR "black")
(define SPACE (text " " TEXT-SIZE TEXT-COLOR))


;; Natural -> Image
;; produce an image of n, (n-1), (n-2), ... 0
(check-expect (decreasing-image 0) (text "0" TEXT-SIZE TEXT-COLOR))
(check-expect (decreasing-image 1) (beside
                                    (text "1" TEXT-SIZE TEXT-COLOR) SPACE
                                    (text "0" TEXT-SIZE TEXT-COLOR)))
(check-expect (decreasing-image 3) (beside
                                    (text "3" TEXT-SIZE TEXT-COLOR) SPACE
                                    (text "2" TEXT-SIZE TEXT-COLOR) SPACE
                                    (text "1" TEXT-SIZE TEXT-COLOR) SPACE
                                    (text "0" TEXT-SIZE TEXT-COLOR)))


;(define (decreasing-image n) (text "0" TEXT-SIZE TEXT-COLOR))  ;stub

(define (decreasing-image n)
  (cond [(zero? n) (text "0" TEXT-SIZE TEXT-COLOR)]
        [else
         (beside (text (number->string n) TEXT-SIZE TEXT-COLOR) SPACE
              (decreasing-image (sub1 n)))]))
