;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 06-compound-htdw-water-balloon) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; In this problem, we will design an animation of throwing a water balloon.  
;; When the program starts the water balloon should appear on the left side 
;; of the screen, half-way up.  Since the balloon was thrown, it should 
;; fly across the screen, rotating in a clockwise fashion. Pressing the 
;; space key should cause the program to start over with the water balloon
;; back at the left side of the screen. 

;; NOTE: The rotate function wants an angle in degrees as its first 
;; argument. By that it means Number[0, 360). As time goes by your balloon 
;; may end up spinning more than once, for example, you may get to a point 
;; where it has spun 362 degrees, which rotate won't accept. 
;; 
;; The solution to that is to use the modulo function as follows:
;; (rotate (modulo ... 360) (text "hello" 30 "black"))
;; where ... should be replaced by the number of degrees to rotate.
;; 
;; NOTE: It is possible to design this program with simple atomic data, 
;; but we would like you to use compound data.

(require 2htdp/image)
(require 2htdp/universe)
;; A water-balloon fly across the screen, rotating in a clockwise fashion

;; CONSTANTS:
(define WIDTH 600)
(define HEIGHT 400)
(define CTR-Y (/ HEIGHT 2))
(define MTS (empty-scene WIDTH HEIGHT))

(define BALLOON (overlay/xy
                 (rotate -90 (triangle 30 "solid" "lightseagreen"))
                 15 -20
                 (ellipse 80 60 "solid" "aquamarine")))

(define SPEED 5)
(define R-ANGLE 6)


;; Data Definition:
(define-struct balloon (x r))
;; Balloon is (make-balloon Integer Natural[0, 360))
;; interp. (make-balloon (x r)) is a moving water-balloon with x-coordinate x and rotation angle r
;;         x is the distace from screen to the middle of the balloon (pixels)
;;         r is the rotation per tick
;;
(define B1 (make-balloon 20 45))
(define B2 (make-balloon 20 300))

#;
(define (fn-for-balloon b)
  (... (balloon-x b)      ; Integer 
       (balloon-r b)))    ; Natural[0, 360) 

;; Template rules used:
;;  - compound: 2 fields


;; Functions:
;; Balloon -> Balloon
;; start world with (main (make-balloon 0 0))
;; no tests for main function
(define (main b)
  (big-bang b
    (on-tick next-balloon)   ;Balloon -> Balloon
    (to-draw render-balloon)   ;Balloon -> Image
    (on-key  handle-key)))     ;Balloon KeyEvent -> Balloon


;; Balloon -> Balloon
;; increse balloon x by speed and change angle of rotation
(check-expect (next-balloon (make-balloon 120 45)) (make-balloon (+ SPEED 120) (+ R-ANGLE 45)))
(check-expect (next-balloon (make-balloon 120 372)) (make-balloon (+ SPEED 120) (modulo (+ R-ANGLE 372) 360)))

;(define (next-balloon b) b)  ;stub
; <Templates from Balloon>

(define (next-balloon b)
  (make-balloon
   (+ (balloon-x b) SPEED)
   (modulo (+ R-ANGLE (balloon-r b)) 360)))


;; Balloon -> Image
;; place balloon at its x-position and CTR-Y on MTS with it's proper angle 
(check-expect (render-balloon (make-balloon 120 45)) (place-image (rotate 45 BALLOON) 120 CTR-Y MTS))

;(define (render-balloon b) MTS)  ;stub
; <Templates from Balloon>

(define (render-balloon b)
  (place-image (rotate (balloon-r b) BALLOON) (balloon-x b) CTR-Y MTS))


;; Balloon KeyEvent -> Balloon
;; place the balloon back to it's starting position when space key is pressed 
(check-expect (handle-key (make-balloon 120 45) " ") (make-balloon 0 0))
(check-expect (handle-key (make-balloon 120 45) "a") (make-balloon 120 45))

;(define (handle-key b ke) b)  ;stub

(define (handle-key b ke)
  (cond [(key=? ke " ") (make-balloon 0 0)]
  [else b]))





















































