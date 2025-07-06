A program can be divided into three files.
1. Header file(Interface: Where function can be declared)
2. Assosiative cpp file(Implementation: Where those function are defined)
3. Main Program

### Header file: (mymath.hpp)
```cpp
#ifndef MYMATH_HPP
#define MYMATH_HPP

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

#endif

// Note:

// "#ifndef" is commonly used to create header guards, preventing multiple 
// inclusions of the same header file. This avoids redefinition errors and 
// speeds up compilation.

// MYMATH_HPP is a unique macro name associated with the header file.
// The first time mymath.hpp is included, MYMATH_HPP is not defined, so the code is 
// included, and MYMATH_HPP is defined.
// Subsequent inclusions of mymath.hpp will find MYMATH_HPP defined, and the code will be skipped.
```


### Associative CPP file: (mymath.cpp)
```cpp
#include "mymath.hpp"

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
```


### Main Program: (main.cpp)
```cpp
#include <iostream>
#include "mymath.hpp"

int main() {
    std::cout << add(7, 8) << std::endl;
    std::cout << sub(17, 8) << std::endl;
    std::cout << mul(7, 8) << std::endl;
    return 0;
}
```

> Compile those three file as `g++ main.cpp mymath.cpp -o main`
