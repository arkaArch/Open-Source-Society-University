#lang racket

; Assume that the two short sides of a right triangle have length 3 and 4.
; What is the length of the long side.
(sqrt (+ (sqr 3) (sqr 4)))    ; Expression

; This means the number is very close to 1.4142135623730951 
#i1.414213562373095189783002

; Average of the numbers 4, 6.2 and -12
(/ (+ 4 6.2 -12) 3)

; Let's see another example to see how the evaluation works internally
(+ 2 (* 3 4) (- (+ 1 2) 3))
; The above expression, since it starts with an open parenthesis and then a operator 
; is called a 'primitive call' or a 'call to a primitive'

; Now '+' after first open parenthesis is called 'Operator'

; And in a primitive call, all of these expressions that follow the operator are the operands.
; Here 2, (* 3 4) and (-1 (+ 1 2) 3) are the three operands

; Now again (* 3 4) is a primitive call, with an operator(*) and two operands(3 & 4)

; To evaluate a primitive call first reduced operands to values and then apply primitives to the values
; So the the above primitive call becomes
(+ 2 12 (- (+ 1 2) 3))
; 2nd step
(+ 2 12 (- 3 3))
; 3rd step '(+ 2 12)' and finally it becomes 14

; So an expression evaluates from left to right and from iside to outside

(/ 12 (+ (- 7 4) 3))
; For this expression (+ (-7 4) 3) evaluates as (3 + 3) 
