#include <climits>
#include <iostream>

struct item {
  int value;
  int priority;
};

// Size of priority queue
int size = -1;
// Priority queue
item pq[10000];

void enqueue(int value, int priority) {
  /* If we arrange item during enque it becomes O(N)
   * and deque becomes O(1), but here we enqueue in O(1)
   * and dequeue in O(n) */
  // Increase the size and Insert the element.
  size++;
  pq[size].value = value;
  pq[size].priority = priority;
}

// Here we're implementing highest number has highest priority
int peek() {
  // Returns index of peek element(basis of priority)
  // If priority is same choose the element with the highest value
  int highest_priority = INT_MIN, index = -1;
  for (int i = 0; i <= size; i++) {
    if (highest_priority == pq[i].priority && index > -1 &&
        pq[index].value < pq[i].value) {
      highest_priority = pq[i].priority;
      index = i;
    } else if (highest_priority < pq[i].priority) {
      highest_priority = pq[i].priority;
      index = i;
    }
  }
  return index;
}

void dequeue() {
  // Get the peek index of the queue and shift the array
  int peek_index = peek();
  for (int i = peek_index; i < size; i++) {
    pq[i] = pq[i + 1];
  }
  // Decrease the size of the queue
  size--;
}

int main() {
  enqueue(16, 2);
  enqueue(12, 2);
  enqueue(52, 5);
  enqueue(47, 4);
  enqueue(32, 2);

  // Print the priority queue
  while (size != 0) {
    std::cout << pq[peek()].value << " ";
    dequeue();
  }
  std::cout << std::endl;

  return 0;
}
