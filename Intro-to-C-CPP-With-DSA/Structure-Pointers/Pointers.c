/* 1. Program can directly access code and stack section but not the heap. So to
access the heap section of memory we use pointers.
2. When we try to access any resourses, like HDD, Keyboard, network, we need the
pointer.
3. For parameter passing we also need pointers. */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 10;
  int *p = &a;

  printf("Value of a -> %d \n", a);
  printf("Address of a -> %d \n", p);
  printf("Value of a using pointer -> %d \n", *p);

  int A[5] = {1, 2, 3, 5, 6};
  // int *ptr = &A[0]
  // A holds the address of first element of array
  int *ptr = A;
  for (int i = 0; i < 5; i++)
    // Accessing the element with pointers
    printf("%d ", ptr[i]);
  printf("\n");

  // Intialize an array of 5 element in heap
  int *heap_ptr = (int *)malloc(sizeof(int) * 5);
  // Assigning the values in the array
  heap_ptr[0] = 15;
  heap_ptr[1] = 34;
  heap_ptr[2] = 87;
  heap_ptr[3] = 56;
  heap_ptr[4] = 76;
  //  Printing the array
  for (int i = 0; i < 5; i++)
    printf("%d ", heap_ptr[i]);
  // We can accessing by pointer arithmetic
  // printf("%d ", *heap_ptr++);
  printf("\n");
  // Clear the memory from heap (though here not required)
  free(heap_ptr);

  return 0;
}