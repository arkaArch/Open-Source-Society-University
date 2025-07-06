#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int number_of_nodes(struct Node *head) {
  if (head == NULL)
    return 0;

  int count = 0;
  struct Node *current = head;
  do {
    count++;
    current = current->link;
  } while (current != head);
  return count;
}

void traverse_list(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct Node *current = head;
  do {
    printf("%d ", current->data);
    current = current->link;
  } while (current != head);
  printf("\n");
}

struct Node *insert_at_begining(struct Node *head, int value) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  if (head == NULL) {
    temp->link = temp;
    return temp;
  }
  /* Give the address of first Node in the link part of temp */
  temp->link = head;

  /* Give the value of temp to the link part of last node */
  struct Node *current = head;
  while (current->link != head)
    current = current->link;
  current->link = temp;
  return temp;
  /* Time complexity: O(N) */
}

struct Node *insert_at_begining_efficient(struct Node *head, int value) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  if (head == NULL) {
    temp->link = temp;
    return temp;
  }
  /* The idea is first add a node after the first node, and swap data part
   * between them */
  temp->link = head->link;
  swap(&head->data, &temp->data);
  head->link = temp;
  /* Here we insert the node after the first node and swap their data,
  so our head remain same */
  return head;
  /* Time complexity: O(1) */
}

struct Node *insert_at_end(struct Node *head, int value) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  if (head == NULL) {
    temp->link = temp;
    return temp;
  }
  temp->link = head;
  /* Go to last Node & replace link path with temp address */
  struct Node *current = head;
  while (current->link != head)
    current = current->link;
  current->link = temp;
  return head;
  /* Here time complexity is O(n) */
}

struct Node *insert_at_end_efficient(struct Node *head, int value) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = value;
  if (head == NULL) {
    temp->link = temp;
    return temp;
  }
  /* Here the idea is to insert the node after first node, and swap their data,
  then pointing head to temp, i.e return temp */
  temp->link = head->link;
  head->link = temp;
  swap(&head->data, &temp->data);
  return temp;
  /* Thus we reduce our Time complexity to O(1) */
}

struct Node *delete_first_node(struct Node *head) {
  if (head == NULL)
    return NULL;
  /* If there is a one element delete this and return NULL */
  if (head->link == head) {
    free(head);
    return NULL;
  }

  struct Node *current = head;
  while (current->link != head)
    current = current->link;
  /* Replace it's link part with address of 2'nd Node(head->link) */
  current->link = head->link;
  free(head);
  return current->link;
  /* Here time complexity is O(n) */
}

struct Node *delete_first_node_efficient(struct Node *head) {
  /* Here the idea is to replace data and link of fist node with second node,
  then delete second node Thus we reduce our Time complexity to O(1) */
  if (head == NULL)
    return NULL;
  /* If there is a one element delete this and return NULL */
  if (head->link == head) {
    free(head);
    return NULL;
  }

  struct Node *temp = head->link;
  head->data = head->link->data;
  head->link = head->link->link;
  free(temp);
  return head;
}

struct Node *delete_k_th_node(struct Node *head, int k) {
  if (head == NULL)
    return NULL;
  if (k < 1 || k > number_of_nodes(head)) {
    printf("Position can't be zero, negative or grater than number of nodes");
    return head;
  }
  if (k == 1) {
    /* Delete first node */
    return delete_first_node_efficient(head);
  }
  struct Node *current = head;
  for (int i = 1; i < k - 1; i++) {
    current = current->link;
  }
  struct Node *temp = current->link;
  current->link = current->link->link;
  free(temp);
  return head;
}

int main() {
  /* Create a list */
  struct Node *first = (struct Node *)malloc(sizeof(struct Node));
  first->data = 10;
  first->link = (struct Node *)malloc(sizeof(struct Node));
  first->link->data = 5;
  first->link->link = (struct Node *)malloc(sizeof(struct Node));
  first->link->link->data = 20;
  first->link->link->link = (struct Node *)malloc(sizeof(struct Node));
  first->link->link->link->data = 15;
  first->link->link->link->link = first;

  int choice, value;

  while (1) {
    printf("1. Display list.\n");
    printf("2. Number of nodes in the list.\n");
    printf("3. Insert at the begining of the list.\n");
    printf("4. Insert at the end of the list.\n");
    printf("5. Delete first node of the list.\n");
    printf("6. Delete K'th node of the list.\n");
    printf("7. Quit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      traverse_list(first);
      break;
    case 2:
      printf("%d\n", number_of_nodes(first));
      break;
    case 3:
      printf("Enter the element to be inserted: ");
      scanf("%d", &value);
      first = insert_at_begining_efficient(first, value);
      break;
    case 4:
      printf("Enter the element to be inserted: ");
      scanf("%d", &value);
      first = insert_at_end_efficient(first, value);
      break;
    case 5:
      first = delete_first_node_efficient(first);
      break;
    case 6:
      printf("Enter the position of the element to be deleted: ");
      scanf("%d", &value);
      first = delete_k_th_node(first, value);
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
