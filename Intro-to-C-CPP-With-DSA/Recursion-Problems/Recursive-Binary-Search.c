#include <stdio.h>
int binary_search(int *arr, int low, int high, int key) {
  if (high >= low) {
    int mid = high + (low / 2 - high / 2);
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] > key)
      return binary_search(arr, low, mid - 1, key);
    else
      return binary_search(arr, mid + 1, high, key);
  }
  return -1;
}

int main() {
  int a[] = {2, 6, 8, 9, 14, 17, 19, 26, 37};
  int l = sizeof(a) / sizeof(a[0]);
  printf("%d \n", binary_search(a, 0, l - 1, 19)); // 6
}