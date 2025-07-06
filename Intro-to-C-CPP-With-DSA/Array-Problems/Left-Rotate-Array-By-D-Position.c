/*
If an array is { 1, 2, 3, 4, 5 }. By left rotating one,
the array will become { 2, 3, 4, 5, 1 }

Now, by left rotating three position,
the array will become { 4, 5, 1, 2, 3 }

This is seen in LED board --> Like in train the words are moving
*/

#include <stdio.h>

void left_rotate_array_by_one(int arr[], int length) {
  /* First copy the first element in a variable */
  int temp = arr[0];
  /* Move the element from index "2" to "length - 1" by one position to left */
  for (int i = 1; i < length; i++)
    arr[i - 1] = arr[i];
  /* Copy first element into last element */
  arr[length - 1] = temp;
}

/* Time complexity = O(n^2), Auxiliary space = O(1) */
void left_rotate_array_by_d_brute_force(int arr[], int length, int d) {
  for (int i = 0; i < d; i++)
    left_rotate_array_by_one(arr, length);
}

/* Time complexity = O(n), Auxiliary space = O(n) */
void left_rotate_array_by_d_better(int arr[], int length, int d) {
  /* Copy d element in an array */
  int temp_arr[d];
  for (int i = 0; i < d; i++)
    temp_arr[i] = arr[i];

  /* Now move (length - d) elements at left
  (i-d) gives the access from 0 th element */
  for (int i = d; i < length; i++)
    arr[i - d] = arr[i];

  /* Copy the other elements form temp_arr */
  for (int i = 0; i < d; i++)
    arr[length - d + i] = temp_arr[i];
}

void reverse(int arr[], int first_index, int last_index) {
  while (first_index < last_index) {
    int temp = arr[first_index];
    arr[first_index] = arr[last_index];
    arr[last_index] = temp;
    first_index++;
    last_index--;
  }
}

/* Time complexity = O(n), Auxiliary space = O(1) */
void left_rotate_array_by_d_optimal(int arr[], int length, int d) {
  /* Reverse the element from 0 to (d - 1) */
  reverse(arr, 0, d - 1);
  /* Reverse the element from d to (length - 1) */
  reverse(arr, d, length - 1);
  /* Reverse the whole array */
  reverse(arr, 0, length - 1);
}

void print_array(int arr[], int length) {
  for (int i = 0; i < length; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr_1[5] = {1, 2, 3, 4, 5};
  int arr_2[5] = {1, 2, 3, 4, 5};
  int arr_3[5] = {1, 2, 3, 4, 5};
  int arr_4[5] = {1, 2, 3, 4, 5};

  left_rotate_array_by_one(arr_1, 5);
  print_array(arr_1, 5);

  left_rotate_array_by_d_brute_force(arr_2, 5, 3);
  print_array(arr_2, 5);

  left_rotate_array_by_d_better(arr_3, 5, 3);
  print_array(arr_3, 5);

  left_rotate_array_by_d_optimal(arr_4, 5, 3);
  print_array(arr_4, 5);

  return 0;
}