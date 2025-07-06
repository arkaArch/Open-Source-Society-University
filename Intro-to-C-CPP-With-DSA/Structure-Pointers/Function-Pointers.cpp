#include <functional>
#include <iostream>
// We can typedef function pointer like
typedef int (*PFnIntegerOperation)(int, int);

int add(int x, int y) { return x + y; }

int multiply(int x, int y) { return x * y; }

int main() {
  int x, y;
  std::cout << "Enter two integers: ";
  std::cin >> x >> y;

  // Function pointer
  // int (*operation)(int, int);
  // PFnIntegerOperation operation;
  std::function<int(int, int)> operation;

  char op;
  std::cout << "Enter a for add and m for multiplication: ";
  std::cin >> op;

  if (op == 'a')
    operation = add;
  else if (op == 'm')
    operation = multiply;
  else
    std::cout << "Wrong Input." << std::endl;

  std::cout << "Result: " << operation(x, y) << std::endl;

  return 0;
}

// Function pointers are very useful in graphics programming
// When we add a button and after click it we call a function(callback)
