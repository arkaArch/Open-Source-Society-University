;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname 02-cond-evaluation) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Evaluation of a cond expression:
;If there are no question/answer pairs, signal an error
;
;If the first question is not a value, evaluate it and replace it
;with it's value. That is, replace the entire cond with a new
;cond in which the first question has been replace by its value.
;
;If the first question is true or else, replace the entire cond
;expression with the answer
;
;If the first question is false drop the first question/answer pair
;that is, replace the cond with a new cond that does not have the
;first question/answer pair

; Example steps are below:

(cond [(< 0 0) "negative"]
      [(= 0 0) "zero"]
      [else    "positive"])

(cond [#f "negative"]
      [(= 0 0) "zero"]
      [else    "positive"])

(cond [(= 0 0) "zero"]
      [else    "positive"])

(cond [#t "zero"]
      [else    "positive"])

"zero"