### Minimum & maximum number of nodes if height is given:
**Height 1**:
```
       O                 O
Min:  /         Max:    / \
     O                 O   O
```
Minimum number of nodes: 2 = 1+1 & maximum number of nodes: 3 = $1 + 2$

**Height 2**:
```
         O                 O
        /                /   \
Min:   O          Max:  O     O
      /                / \   / \
     O                O   O O   O
```
Minimum number of nodes: 3 & maximum number of nodes: 7 = $1 + 2 + 2^2$

So general formula for `minimum-nodes` = (h + 1) and `maximum-nodes` = $(1 + 2 + 2^2 + 2^3 + ... + 2^h)$. <br/> 
This is sum of geometric progression.<br>
And in G.P, $a + ar + a^2 + ar^3 + ... + ar^k = a(r^{k+1}-1)/(r-1)$ <br/>
So, `maximum-nodes` = $2^{h+1} - 1$.

<br/>

---
<br/>

Now from this we can make the opposite formula for `max height` & `min height` if number of nodes are given.<br/>
For `maximum-height` = $n - 1$ <br/>
`minimum-height` = $\log_2(n+1) - 1$

**Number of nodes = 3** : Max-height = 3 - 1 = 2 & min-height = $\log_2(3+1) - 1$ = 2 - 1 = 1
```
                  O                     
                 /                     O
Max height:     O       Min height:   / \  
               /                     O   O
              O
```

**Note**: There is a relationship between external and internal nodes in binary tree. `deg(0) = deg(2) + 1`. That is terminal(external) nodes always '+1' than internal nodes having two children. <br/>
This can be written as `external nodes = internal nodes + 1` for `strictly binary trees`, since there is no nodes with `deg(1)`.

<br/>

---
<br/>

### Minimum & maximum number of nodes if height is given in strict binary trees:
**Height 2**:
```
         O                  O
        / \               /   \
Min:   O   O       Max:  O     O
      / \               / \   / \
     O   O             O   O O   O
```
Minimum number of nodes: 5 & maximum number of nodes: 7
For height 3 if we draw we can see minimum number of nodes = 7 and maximum number of nodes = 15 <br/>
So, maximum-nodes are same as above, i.e $2^{h+1} - 1$.
And `minimum-nodes` = $2*h + 1$

So we can make the fomula of `maximum` and `minimum height` if nodes are given: <br/>
`minimum-height` = $\log_2(n+1) - 1$ and `maximum-height` = $(n-1)/2$
