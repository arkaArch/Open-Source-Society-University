#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
  int first_position = -1, last_position = -1;
  int low = 0, high = nums.size() - 1;
  // Find first position
  while (low <= high) {
    int mid = high + (low - high) / 2;
    if (nums[mid] == target) {
      first_position = mid;
      // Search left part to find any occurance
      high = mid - 1;
    } else if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }

  // Find last postion
  // Reset low & high
  low = 0, high = nums.size() - 1;
  while (low <= high) {
    int mid = high + (low - high) / 2;
    if (nums[mid] == target) {
      last_position = mid;
      // Search right part to find any occurance
      low = mid + 1;
    } else if (nums[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return vector<int>{first_position, last_position};
}

int main() {
  vector<int> v1 = {5, 7, 7, 8, 8, 8};
  vector<int> v2 = {};

  vector<int> result_v1 = searchRange(v1, 8);
  vector<int> result_v2 = searchRange(v2, 0);

  for (int position : result_v1)
    cout << position << " ";
  cout << endl;

  for (int position : result_v2)
    cout << position << " ";
  cout << endl;

  return 0;
}
