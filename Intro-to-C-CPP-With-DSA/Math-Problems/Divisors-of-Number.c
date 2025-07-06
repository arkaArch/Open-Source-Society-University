#include <stdio.h>

void print_divisors_of_num_brute_force(int n) {
  for (int i = 1; i <= n; i += 1) {
    if (n % i == 0)
      printf("%d ", i);
  }
  printf("\n");
  /* Time complexity -> O(n) */
}

void print_divisors_of_num_optimal(int n) {
  /* This solution based on two facts.
  1. Divisors always appear in pairs.
     30 -> (1, 30), (2, 15), (3, 10), (5, 6)

  2. One of the divisor in every pair is less or equal to square root of n.

      Proof:--
      So for a pair (x, y), let x <= y
          x*y = n
          x*x <= n
          x <= square root of n */

  for (int i = 1; i * i <= n; i++) {
    /* (i*i <= n) ==> (i <= Math.sqrt(n)) */
    /* This will print the divisors in pair form / unsorted order */
    if (n % i == 0) {
      /* If divisors are equal, print only one */
      if ((n / i) == i)
        printf("%d ", n / i);
      /* Otherwise print both */
      else
        printf("%d %d ", i, n / i);
    }
  }
  printf("\n");
  /* Time complexity -> O(sqrt(n)) */
}

void print_divisors_of_num_optimal_sorted_order(int n) {

  int i = 1;
  for (; i * i <= n; i++) {
    if (n % i == 0)
      printf("%d ", i);
  }
  for (; i >= 1; i--) {
    if (n % i == 0 && (n / i) != i)
      (printf("%d ", n / i));
  }
  printf("\n");
}

int main() {
  print_divisors_of_num_brute_force(78);
  print_divisors_of_num_optimal(78);
  print_divisors_of_num_optimal_sorted_order(78);
  return 0;
}
