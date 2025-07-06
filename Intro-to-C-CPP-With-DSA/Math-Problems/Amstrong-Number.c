/*
An Armstrong number is a number (with 'k' digits) such that the sum of its
digits raised to 'kth' power is equal to the number itself. For example, 371 is
an Armstrong number because 3^3 + 7^3 + 1^3 = 371. 1634 is also an Armstrong
number, as 1^4 + 6^4 + 3^4 + 4^4 = 1634
*/
#include <stdbool.h>
#include <stdio.h>

int power(int n, int power) {
  int result = 1;
  for (int i = 0; i < power; i++) {
    result *= n;
  }
  return result;
}

bool is_armstrong(int n) {
  int digits = 0, n_copy_1 = n, n_copy_2 = n;
  /* Calculate digit number */
  while (n_copy_1 != 0) {
    n_copy_1 /= 10;
    digits++;
  }

  int i = 1, result = 0;
  while (i <= digits) {
    result += power(n_copy_2 % 10, digits);
    n_copy_2 /= 10;
    i++;
  }

  if (result == n)
    return true;
  return false;
}

int main() {
  printf("%d \n", is_armstrong(371));  // 1
  printf("%d \n", is_armstrong(1371)); // 0
  printf("%d \n", is_armstrong(1634)); // 1

  return 0;
}
