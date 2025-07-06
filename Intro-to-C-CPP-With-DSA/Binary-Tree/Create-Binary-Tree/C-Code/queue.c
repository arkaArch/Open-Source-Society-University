#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int is_empty(Queue *q) { return q->front == q->rear; }

void create_queue(Queue *q, int size) {
  q->size = size;
  q->front = q->rear = 0;
  // Create an array of Nodes of size 'size'
  q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

void enqueue(Queue *q, Node *address) {
  if ((q->rear + 1) % q->size == q->front) {
    // Here we use circular array to implement queue,
    // that's why we take the mod operation.
    printf("Queue is full");
  } else {
    // Move rear pointer by one and insert the address of the Node
    // We take one empty space for front
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = address;
  }
}

Node *dequeue(Queue *q) {
  if (q->front == q->rear % q->size) {
    printf("Queue is empty");
    return NULL;
  }
  // Move front one place to delete the element
  q->front = (q->front + 1) % q->size;
  // Return the adress which has to be removed
  // Remeber, we use this queue for binary tree,
  // So dequeue the address just to remove it from queue,
  // DO NOT free() THE MEMORY, ELSE NODE OF BINARY TREE WILL BE DELETED
  Node *temp = q->Q[q->front];
  return temp;
}