#include <stdio.h>

int tree_recursion(int n) {
  /* If a function calling itself more than one time it's said tree recursion
  See the next image to understand flow of the program:

  Tracing Tree – There are total 15 function calls here for "tree_recursion(3)"

  So, 1 + 2 + 4 + 8 = 15 calls (G.P – Geometric Progression series)

  We can write the above equation as, 2^0 + 2^1 + 2^2 + 2^3 = 2^(3+1) – 1
  In general form: 2^0 + 2^1+ 2^2 + … + 2^n = 2^(n+1) – 1.
  So, time Complexity of this function is O(2^n).
  Required space(stack is used) is the height of tracing tree, here is 4, i.e
  O(n)
  */
  if (n > 0) {
    printf("%d ", n);
    tree_recursion(n - 1);
    tree_recursion(n - 1);
  }
  return -1;
}

int main() {
  tree_recursion(3); // 3 2 1 1 2 1 1
  printf("\n");
  return 0;
}
