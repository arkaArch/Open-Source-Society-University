#include <iostream>
#define PRIORITY_LIMIT 3

/* This concept is depends on Limited Set of Priorities. Here priority is fixed.
 * Every element has it's own priority. Lower number gets higher priority.
 * Here I implemented this by taking an array, whose elements are set as
 * priority. Like arr[0] has priority 1, arr[1] has priority 2 & so on. Now here
 * arr[0] saves the address of first node of priority no.1 elements, arr[1]
 * saves the address of first node of elements which have priority no.2 and so
 * on. */

class Node {
public:
  int data;
  Node *link;
  Node(int data) {
    this->data = data;
    link = nullptr;
  }
};

class Priority_Queue {
public:
  Node *first_addresses[PRIORITY_LIMIT] = {nullptr};

  void enqueue(int element, int priority) {
    // Create a new node
    Node *newNode = new Node(element);
    newNode->data = element;
    // Check if the queue is empty
    if (!first_addresses[priority - 1]) {
      first_addresses[priority - 1] = newNode;
    } else {
      // find last node
      Node *current = first_addresses[priority - 1];
      while (current->link)
        current = current->link;
      current->link = newNode;
    }
  }

  void dequeue() {
    // Dequeue is done by priority in FIFO fashion. If queue with priority 1
    // is empty only then it removes the element of queue with priority 2.
    int priority = 0;
    while (priority < PRIORITY_LIMIT) {
      if (first_addresses[priority]) { // If the queue is not empty
        Node *temp = first_addresses[priority];
        first_addresses[priority] = temp->link;
        std::cout << "Deleted " << temp->data << " from queue " << priority + 1
                  << "\n";
        delete temp;
        break;
      } else {
        priority++;
      }
    }
  }

  void display() {
    int priority = 1;
    while (priority <= PRIORITY_LIMIT) {
      display_node(priority);
      priority++;
    }
  }

  void display_node(int priority) {
    Node *temp = first_addresses[priority - 1];
    std::cout << "Queue_" << priority << ": ";
    // If first_address of the queue is not nullptr
    // Then traverse the node and print data
    if (temp) {
      while (temp) {
        std::cout << temp->data << " ";
        temp = temp->link;
      }
    } else {
      std::cout << "Empty";
    }
    std::cout << std::endl;
  }
};

int main() {
  Priority_Queue pq;
  pq.display_node(1);
  pq.enqueue(12, 1);
  pq.enqueue(15, 1);
  pq.enqueue(19, 1);
  pq.enqueue(25, 2);
  pq.enqueue(35, 2);
  pq.display_node(1);
  pq.display_node(2);
  pq.dequeue();
  pq.dequeue();
  pq.dequeue();
  pq.dequeue();
  pq.display_node(2);

  std::cout << "------------------" << std::endl;
  pq.display();

  return 0;
}
