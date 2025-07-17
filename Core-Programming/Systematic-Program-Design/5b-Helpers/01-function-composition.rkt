;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Function-Composition) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Problem
;; Imagine you have a bunch of picture that you would like to store as data and
;; present in different ways. We'll do a simple version of that here, and set
;; the stage for a more elaborate version later.
;;
;; (A) Design a data definition to represent an arbitary number of images.
;; (B) Design a funtion that consumes an arbitary number of images and lays
;;     them out left-to-right in increasing order of size.

(require 2htdp/image)
;; Constant

(define BLANK (rectangle 0 0 "solid" "white"))

;; Data definition

;; ListOfImage is one of:
;;   - empty
;;   - (cons Image ListOfImage)
;; interp. a list of image
(define LOI1 empty)
(define LOI2 (cons (rectangle 20 30 "solid" "blue")
                   (cons (rectangle 10 20 "solid" "red") empty)))
#;
(define (fn-for-loi loi)
  (cond [(empty? loi) (...)]
        [else
         (... (first loi)
              (fn-for-loi (rest loi)))]))

;; Template rules used:
;;   - one of: 2 cases
;;   - atomic distinct: empty
;;   - compound: (cons Image ListOfImage)
;;   - self-reference: (rest loi) is ListOfImage




;; Functions:

;; ListOfImage -> Image
;; layout images left-to-right in increasing order of size

;; NOTE: Tests for arrange-images do not need to fully exercise layout-images
;;       and sort-images; but they do need to exercise the combination of the
;;       two functions. And in case of function composition base case test isn't
;;       really needed.

(check-expect (arrange-images (cons (rectangle 20 30 "solid" "blue")
                                    (cons (rectangle 30 40 "solid" "red")
                                          empty)))
              (beside (rectangle 20 30 "solid" "blue")
                      (rectangle 30 40 "solid" "red")
                      BLANK))

(check-expect (arrange-images (cons (rectangle 20 30 "solid" "blue")
                                    (cons (rectangle 10 20 "solid" "red")
                                          empty)))
              (beside (rectangle 10 20 "solid" "red")
                      (rectangle 20 30 "solid" "blue")
                      BLANK))

;(define (arrange-images loi) BLANK)  ;stub

;; Now this is a case of function composition:
;; Use function composition when a function must perform two or more distinct
;; and complete operations on the consumed data. Like here:
;; The function that must sort and layout a list of images. First it must sort
;; the complete list and then lay it out. It cannot sort and layout each image
;; one at a time.

;; When using function composition the normal template for the function is
;; discarded, and the body of the function has two or more function compositions.
;; So in the case of arrange-images the function design would look like this:

(define (arrange-images loi)
  (layout-images (sort-images loi)))



;; ListOfImage -> Image
;; place images beside each other in order of list
(check-expect (layout-images LOI1) BLANK)
(check-expect (layout-images (cons (rectangle 20 30 "solid" "blue")
                                   (cons (rectangle 10 20 "solid" "red")
                                         empty)))
                             (beside (rectangle 20 30 "solid" "blue")
                                     (rectangle 10 20 "solid" "red")
                                     BLANK))

;(define (layout-images loi) BLANK)  ; stub
;; <Templates from ListOfImage>
(define (layout-images loi)
  (cond [(empty? loi) BLANK]
        [else
         (beside (first loi)
              (layout-images (rest loi)))]))



;; ListOfImage -> ListOfImage
;; sort image in increasing order of size (area)
(check-expect (sort-images LOI1) empty)
(check-expect (sort-images
               (cons (rectangle 20 30 "solid" "blue")
                     (cons (rectangle 10 20 "solid" "yellow")
                           (cons (rectangle 15 18 "solid" "red")
                                 empty))))
              (cons (rectangle 10 20 "solid" "yellow")
                    (cons (rectangle 15 18 "solid" "red")
                          (cons (rectangle 20 30 "solid" "blue")
                                empty))))
              
;(define (sort-images loi) loi)  ; stub
;; <Templates from ListOfImage>

(define (sort-images loi)
  (cond [(empty? loi) empty]
        [else
         (insert (first loi)
              (sort-images (rest loi)))]))  ; result of natural recursion will be sorted
                                            ; so our job is to insert the (first loi) in
                                            ; its proper place, so wish for a new function
                                            ; called insert



;; Image ListOfImage -> ListOfImage
;; insert the image in its proper position in list (increasing increasing order of size)
;; ASSUME: los is already sorted

;; NOTE: Sometimes the signature can't say everything that matters about the consumed data.
;;       In those cases we can write an 'ASSUMPTION' as part of the function design.
(check-expect (insert (rectangle 15 18 "solid" "red") empty)
              (cons (rectangle 15 18 "solid" "red") empty))
(check-expect (insert (rectangle 15 18 "solid" "red")
                      (cons (rectangle 10 20 "solid" "yellow")
                                  (cons (rectangle 20 30 "solid" "blue")
                                        empty)))
              (cons (rectangle 10 20 "solid" "yellow")
                    (cons (rectangle 15 18 "solid" "red")
                          (cons (rectangle 20 30 "solid" "blue")
                                empty))))

;(define (insert i los) los)  ;stub
;; <Templates from ListOfImage>

(define (insert i loi)
  (cond [(empty? loi) (cons i empty)]
        [else
         (if (larger? i (first loi))
             (cons (first loi)           ; if true
                   (insert i
                           (rest loi)))
             (cons i loi))]))            ; if false

;; NOTE: The above function, for insert right image into a list.
;;       and to compare image size of 2 images are different things
;;       to do with. Which is called "Shift in Knowledge domain".
;;       And when this happen you should use a helper function.



;; Image Image -> Boolean
;; produce true if area of first image is larger than the second
(check-expect (larger?
               (rectangle 10 20 "solid" "yellow")
               (rectangle 15 18 "solid" "red"))
               #false)
(check-expect (larger?
               (rectangle 15 22 "solid" "yellow")
               (rectangle 10 20 "solid" "red"))
               #true)

;(define (larger? i1 i2) #false)  ; stub

(define (larger? i1 i2)
  (> (* (image-height i1) (image-width i1))
     (* (image-height i2) (image-width i2))))