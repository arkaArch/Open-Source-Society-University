;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 10-itemz-rocket) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Data definitions:
;; 
;; PROBLEM A: 
;; You are designing a program to track a rocket's journey as it descends 
;; 100 kilometers to Earth. You are only interested in the descent from 
;; 100 kilometers to touchdown. Once the rocket has landed it is done.
;; Design a data definition to represent the rocket's remaining descent. 

;; RocketDescent is one of:
;;   - false
;;   - Number(0, 100]
;; interp. false means rocket has landed, otherwise descent distance of rocket
(define RD1 #f)   ;landed
(define RD2 100)  ;max distance
(define RD3 50)   ;middle in the way
(define RD4 0.5)  ;almost landed

#;
(define (fn-for-rocket-descent rd)
  (cond [(false? rd) (...)]
        [(number? rd) (... rd)]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic distinct: false
;;   - atomic non-distinct: Number(1, 100]


;; Functions:
;; 
;; PROBLEM B: 
;; Design a function that will output the rocket's remaining descent distance 
;; in a short string that can be broadcast on Twitter. 
;; When the descent is over, the message should be "The rocket has landed!".
;; Call your function rocket-descent-to-msg.

;; RocketDescent -> String
;; produce rocket's distance as string, or landed message
(check-expect (rocket-descent-to-msg #f) "The rocket has landed!")
(check-expect (rocket-descent-to-msg 100) "100 km to landing")
(check-expect (rocket-descent-to-msg 50) "50 km to landing")
(check-expect (rocket-descent-to-msg 0.5) "1/2 km to landing")

;(define (rocket-descent-to-msg rd) "The rocket has landed!")  ;stub
; <template from RocketDescent>

(define (rocket-descent-to-msg rd)
  (cond [(false? rd) "The rocket has landed!"]
        [(number? rd) (string-append (number->string rd) " km to landing")]))

