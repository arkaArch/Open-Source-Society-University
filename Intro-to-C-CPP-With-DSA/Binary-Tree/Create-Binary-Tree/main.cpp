#include <iostream>
#include <queue>

struct Node {
  int data;
  Node *l_child;
  Node *r_child;
  Node(int data) {
    this->data = data;
    l_child = nullptr;
    r_child = nullptr;
  }
};

Node *root = nullptr;

void create_binary_tree() {
  std::queue<Node *> q;

  // Create a root node
  int value;
  std::cout << "Enter the value of root node: ";
  std::cin >> value;
  root = new Node(value);

  // Store the root address inside queue
  q.push(root);

  Node *p_parent, *p_child;
  // Now dequeue the adress and asks for left and right child
  while (!q.empty()) {
    p_parent = q.front();
    q.pop();

    // Create left child
    std::cout << "Enter value of left child of " << p_parent->data
              << " (if not present enter -1): ";
    std::cin >> value;
    if (value != -1) {
      p_child = new Node(value);
      // Link child with parent
      p_parent->l_child = p_child;
      q.push(p_child);
    }

    // Create right child
    std::cout << "Enter value of right child of " << p_parent->data
              << " (if not present enter -1): ";
    std::cin >> value;
    if (value != -1) {
      p_child = new Node(value);
      // Link child with parent
      p_parent->r_child = p_child;
      q.push(p_child);
    }
  }
}

void inorder_printing(Node *ptr) {
  if (ptr) {
    inorder_printing(ptr->l_child);
    std::cout << ptr->data << " ";
    inorder_printing(ptr->r_child);
  }
}

int main() {
  create_binary_tree();
  inorder_printing(root);
  std::cout << std::endl;
  return 0;
}
