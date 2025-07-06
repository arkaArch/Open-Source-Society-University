#include <iostream>
#include <memory> // unique_ptr

// Some User Defined Type
class UDT {
public:
  // Constructor (called on creation)
  UDT() { std::cout << "UDT Created" << std::endl; }
  // Destructor (Called on destruction)
  ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main() {
  // Raw pointers allow sharing. So both pointers referring
  // to the same address.
  // But there is a room for error, which is forgotten to deallocate
  // And there is another problem with ownership
  // Smart pointers adresses this issue
  /*
      int* arr = new int[100];
      for(int i = 0; i < 100; i++)
          arr[i] = i+3;

      int* ptr1 = arr;
      int* ptr2 = ptr1;

      std::cout << "Value stored in prt1: " << *ptr1 << std::endl;
      std::cout << "Value stored in prt2: " << *ptr2 << std::endl;

      delete[] arr;
  */

  // Creating one unique pointer
  // We scoped the below line to see the destruction of this pointer before
  // calling the array
  {
    // std::unique_ptr<UDT> a = std::unique_ptr<UDT>(new UDT);
    // Here we use a factory function which is a function that returns an object
    // of a class.
    std::unique_ptr<UDT> a = std::make_unique<UDT>();
    // We haven't delete it manually, since it automatically delete
    // when the scope{} is ended.
    // We can't share/copy the unique pointer, but we can move
    // std::unique_ptr<UDT> b = a ---> This gives an error
    std::unique_ptr<UDT> b = std::move(a);
  }

  // Create an 'array' that is pointed to, by one unique ptr
  // std::unique_ptr<UDT[]> array = std::unique_ptr<UDT[]>(new UDT[5]);
  // The equivalent, to the line above is:
  std::unique_ptr<UDT[]> array = std::make_unique<UDT[]>(5);

  return 0;
}
