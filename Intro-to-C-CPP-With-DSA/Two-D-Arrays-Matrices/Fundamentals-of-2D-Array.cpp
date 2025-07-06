#include <iostream>
using namespace std;

void print(int (*arr)[4], int row, int col) {
  // arr will store the first address of three address array,
  // Where each address holds the first address of an integer array
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      cout << arr[i][j] << "\t";
    cout << endl;
  }
}

int main() {
  // Initialize a array with 3 rows and 4 columns
  int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  // int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  print(arr1, 3, 4);
  // So if we declare as above the array take inputs row-wise
  // If we want to it's take input as coloumn wise then,
  int arr2[3][4] = {{1, 4, 7, 10}, {2, 5, 8, 11}, {3, 6, 9, 12}};
  cout << endl;
  print(arr2, 3, 4);

  int arr3[3][4];
  // Taking input in row-wise
  cout << "Enter element row wise(first four element will go in first row): ";
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 4; col++) {
      // cout << "Enter element of row " << row + 1 << ", column " << col + 1 <<
      // " : ";
      cin >> arr3[row][col];
    }
  }
  print(arr3, 3, 4);

  int arr4[3][4];
  // Taking input in column-wise
  cout << "Enter element column wise(first three element will go in first "
          "column): ";
  for (int col = 0; col < 4; col++) {
    for (int row = 0; row < 3; row++) {
      // cout << "Enter element of col " << col + 1 << ", row " << row + 1 << "
      // : ";
      cin >> arr4[row][col];
    }
  }
  print(arr4, 3, 4);
}
