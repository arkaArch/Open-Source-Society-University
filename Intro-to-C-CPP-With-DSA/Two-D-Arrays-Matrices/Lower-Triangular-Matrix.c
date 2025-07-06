/*
Lower Triangular Matrix:
Square matrix, M[row, col] = 0, if row < col
and M[row, col] != 0 if row >= col

a 0 0 0 0
b c 0 0 0
d e f 0 0
g h i j 0
k l m n p

So the idea is to store the non-zero element into a 1D array and
access them by row-major mapping or column major mapping

Total element = 1 + 2 + 3 + .... + n = n(n + 1) / 2

Row major mapping: [(a), (b, c), (d, e, f), (g, h, i, j), (k, l, m, n, p)]
Here, we use braces to seperate the element of every row for better sight
So, to access M[5,4] = [1 + 2 + 3 + 4] + (4 - 1) = 13th index = n
M[i,j] = {1 + 2 + .... + (i - 1)} + (j - 1) = {i * (i - 1) / 2} + (j - 1)

Column major mapping: [(a, b, d, g, k), (c, e, h ,l), (f, i, m), (j, n), (p)]
M[i,j] = [{(j-1) * n} - {(j-2) * (j-1) / 2}] + (i-j)

So, implementing row-major mapping is easy
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *lower_triangular_matrix, row, choice;
  printf("Enter the row/column number of the matrix: ");
  scanf("%d", &row);
  int total_element = (row * (row + 1)) / 2;
  lower_triangular_matrix = (int *)malloc(sizeof(int) * total_element);

  while (1) {
    printf("1. Create matrix\n");
    printf("2. Set a value\n");
    printf("3. Get a value\n");
    printf("4. Display matrix\n");
    printf("5. Quit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      // Create matrix
      for (int i = 0; i < total_element; i++) {
        printf("Enter the non zero element: ");
        scanf("%d", &lower_triangular_matrix[i]);
      }
      break;

    case 2:
      // Set values in matrix
      int r, c, element;
      printf("Enter row column: ");
      scanf("%d %d", &r, &c);
      printf("Enter the element: ");
      scanf("%d", &element);
      if (r >= c)
        lower_triangular_matrix[((r * (r - 1)) / 2) + (c - 1)] = element;
      break;

    case 3:
      // Get values from matrix
      printf("Enter row and column: ");
      scanf("%d %d", &r, &c);
      if (r >= c)
        printf("%d \n", lower_triangular_matrix[((r * (r - 1)) / 2) + (c - 1)]);
      else
        printf("0 \n");
      break;

    case 4:
      // Display matrix
      int k = 0; // Index for the array, which stores non-zero elements
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
          if (i >= j)
            printf("%d ", lower_triangular_matrix[k++]);
          else
            printf("0 ");
        }
        printf("\n");
      }
      break;

    case 5:
      // Exit from the program
      exit(1);
    default:
      printf("Wrong input \n");
    }
  }
  return 0;
}