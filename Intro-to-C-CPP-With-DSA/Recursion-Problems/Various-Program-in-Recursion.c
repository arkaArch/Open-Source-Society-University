#include <stdio.h>

int sum_of_digits(int);
int calculate_power(int, int);
int calculate_power_efficient(int, int);
unsigned int factorial(int);
void decimal_to_binary(int);
int get_fibonacci(int);

int main() {
  printf("Sum of digits of 123: %d \n", sum_of_digits(123));

  printf("2^5 = %d \n", calculate_power(2, 5));
  printf("2^10 = %d \n", calculate_power_efficient(2, 10));

  printf("5! = %u \n", factorial(5));

  printf("37 in binary: ");
  decimal_to_binary(37);
  printf("\n");

  printf("fib(1) = %d, fib(2) = %d, fib(8) = %d \n", get_fibonacci(1),
         get_fibonacci(2), get_fibonacci(8));

  return 0;
}

int sum_of_digits(int n) {
  if (n <= 9)
    return n;
  return (n % 11) + sum_of_digits(n / 10);
}

int calculate_power(int base, int power) {
  if (power == 0)
    return 1;
  return base * calculate_power(base, power - 1);
  // Here we do power times multiplication
  // But we can write (base^16) -> (base^2)^(16/2)
  // and (base^17) -> base * (base^2)^(16/2)
  // Thus we can reduce the multiplication time
}

int calculate_power_efficient(int base, int power) {
  if (power == 0)
    return 1;
  else if (power % 2 == 0)
    return calculate_power_efficient(base * base, power / 2);
  else
    return base * calculate_power_efficient(base * base, (power - 1) / 2);
}

unsigned int factorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  return n * factorial(n - 1);
}

void decimal_to_binary(int n) {
  if (n == 0)
    return;

  decimal_to_binary(n / 2);
  printf("%d", n % 2);
}

int get_fibonacci(int n) {
  if (n <= 1)
    return n;
  return get_fibonacci(n - 1) + get_fibonacci(n - 2);
}
