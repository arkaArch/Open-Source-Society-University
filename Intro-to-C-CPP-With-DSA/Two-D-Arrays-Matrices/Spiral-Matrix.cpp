#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  int totalElement = row * col;
  vector<int> spiral;

  // To traverse spiral we have to print like:
  // startingRow -> endingCol -> endingRow -> startingCol
  int startingRow = 0;
  int startingCol = 0;
  int endingRow = row - 1;
  int endingCol = col - 1;

  int count = 0;
  while (count < totalElement) {
    // Print startingRow
    for (int index = startingCol; index <= endingCol && count < totalElement;
         index++) {
      spiral.push_back(matrix[startingRow][index]);
      count++;
    }
    startingRow += 1;

    // Print endingCol
    for (int index = startingRow; index <= endingRow && count < totalElement;
         index++) {
      spiral.push_back(matrix[index][endingCol]);
      count++;
    }
    endingCol -= 1;

    // Print endingRow
    for (int index = endingCol; index >= startingCol && count < totalElement;
         index--) {
      spiral.push_back(matrix[endingRow][index]);
      count++;
    }
    endingRow -= 1;

    // Print startingCol
    for (int index = endingRow; index >= startingRow && count < totalElement;
         index--) {
      spiral.push_back(matrix[index][startingCol]);
      count++;
    }
    startingCol += 1;
  }
  return spiral;
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  vector<int> spiralMat = spiralOrder(matrix);
  for (int element : spiralMat)
    cout << element << " ";
  cout << endl;

  return 0;
}
