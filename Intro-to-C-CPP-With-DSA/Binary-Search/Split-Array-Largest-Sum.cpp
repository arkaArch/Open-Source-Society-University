/*
 * Given an integer array nums and an integer k, split nums into k non-empty
 * subarrays such that the largest sum of any subarray is minimized. Return the
 * minimized largest sum of the split. A subarray is a contiguous part of the
 * array.
 */

#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> &nums, int k, int mid) {
  int splitCount = 1;
  int splitSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (splitSum + nums[i] <= mid)
      splitSum += nums[i];
    else {
      splitCount++;
      if (splitCount > k || nums[i] > mid)
        return false;
      splitSum = nums[i];
    }
  }
  return true;
}

int splitArray(vector<int> &nums, int k) {
  // We can figure this out with binary search, with a search space
  // from 0 to sum of elements of nums
  long long sum = 0, ans = -1;
  for (int i = 0; i < nums.size(); i++)
    sum += nums[i];

  long long low = 0, high = sum;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isPossibleSolution(nums, k, mid)) {
      ans = mid;
      // Go to left part to find minimum largest sum
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> v1 = {1, 2, 3, 4, 5};
  // Best solution (1+2+3), (4+5) -> 9
  vector<int> v2 = {7, 2, 5, 10, 8, 4, 9, 1};
  // Best solution (7+2+5), (10+8), (4,9,1) -> 18
  cout << splitArray(v1, 2) << endl;
  cout << splitArray(v2, 3) << endl;
  return 0;
}
