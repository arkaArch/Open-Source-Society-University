;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 08-itemization) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

;; Problem A:
; Consider designing the system for controlling a New Year's Eve
; display. Design a data definition to represent the current state
; of the countdown, which falls into one of three categories:
;  - not yet started
;  - from 10 to 1 seconds before midnight
;  - complete (Happy New Year!)


;; Data Definitions:

;; Note:
; Use itemization when domain information is comprised of 2 or
; more subclasses, at least one of which is not a distinct item.

;; Countdown is one of:
;;  - false
;;  - Natural[1, 10]
;;  - "complete"

;; interp.
;;    false           means countdown has not yet started
;;    Natural[1, 10]  means countdown is running and how many seconds left
;;    "complete"      means countdown is over
(define CTD1 false)    ; not started
(define CTD2 10)       ; just started running
(define CTD3 1)        ; almost over
(define CTD4 "complete")

#;
(define (fn-for-countdown ctd)
  (cond [(false? ctd) (...)]
        
        ;; This type of itemization is called "mixed data itemization". Since all clauses are not same.
        ;; first clause -> boolean, second clause -> number, third claus -> string.
        ;; Now what will happen when a function based on '(>= ctd 1)' is called with "complete" as an
        ;; argument? It'll blow up certainly. So this must be guarded against being called on the wrong
        ;; type of data and this is (number? c) in this case.
        ;[(and (number? ctd) (>= ctd 1) (<= ctd 10)) (... ctd)]
        
        ;; Now we can simplify this template more. Notice that there's only one case here of natural numbers.
        ;; Because there is only one subcategory of numbers, it actually turns out that all we need is the
        ;; '(number? ctd)' guard. That is, if ctd is a number, then our data definition dictates that it
        ;; must be a natural between 1 and 10. So, the second template can be written as
        [(number? ctd) (... ctd)]

        ;; It is permissible to use else for the last question for itemizations and large enumerations.
        ;; Normal enumerations should not use else.
        ;; In this course we're allowed to assume that a function is called with arguments that matches
        ;; its signature. In other programming languages this will be enforced automatically.
        ;; So that means is when this template runs in some specific function, if cd isn't false, and cd
        ;; isn't a number between 1 and 10. Then c is guaranteed to be the string "complete".
        ;; It is actually just a part of compiler called the type checker. And it doesn't have to be part of
        ;; the compiler. And there are several other caveats. But the key point is that many languages enforce
        ;; rules about function arguments matching the function signature.
        [else (...)]))

;; Template rules used:
;;   - one of: 3 cases
;;   - atomic distinct: false
;;   - atomic non-distinct: Natural[1, 10]
;;   - atomic distinct: "complete" 


;; Problem B:
; You're asked to contribute to the design for a very simple New Year's Eve countdown display. You need to design
; a function that consumes Countdown and produces an image showing the current status of the countdown.

;; Functions:
;;
;; Countdown -> Image
;; produce image of current state of countdown
(check-expect (countdown->image #f) (text "wait" 20 "red"))
(check-expect (countdown->image 10) (text "10" 20 "green"))
(check-expect (countdown->image 1) (text "1" 20 "green"))
(check-expect (countdown->image "complete") (text "Happy New Year!" 20 "orange"))

;(define (countdown->image ctd) (square 0 "solid" "white"))  ;stub

; <template from Countdown>

(define (countdown->image ctd)
  (cond [(false? ctd) (text "wait" 20 "red")]
        [(number? ctd) (text (number->string ctd) 20 "green")]
        [else (text "Happy New Year!" 20 "orange")]))
