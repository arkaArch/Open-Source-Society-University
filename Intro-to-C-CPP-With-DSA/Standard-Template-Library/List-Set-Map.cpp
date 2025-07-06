#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>

// ----------------------- List ------------------------ //
// A list is implemented as a doubly linked list. So lists do not support random
// access.
void list_stl() {
  // Operations like, size(), empty(), push_front(), push_back(),
  // pop_front(), pop_back(), front(), back() are same as above
  std::list<int> l = {4, 3, 5, 2};
  // Inserting an element at index 3
  auto it = l.begin();
  advance(it, 3);
  l.insert(it, 9);
  for (auto i : l)
    std::cout << i << " ";
  std::cout << std::endl;

  // Now the list become: {4, 3, 5, 9, 2}
  // So to access 4th element:
  std::cout << "Fourth element in the list: " << *next(l.begin(), 3)
            << std::endl;
}

// ----------------------- Set ------------------------ //
// Sets are associative container which stores unique elements in some sorted
// order. By default, it is sorted ascending order of the keys.
void print(std::set<int> s) {
  for (int i : s)
    std::cout << i << " ";
  std::cout << std::endl;
}
void set_stl() {
  std::set<int> s;
  s.insert(5);
  s.insert(8);
  s.insert(1);
  s.insert(4);
  s.insert(2);
  s.insert(5);
  s.insert(8);
  s.insert(1);
  s.insert(4);
  s.insert(2);
  s.insert(5);
  s.insert(8);
  s.insert(1);
  s.insert(4);
  s.insert(2);
  print(s);

  // We can delete values from set by value and iterator
  s.erase(8);
  s.erase(s.begin());
  print(s);

  // We can check if a value is present in set or not(answer is 1 or 0)
  std::cout << "Is 5 is present inside the set: " << s.count(5) << std::endl;

  // find() method in set returns the iterator
  std::set<int>::iterator it = s.find(4);
  std::cout << "Values >= 4 present in the set: ";
  while (it != s.end()) {
    std::cout << *it << " ";
    it++;
  }
  std::cout << std::endl;
}

// ----------------------- Map ------------------------ //
// Maps are associative containers that store data in the form of key value
// pairs sorted on the basis of keys.
void map_stl() {
  std::map<std::string, std::string> fighter_jets{{"Mirage", "France"},
                                                  {"Sukhoi", "Russia"}};
  fighter_jets.insert({"McDonnell", "America"});
  for (auto jet : fighter_jets)
    std::cout << jet.first << " made in " << jet.second << std::endl;
  // So it printed in the basis of keys - 1. Mc..., 2. Mi..., 3. Su...
  fighter_jets.erase("McDonnell");
  fighter_jets["Saab-JAS-39-Gripen"] = "Sweden";

  std::cout << "\n------->>>>>****<<<<<-------\n" << std::endl;
  for (auto jet : fighter_jets)
    std::cout << jet.first << " made in " << jet.second << std::endl;
}

int main() {
  list_stl();
  set_stl();
  map_stl();
  return 0;
}
