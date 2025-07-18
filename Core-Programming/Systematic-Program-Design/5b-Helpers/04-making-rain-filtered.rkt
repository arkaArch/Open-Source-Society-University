;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname making-rain-filtered) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; Design a simple interactive animation of rain falling down a screen. Wherever we click,
;; a rain drop should be created and as time goes by it should fall. Over time the drops
;; will reach the bottom of the screen and "fall off". You should filter these excess
;; drops out of the world state - otherwise your program is continuing to tick and
;; and draw them long after they are invisible.

;; In your design pay particular attention to the helper rules. In our solution we use
;; these rules to split out helpers:
;;   - function composition
;;   - reference
;;   - knowledge domain shift

(require 2htdp/image)
(require 2htdp/universe)

;; Constants:
;; =============
(define WIDTH 300)
(define HEIGHT 300)

(define SPEED 2)

(define DROP (ellipse 4 8 "solid" "blue"))

(define MTS (rectangle WIDTH HEIGHT "solid" "lightblue"))



;; Data definitions:
;; ===================
(define-struct drop (x y))
;; Drop is (make-drop Integer Integer)
;; interp. A raindrop on screen, with x and y coordinates
(define D1 (make-drop 10 15))

#;
(define (fn-for-drop d)
  (... (drop-x d)
       (drop-y d)))
;; Template rules used
;;   - compound: 2 fields


;; ListOfDrop is one of:
;;   - empty
;;   - (cons Drop ListOfDrop)
;; interp. a list of drops
(define LOD1 empty)
(define LOD2 (cons (make-drop 100 120)
                   (cons (make-drop 220 250)
                         empty)))
#;
(define (fn-for-lod lod)
  (cond [(empty? lod) (...)]
        [else
         (... (fn-for-drop (first lod))
              (fn-for-lod (rest lod)))]))
;; Template rules used
;;   - one of: 2cases
;;   - atomic distinct: empty
;;   - compound: (cons Drop ListOfDrop)
;;   - reference: (first lod)
;;   - self-reference: (rest lod) is ListOfDrop



;; Functions:
;; =============

;; ListOfDrop -> ListOfDrop
;; start rain program with (main empty)
(define (main lod)
  (big-bang lod
    (on-mouse handle-mouse)   ; ListOfDrop Integer Integer MouseEvent -> ListOfDrop
    (on-tick next-drops)      ; ListOfDrop -> ListOfDrop
    (to-draw render-drops)))  ; ListOfDrop -> Image


;; ListOfDrop Integer Integer MouseEvent -> ListOfDrop
;; if "button-down" rain drop will appear at mouse position
(check-expect (handle-mouse empty 12 15 "move") empty)
(check-expect (handle-mouse empty 12 15 "button-down")
               (cons (make-drop 12 15) empty))

;(define (handle-mouse lod mouse-x mouse-y m-event) empty)  ; stub
;; Template from MouseEvent

(define (handle-mouse lod mouse-x mouse-y m-event)
  (cond [(mouse=? m-event "button-down")
         (cons (make-drop mouse-x mouse-y) lod)]
        [else lod]))



;; ListOfDrop -> ListOfDrop
;; produce next postion of drops and discard the fall off drops
(check-expect (next-drops empty) empty)
(check-expect (next-drops (cons (make-drop 12 15)
                               (cons (make-drop 80 HEIGHT)
                                     empty)))
              (cons (make-drop 12 (+ SPEED 15))
                    empty))

;(define (next-drops lod) lod)  ; stub
;; Template as function composition>

(define (next-drops lod)
  (onscreen-drops (tick-drops lod)))


;; ListOfDrop -> ListOfDrop
;; produce next position of drops on a tick
(check-expect (tick-drops empty) empty)
(check-expect (tick-drops (cons (make-drop 12 15)
                               (cons (make-drop 80 90)
                                     empty)))
              (cons (make-drop 12 (+ SPEED 15))
                    (cons (make-drop 80 (+ SPEED 90))
                          empty)))

;(define (tick-drops lod) lod)  ; stub
;; <Templates from ListOfDrop>

(define (tick-drops lod)
  (cond [(empty? lod) empty]
        [else
         (cons (tick-drop (first lod))
              (tick-drops (rest lod)))]))



;; Drop -> Drop
;; produce next position of a drop
(check-expect (tick-drop (make-drop 12 15))
  (make-drop 12 (+ SPEED 15)))

;(define (tick-drop d) d)  ; stub
;; <Took templates from Drop>

(define (tick-drop d)
  (make-drop (drop-x d)
       (+ SPEED (drop-y d))))



;; ListOfDrop -> ListOfDrop
;; produce a list of drops which are within screen
(check-expect (onscreen-drops empty) empty)
(check-expect (next-drops (cons (make-drop 12 15)
                               (cons (make-drop 80 (+ HEIGHT 1))
                                     empty)))
              (cons (make-drop 12 (+ SPEED 15))
                    empty))

;(define (onscreen-drops lod) lod)  ; stub
;; <Templates from ListOfDrop>

(define (onscreen-drops lod)
  (cond [(empty? lod) empty]
        [else
         (if (onscreen? (first lod))
             (cons (first lod) (onscreen-drops (rest lod)))
             (onscreen-drops (rest lod)))]))



;; Drop -> Boolean
;; produce true if drop is within screen
(check-expect (onscreen? (make-drop 2 -1)) #false)
(check-expect (onscreen? (make-drop 12 0)) #true)
(check-expect (onscreen? (make-drop 12 150)) #true)
(check-expect (onscreen? (make-drop 200 HEIGHT)) #true)
(check-expect (onscreen? (make-drop 200 (+ HEIGHT 1))) #false)

; (define (onscreen? d) #false)  ;stub
;; Templates from Drop

(define (onscreen? d)
  (and (<= 0 (drop-y d))
       (<= (drop-y d) HEIGHT)))
;; This can be also write as
#;
(define (onscreen? d)
  (<= 0 (drop-y d) HEIGHT))



;; ListOfDrop -> Image
;; render image of drops at their correct position
(check-expect (render-drops empty) MTS)
(check-expect (render-drops (cons (make-drop 120 220) empty))
              (place-image DROP 120 220 MTS))
(check-expect (render-drops (cons (make-drop 120 220)
                                  (cons (make-drop 12 34)
                                        empty)))
              (place-image DROP 120 220
                           (place-image DROP 12 34 MTS)))

;(define (render-drops lod) MTS)  ; stub
;; Templates of ListOfDrop

(define (render-drops lod)
  (cond [(empty? lod) MTS]
        [else
         (render-drop (first lod)
         (render-drops (rest lod)))]))


;; Drop Image -> Image
(check-expect (render-drop (make-drop 9 5) MTS)
              (place-image DROP 9 5 MTS))

;(define (render-drop d i) MTS)  ; stub
;; Templates from drop with an extra atomic parameter

(define (render-drop d i)
  (place-image DROP (drop-x d) (drop-y d) i))
