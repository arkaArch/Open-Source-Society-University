#include <iostream>
#include <vector>
using namespace std;

// In selection sort we find the smallest element in array
// and place in its right position
void selectionSort(vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    int minIndex = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  }
}

int main() {
  vector<int> v1 = {12, 18, 6, 9, 4, 2, 16, 7};
  selectionSort(v1);
  for (int element : v1)
    cout << element << " ";
  cout << endl;
  return 0;
}
