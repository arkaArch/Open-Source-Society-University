#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)

void pattern_1(int n) {
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < n; i++)
      printf("#");
    printf("\n");
  }
}

void pattern_2(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++)
      printf("*");
    printf("\n");
  }
}

void pattern_3(int n) {
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= i; j += 1)
      printf("%d", j);
    printf("\n");
  }
}

void pattern_4(int n) {
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= i; j += 1)
      printf("%d", i);
    printf("\n");
  }
}

void pattern_5(int n) {
  for (int i = n; i > 0; i -= 1) {
    for (int j = 0; j < i; j += 1)
      printf("#");
    printf("\n");
  }
}

void pattern_6(int n) {
  for (int i = n; i >= 1; i -= 1) {
    for (int j = 1; j <= i; j += 1)
      printf("%d", j);
    printf("\n");
  }
}

void pattern_7(int n) {
  // First print upper half
  for (int i = 1; i <= n; i++) {
    /* For first row we print 4 spaces 1 star
    For second row we print 3 spaces 3 star
    For third row we print 2 spaces 5 star

    Therefore, Number of spaces = (number - i)
    Number of star = (2*i - 1) */

    // printing spaces
    for (int j = 1; j <= (n - i); j++)
      printf(" ");
    // printing starts
    for (int j = 1; j <= (2 * i - 1); j++)
      printf("*");
    // End line after each row
    printf("\n");
  }

  // Then print lower half
  for (int i = n; i >= 1; i--) {
    // printing spaces
    for (int j = 1; j <= (n - i); j++)
      printf(" ");
    // printing starts
    for (int j = 1; j <= (2 * i - 1); j++)
      printf("*");
    // End line after each row
    printf("\n");
  }
}

void pattern_8(int n) {
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= i; j += 1) {
      if ((i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0))
        printf("0 ");
      else
        printf("1 ");
    }
    printf("\n");
  }
}

void pattern_9(int n) {
  for (int i = 1; i <= n; i += 1) {
    for (int j = 1; j <= i; j += 1)
      printf("%d", j);

    // printing space
    for (int j = 1; j <= (n - i) * 2; j += 1)
      printf(" ");

    for (int j = i; j >= 1; j -= 1)
      printf("%d", j);
    printf("\n");
  }
}

void pattern_10(int n) {
  for (int i = 1; i <= n; i += 1) {
    // Printing spaces
    for (int j = n - i; j >= 1; j -= 1)
      printf(" ");

    int ch = 'A';
    for (int j = 1; j <= 2 * i - 1; j += 1)
      (j < i) ? printf("%c", ch++) : printf("%c", ch--);
    printf("\n");
  }
}

void pattern_11(int n) {
  for (int i = 1; i <= n; i += 1) {
    for (int j = 'A' + (n - i); j <= 'A' + (n - 1); j += 1)
      printf("%c ", j);
    printf("\n");
  }
}

void pattern_12(int n) {
  for (int i = 1; i <= n * 2; i += 1) {
    for (int j = 1; j <= n * 2; j += 1) {
      if ((i <= n) && (j >= n - i + 2 && j <= n + i - 1))
        printf(" ");
      else if ((i > n) && (j >= i - n + 1 && j <= 2 * n - i + n))
        printf(" ");
      else
        printf("*");
    }
    printf("\n");
  }
}

void pattern_13(int n) {
  for (int i = 1; i <= 2 * n - 1; i += 1) {
    for (int j = 1; j <= 2 * n; j += 1) {
      if ((i <= n) && (j > i && j <= 2 * n - i))
        printf(" ");
      else if ((i > n) && (j > 2 * n - i && j <= i))
        printf(" ");
      else
        printf("*");
    }
    printf("\n");
  }
}

void pattern_14(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 || i == n || j == 1 || j == n)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
}

void pattern_15(int n) {
  for (int i = 1; i < 2 * n; i++) {
    for (int j = 1; j < n * 2; j++) {
      /* We print --> element - (minimum distence of element
      from top, left, right, bottom) */
      int topDist = i - 1;
      int leftDist = j - 1;
      int rightDist = 2 * n - 1 - j;
      int bottomDist = 2 * n - 1 - i;

      printf("%d ",
             n - MIN(MIN(topDist, bottomDist), MIN(leftDist, rightDist)));
    }
    printf("\n");
  }
}

int main() {
  // Butterflies are always beautiful
  pattern_13(5);
  return 0;
}