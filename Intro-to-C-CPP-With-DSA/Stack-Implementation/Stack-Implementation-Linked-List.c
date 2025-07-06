#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
} *top = NULL;

void push(int element) {
  // stack is full when heap is full
  // That is when we're unable to create a new node
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL) {
    printf("Stack Overflow.\n");
    return;
  }
  node->data = element;
  node->link = top;
  top = node;
}

void pop() {
  // Stack is empty when top is NULL
  if (top == NULL) {
    printf("Stack Underflow\n");
    return;
  }
  // We have to delete the node
  struct Node *temp = top;
  printf("Popped element %d\n", temp->data);
  top = temp->link;
  free(temp);
}

void display() {
  if (top == NULL) {
    printf("Stack is empty");
    return;
  }
  // Print from peek
  struct Node *current = top;
  do {
    printf("%d ", current->data);
    current = current->link;
  } while (current != NULL);
  printf("\n");
}

int main() {
  push(10);
  push(20);
  push(30);
  display(); // 30 20 10 --> Print from peek
  pop();     // Popped element 30
  display(); // 20 10 --> Print from peek
  pop();     // Popped element 20
  display(); // 10
  return 0;
}