#include <stdio.h>
#include <stdlib.h>

#define __min(a, b) ((a < b) ? a : b)

struct Array {
  int A[20];
  int size;
  int length;
};

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

// Union array is happend in O(m + n) if two array is sorted
// Otherwise it takes O(m * n)
struct Array *sorted_union(struct Array *a, struct Array *b) {
  struct Array *c = (struct Array *)malloc(sizeof(struct Array));
  int i = 0, j = 0, k = 0;
  while (i < a->length && j < b->length) {
    if (a->A[i] < b->A[j])
      c->A[k++] = a->A[i++];

    else if (a->A[i] > b->A[j])
      c->A[k++] = b->A[j++];

    else { // a->A[i] == b->A[j]
      c->A[k++] = a->A[i++];
      j++;
    }
  }
  // If left copy the remaining element from first array
  for (; i < a->length; i++)
    c->A[k++] = a->A[i];
  // If left copy the remaining element from second array
  for (; j < b->length; j++)
    c->A[k++] = b->A[j];

  c->size = a->length + b->length; // Doesn't matter until it's >= length
  c->length = k;
  return c;
}

struct Array *sorted_intersection(struct Array *a, struct Array *b) {
  struct Array *c = (struct Array *)malloc(sizeof(struct Array));
  int i = 0, j = 0, k = 0;
  while (i < a->length && j < b->length) {
    if (a->A[i] == b->A[j]) {
      c->A[k++] = a->A[i++];
      j++;
    } else if (a->A[i] < b->A[j])
      i++;
    else // a->A[i] > b->A[j]
      j++;
  }
  c->size = __min(a->length, b->length);
  c->length = k;
  return c;
}

struct Array *sorted_difference(struct Array *a, struct Array *b) {
  struct Array *c = (struct Array *)malloc(sizeof(struct Array));
  int i = 0, j = 0, k = 0;
  while (i < a->length) {
    if (a->A[i] < b->A[j])
      // a->A[i] not present in b->A[j] since the arrays are sorted
      c->A[k++] = a->A[i++];

    else if (a->A[i] > b->A[j])
      j++;

    else { // a->A[i] == b->A[j]
      i++;
      j++;
    }
  }

  c->size = a->length;
  c->length = k;
  return c;
}

int main() {
  struct Array arr_1 = {{8, 16, 20, 25, 27}, 10, 5};
  struct Array arr_2 = {{4, 12, 16, 20, 23, 27}, 10, 6};

  struct Array *arr_u = sorted_union(&arr_1, &arr_2);
  struct Array *arr_i = sorted_intersection(&arr_1, &arr_2);
  struct Array *arr_d1 = sorted_difference(&arr_1, &arr_2);
  struct Array *arr_d2 = sorted_difference(&arr_2, &arr_1);

  display(arr_u);
  display(arr_i);
  display(arr_d1);
  display(arr_d2);

  // Union: 4 8 10 12 16 20 23 25 27
  // Intersection: 16 20 27
  // arr_1 - arr_2: 8 25
  // arr_2 - arr_1: 4 12 23
  return 0;
}