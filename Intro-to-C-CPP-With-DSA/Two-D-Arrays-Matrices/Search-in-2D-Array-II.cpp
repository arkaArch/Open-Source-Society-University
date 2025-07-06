#include <iostream>
#include <vector>
using namespace std;

// You are given an m x n integer matrix matrix with the following two
// properties: Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  // Start at the top-right cell. Now if the current value is greater than the
  // target, then the target is not exist in this row, since under the current
  // value, all are greater than the current value so move left. Now if the
  // current value is less than target we have to move downward since top values
  // are minimum in the row.
  int row = 0;
  int col = matrix[0].size() - 1;

  while (row < matrix.size() && col >= 0) {
    if (matrix[row][col] == target)
      return true;
    else if (matrix[row][col] > target)
      col--;
    else
      row++;
  }
  return false;
}

int main() {
  vector<vector<int>> v = {{1, 4, 7, 11, 15},
                           {2, 5, 8, 12, 19},
                           {3, 6, 9, 16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}};

  cout << searchMatrix(v, 5) << endl;
  cout << searchMatrix(v, 20) << endl;

  return 0;
}
