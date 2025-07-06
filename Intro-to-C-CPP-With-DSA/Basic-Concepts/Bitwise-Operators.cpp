#include <iostream>

int main() {
  std::cout << "10 | 6 = " << (10 | 6)
            << std::endl; // OR: 1010 | 0110 = 1110 = 14
  std::cout << "10 & 6 = " << (10 & 6)
            << std::endl; // AND: 1010 & 0110 = 0010 = 2
  int x = 10,
      y = 6; // In statement (10 ^ 6) gcc will complain that it may be "1e6"
  std::cout << "10 ^ 6 = " << (x ^ y)
            << std::endl; // XOR(Exclusive Or): 1010 ^ 0110 = 1100 = 12

  std::cout
      << "10 << 1 = " << (10 << 1)
      << std::endl; // Left Shift by one: 1010 << 1 = 10100 = 20 = 10 * 2^1
  std::cout
      << "10 << 2 = " << (10 << 2)
      << std::endl; // Left Shift by two: 1010 << 2 = 101000 = 40 = 10 * 2^2
  // So if we left shift n by k it's become: n * 2^k
  std::cout
      << "20 >> 1 = " << (20 >> 1)
      << std::endl; // Right Shift by one: 10100 >> 1 = 1010 = 10 = 20 / 2^1
  std::cout << "20 >> 2 = " << (20 >> 2)
            << std::endl; // Right Shift by two: 10100 >> 2 = 101 = 5 = 20 / 2^2
  // So if we right shift n by k it's become: n / 2^k

  /* Now we know that 10 can be represented in binary(8 bits) like: 00001010
   * And -10 is represented by 2's complement: 11110110
   * Now if we right shift this by one(-10 >> 1) it becomes: 11101100
   * So we can see that MSB remain unchanged and this becomes -5
   *
   * Now if we operate unsigned right shift operation, the MSB become 0 after
   * shifting and thus -10 >>> 1 becomes 01101100 in 8 bits.
   * And it 32 its it becomes 01111111111111111111111111111011 = 2147483643 */

  /* ~10 = !(00001010) = 11110101, since MSB is 1, this is a negative value.
   * So by taking 2's complement we can say that the number is -[(1010) + 1] =
   * -(1011) = -11 */

  std::cout << "!10 = " << (~10) << std::endl;
  std::cout << "!14 = " << (~14) << std::endl;
  std::cout << "!(-15) = " << (~(-15)) << std::endl;
  // So, (~x) = -(x + 1)

  return 0;
};