#include <iostream>
/* In C++ programming language, literals are fundamental elements used to
 * represent fixed values. These values can include numbers, characters,
 * strings, and more. They are generally present as the right operand in the
 * assignment operation. */
int main() {
  /* All the decimal numbers are considered to be of type int by C++ compiler if
   * not specified. Integer literal might implicitly become a l'ong' if its
   * value exceeds the range of an int. Integer literals can have different
   * bases such as decimal, octal, or hexadecimal. */
  int decimal = 10;
  int octal = 012;
  int hexadecimal = 0xA;
  int binary = 0b1010;
  long int l_int = 10L;
  long long ll_int = 10LL;
  unsigned int u_int = 10U;
  std::cout << decimal << ", " << octal << ", " << hexadecimal << ", " << binary
            << ", " << l_int << ", " << ll_int << ", " << u_int << std::endl;

  /* By default, all the fractional numbers are considered to be of type double
   * by C++ compiler if not specified. */
  float real = 10.98F;
  double d_real = 10.98;
  long double ld_real = 10.98L;
  std::cout << real << ", " << d_real << ", " << ld_real << std::endl;

  // In cpp you have also character literals, string literals, boolean literals
  // and others.
}