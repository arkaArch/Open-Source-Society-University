#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  int size;
  int top;
  char *arr;
};

bool is_empty(struct Stack *st) {
  if (st->top == -1)
    return true;
  return false;
}

void push(struct Stack *st, char element) {
  if (st->top == st->size - 1) {
    printf("Stack Overflow.\n");
    return;
  }
  st->top += 1;
  st->arr[st->top] = element;
}

char pop(struct Stack *st) {
  if (st->top == -1)
    return -1;
  char x = st->arr[st->top];
  st->top -= 1;
  return x;
}
// ========== END OF MAKING STACK DATA STRUCTURE ============ //

bool is_paranthesis_balanced(char *exp) {
  struct Stack st;
  // Let the whole expression has parenthesis
  st.size = strlen(exp);
  st.top = -1;
  // Create the stack
  st.arr = (char *)malloc(sizeof(char) * st.size);

  for (int i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(')
      push(&st, exp[i]);
    else if (exp[i] == ')') {
      // First check while the stack is empty
      // for this type of condition: ((a + b)))
      if (is_empty(&st))
        return false;
      pop(&st);
    }
  }
  // Now check if some element left in stack or not
  // for this type of condition: (((a + b))
  return is_empty(&st) ? true : false;
}

int main() {
  char *expression1 = "((a + b) * (c + d))";
  printf("%s\n",
         is_paranthesis_balanced(expression1) ? "True" : "False"); // True

  char *expression2 = "(((a + b) * (c + d))";
  printf("%s\n",
         is_paranthesis_balanced(expression2) ? "True" : "False"); // False

  char *expression3 = "((a + b) * (c + d)))";
  printf("%s\n",
         is_paranthesis_balanced(expression3) ? "True" : "False"); // False

  return 0;
}