#include <stdlib.h>

int main() {
  int *i = (int *)malloc(sizeof(int));
  /* Here variable 'i' created in stack and store the
  address of '32' which is created in heap */

  int *arr[4];
  for (int i = 0; i < 4; i++)
    arr[i] = (int *)malloc(sizeof(int) * 3);
  /* Here 'arr' is created in stack which allocates 4 contiguous
  memory location of 8 bytes. Since every element of 'arr' holds
  the first location of the array created in heap.
  In heap 4 arrays will be created, each of which contains 4 bytes
  (int) of 3 contiguous memory. */

  int **arr_ = (int **)malloc(sizeof(int *) * 4);
  for (int i = 0; i < 4; i++)
    arr_[i] = (int *)malloc(sizeof(int) * 3);
  /* Here 'arr' is just a variable store in stack which contains
  the address of arr[0].
  Now 'arr' array is created in heap which contain 8 bytes of memory
  (address) in each element. Each element is contain the address of
  array of 3 integer elements.
  So, here the whole 2D array is created inside heap.
  */

  return 0;
}