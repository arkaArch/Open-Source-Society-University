#include <iostream>
#include <memory>

// We can create a seperate file where class members are declared like
// Rectangle.hpp
class Rectangle {
  // Data members
  // By default class members are private
  // They are hidden 'fields' or 'attributes'
private:
  int length;
  int breadth;

  // Member functions
public:
  // Constructor: Called when an object is created
  // constructor will not have any return type but
  // it may or may not take parameters
  // Default constructor
  Rectangle();

  // Parameterized constructor
  // Constructor overloading
  Rectangle(int l, int b);
  // I'll be defining it outside, using scope resolution operator
  // So this is just a prototype or a signature/header of a function.

  // These two functions perform some operations on data members of an object
  // We call them as facilitators.
  int area();
  int perimeter();

  // These two functions are accessor(of private members)
  int getLength() { return length; }
  int getBreadth() { return breadth; }

  // These two are mutators
  void setLength(int l) { length = l; }
  void setBreadth(int b) { length = b; }

  // Destructor: Called when an object is destroyed
  // Though here we don't need it but inside main function
  // we can see the working of it
  ~Rectangle();
};

// We can create a seperate file where class members are defined/implemented
// Like Rectangle.cpp. To access class members outside of its scope we must
// prefix them with 'Class_Name::'
Rectangle::Rectangle() {
  std::cout << "Default constructor is called" << std::endl;
  length = 0;
  breadth = 0;
}

Rectangle::Rectangle(int l, int b) {
  std::cout << "Parameterized constructor is called" << std::endl;
  length = l;
  breadth = b;
}

int Rectangle::area() { return length * breadth; }

int Rectangle::perimeter() { return 2 * (length + breadth); }

Rectangle::~Rectangle() { std::cout << "Destructor is called" << std::endl; }

// Main program: Can be seperated in different file like 'main.cpp'
// For more detail see: Interface-vs-Implementation.md
int main() {
  std::cout << "Constructor must be called after this line" << std::endl;
  {
    // Creating an instance/object of a 'Rectangle'
    Rectangle r(10, 5);
    std::cout << "Area of the rectangle is: " << r.area() << std::endl;
    std::cout << "Perimeter of the rectangle is: " << r.perimeter()
              << std::endl;

    // We can't access private member of a class by an object like 'r.length =
    // 20'
    r.setLength(20);
    r.setBreadth(15);
    std::cout << "Updated length: " << r.getLength() << std::endl;
    std::cout << "Updated breadth: " << r.getBreadth() << std::endl;
  }
  std::cout << "Destructor must be called before this line" << std::endl;

  std::cout << std::endl;

  // If we create a pointer of an object the constructor by default called
  // But destructor is not called until we 'freed' the memory.
  std::cout << "Default constructor must be called after this line"
            << std::endl;
  Rectangle *rect = new Rectangle;
  std::cout << "Destructor must be called after this line" << std::endl;
  delete rect;

  std::cout << std::endl;

  // But if we call smart pointer instead of raw pointer, it calls
  // destructor automatically, since it 'freed' automatically
  std::unique_ptr<Rectangle> r_unique = std::make_unique<Rectangle>(4, 3);
  std::cout << "Area of the r_unique: " << r_unique->area() << std::endl;
  return 0;
}
