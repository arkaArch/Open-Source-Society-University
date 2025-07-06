;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname bike-route-starter) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Data Definition:
;;
;; PROBLEM a:
;; Suppose you are developing a route planning tool for bicycling in Vancouver.
;; There are four varieties of designated bike routes: 
;; 1) Separated Bikeway
;; 2) Local Street Bikeway
;; 3) Painted Bike Lane
;; 4) Painted Shared-Use Lane

;; BikeRoute is one of:
;;   - "Separated Bikeway"
;;   - "Local Street Bikeway"
;;   - "Painted Bike Lane"
;;   - "Painted Shared-Use Lane"
;; interp. varities of bike routes
;; <examples are redundant for enumeration>
#;
(define (fn-for-bike-route br)
  (cond [(string=? br "Separated Bikeway") (...)]
        [(string=? br "Local Street Bikeway") (...)]
        [(string=? br "Painted Bike Lane") (...)]
        [(string=? br "Painted Shared-Use Lane") (...)]))
;; Template rules used:
;;   - one of: 4 cases
;;   - atomic distinct: "Separated Bikeway"
;;   - atomic distinct: "Local Street Bikeway"
;;   - atomic distinct: "Painted Bike Lane"
;;   - atomic distinct: "Painted Shared-Use Lane"


;; Functions:
;;
;; PROBLEM b:
;; Separated bikeways and painted bike lanes are exclusively designated for bicycles, while
;; local street bikeways and shared-use lanes must be shared with cars and/or pedestrians.
;; Design a function called 'exclusive?' that takes a bike route and indicates whether it 
;; is exclusively designated for bicycles.

;; BikeRoute -> Boolean
;; indicate whether a bike route is exclusively designated for bicycles
(check-expect (exclusive? "Separated Bikeway") #t)
(check-expect (exclusive? "Local Street Bikeway") #f)
(check-expect (exclusive? "Painted Bike Lane") #t)
(check-expect (exclusive? "Painted Shared-Use Lane") #f)

;(define (exclusive? br) #f)  ;stub

; <template from BikeRoute>

(define (exclusive? br)
  (cond [(string=? br "Separated Bikeway") #t]
        [(string=? br "Local Street Bikeway") #f]
        [(string=? br "Painted Bike Lane") #t]
        [(string=? br "Painted Shared-Use Lane") #f]))