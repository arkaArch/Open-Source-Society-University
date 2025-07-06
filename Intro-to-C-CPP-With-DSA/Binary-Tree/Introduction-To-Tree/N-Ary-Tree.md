## n-ary tree:
Means every nodes is maximum degree of n.

**3-ary tree examples:**<br/>
deg(0) <= deg(n) <= deg(3)
```
       O              O         O       
     / | \           / \       / \
    O  O   O        O   O     O   O
   / \   / | \     /  / | \      / \
  O   O O  O  O   O  O  O  O    O   O
```
---

### Strict n-ary tree:
Means every nodes is eiher degree of n or zero or every internal nodes must be of deg(n).

**Strict 3-ary tree examples:**<br/>
deg(n) = deg(0) or deg(3) or every internal nodes must be of deg(3).  
```
       O                   O
     / | \               / | \ 
    O  O  O            O   O   O
     / | \           / | \   / | \
    O  O  O         O  O  O O  O  O  
```

### Height & node relationship for strict n-ary tree:
For strict 3-ary tree in height 2:

```
       O                      O
     / | \               __ / | \ __ 
    O  O  O            /      |      \ 
  / | \               O       O       O     
 O  O  O            / | \   / | \   / | \ 
                   O  O  O O  O  O O  O  O
```
So, for height 2:  `minimum nodes`: 7 and `maximum nodes`: $13 = 3^0 + 3^1+ 3^2$ <br/>
and for height 3:  `minimum nodes`: 7+3 = 10 and `maximum nodes`: $13 + (9 * 3) = 40 = 3^0 + 3^1 + 3^2 + 3^3$

**Formula: For k-ary tree in height `h`:** <br/>
`Minimum no of nodes` = $k*h + 1$ and `Maximum no of nodes` = $1 + k + k^2 +...+ k^{h-2} + k^{h-1} + k^h$ <br/>
So this is sum of G.P => $a(r^{k+1})/r-1$ <br/> 
So, `Maximum no of nodes` = $(k^{h+1} + 1)/(k-1)$

So we can make the fomula of `maximum` and `minimum height` if nodes are given: <br/>
`maximum-height` = $(n-1)/k$ and `minimum-height` = $\log_k[(n(k-1)+1)]-1$

---

### Relationship between external and internal nodes:
In 3-ary tree, for height 2 (See above picture)<br/>
number of `min internal nodes` = 2 and `min external nodes` = 5 <br/>
number of `max internal nodes` = 4 and `min external nodes` = 9 <br/>

So, for n-ary tree: $externalNodes = (n-1)*interNodes + 1$