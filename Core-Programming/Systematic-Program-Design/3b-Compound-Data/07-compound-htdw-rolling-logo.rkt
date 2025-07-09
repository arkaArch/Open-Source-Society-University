;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 07-compound-htdw-rolling-logo-v1) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; Design a world program as follows:
;; The world starts off with a open-source logo on the left hand side of the screen.
;; As time passes, the logo will roll towards the right hand side of the screen. 
;; Clicking the mouse changes the direction the logo is rolling (i.e. from 
;; left -> right to right -> left). If the logo hits the side of the window 
;; it should also change direction.
;; 
;; I worked with this code without any state, just with raw compound-data
;; It's hectic to manage rotation angle this way, but for myself it's JOYFULL 🫩

(require 2htdp/image)
(require 2htdp/universe)
;; An open-source logo rolling back and forth across the screen

;; Constants:
(define WIDTH 500)
(define HEIGHT 200)
(define CTR-Y (/ HEIGHT 2))

(define LOGO
  (overlay (circle 10 "solid" "white")
           (rotate -60 (wedge 30 300 "solid" "seagreen"))))

(define MTS (empty-scene WIDTH HEIGHT))

(define R-ANGLE 4)  ; Rotation angle

;; Data Definition
(define-struct logo (x dx r))
;; Logo is (make-logo Natural[0, WIDTH] Integer Number[0, 360))
;; interp. (make-logo (x dx r)) is a rolling open source logo with x-coordinate x and rotation angle r
;;         x is the distace from screen to the middle of the balloon (pixels)
;;         dx is in pixel per tick
;;         r is the rotation per tick
(define L1 (make-logo 100 3 45))
#;
(define (fn-for-logo l)
  (... (logo-x l)        ; Integer[0, WIDTH]
       (logo-dx l)       ; Integer
       (logo-r l)))      ; Number[0, 360)
;; Template rules used:
;;   - compound: 3 fields


;; Functions
;; Logo -> Logo
;; start world with (main (make-logo 0 3 0))
;; no test for main function
(define (main l)
  (big-bang l
    (on-tick next-logo)         ; Logo -> Logo
    (to-draw render-logo)       ; Logo -> Image
    (on-mouse handle-mouse)))   ; Logo Number Number MouseEvent -> Logo



;; Logo -> Logo
;; increase logo x by dx and change angle of rotation

;; Make negative angle rotation when logo move left -> right
;; Make positive angle rotation when logo move left <- right
(check-expect (next-logo (make-logo 100 3 -5)) (make-logo 103 3 (- (+ R-ANGLE 5))))  ;; Far from edge left -> right
(check-expect (next-logo (make-logo 100 -3 5)) (make-logo 97 -3 (+ R-ANGLE 5)))      ;; Far from edge left <- right

(check-expect (next-logo (make-logo (- WIDTH 2) 3 -480)) (make-logo WIDTH -3 (- (+ R-ANGLE -120))))   ;; Right edge
(check-expect (next-logo (make-logo 2 -3 480)) (make-logo 0 3 (+ R-ANGLE -120)))                      ;; Left edge

;(define (next-logo l) l)  ;stub
;<Templates from Logo>

(define (next-logo l)
  (cond [(> (+ (logo-x l) (logo-dx l)) WIDTH)  ;; Try to cross right edge
         (make-logo WIDTH (- (logo-dx l)) (modulo (- (+ R-ANGLE (logo-r l))) 360))]
        [(< (+ (logo-x l) (logo-dx l)) 0)  ;; Try to cross left edge
         (make-logo 0 (- (logo-dx l)) (- (modulo (- (+ R-ANGLE (- (logo-r l)))) 360)))]
        [(> (logo-dx l) 0)  ;; Move left -> right far from edge
         (make-logo (+ (logo-x l) (logo-dx l)) (logo-dx l) (- (modulo (+ R-ANGLE (- (logo-r l))) 360)))]  
        [(< (logo-dx l) 0)  ;; Move left <- right far from edge
         (make-logo (+ (logo-x l) (logo-dx l)) (logo-dx l) (modulo (+ R-ANGLE (logo-r l)) 360))]))



;; Logo -> Image
;; render the correct image of the logo at its x-position and CTR-Y with it's correct angle on MTS
(check-expect (render-logo (make-logo 2 -3 80)) (place-image (rotate 80 LOGO) 2 CTR-Y MTS))

;(define (render-logo l) MTS)  ;stub
;<Templates from Logo>

(define (render-logo l)
  (place-image (rotate (logo-r l) LOGO) (logo-x l) CTR-Y MTS))

;; Logo Number Number MouseEvent -> Logo
;; changes the direction the logo is rolling on mouse click
(check-expect (handle-mouse (make-logo 2 -3 80) 120 CTR-Y "button-down") (make-logo 2 3 80))

;(define (handle-mouse l x CTR-Y me) 0)  ;stub

(define (handle-mouse l mouse-x mouse-y me)
  (cond [(mouse=? me "button-down") (make-logo (logo-x l) (- (logo-dx l)) (logo-r l))]
        [else l]))

(main (make-logo 0 3 0))




































