#include <stdio.h>

/* In Pass by value: the function is called by directly passing the value of the
variable as an argument. So any changes made inside the function do not affect
the original value. Here, parameters passed as arguments create their own copy.
So any changes made inside the function are made to the copied value not to the
original value */

void passByValue(int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
  printf("Inside passByValue function a->%d, b->%d \n", a, b);
}

/* In Pass by Reference, Function is called by directly passing the
reference/address of the variable as an argument. So changing the value inside
the function also change the original value. In Pass by reference, parameters
passed as an arguments does not create its own copy, it refers to the original
value so changes made inside function affect the original value. */

void passbyReferenece(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  printf("Inside passByReference function a->%d, b->%d \n", *a, *b);
}

int main() {
  int a = 10;
  int b = 20;

  printf("Before calling passByValue a->%d, b->%d \n", a, b);
  passByValue(a, b);
  printf("After calling passByValue a->%d, b->%d \n\n", a, b);

  printf("Before calling passByReference a->%d, b->%d \n", a, b);
  passbyReferenece(&a, &b);
  printf("After calling passByReference a->%d, b->%d \n\n", a, b);

  return 0;
}