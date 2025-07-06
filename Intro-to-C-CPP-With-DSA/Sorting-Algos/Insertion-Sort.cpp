#include <iostream>
#include <vector>
using namespace std;

// In insertion sort we pick an element and put it in a sorted part
void insertionSort(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    // Peak an element
    int element = arr[i];
    int j = i - 1;
    /*
    while(j >= 0) {
        if(arr[j] > element) {
            // Shift the greater element in right side
            arr[j+1] = arr[j];
            arr[j] = element;
            j--;
        } else      // arr[j] < element
            break;
    }
    */

    while (j >= 0 && arr[j] > element) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = element;
  }
}

int main() {
  vector<int> v1 = {12, 18, 6, 9, 4, 2, 16, 7};
  insertionSort(v1);
  for (int element : v1)
    cout << element << " ";
  cout << endl;
  return 0;
}
