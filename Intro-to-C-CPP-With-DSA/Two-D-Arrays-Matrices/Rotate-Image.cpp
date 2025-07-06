#include <iostream>
#include <vector>
using namespace std;

// You have to rotate the image in-place, which means you have to modify the
// input 2D matrix directly. Do not allocate another 2D matrix and do the
// rotation.

void rotate(vector<vector<int>> &matrix) {
  // First swap the rows, i.e swap n th row with 0th row
  // n-1 th row with 1st row, n-2 th row with 2nd row, and so on.
  int n = matrix.size() - 1;
  // Change from 0 to n/2 th row
  for (int i = 0; i <= n / 2; i++) {
    // Swap each element
    for (int j = 0; j <= n; j++)
      swap(matrix[i][j], matrix[n - i][j]);
  }

  // Now swap row with column, i.e nth row with nt column
  // n-1 th row with n-1 th column and so on untill 1st row
  // with 1st column. matrix[k][k] for k <= n are already sorted.
  for (int i = n; n >= 0; n--) {
    for (int j = 0; j < n; j++)
      swap(matrix[n][j], matrix[j][n]);
  }
}

int main() {
  vector<vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  rotate(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++)
      cout << matrix[i][j] << "\t";
    cout << endl;
  }
  return 0;
}
