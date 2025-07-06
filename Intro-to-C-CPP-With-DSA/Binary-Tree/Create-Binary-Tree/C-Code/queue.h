#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
  int data;
  struct Node *left_child;
  struct Node *right_child;
} Node;

// We store the address of the nodes in a queue
typedef struct Queue {
  int size;  // size/capacity of queue
  int front; // points to the front element of the queue
  int rear;  // points to the rear element of the queue
  // We store the address of the array, inside which addresses of Nodes are
  // storing. So first pointer to store addresses of Node and second pointer for
  // the Node array.
  Node **Q;
} Queue;

int is_empty(Queue *q);
void create_queue(Queue *q, int size);
void enqueue(Queue *q, Node *address);
Node *dequeue(Queue *q);

#endif