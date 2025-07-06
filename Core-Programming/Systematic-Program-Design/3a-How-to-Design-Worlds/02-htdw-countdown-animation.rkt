;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 02-htdw-countdown-animation) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; 
;; Design an animation of a simple countdown. 
;; 
;; Your program should display a simple countdown, that starts at ten, and
;; decreases by one each clock tick until it reaches zero, and stays there.
;; 
;; To make your countdown progress at a reasonable speed, you can use the 
;; rate option to on-tick. If you say, for example, 
;; (on-tick advance-countdown 1) then big-bang will wait 1 second between 
;; calls to advance-countdown.
;; 
;; Remember to follow the HtDW recipe! Be sure to do a proper domain 
;; analysis before starting to work on the code file.
;; 
;; Once you are finished the simple version of the program, you can improve
;; it by reseting the countdown to ten when you press the spacebar.

(require 2htdp/image)
(require 2htdp/universe)

;; A countdown, shows from 10 to 0 in screen.

;; Constants:
;;
(define WIDTH 100)
(define HEIGHT 120)

(define CTR-X (/ WIDTH 2))
(define CTR-Y (/ HEIGHT 2))

(define TEXT-SIZE 35)
(define TEXT-COLOR "black")

(define MTS (empty-scene WIDTH HEIGHT))

;; Data definitions:
;;
;; Countdown is Natural[0, 10]
;; interp. the current seconds remaining in the countdown
(define CTD1 10)
(define CTD2 5)
(define CTD3 0)
#;
(define (fn-for-countdown ctd)
  (... ctd))

;; Template rules used:
;;  - atomic non-distinct: Natural[0, 10]


;; Function:
;;
;; Countdown -> Countdown
;; called to run the animation; start with (main 10)
(define (main ctd)
  (big-bang ctd
            (on-tick  advance-countdown 0.8)  ; Countdown -> Countdown
            (to-draw  render)                 ; Countdown -> Image
            (on-key   handle-key)))           ; Countdown KeyEvent -> Countdown

;; Countdown -> Countdown
;; Produce how many time left by subtracting 1 from previous
(check-expect (advance-countdown 10) 9)
(check-expect (advance-countdown 5) 4)
(check-expect (advance-countdown 0) 0)

;(define (advance-countdown ctd) 0)  ; stub

;; <Templates from Countdown>

(define (advance-countdown ctd)
  (if (> ctd 0) (- ctd 1) 0))


;; Countdown -> Image
;; render the countdown at appropriate position in MTS
(check-expect (render 10) (place-image (text "10" TEXT-SIZE TEXT-COLOR)
                                       CTR-X CTR-Y
                                       MTS))
(check-expect (render 0) (place-image (text "0" TEXT-SIZE TEXT-COLOR)
                                       CTR-X CTR-Y
                                       MTS))
; (define (render ctd) MTS) ; stub

;; <Templates from Countdown>

(define (render ctd)
  (place-image (text (number->string num) TEXT-SIZE TEXT-COLOR)
               CTR-X CTR-Y
               MTS))


;; Countdown KeyEvent -> Countdown
;; reset countdown to 10 when space key is pressed
(check-expect (handle-key 5 " ") 10)
(check-expect (handle-key 0 " ") 10)
(check-expect (handle-key 6 "t") 6)

; (define (handle-key ctd ke) 0)  ; stub

;<template from KeyEvent>

(define (handle-key ctd ke)
  (cond [(key=? ke " ") 10]
        [else ctd]))
