#lang racket

; Image functions from the 2nd edition of
; How to Design Programs book
(require 2htdp/image)

"apple"   ; This is a string
(string-length "apple")   ; 5
(string-append "Ada" " " "Lovelace")  ; String concatenation
(substring "Hello" 1 3)   ; 0 based indexing, last limit excludes 

(rectangle 20 40 "outline" "blue")
(text "Hello World!" 25 "orange")

; There are another functions like "above", "beside" and many more like overlay
(overlay (circle 5 "solid" "red")
         (circle 10 "solid" "yellow")
         (circle 15 "solid" "green"))
