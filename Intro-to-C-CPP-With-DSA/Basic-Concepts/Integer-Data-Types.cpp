#include <climits>
#include <iostream>

int main() {
  std::cout << "Integer takes " << sizeof(int) << " bytes of memory.\n";
  std::cout << "Integer takes " << sizeof(uint) << " bytes of memory.\n";

  std::cout << "Maximum Value of integer: " << INT_MAX << std::endl;
  std::cout << "Minimum Value of integer: " << INT_MIN << std::endl;
  std::cout << "Maximum Value of unsigned integer: " << UINT_MAX << std::endl;
  std::cout << "Minimum Value of unsigned integer is 0\n";

  /* Take an example with 4 bits:
   * Minimum number in 4 bits: 0000 = 0
   * maximum number: 1111 = 15 = 2^4 - 1
   * Since unsigned integer takes 4 bytes, i.e 32 bits so max number of
   * unsigned integer = 4294967295
   * For signed integers min number = (4294967295 - 1) / 2 = -2147483647 = 2^(32
   * - 1) - 1 And max number = (4294967295 - 1) / 2 + 1 = 2147483648 = 2^(32 -
   * 1) */

  // Now let's understand overflow and underflow:
  /* From upper example we know that max number of in 4 bits is 15,
   * Now lets try to fit 16 inside 4 bits. 16 => 10000, so it takes
   * five bits, so if we try to fit it in 4 bits left most bit / Most
   * significant bit is cancelled out, so our number becomes 0000 in binary,
   * i.e 0 in decimal, same happens if we try to fit UINT_MAX + 1 in 32 bits
   * The number becomes zero. And this is called 'overflow'.
   * For signed integer INT_MAX + 1 becomes INT_MIN */
  std::cout << "Overflow => UINT_MAX + 1 = " << UINT_MAX + 1 << std::endl;

  // You get the overflow warning during compilation time
  std::cout << "Overflow => INT_MAX + 1 = " << INT_MAX + 1 << std::endl;
  std::cout << "Overflow => INT_MAX + 1 = " << INT_MIN - 1
            << std::endl; // Underflow

  return 0;
}