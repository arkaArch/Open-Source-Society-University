;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 07-enumeration) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem:
; As a part of desigining a system to keep track of student grades, you
; are asked to design a data definition to represent the letter grade in
; a course, which os one of A, B or C.
; Also design a function that consumes a letter grade and produces the next
; highest letter grade.

;; Data Definitions:

;; LetterGrade is one of:
;;    - "A"
;;    - "B"
;;    - "C"
;; interp. the letter grade in a course
;; <examples are redundant for enumerations>
#;
(define (fn-for-letter-grade lg)
  (cond [(string=? lg "A") (...)]
        [(string=? lg "B") (...)]
        [(string=? lg "C") (...)]))
;; Template rules used:
;;  - one of: 3 cases
;;  - atomic distinct: "A"
;;  - atomic distinct: "B"
;;  - atomic distinct: "C"

;; Functions
;; LetterGrade -> LetterGrade
;; produce next highest letter grade(no change for A)
(check-expect (bump-up "A") "A")
(check-expect (bump-up "B") "A")
(check-expect (bump-up "C") "B")

; (define (bump-up lg) "A")  ;stub

; <tamplate from LetterGrade>
(define (bump-up lg)
  (cond [(string=? lg "A") "A"]
        [(string=? lg "B") "A"]
        [(string=? lg "C") "B"]))