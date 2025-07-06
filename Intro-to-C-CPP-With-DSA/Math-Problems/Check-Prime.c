#include <stdbool.h>
#include <stdio.h>

bool isPrimeBruteForce(int n) {
  /* Complexity: O(n) */
  if (n == 1)
    return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

bool isPrimeOptimal(int n) {
  /* Complexity: O(sqrt(n)) */
  /* We know that divisors are always in pair.(See: Divisors-of-Number.c)
  And one of the divisor in every pair is less or equal to square root of n.
  So if we check first part i.e from 2 to sqrt(n) then we can know that the
  number is prime or not. */
  if (n == 1)
    return false;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  printf("%d \n", isPrimeOptimal(691));    // 1
  printf("%d \n", isPrimeOptimal(650));    // 0
  printf("%d \n", isPrimeBruteForce(691)); // 1
  printf("%d \n", isPrimeBruteForce(650)); // 0

  return 0;
}
