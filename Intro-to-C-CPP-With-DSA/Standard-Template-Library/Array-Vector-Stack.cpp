#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

void array_stl() {
  std::array<int, 4> arr = {6, 8, 3, 4};
  std::cout << "Is array empty: " << arr.empty() << std::endl;
  std::cout << "Element at index-2: " << arr.at(2) << std::endl;
  std::cout << "First and last element: " << arr.front() << " " << arr.back()
            << std::endl;
}

void vector_stl() {
  std::vector<int> v = {6, 8, 3, 4};
  // All the array operations have shown above is applicable in vectors

  // An iterator in C++ is a pointer-like object that points to an element of
  // the STL container.
  std::vector<int>::iterator first = v.begin();
  auto last = v.end(); // Automatically assign variable type
  while (first < last) {
    std::cout << *first << " ";
    first++;
  }
  std::cout << "\n";

  // Vector double it size when an element is pushed, and dumped the old
  std::cout << "Size of v: " << v.size() << std::endl;
  std::cout << "Capacity of v: " << v.capacity() << std::endl;
  v.push_back(9);
  std::cout << "After insert one element size of v: " << v.size() << std::endl;
  std::cout << "After insert one element capacity of v: " << v.capacity()
            << std::endl;
  v.pop_back();
  std::cout << "After popping last element size of v: " << v.size()
            << std::endl;
  std::cout << "After popping last element capacity of v: " << v.capacity()
            << std::endl;
  v.clear();
  std::cout << "After clearing size of v: " << v.size() << std::endl;
  std::cout << "After clearing last element capacity of v: " << v.capacity()
            << std::endl;
}

void stack_stl() {
  std::stack<std::string> s;
  s.push("cat");
  s.push("bat");
  s.push("rat");

  // Print from the last element
  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl;
}

int main() {
  array_stl();
  vector_stl();
  stack_stl();
  return 0;
}
