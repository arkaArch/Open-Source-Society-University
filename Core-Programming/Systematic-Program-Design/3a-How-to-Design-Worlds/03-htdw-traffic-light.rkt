;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 03-htdw-traffic-light) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; 
;; Design an animation of a traffic light. 
;; 
;; Your program should show a traffic light that is red, then green, 
;; then yellow, then red etc. For this program, your changing world 
;; state data definition should be an enumeration.
;; 
;; Remember to follow the HtDW recipe! Be sure to do a proper domain 
;; analysis before starting to work on the code file.

(require 2htdp/image)
(require 2htdp/universe)
;; A traffic light shows first red light on, then green light, then yellow light and so on. 


;; Constants:
;;
(define WIDTH 60)
(define HEIGHT 200)

(define CTR-X (/ WIDTH 2))

(define RL-Y (/ HEIGHT 4))
(define GL-Y (/ HEIGHT 2))
(define YL-Y (/ (* 3 HEIGHT) 4))

(define DM 20)  ; Diameter of circle
(define ON "solid")  ; Light on indicates solid color
(define OFF "outline")  ; Light off indicates no color

(define MTS (empty-scene WIDTH HEIGHT "black"))

(define RLO (place-images
                             (list (circle DM ON "red")
                                   (circle DM OFF "green")
                                   (circle DM OFF "yellow"))
                             (list (make-posn CTR-X RL-Y)         ;; RED-LIGHT-ON
                                    (make-posn CTR-X GL-Y)
                                    (make-posn CTR-X YL-Y))
              MTS))

(define GLO (place-images
                             (list (circle DM OFF "red")
                                   (circle DM ON "green")
                                   (circle DM OFF "yellow"))
                             (list (make-posn CTR-X RL-Y)         ;; GREEN-LIGHT-ON
                                    (make-posn CTR-X GL-Y)
                                    (make-posn CTR-X YL-Y))
              MTS))

(define YLO (place-images
                             (list (circle DM OFF "red")
                                   (circle DM OFF "green")
                                   (circle DM ON "yellow"))
                             (list (make-posn CTR-X RL-Y)          ;; YELLOW-LIGHT-ON
                                    (make-posn CTR-X GL-Y)
                                    (make-posn CTR-X YL-Y))
              MTS))



;; Data definitions:
;;
;; Light is one of:
;;   - "red"
;;   - "green"
;;   - "yellow"
;; interp. the color of light show up in the signal
;; <examples are redundant for enumerations>
#;
(define (fn-for-light light)
  (cond [(string=? light "red") (...)]
        [(string=? light "green") (...)]
        [(string=? light "yellow") (...)]))

;; Template rules used:
;;  - one of: 3 cases
;;  - atomic distinct: "red"
;;  - atomic distinct: "green"
;;  - atomic distinct: "yellow"


;; Function:
;;
;; Light -> Light
;; called to run the animation; start with (main "red")

(define (main light)
  (big-bang light
            (on-tick next-light 1)    ; Light -> Light
            (to-draw render-light)))  ; Light -> Image


;; Light -> Light
;; Produce next color of light
(check-expect (next-light "red") "green")
(check-expect (next-light "green") "yellow")
(check-expect (next-light "yellow") "red")

;(define (next-light light) "red")  ; stub

;; <Templates from Light>

(define (next-light light)
  (cond [(string=? light "red") "green"]
        [(string=? light "green") "yellow"]
        [(string=? light "yellow") "red"]))


;; Light -> Image
;; render the lights at appropriate position in MTS
; (define (render-light light) MTS) ; stub
(check-expect (render-light "red") RLO)
(check-expect (render-light "green") GLO)
(check-expect (render-light "yellow") YLO)

;; <Templates from Light>

(define (render-light light)
  (cond [(string=? light "red") RLO]
        [(string=? light "green") GLO]
        [(string=? light "yellow") YLO]))