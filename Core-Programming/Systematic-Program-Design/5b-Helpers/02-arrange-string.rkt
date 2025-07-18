;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 02-fc-arrange-string) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

;; Constants:

(define TEXT-SIZE 20)
(define TEXT-COLOR "black")
(define BLANK (text "" TEXT-SIZE TEXT-COLOR))


;; Data definition:

;; ListOfString is one of:
;;   - empty
;;   - (cons String ListOfString)
;; interp. a list of strings
(define LOS1 empty)
(define LOS2 (cons "Paola" empty))
(define LOS3 (cons "Baylee"
                   (cons "Paola"
                         (cons "Amari"
                               empty))))

#;
(define (fn-for-los los)
  (cond [(empty? los) (...)]
        [else
         (... (first los)
              (fn-for-los (rest los)))]))



;; Functions:

;; ListOfStrings -> Image
;; layout strings vertically in alphabetical order

;; NOTE: Since arrange-strings is a function composition, the tests only need
;;       to ensure that arrange-strings is composing the functions properly,
;;       so no base case test is needed.

(check-expect (arrange-strings (cons "Paola"
                                     (cons "Baylee"
                                           empty)))
              (above/align "left"
                           (text "Baylee" TEXT-SIZE TEXT-COLOR)
                           (text "Paola" TEXT-SIZE TEXT-COLOR)
                           BLANK))

;(define (arrange-string los) BLANK)  ; stub

(define (arrange-strings los)
  (layout-strings (sort-strings los)))



;; ListOfString -> Image
;; place images above each other in order of list
(check-expect (layout-strings empty) BLANK)
(check-expect (layout-strings (cons "Paola"
                                     (cons "Baylee"
                                           empty)))
              (above/align "left"
                           (text "Paola" TEXT-SIZE TEXT-COLOR)
                           (text "Baylee" TEXT-SIZE TEXT-COLOR)
                           BLANK))

;(define (layout-strings los) BLANK)  ; stub
;; <Templates from list of string>

(define (layout-strings los)
  (cond [(empty? los) BLANK]
        [else
         (above/align "left"
                      (text (first los) TEXT-SIZE TEXT-COLOR)
                      (layout-strings (rest los)))]))



;; ListOfString -> ListOfString
;; sort strings in alphabetical order
(check-expect (sort-strings empty) empty)
(check-expect (sort-strings (cons "Paola"
                                     (cons "Baylee"
                                           empty)))
              (cons "Baylee"
                    (cons "Paola"
                          empty)))

;(define (sort-strings los) los)  ; stub
;; <Templates from list of string>

(define (sort-strings los)
  (cond [(empty? los) empty]
        [else
         (insert-string (first los)
              (sort-strings (rest los)))]))
 
                       

;; String ListOfString -> ListOfString
;; insert s in the correct place in the sorted list los
;; ASSUME: los is already sorted
(check-expect (insert-string "Baylee" empty)
              (cons "Baylee" empty))
;; remember the assumption:
;; "Baylee" and "Peyton" are assumed to be in sorted order
;; HERE we are just focusing on inserting the 's' inside los, not sort the los
(check-expect (insert-string "Paola" (cons "Baylee" (cons "Peyton" empty)))
              (cons "Baylee" (cons "Paola" (cons "Peyton" empty))))

;(define (insert-string s los) los)  ;stub

(define (insert-string s los)
  (cond [(empty? los) (cons s empty)]
        [else
         (if (string>=? s (first los))
             (cons (first los) (insert-string s (rest los)))
                   (cons s los))]))
