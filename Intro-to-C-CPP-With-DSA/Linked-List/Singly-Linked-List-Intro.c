#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

int main() {
  struct Node *head = NULL;
  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = 45;
  head->link = NULL;

  /* Creating second node */
  struct Node *current = NULL;
  current = (struct Node *)malloc(sizeof(struct Node));
  current->data = 56;
  current->link = NULL;
  /* Link this node with first one */
  head->link = current;

  /* Creating third node */
  current = (struct Node *)malloc(sizeof(struct Node));
  current->data = 68;
  current->link = NULL;
  /* Link this node with second one */
  head->link->link = current;

  return 0;
}
