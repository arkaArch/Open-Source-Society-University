#include <stdio.h>

struct Rectangle {
  int length;
  int breadth;
} r1;
// Size of this structure is 8 byte: 4 byte for length and 4 bytes for breadth
// Here we also initialize a varibale r1 of struct type rectangle in here

int main() {
  r1.length = 5;
  r1.breadth = 6;

  struct Rectangle r2 = {10, 15};
  printf("%lu\n", sizeof(r2));
  printf("Area of rectangle r is: %d\n", r2.length * r2.breadth);
  return 0;
}