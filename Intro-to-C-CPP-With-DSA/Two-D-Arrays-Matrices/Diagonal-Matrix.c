/* A square matrix in which every element except the principal diagonal elements
is zero is called a Diagonal Matrix. So, we can store the diagonal element into
a 1D array, to save space and operations complexity such as multiply by zero.

Diagonal Matrix:
1 0 0 0
0 4 0 0
0 0 7 0
0 0 0 5

So, the idea is to save the diagonal elements in an array -> [1, 4, 7, 5];
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *diagonal_matrix, row, choice;
  printf("Enter the row/column number of the matrix: ");
  scanf("%d", &row);
  diagonal_matrix = (int *)malloc(sizeof(int) * row);

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
      for (int i = 0; i < row; i++) {
        printf("Enter the value for [%d, %d]: ", i, i);
        scanf("%d", &diagonal_matrix[i]);
      }
      break;

    case 2:
      // Set values in matrix
      int r, c, element;
      printf("Enter row column: ");
      scanf("%d %d", &r, &c);
      printf("Enter the element: ");
      scanf("%d", &element);
      if (r == c)
        diagonal_matrix[r - 1] = element;
      // We store the diagonal value in a 1D array
      // Since for every (row != column) the value will be zero
      break;

    case 3:
      // Get values from matrix
      printf("Enter row and column: ");
      scanf("%d %d", &r, &c);
      if (r == c)
        printf("%d \n", diagonal_matrix[r - 1]);
      else
        printf("0 \n");
      break;

    case 4:
      // Display matrix
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
          if (i == j)
            printf("%d ", diagonal_matrix[i]);
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
