#include <iostream>
#include <queue>
#include <stack>

struct Node {
  int data;
  Node *l_child;
  Node *r_child;
  Node(int data) {
    this->data = data;
    l_child = r_child = nullptr;
  }
};

void preorder(Node *ptr) {
  // if node is not null
  //    Print data, Store address to the stack, go to left child
  // if null
  //    pop out the parent address from stack, go to it's right child
  std::stack<Node *> st;
  while (ptr || !st.empty()) {
    if (ptr) {
      std::cout << ptr->data << " ";
      st.push(ptr);
      ptr = ptr->l_child;
    } else {
      ptr = st.top();
      st.pop();
      ptr = ptr->r_child;
    }
  }
}

void inorder(Node *ptr) {
  // if node is not null
  //    Store address to the stack, go to left child
  // if null
  //    pop out the parent address from stack, print data, go to it's right
  //    child
  std::stack<Node *> st;
  while (ptr || !st.empty()) {
    if (ptr) {
      st.push(ptr);
      ptr = ptr->l_child;
    } else {
      ptr = st.top();
      st.pop();
      std::cout << ptr->data << " ";
      ptr = ptr->r_child;
    }
  }
}

void level_order(Node *ptr) {
  // print root data
  // store the address inside a queue
  // while queue is not empty
  //      take the front address of the queue
  //      prints it's left child data
  //      enqueue the address
  //      do it again for right child
  std::queue<Node *> q;
  std::cout << ptr->data << " ";
  q.push(ptr);
  while (!q.empty()) {
    ptr = q.front();
    q.pop();
    if (ptr->l_child) {
      std::cout << ptr->l_child->data << " ";
      q.push(ptr);
    }
    if (ptr->r_child) {
      std::cout << ptr->r_child->data << " ";
      q.push(ptr);
    }
  }
}