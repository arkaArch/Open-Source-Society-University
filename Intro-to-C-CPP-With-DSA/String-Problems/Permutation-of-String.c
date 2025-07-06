#include <stdio.h>
#include <string.h>

void permutation_string(char *str, int k) {
  static int flag[20] = {0};
  static char result[20];
  // "i" for flag index and 'k' for result index
  if (str[k] == '\0') {
    result[k] = '\0';
    printf("%s\n", result);
  }

  for (int i = 0; str[i] != '\0'; i++) {
    if (flag[i] == 0) {
      result[k] = str[i];
      flag[i] = 1;
      permutation_string(str, k + 1);
      // Return time make flag[i] 0 again
      flag[i] = 0; // Backtrack
    }
  }
}

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

// To decrease auxiliary space we can rewrite this using swap
void permutation_string_opt(char *str, int low, int high) {
  if (high == low)
    printf("%s\n", str);
  else {
    for (int i = low; i <= high; i++) {
      // Swap i and low
      if (str[i] != str[low])
        swap(&str[i], &str[low]);
      permutation_string_opt(str, low + 1, high);
      // Swap as its previous position
      swap(&str[i], &str[low]); // Backtrack
    }
  }
}

int main() {
  char str[50];
  printf("Enter a string: ");
  scanf("%s", str);
  permutation_string_opt(str, 0, strlen(str) - 1);
  return 0;
}