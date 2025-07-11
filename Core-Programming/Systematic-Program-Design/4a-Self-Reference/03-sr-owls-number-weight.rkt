;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 03-sr-owls-number-weight) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem:
;; You've been asked to design a program having to do with all the owls in the owlery.
;;
;; (A) Design a data definition to represent the weights of all the owls.
;;     For this problem call it ListOfNumber.
;;
;; (B) Design a function that consumes the weights of owls and produces the total weight
;;     of all the owls.
;;
;; (C) Design a function that consumes the weights of owls and produces the total number
;;     of owls.
;;
;; (D) Design a function that consumes a list of weights and doubles every weight of owl 
;;     in the list.

;; ListOfNumber is one of:
;;   - empty
;;   - (cons Number ListOfNumber)
;;interp. is number in the list is an owl weight in pounds
(define LON1 empty)
(define LON2 (cons 2.6 empty))
(define LON3 (cons 2.6 (cons 3.1 empty)))
#;
(define (fn-for-lon lon)
  (cond [(empty? lon) (...)]
        [else
         (... (first lon)
              (fn-for-lon (rest lon)))]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic-distinct: empty
;;   - compound: (cons Number ListOfNumber)
;;   - self-reference: (rest lon) is ListOfNumber



;; ListOfNumber -> Number
;; produce total weight of all the owls
(check-expect (total-weight empty) 0);
(check-expect (total-weight (cons 2.7 empty)) 2.7);
(check-expect (total-weight (cons 2.7 (cons 3.2 empty))) 5.9);

;(define (total-weight lon) 0)  ;stub

(define (total-weight lon)
  (cond [(empty? lon) 0]
        [else
         (+ (first lon)
            (total-weight (rest lon)))]))



;; ListOfNumber -> Number
;; produce total number of owls
(check-expect (total-owl empty) 0);
(check-expect (total-owl (cons 2.7 empty)) 1);
(check-expect (total-owl (cons 2.7 (cons 3.2 empty))) 2);

;(define (total-owl lon) 0)  ;stub
(define (total-owl lon)
  (cond [(empty? lon) 0]
        [else
         (+ 1
         (total-owl (rest lon)))]))


;; ListOfNumber -> ListOfNumber
;; double every weight in the list
(check-expect (double-weight empty) empty);
(check-expect (double-weight (cons 2.7 empty)) (cons 5.4 empty));
(check-expect (double-weight (cons 3 (cons 2.2 empty))) (cons 6 (cons 4.4 empty)));
(check-expect (double-weight (cons 2.1 (cons 2.9 (cons 3.1 empty))))
                             (cons 4.2 (cons 5.8 (cons 6.2 empty))));

;(define (double-weight lon) lon)  ;stub

(define (double-weight lon)
  (cond [(empty? lon) empty]
        [else
         (cons (* 2 (first lon))
              (double-weight (rest lon)))]))