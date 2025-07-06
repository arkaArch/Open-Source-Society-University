;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 06-andi-aisle-seat) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem:
; Imagine that you are designing a program to manage ticket sales for a theatre.
; (Also imagine that the theatre is perfectly rectangle in shape!)
; Design a data definition to represent a seat number in a row, where each
; row has 32 seats.
;
; Design a function that produces true if the given seat number is on the aisle. 


;; Data definitions:

;; SeatNum is Integer[1, 32]    ;Remember [] -> inclusive and () -> exclusive
;; interp. seat numbers in a row, 1 and 32 are aisle seat
(define SN1 1)     ;aisle
(define SN2 16)    ;middle
(define SN3 32)    ;aisle

#;
(define (fn-for-seat-number sn)
  (... sn))

;; Template rules used:
;;  - atomic non-distinct: Integer[1, 32]

;; Functions :

;; SeatNum -> Boolean
; produces true if the given seat number is on the aisle
(check-expect (aisle? 1) #t)
(check-expect (aisle? 16) #f)
(check-expect (aisle? 32) #t)

;(define (aisle? sn) "")    ;stub

; <template from SeatNum>

(define (aisle? sn)
  (or (= sn 1)
       (= sn 32)))
