;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 08-compound-htdw-rolling-logo-v2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; Design a world program as follows:
;; The world starts off with a open-source logo on the left hand side of the screen.
;; As time passes, the logo will roll towards the right hand side of the screen. 
;; Clicking the mouse changes the direction the logo is rolling (i.e. from 
;; left -> right to right -> left). If the logo hits the side of the window 
;; it should also change direction.
;; 
;; Work out the math you need to in order to make the logo look like it is
;; actually rolling. Remember that the circumference of a circle is 2*pi*radius,
;; so that for each degree of rotation the circle needs to move: {(2*pi*radius) / 360}

(require 2htdp/image)
(require 2htdp/universe)
;; A lambda that rolls back and forth across screen.

;; Constants:
(define BALL (text "⚽" 40 "white"))
(define ALMOST-PI 3.14159)
;; We use ALMOST-PI instead of pi because if we use pi
;; then we end up having to use check-within in all the tests
(define RADIUS (/ (image-height BALL) 2))
(define CIRCUMFERENCE (* 2 ALMOST-PI RADIUS))

(define X-MOVE-PER-DEGREE (/ CIRCUMFERENCE 360))
;; This is how far a circle moves in the x direction for each degree of angle it turns.

(define ANGULAR-SPEED -2)  ;; Change degree in a clock tick
(define X-SPEED (* -1 ANGULAR-SPEED X-MOVE-PER-DEGREE))  ;; Change x-position of ball per clock tick

(define WIDTH (+ CIRCUMFERENCE (* 2 RADIUS)))
(define HEIGHT 100)

(define YPOS (- HEIGHT RADIUS))  ;; BALL rolls on floor

(define MTS (empty-scene WIDTH HEIGHT))



;; Data definitions:
(define-struct ball (d x r))
;; Logo is (make-ball Integer Natural[0, WIDTH] Number[0, 360))
;; interp. d is the direction ball is moving, -1 means to left, +1 means to right
;;         x is screen coordinate of center of ball
;;         r is angular rotation of ball
(define B1 (make-ball 1 5 100))
(define B2 (make-ball -1 10 50))
#;
(define (fn-for-ball b)
  (... (ball-d b)        ; Integer
       (ball-x b)        ; Integer[0, WIDTH]
       (ball-r b)))      ; Number[0, 360)
;; Template rules used:
;;   - compound: 3 fields



;; Functions:
;; Ball -> Ball
;; starts the world - to start with BALL at left hand side evaluate (main (make-ball 1 RADIUS 359))
;; <examples not needed>
(define (main l)
  (big-bang l
    (on-tick next-ball)         ; Ball -> Ball
    (to-draw render-ball)       ; Ball -> Image
    (on-mouse handle-mouse)))   ; Ball Number Number MouseEvent -> Ball


;; Ball -> Ball
;; roll the ball in direction ball-d
(check-expect (next-ball (make-ball 1 60 100)) (make-ball 1 (+  60 X-SPEED) (+ 100 ANGULAR-SPEED)))  ; Ball is away from edge
(check-expect (next-ball (make-ball 1 (- WIDTH RADIUS) 1)) (make-ball -1 (- WIDTH RADIUS) 1))        ; Ball touches the right edge 
(check-expect (next-ball (make-ball -1 0 359)) (make-ball 1 RADIUS 359))                             ; Ball touches the left edge

;(define (next-ball b) b)  ;stub
;; <took template from Ball>

(define (next-ball b)
  (cond [(>= (+ (ball-x b) (* (ball-d b) X-SPEED)) (- WIDTH RADIUS)) (make-ball -1 (- WIDTH RADIUS) 1)]  ;; hit right edge
        [(<= (+ (ball-x b) (* (ball-d b) X-SPEED)) RADIUS) (make-ball 1 RADIUS 359)]                    ;; hit left edge
        [else (make-ball (ball-d b) (+ (ball-x b) (* (ball-d b) X-SPEED)) (modulo (+ (ball-r b) (* (ball-d b) ANGULAR-SPEED)) 359))]))



;; Ball -> Image
;; place the ball at ball-x, with angle ball-r
(check-expect (render-ball B1) (place-image (rotate (ball-r B1) BALL) (ball-x B1) YPOS MTS))

;(define (render-ball Ball) MTS)  ; stub
; <took template from Ball>

(define (render-ball b) (place-image (rotate (ball-r b) BALL) (ball-x b) YPOS MTS))


;; Ball Number Number MouseEvent -> Ball
;; reverse direction of ball (ball-d)
(check-expect (handle-mouse B1 0 0 "button-down") (make-ball -1  5 100))
(check-expect (handle-mouse B2 10 20 "button-down") (make-ball 1 10 50))

;(define (handle-mouse b mouse-x mouse-y me) b)  ; stub
; <template according to MouseEvent>

(define (handle-mouse b mouse-x mouse-y me)
   (cond [(mouse=? "button-down" me) (make-ball (* -1 (ball-d b)) (ball-x b) (ball-r b))]
         [else b]))

(main (make-ball 1 RADIUS 359))


















