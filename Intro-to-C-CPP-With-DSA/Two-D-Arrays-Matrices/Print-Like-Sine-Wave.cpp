#include <iostream>
#include <vector>
using namespace std;

// Print the first column top to bottom, next column bottom to top, and so on.
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
  // So if column number is even it goes downward and if odd it goes upward
  vector<int> result;
  for (int i = 0; i < mCols; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < nRows; j++)
        result.push_back(arr[j][i]);
    } else
      for (int j = nRows - 1; j >= 0; j--)
        result.push_back(arr[j][i]);
  }
  return result;
}

int main() {
  vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> sineWave = wavePrint(v, 3, 4);

  // Print wave vector
  for (int element : sineWave)
    cout << element << " ";
  cout << endl;

  return 0;
}
