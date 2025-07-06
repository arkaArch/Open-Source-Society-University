/*
Input: 5
Output: 21

We need to find the sum of ‘sum_of_divisors(i)’ for all ‘i’ from 1 to 5.
‘sum_of_divisors(1)’ = 1
‘sum_of_divisors(2)’ = 2 + 1 = 3
‘sum_of_divisors(3)’ = 3 + 1 = 4
‘sum_of_divisors(4)’ = 4 + 2 + 1 = 7
‘sum_of_divisors(5)’ = 5 + 1 = 6
Therefore our answer is:
sumOfDivisors(1) + sumOfDivisors(2) + sumOfDivisors(3) + sumOfDivisors(4) +
sumOfDivisors(5) = 1 + 3 + 4 + 7 + 6 = 21.

Solve this in O(sqrt(n)).
*/
#include <stdio.h>

int sum_of_all_divisors(int n) {
  int sum_of_all_divisors_val = 0;
  for (int k = 1; k <= n; k++) {
    /* For single number  */
    int sum_of_divisors = 0;
    for (int i = 1; i * i <= k; i++) {
      if (k % i == 0) {
        sum_of_divisors += i;
        if (k / i != i)
          sum_of_divisors += k / i;
      }
    }
    sum_of_all_divisors_val += sum_of_divisors;
  }
  return sum_of_all_divisors_val;
}

int main() {
  printf("%d \n", sum_of_all_divisors(5));
  return 0;
}
