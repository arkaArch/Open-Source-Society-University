#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

/* Number of nodes */
void number_of_nodes(struct Node *head) {
  int count = 0;
  struct Node *p;
  p = head;
  while (p != NULL) {
    count++;
    p = p->link;
  }
  printf("Number of node in the list is: %d \n", count);
}

/* Traverse linked list */
void display_list(struct Node *head) {
  struct Node *p;
  if (head == NULL) {
    printf("List is empty \n");
    return;
  }

  p = head;
  printf("List is: ");
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->link;
  }
  printf("\n\n");
}

/* Search an item in the list */
void search(struct Node *head, int item) {
  int position = 1;
  struct Node *p;
  p = head;
  while (p != NULL) {
    if (p->data == item) {
      printf("%d found at position %d. \n", item, position);
      return;
    }
    position++;
    p = p->link;
  }
  printf("%d is not found in the list. \n", item);
}

/* Insertion a Node at the begining of the list */
struct Node *add_node_at_begining(struct Node *head, int value) {
  struct Node *temp;
  /* Create an empty Node first */
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  temp->link = head;
  head = temp;
  return head;
}

/* Insertion a Node at the end of the list */
struct Node *add_node_at_last(struct Node *head, int value) {
  struct Node *temp, *current;
  /* Create an empty Node first */
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  /* Find the address of the last Node */
  current = head;
  while (current->link != NULL)
    current = current->link;
  current->link = temp;
  temp->link = NULL;
  return head;
}

/* Insertion a Node after a Node of the list */
struct Node *add_node_after_a_node(struct Node *head, int target, int value) {
  struct Node *temp, *current;
  /* Find the address of the target Node */
  current = head;
  while (current != NULL) {
    if (current->data == target) {
      temp = (struct Node *)malloc(sizeof(struct Node));
      /* Insert the Node after it */
      temp->data = value;
      temp->link = current->link;
      current->link = temp;
      return head;
    }
    current = current->link;
  }
  printf("%d is not present in the list\n", target);
  return head;
}

/* Insertion a Node before a Node of the list */
struct Node *add_node_before_a_node(struct Node *head, int target, int value) {
  if (head == NULL) {
    printf("List is empty \n");
    return head;
  }
  /* If traget is the first node */
  if (head->data == target) {
    head = add_node_at_begining(head, value);
    return head;
  }
  struct Node *temp, *current;
  temp = (struct Node *)malloc(sizeof(struct Node));
  /* Find the address of the target Node */
  current = head;
  while (current->link != NULL) {
    if (current->link->data == target) {
      temp->data = value;
      temp->link = current->link;
      current->link = temp;
      return head;
    }
    current = current->link;
  }
  printf("%d is not present in the list\n", target);
  return head;
}

/* Insertion at a given position */
struct Node *add_at_position(struct Node *head, int value, int position) {
  /* position 1 -> before first node, position = 2 --> before 2nd node,
  position 3 -> before 3rd node ...etc */
  struct Node *temp, *current;
  current = head;
  /* Let's say, we want to insert a node at 3rd position, so to change 2nd Node
  link part, we have to go current upto 1st position, then current->link = 2nd
  node link, thats why i < position - 1 */
  for (int i = 1; i < position - 1 && current != NULL; i++)
    current = current->link;
  if (current == NULL)
    printf("There are less than %d elements.\n", position);
  else {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    if (position == 1) {
      /* psoition = 1 means add node first of the list */
      temp->link = head;
      head = temp;
    } else {
      temp->link = current->link;
      current->link = temp;
    }
  }
  return head;
}

struct Node *create_list(struct Node *head) {
  int number_of_nodes;
  printf("Enter the number of nodes: ");
  scanf("%d", &number_of_nodes);
  head = NULL;
  if (number_of_nodes == 0)
    return head;

  int value;
  printf("Enter the element to be inserted: ");
  scanf("%d", &value);
  head = add_node_at_begining(head, value);

  for (int i = 2; i <= number_of_nodes; i++) {
    printf("Enter the element to be inserted: ");
    scanf("%d", &value);
    head = add_node_at_last(head, value);
  }
  return head;
}

struct Node *delete_a_node(struct Node *head, int value) {
  if (head == NULL) {
    printf("List is empty \n");
    return head;
  }

  /* Deletion of first node */
  struct Node *temp;
  if (head->data == value) {
    temp = head;
    head = head->link;
    free(temp);
    return head;
  }

  /* Deletion in between or at the end */
  struct Node *current;
  current = head;
  while (current->link != NULL) {
    if (current->link->data == value) {
      temp = current->link;
      current->link = temp->link;
      free(temp);
      return head;
    }
    current = current->link;
  }
  printf("Element %d is not found in the list.", value);
  return head;
}

struct Node *revese_list(struct Node *head) {
  struct Node *prev, *next, *current;
  prev = NULL;
  current = head;
  while (current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}

int main() {
  struct Node *head = NULL;
  int choice, item, target, position;
  while (1) {
    printf("1. Create List. \n");
    printf("2. Display List. \n");
    printf("3. Show number of nodes. \n");
    printf("4. Search an item in List. \n");
    printf("5. Add to empty list / Add at begining of the node. \n");
    printf("6. Add a node at the end of the list. \n");
    printf("7. Add a node after a node. \n");
    printf("8. Add a node before a node. \n");
    printf("9. Add a node at a certain position. \n");
    printf("10. Delete a node. \n");
    printf("11. Reverse the list. \n");
    printf("12. Quit. \n\n");

    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      head = create_list(head);
      break;
    case 2:
      display_list(head);
      break;
    case 3:
      number_of_nodes(head);
      break;
    case 4:
      printf("Enter the element you want to search: ");
      scanf("%d", &item);
      search(head, item);
      break;
    case 5:
      printf("Enter the element you want to insert: ");
      scanf("%d", &item);
      head = add_node_at_begining(head, item);
      break;
    case 6:
      printf("Enter the element you want to insert: ");
      scanf("%d", &item);
      head = add_node_at_last(head, item);
      break;
    case 7:
      printf("Enter the element you want to insert: ");
      scanf("%d", &item);
      printf("Enter the element after which to insert: ");
      scanf("%d", &target);
      head = add_node_after_a_node(head, target, item);
      break;
    case 8:
      printf("Enter the element you want to insert: ");
      scanf("%d", &item);
      printf("Enter the element before which to insert: ");
      scanf("%d", &target);
      head = add_node_before_a_node(head, target, item);
      break;
    case 9:
      printf("Enter the element you want to insert: ");
      scanf("%d", &item);
      printf("Enter the postion at which to insert: ");
      scanf("%d", &position);
      head = add_at_position(head, item, position);
      break;
    case 10:
      printf("Enter the element to be deleted: ");
      scanf("%d", &item);
      head = delete_a_node(head, item);
      break;
    case 11:
      head = revese_list(head);
      break;
    case 12:
      exit(1);
      break;
    default:
      printf("Wrong choice. \n");
    }
  }
  return 0;
}
