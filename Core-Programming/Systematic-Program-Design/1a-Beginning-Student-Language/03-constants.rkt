#lang racket
(require 2htdp/image)

(define WIDTH 20)
(define HEIGHT 30)
(* WIDTH HEIGHT)

; We can directly copy image into the language
(define TREE
  (above (circle 20 "solid" "green")
         (rectangle 10 15 "solid" "brown")))

(beside (rotate 20 TREE)    ; Rotate tree 20 degree to the right
        (rotate -20 TREE))  ; Rotate tree 20 degree to the left
        
         
