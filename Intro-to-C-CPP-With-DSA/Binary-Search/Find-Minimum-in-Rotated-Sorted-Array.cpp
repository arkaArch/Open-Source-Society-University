#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums) {
  int low = 0, high = nums.size() - 1, min;
  while (low <= high) {
    if (nums[0] < nums[nums.size() - 1]) {
      return nums[0];
    }
    int mid = high + (low - high) / 2;
    if (nums[mid] <= nums[0] && nums[mid] <= nums[nums.size() - 1]) {
      // Maybe minimum, or minimum element is in left part
      min = nums[mid];
      high = mid - 1;
    } else
      // Find in right part
      low = mid + 1;
  }
  return min;
}

int main() {
  vector<int> v1 = {11, 12, 13, 14, 15};
  vector<int> v2 = {4, 5, 6, 7, 8, 0, 1, 2, 3};

  cout << findMin(v1) << endl;
  cout << findMin(v2) << endl;
  return 0;
}
