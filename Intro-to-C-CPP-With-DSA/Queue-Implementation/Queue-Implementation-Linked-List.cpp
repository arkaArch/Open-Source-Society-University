#include <iostream>

// Node class
class Node {
public:
  int data;
  Node *link;
  Node(int data);
};

// Node constructor
Node::Node(int data) {
  this->data = data;
  link = nullptr;
}

// Queue class
class Queue {
private:
  Node *front;
  Node *rear;

public:
  Queue();
  void enqueue(int element);
  void dequeue();
  void display();
};

Queue::Queue() { front = rear = nullptr; }

void Queue::enqueue(int element) {
  // Create a new node
  Node *newNode = new Node(element);
  // Check if queue is full, it's full when heap is full i.e no node can't be
  // created
  if (newNode == nullptr)
    std::cout << "Queue is full" << std::endl;
  else {
    newNode->data = element;
    newNode->link = nullptr;
    // If 1st node is created then front and rear will be pointing to same node
    if (front == nullptr)
      front = rear = newNode;
    else {
      rear->link = newNode;
      rear = newNode;
    }
  }
}

void Queue::dequeue() {
  // Check if Queue is empty or not
  if (front == nullptr)
    std::cout << "Queue is empty. Nothing to delete." << std::endl;
  // Save first Node address to some variable
  Node *temp = front;
  // Assign front node to its next node
  front = front->link;
  // If it was the one and only node make rear to null.Since if queue has
  // one node front and rear will point to the same node. (see enque() above)
  if (front == nullptr)
    rear = nullptr;
  // Delete previous front node
  delete temp;
}

void Queue::display() {
  if (front == nullptr)
    std::cout << "Queue is empty";
  Node *next = front;
  while (next != nullptr) {
    std::cout << next->data << " ";
    next = next->link;
  }
  std::cout << std::endl;
}

int main() {
  Queue queue;
  queue.enqueue(22);
  queue.enqueue(67);
  queue.enqueue(34);
  queue.enqueue(78);
  queue.enqueue(98);
  queue.display();
  queue.dequeue();
  queue.dequeue();
  queue.display();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.display();

  return 0;
}
