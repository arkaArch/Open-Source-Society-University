#include <stdio.h>
#include <stdlib.h>

// Simple array implementation is not used in practice as it is not efficient.
// We can't push an element in front though there are empty space. In practice
// we either use circular array or linked list.

struct Queue {
  int capacity; // Size of the array
  int front;    // Front index pointer
  int rear;     // Rear index pointer
  int *arr;     // Pointer to the array
};

// Create a queue
void create(struct Queue *q, int size) {
  q->capacity = size;
  // Initialize front and rear to -1
  q->front = q->rear = -1;
  // Create an "q->capacity" size array in heap
  q->arr = (int *)malloc(q->capacity * sizeof(int));
}

// Add an element in queue(last)
void enqueue(struct Queue *q, int element) {
  // Check the queue is full or not
  if (q->rear == q->capacity - 1) {
    printf("Queue is full. Can't be inserted\n");
    return;
  }
  // Move rear index one step forward & insert
  q->arr[++q->rear] = element;
}

// Delete an element from first
void dequeue(struct Queue *q) {
  // Check if queue is empty or not
  if (q->front == q->rear) {
    printf("Queue is empty. Nothing to delete\n");
    return;
  }
  // Move front index one step forward
  q->front++;
}

// Display the queue
void display(struct Queue *q) {
  if (q->front == q->rear)
    printf("Queue is empty\n");
  else {
    // Front always pointing before the deleted item
    for (int i = q->front + 1; i <= q->rear; i++)
      printf("%d ", q->arr[i]);
    printf("\n");
  }
}

int main() {
  struct Queue q;
  // Create the queue
  create(&q, 5);

  // Enter the element of queue
  enqueue(&q, 4);
  enqueue(&q, 8);
  enqueue(&q, 15);
  enqueue(&q, 9);
  enqueue(&q, 14);
  enqueue(&q, 16); // This should print "Queue is full"

  // Print queue
  display(&q);

  // Delete two element from queue
  dequeue(&q);
  dequeue(&q);

  // Print queue
  display(&q);

  return 0;
}
