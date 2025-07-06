#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr) {
  int low = 0, high = arr.size() - 1, mid;
  while (low < high) {
    mid = low + (high - low) / 2;
    // mid in increasing slope
    if (arr[mid] < arr[mid + 1])
      low = mid + 1;
    else // element is peak or in decreasing slope
      high = mid;
  }
  return low;
}

int main() {
  vector<int> v1 = {0, 3, 6, 9, 10, 5, 3, 2};
  vector<int> v2 = {3, 5, 3, 2, 0};
  cout << peakIndexInMountainArray(v1) << endl;
  cout << peakIndexInMountainArray(v2) << endl;
  return 0;
}
