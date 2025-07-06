#include <stdio.h>

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  /* Declaring an array */
  int A[5];
  // The value of each element will initialized as a garbage value
  int B[5] = {0};
  // The value of each element will initialized 0
  int C[5] = {12, 16};
  // The value of each element will initialized as: 12, 16, 0, 0, 0
  int D[5] = {19, 45, 65, 76, 98};

  print_array(A, 5);
  print_array(B, 5);
  print_array(C, 5);
  print_array(D, 5);

  return 0;
}