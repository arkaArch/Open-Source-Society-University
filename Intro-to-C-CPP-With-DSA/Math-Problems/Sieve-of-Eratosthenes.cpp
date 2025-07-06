#include <iostream>
#include <vector>
using namespace std;

// Simple sieve of eratosthenes:
void printPrimes(int n) {
  /* Create a boolean array "prime[0..n]" and initialize
   * all entries in it as true. i.e mark all number as prime. */
  vector<bool> prime(n + 1, true);
  prime[0] = prime[1] = false;

  for (int i = 2; i <= n; i++) {
    // Check if current number is prime
    if (prime[i]) {
      // Now check all numbers which is divisible by the number
      // and mark them as false.
      for (int j = i * 2; j <= n; j += i)
        prime[j] = false;
    }
  }

  // Print the prime numbers
  for (int i = 2; i <= n; i++) {
    if (prime[i])
      cout << i << " ";
  }
  cout << endl;
}

// The number of prime numbers that are strictly less than n
// Optimized code
int countPrimes(int n) {
  if (n == 0)
    return false;
  vector<bool> prime(n, true);
  prime[0] = prime[1] = false;

  // We can see the second loop and there lets say n = 30,
  // so do I need to start from 6*6 ? Of course not since 36 < n and
  // it doesn't mark anything, So we can go to root of n instead of n
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      // We generally start the loop from 2*i and go to n, like
      // for 2 -> 2*2, 2*3, 2*4, 2*5, 2*6...
      // for 3 -> 3*2, 3*3, 3*4, 3*5, 3*6... but 3*2 already marked by 2 (2*3)
      // for 5 -> 5*2, 5*3, 5*4, 5*5, 5*6... but 5*2 already marked by 2 and 3
      // (2*5, 3*5) So it's ideal to start with i*i
      for (long long j = i * i; j < n; j += i)
        prime[j] = false;
    }
  }

  // Count the prime numbers
  int count = 0;
  for (bool number : prime) {
    if (number)
      count++;
  }
  return count;
}

int main() {
  cout << "Prime numbers upto 40 are: ";
  printPrimes(40);
  cout << "Number of prime < 5000000: " << countPrimes(5000000) << endl;
  return 0;
}
