#include <iostream>
using namespace std;

int sqrtInt(int x) {
  if (x <= 1)
    return x;
  int low = 1, high = x, squareRoot;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    // mid * mid == x gives stack overflow error, if mid = INT_MAX
    if (mid <= x / mid) {
      // Maybe it's a square root
      squareRoot = mid;
      // Find if any greater number satisfy the condition
      low = mid + 1;
    } else
      high = mid - 1;
  }
  return squareRoot;
}

double squareRoot(int x, int precision) {
  double factor = 1;
  double sqrt = sqrtInt(x);

  // We have to add 0.1 with the intSqrt and check if it's square <= x
  // Then add 0.01 with the intSqrt and check if it's square <= x
  // This process is going upto precision
  for (int i = 0; i < precision; i++) {
    factor /= 10; // This gives 0.1
    for (double j = sqrt; j * j <= x; j += factor)
      sqrt = j;
  }
  return sqrt;
}

int main() {
  cout << sqrtInt(4) << endl;
  cout << sqrtInt(8) << endl;
  cout << sqrtInt(2147395599) << endl;
  cout << squareRoot(36, 1) << endl;
  cout << squareRoot(37, 3) << endl;
  cout << squareRoot(55, 5) << endl;

  return 0;
}
