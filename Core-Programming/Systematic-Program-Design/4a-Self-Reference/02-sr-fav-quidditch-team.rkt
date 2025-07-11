;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 02-sr-fav-quidditch-team) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem A
;; Imagine that you are designing a program that will keep track of your
;; favorite Quidditch teams.
;; Design a data definition to represent a list of Quidditch teams.


;; ListOfString is one of:
;;   - empty                       ; Base case
;;   - (cons String ListOfString)  ; Here comes self-reference which lets us match arbitarily long list
;; interp. a list of string                 

(define LOS1 empty)
(define LOS2 (cons "McGill" empty))
(define LOS3 (cons "UBC" (cons "McGill" empty)))

#;
(define (fn-for-los los)
  (cond [(empty? los) (...)]
        [else             
         (... (first los)
              (fn-for-los (rest los)))]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic distinct: empty
;;   - compound: (cons String ListOfString)
;;   - self-reference: (rest los) is ListOfString

;; Note: The self-reference template rule puts a natural recursion in the template
;;       that corresponds to the self-reference in the type comment



;; Problem B:
;; We want to know whether your list of favourite Quindicth teams includes UBC!
;; Design a function that consumes ListOfString and produces true if the list
;; includes "UBC"

;; ListOfString -> Boolean
;; produce true if los includes "UBC"
(check-expect (contains-ubc? LOS1) #false)
(check-expect (contains-ubc? LOS2) #false)
(check-expect (contains-ubc? LOS3) #true)
(check-expect (contains-ubc? (cons "McGill" (cons "UBC" empty))) #true)

;(define (contains-ubc? los) #false)  ; stub

(define (contains-ubc? los)
  (cond [(empty? los) #false]
        [else
         (if (string=? (first los) "UBC") #true  
             (contains-ubc? (rest los)))]))       ; Recursive call