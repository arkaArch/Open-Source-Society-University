#include <stdio.h>

double taylor_series_e(int x, int n) {
  // Taylor series: e^x = 1 + x/1 + x^2/2! + x^3/3! + x^4/4! + ...
  static double pow = 1, fact = 1;
  double r;
  if (n == 0)
    return 1;
  else {
    // head_recursion, so all logic performs after all
    // recursive function call(after base condition is mate)
    r = taylor_series_e(x, n - 1);
    pow *= x;
    fact *= n;
    return r + pow / fact;
  }
  // Now here 1 + x/1 + x^2/2! + x^3/3! + x^4/4! + ...
  // = 1 + x/1 + x*x/2*1 + x*x*x/3*2*1 + x*x*x*x/4*3*2*1 + ....
  // that is (2+2) + (3+3) + (4+4) + .... + (n+n), 2 * n(n+1) / 2
  // i.e, n^2 + 1, multiplications. so time complexity is O(n^2)
}

double taylor_series_e_honer_rule(int x, int n) {
  // e^x = 1 + x/1 + x^2/2! + x^3/3! + x^4/4! + ...
  // = 1 + x/1 + x*x/2*1 + x*x*x/3*2*1 + x*x*x*x/4*3*2*1 + ....
  // = 1 + x/1 [1 + x/2 + x*x/3*2 + x*x*x/4*3*2 + ...]
  // = 1 + x/1 [1 + x/2 [1 + x/3 + x*x/4*3 + ...]]
  // = 1 + x/1 [1 + x/2 [1 + x/3 [1 + x/4 + ...]]]
  // Thus we can reduce the multiplication by n, & thus time complexity become
  // O(n)
  static double r = 1;
  if (n == 0)
    return r;
  else {
    // r = (1 + x/n) * r
    // Here (x/n) returns int value, since both is integer and then multiplied
    // by 2
    r = (1 + x * r / n);
    return taylor_series_e_honer_rule(x, n - 1);
  }
}

int main() {
  printf("e = %lf", taylor_series_e(1, 10));
  printf("\n");

  printf("e = %lf", taylor_series_e_honer_rule(1, 10));
  printf("\n");

  return 0;
}
