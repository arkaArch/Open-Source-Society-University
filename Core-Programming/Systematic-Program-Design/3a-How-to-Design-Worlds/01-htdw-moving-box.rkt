;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 01-htdw-moving-box) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem:
;; Use the How to Design Worlds recipe to design an interactive program in which a box starts
;; at the left edge of the display and then move across the screen to the right. When the box
;; reaches right edge it should just keep going right off the screen.
;; Once your design is complete revide it to add a new feature, which is that pressing the space
;; key should cause the box to go back to the left edge of the screen. When you do this, go all
;; the way back to your domain analysis and incorpoate the new feature.

;; Now first part of the recipe i.e Domain analysis is in the image file '01b-domain-anlysis.png'
;; Second part of the recipe:
;; Build the actual program
;; 1. Constants
;; 2. Data definitions using HtDD
;; 3. Functions using HtDF
;;      3.1. main first
;;      3.2. wish list entries for big-bang handlers
;; 4. Work through wish list until done

(require 2htdp/image)
(require 2htdp/universe)

;; A red box that moves from left to right across the screen.

;; =================
;; Constants:
(define WIDTH 600)
(define HEIGHT 400)

(define CTR-Y (/ HEIGHT 2))

(define SPEED 4)

(define MTS (empty-scene WIDTH HEIGHT))

(define BOX (square 40 "solid" "red"))

;; =================
;; Data definitions:

;; BoxPosition is number
;; interp. x position of the box in screen coordinates
(define BP1 0)            ; left edge
(define BP2 (/ WIDTH 2))  ; middle
(define BP3 WIDTH)        ; right edge
#;
(define (fn-for-box-position bp)
  (... bp))

;; Template rules used:
;;   - atomic non-distinct: Number

;; =================
;; Functions:

;; BoxPosition -> BoxPosition
;; start the world with (main 0)
;; 
(define (main bp)
  (big-bang bp                              
            (on-tick   next-box-position)   ; BoxPosition -> BoxPosition
            (to-draw   render)              ; BoxPosition -> Image
            (on-mouse  handle-mouse)        ; BoxPosition Integer Integer MouseEvent -> BoxPosition
            (on-key    handle-key)))        ; BoxPosition KeyEvent -> BoxImage

;; BoxPosition -> BoxPosition
;; produce the next box position by advancing it SPEED pixels to right
;; !!!
(check-expect (next-box-position 10) (+ 10 SPEED))

;(define (next-box-position bp) 0)  ; stub

;<use template from BoxPosition>

(define (next-box-position bp)
  (+ bp SPEED))


;; BoxPosition -> Image
;; render the box at appropriate position in MTS
;; !!!
(check-expect (render 12) (place-image BOX 12 CTR-Y MTS))
;(define (render bp) MTS) ; stub

;<use template from BoxPosition>

(define (render bp)
  (place-image BOX bp CTR-Y MTS))


;; BoxPosition Integer Integer MouseEvent -> BoxPosition
;; set box position's x-axis where mouse is clicked
(check-expect (handle-mouse 200 380 CTR-Y "button-down") 380)
;; (mouse-even box-position mouse-x-position mouse-y-position "mouse-event")

;(define (handle-mouse bp x CTR-Y me) 0)  ;stub

(define (handle-mouse bp x CTR-Y me)
  (cond [(mouse=? me "button-down") x]
        [else bp]))


;; BoxPosition KeyEvent -> BoxImage
;; reset box to left edge when space key is pressed
(check-expect (handle-key 200 " ") 0)
(check-expect (handle-key 200 "f") 200)

;(define (handle-key bp ke) 0)  ;stub

(define (handle-key bp ke)
  (cond [(key=? ke " ") 0]
        [else bp]))


;; NOTE:
;; Up here the combination of signature, purpose, !!! and stub are called a wish-list entry
;; '!!!' is a reminder of unfinished function. So it must deleted after completing the function.
;; Here I keep them for study purpose.
;; It promises to back and finish this function later.
;; In bigger programs you can have 10s or 100s wish list entries, so it pays to be disciplined
;; about writing down what you need to do later



