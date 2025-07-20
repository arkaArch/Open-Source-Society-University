;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-abbr-reader.ss" "lang")((modname 03-data-definition-and-functions-for-bst) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
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
#;
(define (fn-for-bst bst)
  (cond [(false? bst) (...)]
        [else
         (... (node-key bst)                   ; Integer
              (node-val bst)                   ; String
              (fn-for-bst (node-l bst))        ; BST
              (fn-for-bst (node-r bst)))]))    ; BST
              
;; Template rules used:
;;   - one of: 2 cases
;;   - atomic distinct: false
;;   - compound: (make-node Integer String BST BST)
;;   - self-reference: (node-l bst) is type BST
;;   - self-reference: (node-r bst) is type BST



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

;(define (lookup-key bst k) false)  ; stub
;; Templates from BST and additional atomic parameter k

(define (lookup-key bst k)
  (cond [(false? bst) false]
        [else
         (cond [(= k (node-key bst))
                (node-val bst)]
               [(< k (node-key bst))
                (lookup-key (node-l bst) k)]      ; go to left
               [(> k (node-key bst))
                (lookup-key (node-r bst) k)])]))  ; go to right

;; -------------------------------------------------------------------------------------------

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

;(define (count-nodes bst) 0)  ; stub
;; Took template from BST

(define (count-nodes bst)
  (cond [(false? bst) 0]
        [else
         (+ 1
            (count-nodes (node-l bst))
            (count-nodes (node-r bst)))]))

;; -------------------------------------------------------------------------------------------

;; PROBLEM C:
;; Design a function that consumes a BST and produces the sum of all
;; the keys in the BST.

;; BST -> Natural
;; produce sum of keys of all BSTs' inside
(check-expect (key-sum BST0)  0)
(check-expect (key-sum BST1)  1)
(check-expect (key-sum BST42) (+ 42 27 50 14))
(check-expect (key-sum BST10) (+ 10 3 42 1 4 27 50 7 14))

;(define (key-sum bst) 0)  ; stub
;; Template from BST

(define (key-sum bst)
  (cond [(false? bst) 0]
        [else
         (+ (node-key bst)               
            (key-sum (node-l bst))    
            (key-sum (node-r bst)))]))

;; -------------------------------------------------------------------------------------------

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

;(define (height bst) 0)  ; stub
;; Took templates from BST

(define (height bst)
  (cond [(false? bst) 0]
        [else
         (max (+ 1 (height (node-l bst)))
              (+ 1 (height (node-r bst))))]))

;; -------------------------------------------------------------------------------------------

;; PROBLEM E:
;; Design a function that consumes an Integer, String and BST, and adds a node
;; that has the given key and value to the tree. The node should be inserted in 
;; the proper place in the tree. The function can assume there is not already 
;; an entry for that number in the tree. The function should produce the new BST.
;; Do not worry about keeping the tree balanced. We will come back to this later.

;; Integer String BST -> BST
;; produce new BST in which key, val pair have been inserted in proper place
;; ASSUME: key does not already exist in tree

;;            2:b
;;       +-----+-----+
;;       |           |
;;      1:a         3:c

(check-expect (insert 2 "b" false)
               (make-node 2 "b" false false))

(check-expect (insert 1 "a"
                       (make-node 2 "b" false false))
               (make-node 2 "b"
                          (make-node 1 "a" false false)
                          false))

(check-expect (insert 3 "c"
                       (make-node 2 "b"
                                  (make-node 1 "a" false false) false))
               (make-node 2 "b"
                          (make-node 1 "a" false false)
                          (make-node 3 "c" false false)))

;(define (insert key val bst) bst)  ;stub
;; Took template from BST with two extra atomic parameter

(define (insert key val bst)
  (cond [(false? bst) (make-node key val false false)]
        [else
         (if (< key (node-key bst))
             (make-node (node-key bst) (node-val bst)
                        (insert key val (node-l bst))
                        (node-r bst))
             (make-node (node-key bst) (node-val bst)
                        (node-l bst)
                        (insert key val (node-r bst))))])) 

