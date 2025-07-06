#include <deque>
#include <iostream>
#include <queue>
#include <string>

void queue_stl() {
  std::queue<std::string> q;
  q.push("cat");
  q.push("bat");
  q.push("rat");

  // Print from the first element
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

void deque_stl() {
  // Operations like, size(), empty(), at() are same as vector
  std::deque<int> dq = {4, 5};
  dq.push_front(3);
  dq.push_back(7);
  auto first = dq.begin(), last = dq.end();
  while (first != last) {
    std::cout << *first << " ";
    first++;
  }
  std::cout << std::endl;
  // We can also do operations like 'pop_back' and 'pop_front()'

  // We can erase the deque by giving a range as arguments
  dq.erase(dq.begin() + 1, dq.end() - 1);
  for (int i = 0; i < dq.size(); i++)
    std::cout << dq.at(i) << " ";
  std::cout << std::endl;
}

void priority_queue_stl() {
  // Priority queue is a type of queue where elements are inserted and removed
  // as per priority(greater by default) Priority queue container provides the
  // built-in implementation of a binary heap data structure. There can be two
  // types of heaps, Max-heap in which the priority is given to the largest
  // element. (Default) Min-heap in which the priority is given to the smallest
  // element.
  std::priority_queue<int> pq_max;
  pq_max.push(3);
  pq_max.push(8);
  pq_max.push(2);
  pq_max.push(5);
  pq_max.push(9);
  while (!pq_max.empty()) {
    std::cout << pq_max.top() << " ";
    pq_max.pop();
  }
  std::cout << std::endl;

  // The default underlying container used by priority queue is vector
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min;
  // Thus we change the order
  pq_min.push(3);
  pq_min.push(8);
  pq_min.push(2);
  pq_min.push(5);
  pq_min.push(9);
  while (!pq_min.empty()) {
    std::cout << pq_min.top() << " ";
    pq_min.pop();
  }
  std::cout << std::endl;
}

int main() {
  queue_stl();
  deque_stl();
  priority_queue_stl();
  return 0;
}
