;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname tuition-graph) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM: 
;; Eva is trying to decide where to go to university. One important factor for her is 
;; tuition costs. Eva is a visual thinker, and has taken Systematic Program Design, 
;; so she decides to design a program that will help her visualize the costs at 
;; different schools. She decides to start simply, knowing she can revise her design
;; later.
;; 
;; The information she has so far is the names of some schools as well as their 
;; international student tuition costs. She would like to be able to represent that
;; information in bar charts.
;;         
;; (A) Design data definitions to represent the information Eva has.
;; (B) Design a function that consumes information about schools and their
;;     tuition and produces a bar chart.
;; (C) Design a function that consumes information about schools and produces
;;     the school with the lowest international student tuition.
;; (D) Design a function that consumes a ListOfSchool and produces a list of the 
;;     school names.


(require 2htdp/image)

;; Constants:

(define TEXT-SIZE 15)
(define TEXT-COLOR "black")

(define Y-SCALE 1/1200)  ; We can multiply this with tuition cost to get a reasonable bar height
(define BAR-WIDTH 20)
(define BAR-COLOR "lightblue")



;; Data definitions:

(define-struct school (name tuition))
;; School is (make-school String Natural)
;; interp. (make-school name tuition) is a school with
;;         name is the school name
;;         tuition is the total tution cost in lakhs
(define S1 (make-school "Banaras Hindu University" 252000))
(define S2 (make-school "Chandigarh University" 220000))
(define S3 (make-school "Jadavpur University" 180000))
#;
(define (fn-for-school s)
  (... (school-name s)          ; String
       (school-tuition s)))     ; Natural     

;; Template rules used
;; - Compound: 2 fields


