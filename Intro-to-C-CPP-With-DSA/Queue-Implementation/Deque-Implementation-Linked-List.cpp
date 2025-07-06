#include <iostream>

// Node class
// Since we have to implement pop_back() in O(1)
// We take a doubly-linked list.
class Node {
public:
  int data;
  Node *prev;
  Node *next;
  Node(int data);
};

// Node constructor
Node::Node(int data) {
  this->data = data;
  prev = nullptr;
  next = nullptr;
}

// Deque class
class Deque {
private:
  Node *front;
  Node *rear;

public:
  Deque();
  void push_front(int element);
  void push_back(int element);
  void pop_front();
  void pop_back();
  void display();
};

Deque::Deque() { front = rear = nullptr; }

void Deque::push_front(int element) {
  // Create a new node
  Node *newNode = new Node(element);
  // Check if queue(heap) is full
  if (newNode == nullptr)
    std::cout << "Queue is full" << std::endl;
  else {
    newNode->data = element;
    newNode->next = front;
    // Check if there is any node before in the queue
    if (front == nullptr)
      // Then rear will be pointing to the new node also
      rear = newNode;
    else
      front->prev = newNode;
    front = newNode;
  }
}

void Deque::push_back(int element) {
  // Create a new node
  Node *newNode = new Node(element);
  // Check if queue(heap) is full
  if (newNode == nullptr)
    std::cout << "Queue is full" << std::endl;
  else {
    newNode->data = element;
    newNode->prev = rear;
    newNode->next = nullptr;
    // Check if there is a node in queue or not
    if (front == nullptr)
      // Then front will be pointing to the new node
      front = newNode;
    else
      rear->next = newNode;
    rear = newNode;
  }
}

void Deque::pop_front() {
  // Check if Queue is empty
  if (front == nullptr)
    std::cout << "Queue is empty, nothing to delete." << std::endl;
  Node *temp = front;
  front = front->next;
  if (front == nullptr) // It's the last element in queue
    rear = nullptr;     // else rear will be dangling
  else
    temp->next->prev = nullptr;
  delete temp;
}

void Deque::pop_back() {
  // Check if Queue is empty
  if (front == nullptr)
    std::cout << "Queue is empty, nothing to delete." << std::endl;
  Node *temp = rear;
  rear = rear->prev;
  if (rear == nullptr) // It's the last element in queue
    front = nullptr;   // else front will be dangling
  else
    temp->prev->next = nullptr;
  delete temp;
}

void Deque::display() {
  if (front == nullptr)
    std::cout << "Queue is empty";
  Node *temp = front;
  while (temp != nullptr) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

int main() {
  Deque dq;
  dq.push_front(17);
  dq.push_front(14);
  dq.push_back(19);
  dq.push_back(23);
  dq.push_front(12);
  dq.push_front(10);
  dq.display();
  dq.pop_front();
  dq.pop_front();
  dq.display();
  dq.pop_back();
  dq.pop_back();
  dq.display();
  dq.pop_back();
  dq.pop_back();
  dq.display();

  return 0;
}
