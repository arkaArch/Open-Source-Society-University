#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char str[], int first_index, int last_index) {
  if (first_index >= last_index)
    return true;
  return (str[last_index] == str[first_index]) &&
         isPalindrome(str, first_index + 1, last_index - 1);
}

int main() {
  char str_1[] = "abcba";
  char str_2[] = "hello";

  printf("%s \n", isPalindrome(str_1, 0, strlen(str_1) - 1) ? "True" : "False");
  printf("%s \n", isPalindrome(str_2, 0, strlen(str_2) - 1) ? "True" : "False");

  return 0;
}