;; -------------------------------------------------------------------------------------------

;; PROBLEM F:

;; For optimal lookup time we want a BST to be balanced. 
;; The oldest approach to this is called AVL self-balancing trees and was invented in 1962. 
;; The remainder of this problem set is based on AVL trees.
;;
;; An individual node is balanced when the height of its left and right branches differ 
;; by no more than 1. A tree is balanced when all its nodes are balanced.
;; For a Balanced Tree(for every node): -1 ≤ balance-factor ≤ 1
;;
;; a) Design the function balance-factor that consumes a node and produces its balance factor,
;; which is defined as the height of its left child minus the height of its right child.
;;
;; b) Use your function in part a) to design the function balanced?, which consumes a BST and 
;; produces true if the tree is balanced.
;;
;; Once you have the function, use it to compare what happens with the following two sequences
;; of insertions:
;;
;; SEQ 1: (insert 4 "a" (insert 5 "a" (insert 6 "a" (insert 7 "a" (insert 8 "a" false)))))
;; SEQ 2: (insert 4 "a" (insert 5 "a" (insert 8 "a" (insert 7 "a" (insert 6 "a" false)))))


;; BST -> Integer
;; produces balance-factor of a tree (height_of_L_child - height_of_R_child)
;;
;;
;;                                             10:why(bf->0)
;;                  +-----------------------------+-----------------------+                         
;;                3:ilk(bf->-1)                                        42:ily(bf->1)
;;     +------------+------------+                           +------------+-------------+
;;    1:abc(bf->0)            4:djc(bf->-1)               27:wit(bf->1)              50:dug(bf->0)
;;                       +------+------+              +------+------+
;;                                   7:ruf(bf->0)  14:olp(bf->0)

(check-expect (balance-factor BST1) 0)
(check-expect (balance-factor BST4) -1)
(check-expect (balance-factor BST3) -1)
(check-expect (balance-factor BST42) 1)
(check-expect (balance-factor BST10) 0)
(check-expect (balance-factor (make-node 3 "c"
                                         (make-node 2 "b"
                                                    (make-node 1 "a" false false) false) false))
              2)

;(define (balance-factor bst) 0)  ; stub
;; Took template from BST

(define (balance-factor bst)
  (- (height (node-l bst))
     (height (node-r bst))))



;; BST -> Boolean
;; produce true if a tree is balance i.e. balance-factor <= 1 and balance-factor >= -1
(check-expect (balance? BST1) #true)
(check-expect (balance? BST3) #true)
(check-expect (balance? BST10) #true)
(check-expect (balance? (make-node 3 "c"
                                   (make-node 2 "b"
                                              (make-node 1 "a" false false) false) false))
              #false)

;(define (balance? bst) #false)  ; stub
;; Took template from BST

(define (balance? bst)
  (<= -1 (balance-factor bst) 1))




(define SEQ1 (insert 4 "a" (insert 5 "a" (insert 6 "a" (insert 7 "a" (insert 8 "a" false))))))
;;
;;         8:a (bf->4)
;;         /
;;       7:a (bf->3)
;;       /
;;     6:a (bf->2)           => Left skewed binary tree
;;     /
;;   5:a (bf->1)
;;   /
;;  4:a (bf->0)

(check-expect (height SEQ1) 5)
(check-expect (balance-factor SEQ1) 4)
(check-expect (balance? SEQ1) #false)

(define SEQ2 (insert 4 "a" (insert 5 "a" (insert 8 "a" (insert 7 "a" (insert 6 "a" false))))))
;;
;;                      6:a (bf->0)           
;;            +----------+----------+        
;;           5:a (bf->1)           7:a (bf->-1)
;;    +-------+-------+     +-------+-------+        
;;   4:a (bf->0)                           8:a (bf->0)

(check-expect (height SEQ2) 3)
(check-expect (balance-factor SEQ2) 0)
(check-expect (balance? SEQ2) #true)
