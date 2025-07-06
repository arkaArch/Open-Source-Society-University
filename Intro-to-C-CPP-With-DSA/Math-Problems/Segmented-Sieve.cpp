#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// So, if we have to find prime numbers between 10^11 to 10^11 + 10^5.
// So with sieve we have to create 10^11 size array, which is not possible.
// So in Segmented Sieve we create a 10^5 size array, which is pointing those
// numbers between the limit

vector<int> listOfPrimes(int n) {
  vector<int> primeNums;
  vector<bool> prime(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i)
        prime[j] = false;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (prime[i])
      primeNums.push_back(i);
  }
  return primeNums;
}

void printPrimesSegmentedSieve(int lowerLimit, int upperLimit) {
  // Step 1: Generate all primes till sqrt(lowerLimit)
  vector<int> primes = listOfPrimes(sqrt(lowerLimit));
  // Lets say we've to find primes between 110 and 130. So we have to find all
  // primes till 11. primes = [2, 3, 5, 7, 11]

  // Step 2: Create a dummy array of size (upperLimit - lowerLimit + 1)
  // (since we're including both lowerLimit and upperLimit inside range)
  // After creating the array mark every element as true(i.e prime)
  vector<bool> dummy(upperLimit - lowerLimit + 1, true);
  // So we create an array of size 21, and mark all of them as prime

  // Step 3: Mark all multiples of primes in dummy as false
  for (int prime : primes) {
    // Find first multiple of prime(2, 3, 5, 7, ... , sqrt(n)) inside the range
    int firstMultiple = (lowerLimit / prime) * prime;
    // first multiple of 2 is (110/2)*2 = 110, 3 -> (110/3)*3 = 36*3 = 108 < 110
    // -> 108+3 = 111
    if (firstMultiple < lowerLimit)
      firstMultiple += prime;

    for (long long j = max(firstMultiple, prime * prime); j <= upperLimit;
         j += prime)
      // Since first multiple of 11 is (110/11)*11 = 110 but we start from
      // 121.(Same as sieve)
      dummy[j - lowerLimit] = 0;
    // 110-110 = 0, 111-110 = 1, 112-110 = 2, thus the mapping is go on.
  }

  // Print primes
  for (int i = lowerLimit; i <= upperLimit; i++) {
    if (dummy[i - lowerLimit])
      // Same as above mapping
      cout << i << " ";
  }
}

int main() {
  cout << "Prime numbers between 700 and 800 are: ";
  printPrimesSegmentedSieve(700, 800);
  cout << endl;
  return 0;
}
