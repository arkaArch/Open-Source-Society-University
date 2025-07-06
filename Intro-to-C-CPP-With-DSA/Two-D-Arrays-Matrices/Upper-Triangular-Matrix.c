/*
Upper Triangular Matrix:
Square matrix, M[row, col] =! 0, if row <= col
and m[row, col] = 0 if row > col

a b c d e
0 f g h i
0 0 j k l
0 0 0 m n
0 0 0 0 p

So the idea is to store the non-zero element into a 1D array and
access them by row-major mapping or column major mapping

Total element = n + (n - 1) + ... + 3 + 2 + 1 = n(n + 1) / 2

Row major mapping: [(a, b, c, d, e), (f, g, h, i), (j, k, l), (m, n), (p)]
Here, we use braces to seperate the element of every row for better sight
So, to access M[3,4] = Go to 3rd row i.e (5 + 4) + go to 4 th col i.e (4 - 3)
= 9 + 1 = 10 th element = k
M[i,j] = {n + (n - 1) + ... +  n - (i - 2)} + (j - i)
= [{(i-1) * n} - {(i-2) * (i-1) / 2}] + (j-i)

Column major mapping: [(a), (b, f), (c, g, i), (d, h, k, m), (e, i, l, n, p)]
So, to access M[3, 4] = Go 4th col i.e (1 + 2 + 3) + go to 3rd row i.e (3 - 1)
= (1 + 2 + 3) + (3 - 1) = 8 th element = k
M[i,j] = {1 + 2 + 3 + (j - 1)} + (i - 1) = {j * (j - 1) / 2} + (i - 1)

So, implementing column-major mapping is easy
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *upper_triangular_matrix, row, choice;
  printf("Enter the row/column number of the matrix: ");
  scanf("%d", &row);
  int total_element = (row * (row + 1)) / 2;
  upper_triangular_matrix = (int *)malloc(sizeof(int) * total_element);

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
        scanf("%d", &upper_triangular_matrix[i]);
      }
      break;

    case 2:
      // Set values in matrix
      int r, c, element;
      printf("Enter row column: ");
      scanf("%d %d", &r, &c);
      printf("Enter the element: ");
      scanf("%d", &element);
      if (r <= c)
        upper_triangular_matrix[((c * (c - 1)) / 2) + (r - 1)] = element;
      break;

    case 3:
      // Get values from matrix
      printf("Enter row and column: ");
      scanf("%d %d", &r, &c);
      if (r <= c)
        printf("%d \n", upper_triangular_matrix[((c * (c - 1)) / 2) + (r - 1)]);
      else
        printf("0 \n");
      break;

    case 4:
      // Display matrix
      int k = 0; // Index for the array, which stores non-zero elements
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
          if (i <= j)
            printf("%d ", upper_triangular_matrix[k++]);
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