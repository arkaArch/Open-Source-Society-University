#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Global root Node
Node *root = NULL;

// Follow the picture "Generate-Binary-Tree-Using-Linked-Representation"
void create_binary_tree() {
  // We need a queue to store the address of Nodes
  Queue q;
  create_queue(&q, 100);

  // Create the root Node.
  int value;
  printf("Enter the value of root node: ");
  scanf("%d", &value);
  root = (Node *)malloc(sizeof(Node));
  root->data = value;
  root->left_child = root->right_child = NULL;

  // Store the root address inside queue
  enqueue(&q, root);

  Node *p_parent, *p_child;
  // Now dequeue the adress and asks for left and right child
  while (!is_empty(&q)) {
    p_parent = dequeue(&q);

    // Create left child
    printf("Enter value of left child of %d (if not present enter -1): ",
           p_parent->data);
    scanf("%d", &value);
    if (value != -1) {
      // Create left child node
      p_child = (Node *)malloc(sizeof(Node));
      p_child->data = value;
      p_child->left_child = p_child->right_child = NULL;
      // Link this child with it's parent
      p_parent->left_child = p_child;
      // Enter this child address inside queue
      enqueue(&q, p_child);
    }

    // Create right child
    printf("Enter value of right child of %d (if not present enter -1): ",
           p_parent->data);
    scanf("%d", &value);
    if (value != -1) {
      // Create right child node
      p_child = (Node *)malloc(sizeof(Node));
      p_child->data = value;
      p_child->left_child = p_child->right_child = NULL;
      // Link this child with it's parent
      p_parent->right_child = p_child;
      // Enter this child address inside queue
      enqueue(&q, p_child);
    }
  }
}

void preorder_printing(Node *ptr) {
  if (ptr) {
    printf("%d ", ptr->data);
    preorder_printing(ptr->left_child);
    preorder_printing(ptr->right_child);
  }
}

int main() {
  create_binary_tree();
  preorder_printing(root);
  printf("\n");
  return 0;
}