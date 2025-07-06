#include <stdio.h>
#include <stdlib.h>

int *create_dynamic_array(int arr_size) {
  int *ptr = (int *)malloc(sizeof(int) * arr_size);
  for (int i = 0; i < arr_size; i++)
    ptr[i] = i + 2;
  return ptr;
}

int main() {
  int *arr = create_dynamic_array(5);

  /* Print the array */
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}