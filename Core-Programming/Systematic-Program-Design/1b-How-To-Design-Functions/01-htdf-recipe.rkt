;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname htdf) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))

;; Problem statement:
;; Design a function that consumes a number and produces twice that number.
;; Call your function double. Follow the HtDF(How to Design Function) recipe
;; and show the stub and template.

;; The HtDF recipe consists of the following steps:
;; 1. Signature, purpose and stub.
;; 2. Define examples, wrap each in check-expect.
;; 3. Template and inventory.
;; 4. Code the function body.
;; 5. Test and debug until correct

;; Signature: Declares type of data function consume and produces.
;; Number -> Number 

;; Purpose: One line description of what function produce in terms of what it consumes.
;; Produce 2 times the given number.

;; Signature and Purpose are permanent comment and we usually do it with double semicolon.

;; Stub: Like a piece of scaffolding that we're going to place for a short period of time. It's going to help us
;; with some other parts of our work. And then we'll end up commenting out or delete it.
;; Stub is a function definition that has
;;    1. Correct funtion name
;;    2. Correct number of parameters
;;    3. Produce dummy result of correct type 
;; Stub is actually very useful for writing well-formed Tests, you should run stab and Tests before writing definition.
; (define (double n) 0) 

;; Example/Tests
(check-expect (double 4) 8)
(check-expect (double 2.3) 4.6)

;; Template / Inventory
;(define (double n)
;  (...n))
;; (...n) means do something to n

;; Function body
(define (double n)
  (* 2 n))
