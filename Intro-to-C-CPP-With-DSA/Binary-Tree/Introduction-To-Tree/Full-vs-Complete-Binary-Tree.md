### Full binnary tree:
```
            A    
           / \   
          /   \  
         B     C 
        / \   / \
       D   E  F  G
```
A binary tree of height 'h' having maximum number of nodes is called full binary tree. And we know the number of maximum nodes of a binary tree with height 'h' is $2^{h+1} - 1$

### Complete binnary tree:
```
        Figure: 1          Figure: 2         Figure: 3
            A                  A                 A
           / \                / \               / \
          /   \              B   C             B   C
         B     C            /     \           /
        / \   /            D       E         D 
       D   E  F  
```
If a binary tree is represented in an array, then if there is no blank spaces in between the elements, it's called a complete binary tree.

**Figure 1 represented in array**:  | A | B | C | D | E | F | <br/>
**Figure 2 represented in array**:  | A | B | C | D | \ | \ | E | <br/>
**Figure 2 represented in array**:  | A | B | C | D |

So, figure 1 and figure 2 are a complete binary tree whether Figure 2 is not a complete binary tree.

**Definition:** A complete binary tree of height 'h', will be a full binary tree up to '(h-1)' height and in the last level, the elements will be filled from left to right without skipping any elements.

So a full binary tree always is a complete binary tree.

**Remember**: A strict binary tree is not necessarily be an complete binary tree like below.
```
    A    
   / \   
  B   C 
     / \
    D   E
```