#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int count_distinct_element_unsorted_sequence(int *arr, int length);
int find_single_missing_element_sorted_sequence(int *arr, int length);
void find_multiple_missing_element_sorted_sequence(int *arr, int length);
void find_multiple_missing_element_unsorted_sequence(int *arr, int length);
int *largest_and_second_largest(int *arr, int length);

int main() {
  int arr_5[] = {10, 10, 20, 30, 30, 20, 50, 40, 40, 60, 50};
  int length = sizeof(arr_5) / sizeof(arr_5[0]);
  int distinct_element =
      count_distinct_element_unsorted_sequence(arr_5, length);
  printf("Number of distinct elements in the unsorted sequence: %d \n",
         distinct_element); // 6

  int arr_2[] = {10, 11, 12, 14, 15};
  length = sizeof(arr_2) / sizeof(arr_2[0]);
  int missing_element =
      find_single_missing_element_sorted_sequence(arr_2, length);
  printf("Missing elemenet in the sorted sequence: %d\n", missing_element);

  int arr_3[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18};
  length = sizeof(arr_3) / sizeof(arr_3[0]);
  printf("Missing elements in the sorted sequence are: ");
  find_multiple_missing_element_sorted_sequence(arr_3, length);

  // sorted_sequence = { 2, 3, 5, 7, 10, 11, 13, 14, 15}
  int arr_4[] = {10, 15, 3, 7, 2, 13, 14, 11};
  length = sizeof(arr_4) / sizeof(arr_4[0]);
  printf(
      "Missing elements in the unsorted sequence are: "); // 4, 5, 6, 8, 9, 12
  find_multiple_missing_element_unsorted_sequence(arr_4, length);

  int arr_5_1[] = {1, 3, 4, 5, 7, 4, 7, 3};
  int *result = largest_and_second_largest(arr_5_1, 8);
  printf("Largest and second largest are: %d and %d\n", result[0], result[1]);
  int arr_5_2[] = {6, 6, 6, 6};
  result = largest_and_second_largest(arr_5_2, 4);
  printf("Largest and second largest are: %d and %d\n", result[0], result[1]);

  return 0;
}

int count_distinct_element_unsorted_sequence(int *arr, int length) {
  /* See the left side from an element, if same element not present then it's
   * distinct */
  int distinct_elements = 1;
  for (int i = 1; i < length; i++) {
    bool is_distinct = true;
    for (int j = 0; j < i; j++) {
      if (arr[i] == arr[j])
        is_distinct = false;
    }
    if (is_distinct)
      distinct_elements++;
  }
  return distinct_elements;
}

int find_single_missing_element_sorted_sequence(int *arr, int length) {
  // Calculate the difference between index and element
  for (int i = 1; i < length; i++) {
    if (arr[i] - i != arr[0])
      return arr[i] - 1;
  }
  return -1;
}

void find_multiple_missing_element_sorted_sequence(int *arr, int length) {
  int diff = arr[0];
  for (int i = 1; i < length; i++) {
    if (arr[i] - i != diff) {
      // Found one/more missing element
      while (diff < arr[i] - i) {
        printf("%d ", diff + i);
        diff++;
      }
    }
  }
  printf("\n");
}

void find_multiple_missing_element_unsorted_sequence(int *arr, int length) {
  // Find max and min of the given array
  int max = INT_MIN, min = INT_MAX;
  for (int i = 0; i < length; i++) {
    if (arr[i] > max)
      max = arr[i];
    if (arr[i] < min)
      min = arr[i];
  }

  // Now create an array of size 'max'
  int *hash_arr = (int *)malloc(sizeof(int) * (max + 1));

  /* Update value of index 'arr[i]' of 'hash_arr', i.e hash_arr[arr[i]]
  by 1, if value is found */
  for (int i = 0; i < length; i++)
    hash_arr[arr[i]]++;

  // start i where the sequence is start, i.e min of array
  for (int i = min; i < max; i++) {
    if (hash_arr[i] == 0)
      printf("%d ", i);
  }
  printf("\n");
}

int *largest_and_second_largest(int *arr, int length) {
  int max = INT_MIN, max_2 = INT_MIN;
  int *max_and_second_max = (int *)malloc(sizeof(int) * 2);
  for (int i = 0; i < length; i++)
    max = arr[i] > max ? arr[i] : max;
  max_and_second_max[0] = max;

  for (int i = 0; i < length; i++)
    if (arr[i] > max_2 && arr[i] < max)
      max_2 = arr[i];

  // If max_2 is not found return -1;
  if (max_2 == INT_MIN)
    max_2 = -1;
  max_and_second_max[1] = max_2;

  return max_and_second_max;
}