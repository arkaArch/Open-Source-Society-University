If a data structure is linear then we can traverse it in two method, forward or backward. <br/>
But tree is a non-linear data structure. <br/>
For binary tree there are four possible traversal way:
1. `Preorder`: visit(node), preorder(left subtree), preorder(right subtree) {root -> left -> right}
2. `Inorder`: Inorder(left subtree), visit(node), Inorder(right subtree) {left -> root -> right}
3. `Postorder`: Postorder(left subtree), Postorder(right subtree), visit(node) {left -> right -> root}
4. `Levelorder`: Level by level
```
 Figure: 1                  Figure: 2
                               A
    A                         / \
   / \                      B     C
  B   C                    / \   / \
                          D   E F   G
```                 
**For figure 1**: <br/> 
Preorder: A, B, C; Inorder: B, A, C; Postorder: B, C, A; Levelorder: A, B, C

**For figure 2**: <br/>
Preorder: A, (B, D, E), (C, F, G) <br/>
Inorder: (D, B, E), A, (F, C, G)<br/>
Postorder:(D, E, B), (F, G, C), A <br/>
Levelorder: A, (B, C), (D, E, F, G) <br/>
