#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Array {
  int *A;     // Adress of the Array
  int size;   // Size of the Array
  int length; // Length of the Array/No of element
};

int sum(struct Array *a);
int avg(struct Array *a);
void swap(int *x, int *y);
bool is_sorted(struct Array *a);
void display(struct Array *a);
void increase_size(struct Array *a, int increase_size_by);
void append(struct Array *a, int element);
void insert(struct Array *a, int position, int element);
void delete(struct Array *a, int position);
int linear_search(struct Array *a, int key);
int binary_search(struct Array *a, int key);
void reverse_array(struct Array *a);
void rearrange_negatives(struct Array *a);

/* ==================== START MAIN FUNCTION ==================== */
int main() {
  struct Array arr;
  printf("Enter the size of the array: ");
  scanf("%d", &arr.size);
  arr.A = (int *)malloc(sizeof(int) * arr.size);
  printf("How many number you want to insert: ");
  scanf("%d", &arr.length);
  for (int i = 0; i < arr.length; i++) {
    printf("Enter the element %d: ", (i + 1));
    scanf("%d", &arr.A[i]);
  }

  int choice, element, position, increase_size_by;
  while (1) {
    printf("\n");
    printf("1. Display Array\n");
    printf("2. Sum of Elements\n");
    printf("3. Avg of Elements\n");
    printf("4. Increase Size\n");
    printf("5. Append Element\n");
    printf("6. Insert Element\n");
    printf("7. Delete Element\n");
    printf("8. Linear Search\n");
    printf("9. Binary Search\n");
    printf("10. Reverse Array\n");
    printf("11. Rearrange Negatives\n");
    printf("12. Quit Program\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      display(&arr);
      break;
    case 2:
      printf("Sum: %d", sum(&arr));
      break;
    case 3:
      printf("Avg: %d", avg(&arr));
      break;
    case 4:
      printf("Size to be increased: ");
      scanf("%d", &increase_size_by);
      increase_size(&arr, increase_size_by);
      break;
    case 5:
      printf("Element to be inserted: ");
      scanf("%d", &element);
      append(&arr, element);
      break;
    case 6:
      printf("Position(Not index) to be inserted: ");
      scanf("%d", &position);
      printf("Element to be inserted: ");
      scanf("%d", &element);
      insert(&arr, position, element);
      break;
    case 7:
      printf("Position(Not index) to be deleted: ");
      scanf("%d", &position);
      delete(&arr, position);
      break;
    case 8:
      printf("Element to be search: ");
      scanf("%d", &element);
      printf("Index: %d\n", linear_search(&arr, element));
      break;
    case 9:
      // Binary Search works with sorted array
      if (!is_sorted(&arr))
        printf("You can't do binary search in an unsorted array\n");
      else {
        printf("Element to be search: ");
        scanf("%d", &element);
        printf("Index: %d\n", binary_search(&arr, element));
      }
      break;
    case 10:
      reverse_array(&arr);
      break;
    case 11:
      rearrange_negatives(&arr);
      break;
    case 12:
      exit(1);
    default:
      printf("Wrong choice.\n");
    }
  }

  return 0;
}
/* ==================== END OF MAIN FUNCTION ==================== */

void display(struct Array *a) {
  printf("{ ");
  for (int i = 0; i < a->length; i++) {
    if (i != a->length - 1)
      printf("%d, ", a->A[i]);
    else
      printf("%d", a->A[i]);
  }
  printf(" }\n");
}

int sum(struct Array *a) {
  int sum = 0;
  for (int i = 0; i < a->length; i++)
    sum += a->A[i];
  return sum;
}

int avg(struct Array *a) { return sum(a) / a->length; }

bool is_sorted(struct Array *a) {
  for (int i = 0; i < (a->length - 1); i++)
    if (a->A[i] > a->A[i + 1])
      return false;
  return true;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void increase_size(struct Array *a, int increase_size_by) {
  a->size += increase_size_by;
  // First create a new array of increased size
  int *new_arr = (int *)malloc(sizeof(int) * a->size);
  // Copy old array to the new array
  for (int i = 0; i < a->length; i++)
    new_arr[i] = a->A[i];
  // Delete old array
  free(a->A);
  // Copy the reference of the new_array to old_arr
  a->A = new_arr;
  // Delete the reference of the new array
  new_arr = NULL;
}

void append(struct Array *a, int element) {
  if (a->size <= a->length) {
    printf("Insertion is not possible(Array is already full) \n");
    return;
  }
  // Store the element and increase the length by 1
  a->A[a->length++] = element;
}

void insert(struct Array *a, int position, int element) {
  // Check if there is an empty space in the array
  if (a->size <= a->length) {
    printf("Insertion is not possible(Array is already full) \n");
    return;
  }
  // Move elements from index "position - 1" to "length"
  for (int i = a->length; i >= position; i--)
    a->A[i] = a->A[i - 1];
  // Insert at index "position - 1"
  a->A[position - 1] = element;
  // Length of the array will be increased
  a->length++;
}

void delete(struct Array *a, int position) {
  for (int i = position - 1; i < a->length; i++)
    a->A[i] = a->A[i + 1];
  a->length--;
}

int linear_search(struct Array *a, int key) {
  for (int i = 0; i < a->length; i++) {
    if (key == a->A[i])
      return i;
  }
  return -1;
}

int binary_search(struct Array *a, int key) {
  int low = 0, high = a->length - 1;
  while (low <= high) {
    int mid = high + (low - high) / 2;
    if (a->A[mid] == key)
      return mid;
    else if (a->A[mid] > key)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

void reverse_array(struct Array *a) {
  int first_index = 0;
  int last_index = a->length - 1;
  // Swap first_index with last_index
  while (first_index < last_index) {
    swap(&a->A[first_index], &a->A[last_index]);
    first_index++;
    last_index--;
  }
}

void rearrange_negatives(struct Array *a) {
  // Move negative elements left
  int first_index = 0;
  int last_index = a->length - 1;
  while (first_index < last_index) {
    // Move first_index until it finds a positive number
    while (a->A[first_index] < 0)
      first_index++;
    // Move last_index until it finds a positive number
    while (a->A[last_index] > 0)
      last_index--;
    // Swap them
    if (first_index < last_index)
      swap(&a->A[first_index], &a->A[last_index]);
  }
}
