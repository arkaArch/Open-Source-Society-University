;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 04-atomic-non-distinct) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem:
; Imagine that you are desigining a program that, among other things, has information
; about the names of cities in its problem domain.
; Design a data definition to represent the name of a city.

; ----------------------------------- HtDD recipe -------------------------------------------------
;;                                       
;; 1. A possible structure definition (not until compound data)
;; 2. A type comment that defines a new type name and describes how to form data of that type.
;; 3. An interpretation that describes the correspondence between information and data.
;; 4. One or more examples of the data.
;; 5. A template for a 1 argument function operating on data of this type.
;;
;---------------------------------------------------------------------------------------------------

; A data definition establishes the represent/interpret relationship between information and data:
; Information: Delhi, Kolkata
; Now we have to represent that information:

; Here we're trying to represent city name and it's "Simple Atomic Data".
; Atomic data can't be apart into pieces that are meaningfully part of the same problem domain

;; CityName is String               (step 2 of recipe)
;; 'CityName'(new form of data) is 'String'(type)

;; interp. the name of a city       (step 3 of recipe)

(define CN1 "Delhi")                ;(step 4 of recipe)
(define CN2 "Kolkata")

#;
(define (fn-for-city-name cn)       ;(step 5 of recipe)
  (... cn))

;; Template rules used:
;; - atomic non-distinc: String

;; Functions:
; Design a function that produce #t if the given city is the best city in the world

;; CityName -> Boolean
;; producr true if the given city is the best city in the world
(check-expect (best-city? "Kolkata") #t)
(check-expect (best-city? "Delhi") #f)

;(define (best-city? cn) #f)    ;stub

; took template from CityName
#;
(define (best-city? cn)
  (... cn))

(define (best-city? cn)
  (string=? cn "Kolkata"))



;----------------------------------------------------------------------------------------------------
;Another example of atomic-non-distinct-data-type recipe:

;; CourseName is String
;; interp. the name of a course
(define COURSE "Systematic Program Design")

#;
(define (fn-for-course-name course)
  (... course))

;; Template rules used:
;; - atomic non-distinct: String
