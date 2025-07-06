// Stack -> [L]ast [I]n [First] [O]ut
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int size;
  int top;
  int *arr;
};

void top(struct Stack *st) {
  // the top most element of the stack
  if (st->top == -1) {
    printf("Stack is empty.\n");
    return;
  }
  printf("Top element: %d\n", st->arr[st->top - 1]);
}

void is_empty(struct Stack *st) {
  if (st->top == -1) {
    printf("Stack is empty.\n");
    return;
  }
  printf("Stack is not empty.\n");
}

void is_full(struct Stack *st) {
  if (st->top == st->size - 1) {
    printf("Stack is full.\n");
    return;
  }
  printf("Stack is not full.\n");
}

void push(struct Stack *st) {
  if (st->top == st->size - 1) {
    printf("Stack Overflow.\n");
    return;
  }
  int element;
  printf("Enter the element to be added onto the stack: ");
  scanf("%d", &element);
  st->top += 1;
  st->arr[st->top] = element;
}

void pop(struct Stack *st) {
  if (st->top == -1) {
    printf("Stack Underflow\n");
    return;
  }
  printf("Popped element %d\n", st->arr[st->top]);
  st->top -= 1;
}

void peek(struct Stack *st) {
  int pos;
  printf("Enter the position: ");
  scanf("%d", &pos);
  // Calculate the index of array with respect to position of stack
  int index = st->top - pos + 1;
  if (index < 0) {
    printf("Position is invalid\n");
    return;
  }
  printf("Element at position %d is %d\n", pos, st->arr[index]);
}

int main() {
  struct Stack stack;
  printf("Enter the size of the stack: ");
  scanf("%d", &stack.size);
  stack.arr = (int *)malloc(sizeof(int) * stack.size);
  // Since the stack is empty now so
  stack.top = -1;

  int choice;
  while (1) {
    printf("1. Top element of the stack.\n");
    printf("2. Check if stack is empty.\n");
    printf("3. Check if stack is full.\n");
    printf("4. Append an element to the stack.\n");
    printf("5. Pop out an element from the stack.\n");
    printf("6. Check an element at a certain postion.\n");
    printf("7. Exit.\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      top(&stack);
      break;
    case 2:
      is_empty(&stack);
      break;
    case 3:
      is_full(&stack);
      break;
    case 4:
      push(&stack);
      break;
    case 5:
      pop(&stack);
      break;
    case 6:
      peek(&stack);
      break;
    case 7:
      exit(1);
    default:
      printf("Wrong input. \n");
    }
  }
  return 0;
}