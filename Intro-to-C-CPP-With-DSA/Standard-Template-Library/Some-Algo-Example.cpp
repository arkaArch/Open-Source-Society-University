#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string present_or_not(std::vector<int> &v, int k) {
  if (binary_search(v.begin(), v.end(), k))
    return "Present";
  return "Not present";
}

int main() {
  std::vector<int> v = {45, 23, 52, 34};
  // To apply binary search we have to sort the vector
  sort(v.begin(), v.end());
  std::cout << present_or_not(v, 45) << std::endl;
  std::cout << present_or_not(v, 50) << std::endl;

  reverse(v.begin(), v.end());
  for (int i : v)
    std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
