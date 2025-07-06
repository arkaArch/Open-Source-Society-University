/* A jagged array is a 2D array where every element holds a different sized
array like: { { 1 }, { 1, 2 }, { 1, 2, 3 }} We can create this array my
dynamically allocated memory
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  /* This array will hold 4 addreeses of 4 array */
  int *jagged_array[4];
  /* This array will hold the size of each row */
  int size[4];
  int n = 2;
  for (int i = 0; i < 4; i++) {
    jagged_array[i] = (int *)malloc(sizeof(int) * n);
    size[i] = n;
    n++;
  }

  /* Enter the values in Jagged array */
  int initial_value = 10, k = 0;
  for (int i = 0; i < 4; i++) {
    int *ptr = jagged_array[i];
    for (int j = 0; j < size[k]; j++) {
      *ptr = initial_value;
      initial_value += 5;
      /* Move the pointer */
      ptr++;
    }
    k++;
  }

  k = 0;
  /* Display the jagged array */
  for (int i = 0; i < 4; i++) {
    int *ptr = jagged_array[i];
    for (int j = 0; j < size[k]; j++) {
      printf("%d ", *ptr);
      /* Move the pointer to next element */
      ptr++;
    }
    printf("\n");
    k++;
  }

  return 0;
}