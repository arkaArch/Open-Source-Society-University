#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

void display_list(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

struct Node *insert_at_begining(struct Node *head, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = head;
  if (head != NULL)
    head->prev = temp;
  return temp;
}

struct Node *insert_at_end(struct Node *head, int data) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  if (head == NULL)
    return temp;
  struct Node *current = head;
  /* Going to last Node */
  while (current->next != NULL)
    current = current->next;
  current->next = temp;
  temp->prev = current;
  return head;
}

struct Node *reverse_list(struct Node *head) {
  /* If we swap next and prev of every node and change head to last
  node address then we can reverse the list */
  if (head == NULL || head->next == NULL)
    return head;

  struct Node *current = head;
  struct Node *temp = NULL;
  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  return temp->prev;
}

struct Node *delete_first_node(struct Node *head) {
  if (head == NULL)
    return NULL;
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  struct Node *temp = head;
  head = head->next;
  head->prev = NULL;
  free(temp);
  return head;
}

struct Node *delete_last_node(struct Node *head) {
  if (head == NULL)
    return NULL;
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  struct Node *current = head;
  while (current->next != NULL)
    current = current->next;
  current->prev->next = NULL;
  free(current);
  return head;
}

int main() {
  /* Creating a Doubly Linked List */
  struct Node *first = (struct Node *)malloc(sizeof(struct Node));
  first->data = 10;
  struct Node *second = (struct Node *)malloc(sizeof(struct Node));
  second->data = 20;
  struct Node *third = (struct Node *)malloc(sizeof(struct Node));
  third->data = 30;
  struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
  fourth->data = 40;

  first->next = second;
  second->prev = first;
  second->next = third;
  third->prev = second;
  third->next = fourth;
  fourth->prev = third;

  int choice, value;
  while (1) {
    printf("1. Display list\n");
    printf("2. Insert at the begining of the list.\n");
    printf("3. Insert at the end of the list.\n");
    printf("4. Reverse the list.\n");
    printf("5. Delete first node.\n");
    printf("6. Delete last node.\n");
    printf("7. Quit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      display_list(first);
      break;
    case 2:
      printf("Enter the element to be inserted: ");
      scanf("%d", &value);
      first = insert_at_begining(first, value);
      break;
    case 3:
      printf("Enter the element to be inserted: ");
      scanf("%d", &value);
      first = insert_at_end(first, value);
      break;
    case 4:
      first = reverse_list(first);
      break;
    case 5:
      first = delete_first_node(first);
      break;
    case 6:
      first = delete_last_node(first);
      break;
    case 7:
      exit(1);
      break;
    default:
      printf("Wrong input\n");
    }
  }
  return 0;
}