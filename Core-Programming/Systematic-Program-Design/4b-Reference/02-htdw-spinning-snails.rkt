;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname spinning-bears) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; In this problem you will design another world program. In this program the changing 
;; information will be more complex - your type definitions will involve arbitrary 
;; sized data as well as the reference rule and compound data. But by doing your 
;; design in two phases you will be able to manage this complexity. As a whole, this problem 
;; will represent an excellent summary of the material covered so far in the course, and world 
;; programs in particular.
;;
;; This world is about spinning snails. The world will start with an empty screen. Clicking
;; anywhere on the screen will cause a snail to appear at that spot. The snail starts out upright,
;; but then rotates counterclockwise at a constant speed. Each time the mouse is clicked on the 
;; screen, a new upright snail appears and starts spinning.
;; 
;; So each snail has its own x and y position, as well as its angle of rotation. And there are an
;; arbitrary amount of snails.


(require 2htdp/image)
(require 2htdp/universe)
;; Snails spinning across the screen


;; Constants:
;; ===============
(define SNAIL (text "🐌" 40 "white"))
(define WIDTH 600)
(define HEIGHT 800)
(define R-SPEED 5)
(define MTS (empty-scene WIDTH HEIGHT))


;; Data definitions:
;; ===============
(define-struct snail (x y r))
;; Snail is (make-snail Natural[0, WIDTH] Natural[0, HEIGHT] Integer)
;; interp. (make-snail (x y r)) is a rotating snail with r angle in it's axis in (x, y) co-ordinate
;;         x is the position from left and right side of the screen
;;         y is the middle point from top and bottom side of the screen
;;         r is the rotation per tick
;;
(define S1 (make-snail 12 15 R-SPEED))
(define S2 (make-snail 100 234 R-SPEED))
(define S3 (make-snail 400 600 R-SPEED))
#;
(define (fn-for-snail s)
  (... (snail-x s)
       (snail-y s)
       (snail-r s)))
;; Template rule used:
;;   - compound: 3 fields


;; ListOfSnail is one of:
;;   - empty
;;   - (cons Snail ListOfSnail)
;; interp. a list of snail
(define LOS1 empty)
(define LOS3 (cons S1 (cons S2 (cons S3 empty))))
#;
(define (fn-for-los los)
  (cond [(empty? los) (...)]
        [else
         (... (fn-for-snail (first los))
              (fn-for-los (rest los)))]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic-distinct: empty
;;   - compound: (cons Snail ListOfSnail)
;;   - reference: (first los)
;;   - self-reference: (rest los) is ListOfSnail



;; Functions:
;; ===============

;; ListOfSnail -> ListOfSnail
;; Start world with (main empty)
;; no test for main function
(define (main los)
  (big-bang los                  ; ListOfSnail
    (on-tick rotate-snails)      ; ListOfSnail -> ListOfSnail
    (to-draw render-snails)      ; ListOfSnail -> Image
    (on-mouse handle-mouse)))    ; ListOfSnail Number Number MouseEvent -> ListOfSnail


;; ListOfSnail -> ListOfSnail
;; rotate snail at (x, y) position by rotation speed R-SPEED
(check-expect (rotate-snails LOS1) empty)
(check-expect (rotate-snails LOS3) (cons (make-snail 12 15 (* 2 R-SPEED))
                                         (cons (make-snail 100 234 (* 2 R-SPEED))
                                               (cons (make-snail 400 600 (* 2 R-SPEED)) empty))))

;(define (rotate-snails los) los)  ; stub
;; <Template from ListOfSnail>
(define (rotate-snails los)
  (cond [(empty? los) empty]
        [else
         (cons (rotate-snail (first los))
              (rotate-snails (rest los)))]))


;; Snail -> Snail
;; Rotate snail forward by R-SPEED
(check-expect (rotate-snail (make-snail 200 300 R-SPEED)) (make-snail 200 300 (* 2 R-SPEED)))

;(define (rotate-snail s) s)  ; stub
;; <Template from Snail>
(define (rotate-snail s)
  (make-snail (snail-x s)
              (snail-y s)
              (+ R-SPEED (snail-r s))))


;; ListOfSnail -> Image
;; Render the snails on empty screen
(check-expect (render-snails LOS1) MTS)
(check-expect (render-snails LOS3) (place-image (rotate R-SPEED SNAIL) 12 15
                                                (place-image (rotate R-SPEED SNAIL) 100 234
                                                             (place-image (rotate R-SPEED SNAIL) 400 600 MTS))))

; (deifne (render-snails los) MTS)  ; stub
;; <Template from ListOfSnail>

(define (render-snails los)
  (cond [(empty? los) MTS]
        [else
         (render-snail (first los)
                       (render-snails (rest los)))]))


;; Snail Image -> Image
;; Render an image of the bear on the given image rather MTS
(check-expect (render-snail (make-snail 200 300 R-SPEED) MTS) (place-image (rotate R-SPEED SNAIL) 200 300 MTS))

;(define (render-snail s img) MTS)  ; stub
;; Took Template from Snail with added atomic parameter img

(define (render-snail s img)
  (place-image (rotate (snail-r s) SNAIL)
               (snail-x s)
               (snail-y s)
               img))


;; Snail Number Number MouseEvent -> ListOfSnail
;; On mouse-click, adds a bear with 0 rotation to the list at the x, y location 
(check-expect (handle-mouse empty 150 412 "move") empty)
(check-expect (handle-mouse empty 150 412 "button-down") (cons
                                                          (make-snail 150 412 0) empty))

;(define (handle-mouse los mouse-x mouse-y me) los)  ;stub
;; <Template according to MouseEvent>

(define (handle-mouse los mouse-x mouse-y me)
  (cond [(mouse=? "button-down" me) (cons (make-snail mouse-x mouse-y 0) los)]
        [else los]))

(main empty)




