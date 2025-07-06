#include <iostream>
#include <vector>
using namespace std;

// In bubble sort we find the largest element in array by comparing
// and swapping two neighbour element
void bubbleSort(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size() - 1 - i; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
  }
}

int main() {
  vector<int> v1 = {12, 18, 6, 9, 4, 2, 16, 7};
  bubbleSort(v1);
  for (int element : v1)
    cout << element << " ";
  cout << endl;
  return 0;
}
