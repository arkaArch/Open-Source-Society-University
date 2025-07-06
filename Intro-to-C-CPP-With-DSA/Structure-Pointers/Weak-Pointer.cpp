#include <iostream>
#include <memory>

class UDT {
public:
  UDT() { std::cout << "UDT Created" << std::endl; }
  ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main() {

  /*
      int* ptr1 = new int[5];
      for(int i = 0; i < 5; i++)
          ptr1[i] = i*2;
      int *ptr2 = ptr1;
      delete[] ptr1;

      // Now ptr2 become dangling pointer and it returns some garbage value.
      std::cout << "Value of ptr2[2]: " << ptr2[2] << std::endl;
  */

  // Now here comes weak_ptr, it's a non-owning pointer unlike unique_pointer
  // And it doesn't increase the reference count unlike shared pointer.

  std::weak_ptr<UDT> ptr2;
  {
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    {
      // Then, in a new scope, I shared the resource with weak_ptr
      ptr2 = ptr1;
      // Now our reference count is not updated
      std::cout << "Use count = " << ptr2.use_count() << std::endl;
    } // Now, 'ptr2' is 'freed'
    // Now I can check the weak_pointer destroyed or not, and the object which
    // ptr2 pointed is not destructed yet. So the answer must be false(0).
    std::cout << "Is ptr2(object that it points to) freed: " << ptr2.expired()
              << std::endl;

    // Then we check our updated reference count
    std::cout << "Use count = " << ptr1.use_count() << std::endl;
  }
  // Here the weak_pointer(the object which ptr2 pointed) is destroyed, so it
  // must return true(1).
  std::cout << "Is ptr2(object that it points to) freed: " << ptr2.expired()
            << std::endl;
  std::cout << "We should see the destruction call before this line\n";

  return 0;
}
