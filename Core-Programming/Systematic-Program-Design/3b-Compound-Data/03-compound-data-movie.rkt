;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname 03-compound-data-movie) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; Data definitions:
;; 
;; PROBLEM A:
;; Design a data definition to represent a movie, including  
;; title, budget, and year released.
;;
(define-struct movie (title budget released))
;; Movie is (make-movie String Integer Integer)
;; interp. (make-movie t b r) is a movie with
;;         t is the title
;;         b is the budget
;;         r is the released year
(define M1 (make-movie "Titanic" 200000000 1997))
(define M2 (make-movie "Avatar" 237000000 2009))
(define M3 (make-movie "The Avengers" 220000000 2012))

#;
(define (fn-for-movie m)
  (... (movie-title m)        ;String
       (movie-budget m)       ;Integer
       (movie-released m)))   ;Integer

;; Template rules used
;; - Compound: 3 fields



;; Functions:
;; 
;; PROBLEM B:
;; You have a list of movies you want to watch, but you like to watch your 
;; rentals in chronological order. Design a function that consumes two movies 
;; and produces the title of the most recently released movie.
;;
;; Movie Movie -> String
;; Compare release date of two movies and produce latest movie title
(check-expect (recent-movie M1 M2) "Avatar")
(check-expect (recent-movie M2 M3) "The Avengers") 
(check-expect (recent-movie M1 M3) "The Avengers")

;(define (recent-movie M1 M2) "")  ; stub

#;
(define (fn-for-movie m1 m2)
  (... (movie-title m1)
       (movie-budget m1)
       (movie-released m1)
       (movie-title m2)
       (movie-budget m2)
       (movie-released m2)))

;; The rule for templating a function that consumes two compound data parameters  
;; is for the template to include all the selectors for both parameters.

(define (recent-movie m1 m2)
  (if (> (movie-released m1) (movie-released m2))
      (movie-title m1)
      (movie-title m2)))   
