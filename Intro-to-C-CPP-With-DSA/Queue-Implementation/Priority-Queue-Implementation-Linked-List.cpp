#include <iostream>

struct Node {
  int data;
  int priority;
  Node *link;
  Node(int data, int priority) {
    this->data = data;
    this->priority = priority;
    link = nullptr;
  }
};

// Return the value of first element
// Here we're implementing highest number has highest priority
int peek(Node *first) { return first->data; }

Node *enqueue(Node *first, int value, int priority) {
  Node *start = first;
  // Create new Node with the given data and priority
  Node *new_node = new Node(value, priority);
  // If the queue is empty
  // or the first has lower priority
  // or they have same priority but new_node->value > first->data
  if (!first || first->priority < priority ||
      (first->priority == priority && first->data < value)) {
    // Insert the new node before first node
    new_node->link = first;
    first = new_node;
  } else {
    // Traverse the list to find the correct position
    // to insert the new node based on priority or
    // for same priority based on data
    while (start->link &&
           (start->link->priority > priority ||
            (start->link->priority == priority && start->link->data > value))) {
      // Go to the next node
      start = start->link;
    }
    // Insert the new node at the found position
    new_node->link = start->link;
    start->link = new_node;
  }
  return first;
}

Node *dequeue(Node *first) {
  // Store the current first node in temp
  Node *temp = first;
  // Move the first node to the next node
  first = first->link;
  // Free the memory of removed first node
  delete temp;
  // Return the new first node
  return first;
}

int main() {
  Node *pq = new Node(16, 2);
  pq = enqueue(pq, 18, 2);
  pq = enqueue(pq, 12, 2);
  pq = enqueue(pq, 52, 5);
  pq = enqueue(pq, 47, 4);
  pq = enqueue(pq, 32, 2);

  while (pq) {
    std::cout << peek(pq) << " ";
    pq = dequeue(pq);
  }
  std::cout << std::endl;

  return 0;
}