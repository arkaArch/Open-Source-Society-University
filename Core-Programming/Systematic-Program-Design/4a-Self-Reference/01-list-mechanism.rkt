;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 01-List-Mechanism) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

;empty  ;; An empty list of any type of value

;; Construct a list with "Flames" on the front of an empty list
(cons "Flames" empty)

;; Construct a list in which "Leafs" is the first element, and add "Leafs" to the front
;; of. Construct a list with "Flames" on the front of an empty list
(cons "Leafs" (cons "Flames" empty))

(define L1 (cons 10 (cons 9 (cons 8 empty))))  ; A list of three elements

(define L2
  (cons (square 18 "solid" "green")
        (cons (circle 10 "solid" "red")
              (cons (triangle 20 "solid" "blue")
                    empty))))  ; A list of images


;; "first" consumes a list with at least one element and produces the first element of the list
;; "cons" is basically a compound data constructor, saying make a new list.
;; "first" is the selector that selects the first element
(first L2)

;; "rest" consumes a list with at least one element and produces the list after the first element
(rest L2)

;; Now we can access second and third element as
(second L2)
(third L2)

;; Or we can access them by rest as
(first (rest L2))
(first (rest (rest L2)))

;; We can check if a list is empty or not by the predicate "empty?"
(empty? (rest (rest (rest L2))))  ; #true