;; ListOfSchool is one of:
;;   - empty
;;   - (cons School ListOfSchool)
;; interp. a list of schools
(define LOS1 empty)
(define LOS2 (cons S1 (cons S2 (cons S3 empty))))
#;
(define (fn-for-los los)
  (cond [(empty? los) (...)]
        [else
         (... (fn-for-school (first los))     ; Natural helper
              (fn-for-los (rest los)))]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic-distinct: empty
;;   - compound: (cons School ListOfSchool)
;;   - reference: (first los)
;;   - self-reference: (rest los) is ListOfSchool

;; Note: Natural helper in template means, do not do something complicated with the referred
;; to type here, instead call an existing function or wish for a new one.


;; ListOfString is one of:
;;  - empty
;;  - (cons String ListOfString)
;; interp. a list of string
(define LS1 empty)
(define LS2 (cons "Cat" (cons "DOG" empty)))
#;
(define (fn-for-los los)
  (cond [(empty? los) (...)]
        [else
         (... (first los)
              (fn-for-los (rest los)))]))

;; Template rules used:
;;  - one of: 2 cases
;;  - atomic distinct: empty
;;  - compound: (cons String ListOfString)
;;  - self-reference: (rest los) is ListOfString



;; Functions:

;; ListOfSchool -> Image
;; produce a bar chart according to tuition fee of schools
(check-expect (chart empty) (rectangle 0 0 "solid" BAR-COLOR))

(check-expect (chart (cons (make-school "Banaras Hindu University" 192000) empty))
              (beside/align "bottom"
                            (overlay/align "center" "bottom"
                                           (rotate 90 (text "Banaras Hindu University" TEXT-SIZE TEXT-COLOR))
                                           (rectangle BAR-WIDTH (* 192000 Y-SCALE) "outline" "black")
                                           (rectangle BAR-WIDTH (* 192000 Y-SCALE) "solid" BAR-COLOR))
                            (rectangle 0 0 "solid" BAR-COLOR)))

(check-expect (chart (cons S2(cons S3 empty)))
              (beside/align "bottom"
                            (overlay/align "center" "bottom"
                                           (rotate 90 (text (school-name S2) TEXT-SIZE TEXT-COLOR))
                                           (rectangle BAR-WIDTH (* (school-tuition S2) Y-SCALE) "outline" "black")
                                           (rectangle BAR-WIDTH (* (school-tuition S2) Y-SCALE) "solid" BAR-COLOR))
                            (overlay/align "center" "bottom"
                                           (rotate 90 (text (school-name S3) TEXT-SIZE TEXT-COLOR))
                                           (rectangle BAR-WIDTH (* (school-tuition S3) Y-SCALE) "outline" "black")
                                           (rectangle BAR-WIDTH (* (school-tuition S3) Y-SCALE) "solid" BAR-COLOR))
                            (rectangle 0 0 "solid" BAR-COLOR)))

;(define (chart los) (rectangle 0 0 "solid" BAR-COLOR))  ; stub

(define (chart los)
  (cond [(empty? los) (rectangle 0 0 "solid" BAR-COLOR)]
        [else
         (beside/align "bottom"
                        (make-bar (first los))
                        (chart (rest los)))]))


;; School -> Image
;; Produce a bar for school according to its tution-fee
(check-expect (make-bar S1)
              (overlay/align "center" "bottom"
                             (rotate 90 (text (school-name S1) TEXT-SIZE TEXT-COLOR))
                             (rectangle BAR-WIDTH (* (school-tuition S1) Y-SCALE) "outline" "black")
                             (rectangle BAR-WIDTH (* (school-tuition S1) Y-SCALE) "solid" BAR-COLOR)))

;(define (make-bar s) (rectangle 0 0 "solid" BAR-COLOR))  ;stub

(define (make-bar s)
  (overlay/align "center" "bottom"
                 (rotate 90 (text (school-name s) TEXT-SIZE TEXT-COLOR))
                 (rectangle BAR-WIDTH (* (school-tuition s) Y-SCALE) "outline" "black")
                 (rectangle BAR-WIDTH (* (school-tuition s) Y-SCALE) "solid" BAR-COLOR)))

;(chart LOS2)


;; ListOfSchool -> School
;; produce the cheapest name of school
;; ASSUME the list includes at least one school or else
;;        the notion of cheapest doesn't make sense
(check-expect (cheapest (cons S3 empty)) S3)
(check-expect (cheapest LOS2) S3)

;(define (cheapest los) (make-school "" 0))  ;stub
;; Template for a function that consumes a non-empty list is:
#;
(define (cheapest los)
  (cond [(empty? (rest los)) (...  (first los))] 
        [else
          (... (first los) 
               (fn-for-nelox (rest los)))]))


(define (cheapest los)
  (cond [(empty? (rest los)) (first los)] 
        [else
          (if (cheaper? (first los) (cheapest (rest los)))
                    (first los)
                    (cheapest (rest los)))]))


;; Schools -> Boolean
;; produce true if tuition of s1 is < tuition of s2
(check-expect (cheaper? (make-school "a" 3) (make-school "b" 4)) true)
(check-expect (cheaper? (make-school "a" 4) (make-school "b" 4)) false)
(check-expect (cheaper? (make-school "a" 5) (make-school "b" 4)) false)

;(define (cheaper? s1 s2) false) ;stub

;Template  for a function that consumes two schools is:
#;
(define (cheaper? s1 s2)
  (... (school-name s1)
       (school-tuition s1)
       (school-name s2)
       (school-tuition s2)))

(define (cheaper? s1 s2)
  (< (school-tuition s1) (school-tuition s2)))


;; ListOfSchool -> ListOfString
;; produce a list of the names of the schools in the given list
(check-expect (get-names LOS1) empty)
(check-expect (get-names LOS2)
              (cons "Banaras Hindu University" (cons "Chandigarh University" (cons "Jadavpur University" empty))))

;(define (get-names los) empty)  ; stub
; <Template from ListOfSchool>

(define (get-names los)
  (cond [(empty? los) empty]
        [else
         (cons (school-name (first los))
               (get-names (rest los)))]))



