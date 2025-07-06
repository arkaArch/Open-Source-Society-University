#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_of_string(char *str) {
  int i = 0;
  for (; str[i] != '\0'; i++)
    ;
  return i;
}

char *to_lower_case(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 65 && str[i] <= 90)
      str[i] = str[i] + 32;
  }
  return str;
}

char *to_upper_case(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 97 && str[i] <= 122)
      str[i] = str[i] - 32;
  }
  return str;
}

void no_of_vowels_and_consonant(char *str) {
  // Change it to lower case
  str = to_lower_case(str);
  int vowels = 0, consonant = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    // The letter must be a character
    if (str[i] >= 'a' && str[i] <= 'z') {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
          str[i] == 'u')
        vowels++;
      else
        consonant++;
    }
  }
  printf("No of vowels: %d and no of consonant: %d \n", vowels, consonant);
}

char *reverse_string(char *str) {
  int i = 0, j = strlen(str) - 1; // We take inputs as fgets()
  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
  return str;
}

int main() {
  char str[50];
  printf("Enter a string: ");
  // 'scanf("%s", str)' can't take input with space
  // *** fgets() will have the new line as the last character
  // *** if less than 50 characters were on the line
  fgets(str, 50, stdin);

  no_of_vowels_and_consonant(str);

  int choice;
  while (1) {
    printf("1. Length of the string\n");
    printf("2. Change to lower case\n");
    printf("3. Change to upper case\n");
    printf("4. Count vowels and consonant\n");
    printf("5. Reverse the string\n");
    printf("9. Quit program\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      // printf("Length of the string is %d\n", strlen(str) - 1);
      printf("Length of the string is %d \n", length_of_string(str) - 1);
      break;
    case 2:
      printf("Your sentence in lower case: %s", to_lower_case(str));
      break;
    case 3:
      printf("Your sentence in upper case: %s", to_upper_case(str));
      break;
    case 4:
      no_of_vowels_and_consonant(str);
      break;
    case 5:
      printf("%s", reverse_string(str));
      break;
    case 9:
      exit(1);
    default:
      printf("Wrong input.\n");
    }
  }
  return 0;
}