;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname employees-starter) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; =================
;; Data definitions:

;; PROBLEM A:
;
; You work in the Human Resources department at a ski lodge. 
; Because the lodge is busier at certain times of year, 
; the number of employees fluctuates. 
; There are always more than 10, but the maximum is 50.
; Design a data definition to represent the number of ski lodge employees. 


;; Employees is Integer(10, 50]
;; interp. number of employees, more than 10 and maximum is 50.
(define EMPS1 11)    ; minimum employees
(define EMPS2 20)    ; sufficient employees
(define EMPS3 25)    ; maximim employees
#;
(define (fn-for-employees emps)
  (... emps))

;; Template rules used:
;;  - atomic non-distinct: Integer(10, 50]

;; =================
;; Functions:

; 
;; PROBLEM B:
; 
; Now design a function that will calculate the total payroll for the quarter.
; Each employee is paid $1,500 per quarter.

;; Employees -> Number
;; produce total payroll for the quarter of employees.
(check-expect (total-payroll 11) 16500)
(check-expect (total-payroll 20) 30000)
(check-expect (total-payroll 50) 75000)

;(define (total-payroll emps) 0)   ;stub

; <template from Employees>

(define (total-payroll emps)
  (* 1500 emps))
