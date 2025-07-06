#include <stdio.h>

void move_zeros_to_end(int arr[], int length) {
  int non_zero_element_index = 0;
  for (int i = 0; i < length; i++) {
    /* Shifted non zero element */
    if (arr[i] != 0)
      arr[non_zero_element_index++] = arr[i];
  }
  /* Replace other element to zero */
  for (int i = non_zero_element_index; i < length; i++)
    arr[i] = 0;
}

void print_array(int arr[], int length) {
  for (int i = 0; i < length; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr_1[] = {5, 10};
  int arr_2[] = {0, 5, 0, 0, 10, 0, 15, 0, 0, 0, 20, 0};

  int n1 = sizeof(arr_1) / sizeof(arr_1[0]);
  int n2 = sizeof(arr_2) / sizeof(int);

  move_zeros_to_end(arr_1, n1);
  move_zeros_to_end(arr_2, n2);
  print_array(arr_1, n1);
  print_array(arr_2, n2);

  return 0;
}