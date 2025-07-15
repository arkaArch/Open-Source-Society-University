;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 03-htdw-moving-rockets) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
;; Moving rockets accross the screen

;; Constants:
;; ==============
(define WIDTH 600)
(define HEIGHT 800)
(define SPEED 5)
(define MTS (empty-scene WIDTH HEIGHT))
(define ROCKET (rotate -45 (text "🚀" 40 "white")))



;; Data definition:
;; ==================
(define-struct rocket (x y))
;; Rocket is (make-rocket Natural[0, WIDTH), Natural[0, HEIGHT])
;; interp. (make-rocket (x y)) is a moving rocket with (x, y) co-ordinate
;;         x is the distance of the rocket from left edge
;;         y is the distance of the rocket from top edge
(define R1 (make-rocket 200 300))
(define R2 (make-rocket 400 600))
(define R3 (make-rocket 620 700))
#;
(define (fn-for-rocket r)
  (... (rocket-x r)        ; Natural[0, WIDTH)
       (rocket-y r)))      ; Natural[0, HEIGHT]

;; Template rules used:
;;   - compound: 2 fields


;; ListOfRocket is one of
;;   - empty
;;   - (cons Rocket ListOfRocket)
;; interp. a list of rocket
(define LOR1 empty)
(define LOR2 (cons R1 (cons R2 (cons R3 empty))))
#;
(define (fn-for-lor lor)
  (cond [(empty? lor) (...)]
        [else
         (... (fn-for-rocket (first lor))
              (fn-for-lor (rest lor)))]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic-distinct: empty
;;   - compound: (cons Rocket ListOfRocket)
;;   - reference: (first lor)
;;   - self-reference: (rest lor) is ListOfRocket



;; Functions:
;; ===============

;; ListOfRocket -> ListOfRocket
;; start world with (main empty)
;; no test for main function
(define (main lor)
  (big-bang lor                   ; ListOfRocket
    (on-tick next-rockets)        ; ListOfRocket -> ListOfRocket
    (to-draw render-rockets)      ; ListOfRocket -> Image
    (on-mouse handle-mouse)))     ; ListOfRocket Number Number MouseEvent -> ListOfRocket

;; ListOfRocket -> ListOfRocket
;; move rockets at SPEED on x horizon
(check-expect (next-rockets LOR1) empty)
(check-expect (next-rockets LOR2) (cons (make-rocket (+ SPEED 200) 300)
                                        (cons (make-rocket (+ SPEED 400) 600)
                                              (cons (make-rocket (+ SPEED 20) 700) empty))))

; (define (next-rockets lor) lor)  ;stub
;; <Template from ListOfRocket>
(define (next-rockets lor)
  (cond [(empty? lor) empty]
        [else
         (cons (next-rocket (first lor))
               (next-rockets (rest lor)))]))


;; Rocket -> Rocket
;; increase rocket x by speed, if crosses right edge again starts from 0
(check-expect (next-rocket R1) (make-rocket (+ SPEED 200) 300))
(check-expect (next-rocket R3) (make-rocket (+ SPEED 20) 700))

; (define (next-rocket r) r)  ;stub
;; <Template from Rocket>

(define (next-rocket r)
  (cond [(> (+ (rocket-x r) SPEED) WIDTH) (make-rocket (+ SPEED (modulo (rocket-x r) WIDTH)) (rocket-y r))]
        [else (make-rocket (+ (rocket-x r) SPEED) (rocket-y r))]))


;; ListOfRocket -> Image
;; Render the rocket images on MTS
(check-expect (render-rockets LOR1) MTS)
(check-expect (render-rockets LOR2) (place-image ROCKET 200 300
                                                 (place-image ROCKET 400 600
                                                              (place-image ROCKET 620 700 MTS))))

;(define (render-snails lor))  ;stub
;; <Templates from ListOfRocket>
(define (render-rockets lor)
  (cond [(empty? lor) MTS]
        [else
         (render-rocket (first lor)
                        (render-rockets (rest lor)))]))


;; Rocket Image -> Image
;; Place rocket into its correct (x, y) position on existing rocket image
(check-expect (render-rocket R1 MTS) (place-image ROCKET 200 300 MTS))

; (define (render-rocket r) MTS)  ;stub
;; Template from Rocket with added atomic paremeter

(define (render-rocket r img)
  (place-image ROCKET (rocket-x r) (rocket-y r) img))


;; ListOfRocket Number Number MouseEvent -> ListOfRocket
;; On mouse-click, adds a rocket to the list at (x, y) position
(check-expect (handle-mouse empty 150 412 "move") empty)
(check-expect (handle-mouse empty 150 412 "button-down") (cons
                                                          (make-rocket 150 412) empty))

;(define (handle-mouse lor mouse-x mouse-y me) lor)  ; stub
;; <Template according to MouseEvent>

(define (handle-mouse lor mouse-x mouse-y me)
  (cond [(mouse=? "button-down" me) (cons (make-rocket mouse-x mouse-y) lor)]
        [else lor]))

(main empty)