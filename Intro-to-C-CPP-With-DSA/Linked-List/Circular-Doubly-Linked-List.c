#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

void traverse_list(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct Node *current = head;
  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
}

struct Node *insert_at_begining(struct Node *head, int item) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  if (head == NULL) {
    temp->next = temp;
    temp->prev = temp;
    return temp;
  }
  /* temp->next will contain the address of last node, which is head->prev */
  temp->prev = head->prev;
  /* temp->next contain it's next node address, which is head */
  temp->next = head;
  /* Last Node is head->prev, change last Node->next to temp */
  head->prev->next = temp;
  /* Change first Node->prev to temp */
  head->prev = temp;
  return temp;
}
/* insert_at_end is same as insert_at_begining, just return head instead of temp
 */

int main() {
  struct Node *first = (struct Node *)malloc(sizeof(struct Node));
  first->data = 10;
  struct Node *second = (struct Node *)malloc(sizeof(struct Node));
  second->data = 20;
  struct Node *third = (struct Node *)malloc(sizeof(struct Node));
  third->data = 30;
  struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
  fourth->data = 40;

  first->prev = fourth;
  first->next = second;

  second->prev = first;
  second->next = third;

  third->prev = second;
  third->next = fourth;

  fourth->prev = third;
  fourth->next = first;

  printf("Before Insertion: ");
  traverse_list(first);
  first = insert_at_begining(first, 5);
  printf("After Insertion: ");
  traverse_list(first);

  return 0;
}