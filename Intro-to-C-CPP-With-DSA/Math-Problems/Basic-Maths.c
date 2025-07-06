#include <stdbool.h>
#include <stdio.h>

bool is_adult(int age) { return age > 18 ? true : false; }

void find_character_case(char ch) {
  (ch >= 65 && ch <= 90)    ? printf("Upper case\n")
  : (ch >= 97 && ch <= 122) ? printf("Lower case\n")
                            : printf("Not a character\n");
}

void sum_of_even_odd(int n) {
  int oddSum = 0, evenSum = 0;
  while (n != 0) {
    int lastDigit = n % 10;
    if (lastDigit % 2 == 0)
      evenSum += lastDigit;
    else
      oddSum += lastDigit;
    // Remove the last digit
    n /= 10;
  }
  printf("Sum of even digits: %d \n", evenSum);
  printf("Sum of odd digits: %d \n", oddSum);
}

int no_of_divisors_present_in_digit(int n) {
  int n_copy = n;
  int count = 0;
  while (n != 0) {
    int last_digit = n % 10;
    if ((last_digit != 0) && (n_copy % last_digit == 0))
      count++;
    n /= 10;
  }
  return count;
}

bool is_palindrome(int n) {
  int reverse_num = 0, n_copy = n;
  while (n != 0) {
    int last_dig = n % 10;
    reverse_num = reverse_num * 10 + last_dig;
    n /= 10;
  }
  if (reverse_num == n_copy)
    return true;
  return false;
}

int main() {
  is_adult(19);              // True
  find_character_case('H');  // Upper Case
  sum_of_even_odd(53712891); //  Sum of even: 10, sum of odd: 26
  printf("%d \n",
         no_of_divisors_present_in_digit(65)); // 1 {5, 13} & 5 is present in 65
  printf("%d \n", is_palindrome(47874));       // 1
  return 0;
}