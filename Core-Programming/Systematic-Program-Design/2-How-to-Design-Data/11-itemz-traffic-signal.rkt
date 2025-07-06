;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 09-itemz-traffic-signal) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
;; Problem A:
;; Design a data definition for a traffic light that can either be disabled,
;; or be one of red, yellow or green.

;; Data Definitions:
;;
;; TrafficLight is one of:
;;   - false
;;   - "red"
;;   - "yellow"
;;   - "green"
;; interp. false means the light is disables, otherwisw color of the light
(define TL1 false)
(define TL2 "red")

#;
(define (fn-for-tl tl)
  (cond [(false? tl) (...)]
        [(string=? tl "red") (...)]
        [(string=? tl "green") (...)]
        [(string=? tl "yellow") (...)]))
;; Here we do not have to guard those string with "(and (string? tl)".
;; There is two rules for simplifying mixed data itemization templates:
;;
;; 1. If a given subclass is the last subclass of its type, we can reduce
;; the test to just the guard. See previous example of itemization "(number? ctd)"
;;
;; 2. If all remaining subclasses are of the same type, then we can eliminate all
;; of the guards, like here we did.

;; Template rules used:
;;   - one of: 4 cases
;;   - atomic distinct: false
;;   - atomic distinct: "red"
;;   - atomic distinct: "yellow"
;;   - atomic distinct: "green"

;; Problem B:
;; Design a function that consumes TrafficLight and produces an image showing the
;; current status of the countdown.
;;
;; TrafficLight -> Image
;; produce image of current state of traffic ligths.
(check-expect (traffic-light-image #f) (circle 0 "solid" "white"))
(check-expect (traffic-light-image "red") (circle 20 "solid" "red"))
(check-expect (traffic-light-image "yellow") (circle 20 "solid" "yellow"))
(check-expect (traffic-light-image "green") (circle 20 "solid" "green"))

;(define (traffic-light-image tl) (circle 0 "solid" "white"))  ;stub

; <template from TrafficLight>

(define (traffic-light-image tl)
  (cond [(false? tl) (light "none")]
        [(string=? tl "red") (light "red")]
        [(string=? tl "yellow") (light "yellow")]
        [(string=? tl "green") (light "green")]))


;; String -> Image
;; produce image of a circle based on color 
(define (light color)
  (if (string=? color "none")
      (circle 0 "solid" "white")
      (circle 20 "solid" color)))