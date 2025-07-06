### Tree:

```
           A
         / | \
       /   |   \  
      B    C     D
     / \       / | \
    /   \     /  |  \
    E    F   G   H   I
        / \      |
       J   K     L
       |        / \
       M       N   O

```

1. `Tree` is a collection of `nodes/vertices` and `edges`(connector between two nodes). 

2. If there is n nodes then there will be (n-1) edges.

3. Here `A` is the `root` of the tree. From `B` and its below part or from `D` and its below are subtree.

4. So tree is a collection of nodes. Among those one node is taken as root node. Rest of the nodes are divided into `disjoint subsets`. And each subsets is a tree again or subtree again.

5. A node is a `Parent` to its very next desendants or those `Children` which are connected to just one edge.
    * `E` & `F` are childrens of `B`
    * `D` is the parent of `G`, `H` and `I`.

6. `Siblings` are children of same parent. 
    * `G`, `H`, `I` are siblings. 
    * `N` & `O` are siblings.

7. `Desendants` are all those set of nodes which can be reached from a particular node. 
    * `E`, `F`, `J`, `K`, `M` all these are descendants of `B`.
    * `L`, `N`, `O` are decendants of `H`.

8. `Ancestors`: For any node, all the nodes along the path from that node to root node. 
    * `J`, `F`, `B`, `A` are ancestors of `M`. 
    * `H`, `D`, `A` are ancestors of `L`.

9. `Degree` of nodes is the number of children it is having.
    * Degree of `A` is 3.
    * Degree of `H` is 1.
    * Degree of `M` is 0.

10. `Internal/Non-Leaf/Non-Terminal Nodes` and `External Nodes/Leaf/Terminal Nodes`: Nodes with degree zero are called as external nodes and nodes with degree greater than zero is called internal nodes.
    * `C`, `E`, `M`, `K`, `G`, `N`, `O`, `I` are external nodes.
    * `A`, `B`, `D`, `F`, `J`, `H`, `L` are internal nodes.

11. `Level` and `Height`: 
    * Root node is level 1 and height 0. 
    * `B`, `C`, `D` is level 2 and height 1.
    * `E`, `F`, `G`, `H`, `I` is at level 3 and height 2.
    * `J`, `K`, `L` is at level 3 and height 2.
    * `M`, `N`, `O` is at level 4 and height 3.

12. `Forest`: A collection of tree is calledas forest.


## Binary Tree:
```
            A                              A                    A
           / \                            /                      \   
          /   \   -> Strict binary       B   -> Left Skewed       B    -> Right skewed
         B     C     Tree               /       Binary Tree        \      Binary Tree
        / \   / \                      C                            C
       D   E  F  G
```
A tree of degree two, i.e. a tree where every node can have maximum two children is called binary tree.<br/>
`Strict binary trees` have nodes with `deg(0)` or `deg(2)`. No `deg(1)` nodes are present in strict binary trees.


### Number of different shaped binary trees from given number of unlebelled nodes:
Let's number of nodes = 3. So the shapes are
```
     O    O    O    O    O    
    /    /    / \    \    \
   O    O    O   O    O    O
  /      \           /      \
 O        O         O        O
```
So, T(3) = 5 <br/>
The formula is $T(n) = \frac{^{2n}C_n}{n+1}$. Here T(n)/Fomrmula is called `Catalan Number`.<br>
So, for $$T(4) = \frac{^{8}C_4}{4+1} = \frac{\frac{8!}{4!*(8-4)!}}{5} = \frac{\frac{8*7*6*5}{4*3*2}}{5} = 14$$

We have another fomula for generate catalan number. We know that T(0) = 1, T(1) = 1, T(2) = 2, T(3) = 5 <br/>
Now, T(4) = T(0)*T(3) + T(1)*T(2) + T(2)*T(1) + T(3)*T(0) = 5 + 2 + 2 + 5 = 14 <br/>
So, `Catalan number`, $T(n) = \sum_{i=0}^{n}T(i-1) * T(n - i)$


> The number of binary tree with maximum height(2) for 3 nodes $= 2^{3-1} = 4$ <br/>
> The number of binary tree with maximum height(3) for 4 nodes $= 2^{4-1} = 8$
```
     O   O  O   O    
    /   /    \   \
   O   O      O   O        For 3 nodes and height 2
  /     \    /     \
 O       O  O       O
```
```
        O   O  O   O      O    O   O   O    
       /   /  /   /        \    \   \   \
      O   O  O   O          O    O   O   O     For 4 nodes and height 3
     /   /    \   \        /    /     \   \
    O   O      O   O      O    O       O   O
   /     \    /     \    /      \     /     \
  O       O  O       O  O        O   O       O
```

### Number of different shaped binary trees from given number of lebelled nodes:
Let's say number of nodes is 3 and the nodes are `A`, `B` and `C`. <br/> 
For unlebelled 3 nodes we have seen the result. Now one unlabel pattern can generate 3! trees with lebel nodes.
```
      O        A  A  B  B  C  C
     /        /  /  /  /  /  /
    O    =>  B  C  A  C  A  B
   /        /  /  /  /  /  /
  O        C  B  C  A  B  A
```
Thus for 3 labelled nodes the number of trees can be generated = 5 * 3! = 30 <br/>
So, general formula can be written as: $\frac{^{2n}C_n}{n+1} * n!$
