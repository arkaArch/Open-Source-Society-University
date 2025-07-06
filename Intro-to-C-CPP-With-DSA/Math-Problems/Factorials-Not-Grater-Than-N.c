/*
Problem: Factorial Numbers Not Greater Than N.
Your task is to print all the factorial numbers which are less than or equal to
‘n’.

Input: 7
Output: 1 2 6
Since, 1! < 7, 2! < 7 and 3! < 7

Expected time complexity: O(m),
where ‘m’ is the number of factorial numbers which are less than or equal to
‘n’.

*/

#include <stdio.h>

void print_factorial_numbers(int n) {
  int fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
    if (fact <= n) {
      printf("%d ", fact);
      continue;
    }
    break;
  }
  printf("\n");
}

int main() {
  print_factorial_numbers(7);
  return 0;
}
