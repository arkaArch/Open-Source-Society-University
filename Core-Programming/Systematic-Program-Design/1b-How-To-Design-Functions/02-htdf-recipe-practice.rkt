;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname 02-htdf-recipe-practice) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Design a function that pluralizes a given word.
; For simplicity you may assume that just adding s is enough to pluralize a word.

; Signature
;; String -> String

; Purpose
;; Produce the given string with "s" added to the end.

; Stub
; (define (pluralize str) "")

; Examples/Test
(check-expect (pluralize "dog") "dogs")
(check-expect (pluralize "grass") "grasss")

; Template
; (define (pluralize str)             
;    (... str))

(define (pluralize str)             
    (string-append str "s"))
