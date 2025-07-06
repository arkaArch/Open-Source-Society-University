#include <iostream>

template <class T> class Arithmetic {
private:
  T a;
  T b;

public:
  Arithmetic(T a, T b);
  T add();
  T sub();
};

template <class T> Arithmetic<T>::Arithmetic(T a, T b) {
  this->a = a;
  this->b = b;
}

template <class T> T Arithmetic<T>::add() { return a + b; }

template <class T> T Arithmetic<T>::sub() { return a - b; }

int main() {
  Arithmetic<int> arithmatic_int(10, 5);
  std::cout << "10 + 5 = " << arithmatic_int.add() << std::endl;
  std::cout << "10 - 5 = " << arithmatic_int.sub() << std::endl;

  Arithmetic<double> arithmatic_doub(87.765, 58.654);
  std::cout << "87.765 + 58.654 = " << arithmatic_doub.add() << std::endl;
  std::cout << "87.765 - 58.654 = " << arithmatic_doub.sub() << std::endl;

  return 0;
}
