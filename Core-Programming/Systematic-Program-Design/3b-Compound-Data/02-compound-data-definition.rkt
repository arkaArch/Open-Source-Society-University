;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 02-compound-data-definition) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem:
;; Design a data definition to represent hockey players, including
;; both their first and last name

;; Data Definition:
;;
(define-struct player (fn ln))
;; Player is (make-player String String)
;; interp. (make-player fn ln) is a hockey player with
;;         fn is the first name
;;         ln is the last name
(define P1 (make-player "Dhyan" "Chand"))
(define P2 (make-player "Wayne" "Gretzky"))
#;
(define (fn-for-player p)
  (... (player-fn p)     ;String
       (player-ln p)))   ;String

;; Template rules used
;; - Compound: 2 fields

;; Player -> String
;; produce player full name
(check-expect (player-name P1) "Dhyan Chand")

;(define (player-name p) "")  ;stub

;; <templates from Player>

(define (player-name p)
  (string-append (player-fn p)
                 " "
                 (player-ln p)))

