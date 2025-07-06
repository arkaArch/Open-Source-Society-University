#include <stdio.h>

/* If a in recursive function the recursive call is the last statement
that is executed by the function it's called tail recursion */
void tail_recursive(int n) {
  if (n > 0) {
    printf("%d ", n);
    tail_recursive(n - 1);
  }
  /* So, function executed at the calling time.
  It's very easy to convert tail recursion into loop
  And since the loop takes just one call stack in memory
  Internally compiler converts it into loop */
}

void tail_recursive_to_loop(int n) {
  while (n > 0) {
    printf("%d ", n);
    n--;
  }
  printf("\n");
}

/* Opposite of this is called head recursion, where first statement is
recursive call, and rest of the statement executed after this.
So, first the recursive functions are called till base condition is mate
then all logic in the function executed at return times. */
void head_recursive(int n) {
  if (n > 0) {
    head_recursive(n - 1);
    printf("%d ", n);
  }
  /* So, function executed at the return time. */
}

void head_recursive_to_loop(int n) {
  int i = 1;
  while (i <= n) {
    printf("%d ", i);
    i++;
  }
  printf("\n");
}

int main() {
  tail_recursive(5);
  printf("\n");
  tail_recursive_to_loop(5);

  head_recursive(5);
  printf("\n");
  head_recursive_to_loop(5);
  return 0;
}