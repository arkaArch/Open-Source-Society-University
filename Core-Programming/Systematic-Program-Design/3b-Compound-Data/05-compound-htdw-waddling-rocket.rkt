;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 05-compound-htdw-cowabunga) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM: 
;; Design a world program with the following behaviour:
;;    - A rocket flies back and forth across the screen.
;;    - When it gets to an edge it changes direction and goes back the other way
;;    - When you start the program it should be possible to control how fast a
;;      flier your rocket is.
;;    - Pressing space makes it change direction right away.
;; 
;; Once your program works here is something you can try for fun. If you rotate the
;; images of the rocket slightly, and you vary the image you use as the rocket moves, you
;; can make it appear as if the rocket is waddling as it flies across the screen.

(require 2htdp/image)
(require 2htdp/universe)
;; A rocket, meandering back and forth across the screen

;; CONSTANTS:
(define WIDTH 600)
(define HEIGHT 400)
(define CTR-Y (/ HEIGHT 2))
(define MTS (empty-scene WIDTH HEIGHT))

(define R-ROCKET (beside
 (rectangle 30 28 "solid" "red")
 (rotate 90 (triangle/sss 65 65 50 "solid" "blue"))))

(define L-ROCKET (rotate 180 (beside
 (rectangle 30 28 "solid" "red")
 (rotate 90 (triangle/sss 65 65 50 "solid" "blue")))))

(define ANGLE 2)

(define R-ROCKET-UP (rotate ANGLE R-ROCKET))
(define L-ROCKET-UP (rotate ANGLE L-ROCKET))
(define R-ROCKET-DN (rotate (- ANGLE) R-ROCKET))
(define L-ROCKET-DN (rotate (- ANGLE) L-ROCKET))

;; Data Definition:
(define-struct rocket (x dx))
;; Rocket is (make-rocket Natural[0, WIDTH] Integer)
;; iterp. (make-rocket x dx) is a moving rocket with x-cordinate x and velocity dx
;;        x is the distace from screen to the middle of the rocket (pixels)
;;        dx is in pixel per tick
;;
(define R1 (make-rocket 10 3))  ; at 10, left -> right
(define R2 (make-rocket 20 -4))  ; at 20, left <- right

#;
(define (fn-for-rocket r)
  (... (rocket-x r)       ; Natural[0, WIDTH]
       (rocket-dx r)))    ; Integer

;; Template rules used:
;;  - compound: 2 fields


;; Functions:
;; Rocket -> Rocket
;; start the world with (main (make-rocket 0 3)). To waddle the cow, dx must be odd
;; no tests for main function
(define (main c)
  (big-bang c                              
            (on-tick   next-rocket)    ; Rocket -> Rocket
            (to-draw   render-rocket)  ; Rocket -> Image
            (on-key    handle-key)))   ; Rocket KeyEvent -> Rocket


;; Rocket -> Rocket
;; increase rocket x by dx; bounce off edge
(check-expect (next-rocket (make-rocket 100 3)) (make-rocket 103 3))   ;rocket is in middle going left->right
(check-expect (next-rocket (make-rocket 100 -3)) (make-rocket 97 -3))  ;rocket is in middle going left<-right

;; Remember rocket is going at speed 3px/tick
(check-expect (next-rocket (make-rocket (- WIDTH 3) 3)) (make-rocket WIDTH 3))   ;rocket is in right edge going left->right it has to go all up to width
(check-expect (next-rocket (make-rocket 3 -3)) (make-rocket 0 -3))               ;rocket is in left edge going left<-right it has to go all up to width

(check-expect (next-rocket (make-rocket (- WIDTH 2) 3)) (make-rocket WIDTH -3))  ;rocket tries to cross the right edge
(check-expect (next-rocket (make-rocket 2 -3)) (make-rocket 0 3))                ;rocket tries to cross the left edge

;(define (next-rocket c) c)  ; stub
;<Templates from Rocket>

(define (next-rocket c)
  (cond [(> (+ (rocket-x c) (rocket-dx c)) WIDTH) (make-rocket WIDTH (- (rocket-dx c)))]    ;rocket tries to cross the right edge
        [(< (+ (rocket-x c) (rocket-dx c))     0) (make-rocket     0 (- (rocket-dx c)))]    ;rocket tries to cross the left edge
        [else (make-rocket (+ (rocket-x c) (rocket-dx c)) (rocket-dx c))]))


;; Rocket -> Image
;; render the correct image of the rocket at its x-position and CTR-Y on MTS 
(check-expect (render-rocket (make-rocket 100 3)) (place-image R-ROCKET-UP 100 CTR-Y MTS))    ;rocket is going left->right in even co-ordinate
(check-expect (render-rocket (make-rocket 101 3)) (place-image R-ROCKET-DN 101 CTR-Y MTS))    ;rocket is going left->right in odd co-ordinate

(check-expect (render-rocket (make-rocket 100 -3)) (place-image L-ROCKET-UP 100 CTR-Y MTS))   ;rocket is going left<-right in even co-ordinate
(check-expect (render-rocket (make-rocket 101 -3)) (place-image L-ROCKET-DN 101 CTR-Y MTS))   ;rocket is going left<-right in odd co-ordinate

(check-expect (render-rocket (make-rocket 100 0)) (place-image L-ROCKET-DN 100 CTR-Y MTS))    ;rocket is resting

;(define (render-cow r) MTS)  ; stub
;<Templates from Rocket>

(define (render-rocket c)
  ;; Check rocket is resting or not
  (if (= (rocket-dx c) 0)
      (place-image L-ROCKET-DN (rocket-x c) CTR-Y MTS)
      ;; Check rocket-dx is +ve/-ve
      (if (> (rocket-dx c) 0)                        
          ;; Check rocket-x is odd/even
          (if (odd? (rocket-x c))
              (place-image R-ROCKET-DN (rocket-x c) CTR-Y MTS)
              (place-image R-ROCKET-UP (rocket-x c) CTR-Y MTS))
          (if (odd? (rocket-x c))
              (place-image L-ROCKET-DN (rocket-x c) CTR-Y MTS)
              (place-image L-ROCKET-UP (rocket-x c) CTR-Y MTS)))))


;; Rocket KeyEvent -> Rocket
;; reverse direction of rocket travel when space bar is pressed
(check-expect (handle-key (make-rocket 100 3) " ") (make-rocket 100 -3))
(check-expect (handle-key (make-rocket 100 -3) " ") (make-rocket 100 3))
(check-expect (handle-key (make-rocket 100 -3) "a") (make-rocket 100 -3))

;(define (handle-key c ke) c)  ;stub

(define (handle-key c ke)
  (cond [(key=? ke " ") (make-rocket (rocket-x c) (- (rocket-dx c)))]
        [else c]))
