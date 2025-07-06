#include <iostream>
/* #include <iostream>: This line is called a preprocessor directive.
 *
 * Preprocessor: replaces text(starting with '#') with the actual content(here
 * the file 'stdio.h') It replaces the text before compilation begins. Output of
 * preprocessing is called expanded source code. After expanding source code
 * it's send to the compiler & compiler converts it into machine code.
 *
 * Header files: contains declaration of function.
 *
 * C standard library: contains actual definition of functions.
 *
 * Linker: maps down the prototypes mentioned by the preprocessors to the actual
 * code written in the standard library. It simply maps & doesn't copy paste the
 * content like preprocessor. This separate process of linking make computation
 * of program a little faster. If preprocessor does the job of getting all the
 * actual definitions of one source code, it increases the size of the extended
 * code exponentially & therefore the speed of compilation fall down drstically.
 * Therefore maintaining header file(just declaration of functions) and standard
 * library (or actual definition of functions in large code base) seperately is
 * essential. */
int main() {
  int var = 5;
  /* Declaration: Means announcing the properties of the variable(size of the
   variable, i.e data types and name of
   * the variable) to the compiler.
   *
   * Definition: Allocating memory to a variable.

   * Most of the time declaration& definition will done at the same time. But
   this is not always the case.
   * It depends on the modidfiers you had mentioned with the variables.
   * If you assign some values to a variable, at the time of declaration
   itselft, then this is called 'initialization'. */

  // int var = 6;
  // Error: Means you want to allocate two memory location for same name var.
  std::cout << "Value of var: " << std::endl;
}
