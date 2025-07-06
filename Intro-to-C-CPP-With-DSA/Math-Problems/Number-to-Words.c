#include <stdio.h>

int reverse(int num) {
  int reverse_num = 0;
  while (num != 0) {
    int last_digit = num % 10;
    reverse_num = reverse_num * 10 + last_digit;
    num /= 10;
  }
  return reverse_num;
}

int get_digit_count(int num) {
  if (num < 0)
    return -1;
  int count = 0;
  do {
    /* Since zero is to be counted as a digit */
    num /= 10;
    count++;
  } while (num != 0);
  return count;
}

void number_to_words(int num) {
  if (num < 0)
    printf("Invalid Value \n");

  int reverseNum = reverse(num);

  do {
    int lastDigit = reverseNum % 10;
    switch (lastDigit) {
    case 0:
      printf("Zero ");
      break;
    case 1:
      printf("One ");
      break;
    case 2:
      printf("Two ");
      break;
    case 3:
      printf("Three ");
      break;
    case 4:
      printf("Four ");
      break;
    case 5:
      printf("Five ");
      break;
    case 6:
      printf("Six ");
      break;
    case 7:
      printf("Seven ");
      break;
    case 8:
      printf("Eight ");
      break;
    case 9:
      printf("Nine ");
      break;
    }
    reverseNum /= 10;
  } while (reverseNum != 0);

  if (get_digit_count(num) > get_digit_count(reverse(num))) {
    /* At least a zero present. */
    int presenceOfZero = get_digit_count(num) - get_digit_count(reverse(num));
    for (int i = 1; i <= presenceOfZero; i++)
      printf("Zero ");
  }
  printf("\n");
}

int main() {
  number_to_words(674301); // Six Seven Four Three Zero One
  number_to_words(103000); // One Zero Three Zero Zero Zero
  return 0;
}
