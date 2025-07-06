#include <iostream>
#include <memory> // shared_ptr

// Some User Defined Type
class UDT {
public:
  // Constructor (called on creation)
  UDT() { std::cout << "UDT Created" << std::endl; }
  // Destructor (Called on destruction)
  ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main() {
  {
    // Shared pointer is a smart pointer that freed automatically
    // when the scope is closed. But oppose to unique_ptr we can shared it.
    // It tracks how many things pointing to it, and this is called the
    // reference counter. Java has the reference counting, so you don't have to
    // manage memory manually.

    // Creating shared pointer
    // std::shared_ptr<UDT> ptr1 = std::shared_ptr<UDT>(new UDT);
    // Using factory function, to write the above line
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    {
      // Then, in a new scope, I shared the resource
      std::shared_ptr<UDT> ptr2 = ptr1;
      // Now our reference count is updated
      std::cout << "Use count = " << ptr2.use_count() << std::endl;
    } // Now, 'ptr2' is 'freed'

    // Then we check our updated reference count
    std::cout << "Use count = " << ptr1.use_count() << std::endl;
  }
  std::cout << "We should see the destruction call before this line\n";

  return 0;
}
