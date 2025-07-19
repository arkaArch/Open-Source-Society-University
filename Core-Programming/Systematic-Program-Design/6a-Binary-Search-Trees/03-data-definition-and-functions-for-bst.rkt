;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-abbr-reader.ss" "lang")((modname 03-data-definition-for-bst) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
;; PROBLEM:
;; Design a data definition to represent binary search trees.
;; Reference: 02-binary-search-tree.png



;; Data definition:
;; =======================

(define-struct node (key val l r))
;; BST (Binary Search Tree) is one of:
;;   - false
;;   - (make-node Integer String BST BST)
;; interp. false means no BST, or empty BST
;;         key is the node key
;;         val is the node val
;;         l and r are left and right subtrees
;; INVARIANT: for a given node:
;;     key is > all keys in its l(eft) child
;;     key is < all keys in its r(ight) child
;;     the same key never appears twice in the tree
(define BST0 false)
(define BST1 (make-node 1 "abc" false false))
(define BST4 (make-node 4 "dcj" false (make-node 7 "ruf" false false)))
(define BST3 (make-node 3 "ilk" BST1 BST4))
(define BST42 (make-node 42
                         "ily"
                         (make-node 27 "wit"
                                    (make-node 14 "olp" false false) false)
                         (make-node 50 "dug" false false)))
(define BST10 (make-node 10 "why" BST3 BST42))

(define (fn-for-bst t)
  (cond [(false? t) (...)]
        [else
         (... (node-key t)                   ; Integer
              (node-val t)                   ; String
              (fn-for-bst (node-l t))        ; BST
              (fn-for-bst (node-r t)))]))    ; BST
              
;; Template rules used:
;;   - one of: 2 cases
;;   - atomic distinct: false
;;   - compound: (make-node Integer String BST BST)
;;   - self-reference: (node-l t) is type BST
;;   - self-reference: (node-r t) is type BST



;; Functions
;; ==============

;; PROBLEM A:
;; Design a lookup-key function. Note that because this is
;; a search function it will sometimes 'fail'. This happens if it
;; is called with an key that does not exist in the BST it is
;; provided. If this happens the function should produce false.

;; BST Natural -> String or false
;; Try to find node with given key, if found produce value; if not produce false.
(check-expect (lookup-key BST0  99) false)
(check-expect (lookup-key BST1   1) "abc")
(check-expect (lookup-key BST1   0) false)
(check-expect (lookup-key BST1  12) false)
(check-expect (lookup-key BST10  1) "abc")   ; L L
(check-expect (lookup-key BST10  4) "dcj")   ; L R
(check-expect (lookup-key BST10 27) "wit")   ; R L
(check-expect (lookup-key BST10 14) "olp")   ; R L L

;(define (lookup-key t k) false)  ; stub
;; Templates from BST and additional atomic parameter k

(define (lookup-key t k)
  (cond [(false? t) false]
        [else
         (cond [(= k (node-key t))
                (node-val t)]
               [(< k (node-key t))
                (lookup-key (node-l t) k)]      ; go to left
               [(> k (node-key t))
                (lookup-key (node-r t) k)])]))  ; go to right


;; PROBLEM B:
;; Design the function count-nodes, which consumes BST and produces a 
;; natural number which is the total number of nodes in the BST. An 
;; empty tree (false) has 0 nodes.

;; BST -> Natural
;; produce total number of nodes inside bst
(check-expect (count-nodes BST0)  0)
(check-expect (count-nodes BST1)  1)
(check-expect (count-nodes BST42) 4)
(check-expect (count-nodes BST10) 9)

;(define (count-nodes t) 0)  ; stub
;; Took template from BST

(define (count-nodes t)
  (cond [(false? t) 0]
        [else
         (+ 1
            (count-nodes (node-l t))
            (count-nodes (node-r t)))]))



;; PROBLEM C:
;; Design a function that consumes a BST and produces the sum of all
;; the keys in the BST.

;; BST -> Natural
;; produce sum of keys of all BSTs' inside
(check-expect (key-sum BST0)  0)
(check-expect (key-sum BST1)  1)
(check-expect (key-sum BST42) (+ 42 27 50 14))
(check-expect (key-sum BST10) (+ 10 3 42 1 4 27 50 7 14))

;(define (key-sum t) 0)  ; stub
;; Template from BST

(define (key-sum t)
  (cond [(false? t) 0]
        [else
         (+ (node-key t)               
            (key-sum (node-l t))    
            (key-sum (node-r t)))]))



;; PROBLEM D:
;; Design the function height, that consumes a BST and produces its height. Note that 
;; the height of a BST is one plus the height of its highest child. You will want to 
;; use the BSL max function in your solution. The height of a false tree is 0. The 
;; height of (make-node 1 "a" false false) is 1.

;; BST -> Natural
;; produce height of a BST
(check-expect (height BST0)  0)
(check-expect (height BST1)  1)
(check-expect (height BST4)  2)
(check-expect (height BST42) 3)
(check-expect (height BST10) 4)

;(define (height t) 0)  ; stub
;; Took templates from BST

(define (height t)
  (cond [(false? t) 0]
        [else
         (max (+ 1 (height (node-l t)))
              (+ 1 (height (node-r t))))]))

