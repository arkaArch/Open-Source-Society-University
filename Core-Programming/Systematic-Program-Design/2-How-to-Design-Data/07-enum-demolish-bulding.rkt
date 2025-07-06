;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 08-enum-demolish-bulding) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Data definitions:
;; 
;; PROBLEM A: 
;; You are assigned to develop a system that will classify 
;; buildings in downtown Vancouver based on how old they are. 
;; According to city guidelines, there are three different classification levels:
;; new, old, and heritage.
;; Design a data definition to represent these classification levels. 

;; BuildingStatus is one of:
;;   - "new"
;;   - "old"
;;   - "heritage"
;; interp. classification of a building based on age 
;; <examples are redundant for enumerations>
#;
(define (fn-for-building-status bs)
  (cond [(string=? bs "new") (...)]
        [(string=? bs "old") (...)]
        [(string=? bs "heritage") (...)]))
;; Template rules used:
;;   - one of: 3 cases
;;   - atomic distinct: "new"
;;   - atomic distinct: "old"
;;   - atomic distinct: "heritage"


;; Functions:
;;
;; PROBLEM B:
;; The city wants to demolish all buildings classified as "old". 
;; You are hired to design a function called demolish? 
;; that determines whether a building should be torn down or not.

;; BuildingStatus -> Boolean
;; produces whether a building should be torn down or not
(check-expect (demolish? "new") #f)
(check-expect (demolish? "old") #t)
(check-expect (demolish? "heritage") #f)

; (define (demolish? bs) #f)  ;stub

; <template from BuildingStatus>
(define (demolish? bs)
  (cond [(string=? bs "new") #f]
        [(string=? bs "old") #t]
        [(string=? bs "heritage") #f]))

