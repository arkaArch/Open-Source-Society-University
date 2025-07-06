#include <iostream>
#include <vector>
using namespace std;

// You are given an m x n integer matrix matrix with the following two
// properties: Each row is sorted in non-decreasing order. The first integer of
// each row is greater than the last integer of the previous row. Given an
// integer target, return true if target is in matrix or false otherwise. You
// must write a solution in O(log(m * n)) time complexity.

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  // Lets think it as a linear array.
  // So we have to traverse from 0 to (row*col - 1)
  // Now if we take index as linear from and if the index is 'i'
  // then the element lies in matrix[i/col][i%col].

  int row = matrix.size();
  int col = matrix[0].size();

  int low = 0, high = row * col - 1;
  while (low <= high) {
    int mid = high + (low - high) / 2;
    int element = matrix[mid / col][mid % col];
    if (element == target)
      return true;
    else if (element > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return false;
}

int main() {
  vector<vector<int>> v = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  cout << searchMatrix(v, 13) << endl;
  cout << searchMatrix(v, 20) << endl;

  return 0;
}
