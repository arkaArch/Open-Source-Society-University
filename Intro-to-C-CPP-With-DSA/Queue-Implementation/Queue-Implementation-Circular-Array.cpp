#include <iostream>
#include <optional>
// (F)irst (I)n (F)irst (O)ut

template <class T> class Queue {
private:
  T *arr;
  // Front element pointer in a queue
  int front;
  // Number of element in a queue
  int size;
  // Number of capacity in a queue
  int capacity;

public:
  Queue(int capacity);         // Constructor
  std::optional<T> getFront(); // Get front element
  std::optional<T> getRear();  // Get rear element
  void enqueue(T element);     // Insert an element in queue(last element)
  std::optional<T> dequeue();  // Delete an element from queue(first element)
  void display();              // Display the queue
};

template <class T> Queue<T>::Queue(int capacity) {
  // Create an array of size capacity
  arr = new T[capacity];
  this->capacity = capacity;
  size = 0;
  front = 0;
}

template <class T> std::optional<T> Queue<T>::getFront() {
  if (size == 0) {
    std::cout << "Queue is empty" << std::endl;
    return std::nullopt; // Return nothing
  }
  return arr[front];
}

template <class T> std::optional<T> Queue<T>::getRear() {
  if (size == 0) {
    std::cout << "Queue is empty" << std::endl;
    return std::nullopt; // Return nothing
  }
  int rear = (front + size - 1) % capacity;
  return arr[rear];
}

template <class T> void Queue<T>::enqueue(T element) {
  // Check queue is full or not
  if (size == capacity) {
    std::cout << "Queue is full." << std::endl;
    return;
  }
  // Find the rear pointer, increase it by 1 & insert the element
  // Also increase the size of queue.
  // int rear = (front + size - 1) % capacity;
  // rear = (rear + 1) % capacity ;
  int rear = (front + size) % capacity;
  arr[rear] = element;
  size++;
}

template <class T> std::optional<T> Queue<T>::dequeue() {
  // Check if the queue is empty
  if (size == 0) {
    std::cout << "Queue is empty. Nothing to delete" << std::endl;
    return std::nullopt;
  }
  // Element to be deleted
  T element = arr[front];
  // Increase the front index pointer by one
  front = (front + 1) % capacity;
  // Also derease the size
  size -= 1;
  // Return the deleted element
  return element;
}

template <class T> void Queue<T>::display() {
  int rear = (front + size - 1) % capacity;
  if (size == 0) {
    std::cout << "Queue is empty" << std::endl;
  } else if (front < rear) {
    for (int i = front; i <= rear; i++)
      std::cout << arr[i] << " ";
    std::cout << std::endl;
  } else { // rear < front
    for (int i = front; i < capacity; i++)
      std::cout << arr[i] << " ";
    for (int i = 0; i <= rear; i++)
      std::cout << arr[i] << " ";
    std::cout << std::endl;
  }
}

int main() {
  Queue<float> queue(4);
  queue.getRear(); // This should print the "empty" msg
  queue.enqueue(22.98);
  queue.enqueue(67.54);
  queue.enqueue(34.76);
  std::cout << queue.getFront().value() << std::endl; // 22.98
  std::cout << queue.getRear().value() << std::endl;  // 34.76
  std::cout << queue.dequeue().value() << std::endl;  // 22.98
  std::cout << queue.getFront().value() << std::endl; // 67.54
  queue.enqueue(12.87);
  queue.enqueue(78.23);
  queue.enqueue(98.33); // This should print "queue full" msg
  queue.display();

  return 0;
}
