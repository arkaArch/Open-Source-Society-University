#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int calculate_gcd(int a, int b) {
  /* The greatest common divisor is the largest positive integer that
  can fully divide each of the integers (i.e. without leaving a remainder). */

  int gcd = 1;
  for (int i = 1; i <= MIN(a, b); i++) {
    if (a % i == 0 && b % i == 0) {
      gcd = i;
    }
  }
  return gcd;
  /* Time Complexity = O(n) */
}

/* Ecuclidean Algorithm */
int calculate_gcd_opt(int a, int b) {
  int min_val = MIN(a, b);
  int max_val = MAX(a, b);

  if (min_val == 0)
    return max_val;

  while (min_val != 0) {
    int rem = max_val % min_val;
    max_val = min_val;
    min_val = rem;
  }
  return max_val;
}

int main() {
  printf("%d \n", calculate_gcd(18, 54));     // 18
  printf("%d \n", calculate_gcd_opt(36, 60)); // 12

  return 0;
}
