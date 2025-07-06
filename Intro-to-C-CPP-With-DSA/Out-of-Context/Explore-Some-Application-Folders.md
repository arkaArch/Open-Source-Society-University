## Applications:
1. `/usr/bin`: Application supplied by the system, and what I installed via package manager 
are stored in this folder. Like 'pwd', 'yazi', 'nvim'

2. `/usr/local/bin`: Applications added by system administrators for a specific host computer 
or local network are often found in here or '/opt'. Like what I manually install(or like install 
from source). 'dwm', 'st', 'dmenu' are found here. The reason for keeping this files in seperate folder.

3. ` /usr/lib/gcc/x86_64-pc-linux-gnu/15.1.1/`: gcc is located in my thinkpad. 

## Header Files:
1. `/usr/include`: Header files are located.
2. `/usr/include/linux`: Header files to program on linux.
3. `/usr/include/c++`: Header files for cpp.
4. You can use header files in subdirectories or nonstandard places by specifying the -I flag to the C compiler. 
For example, `gcc -I/usr/openwin/include fred.c`. This command will direct the compiler to look in the directory 
`/usr/openwin/include`, as well as the standard places, for header files included in the fred.c program.


## Library Files:
Libraries are collections of precompiled functions that have been written to be reusable. Typically, they consist 
of sets of related functions to perform a common task. Like curses, ncurses, dbm. They are store generally in '/usr/lib' 
or 'lib'(generally symlink of /usr/lib).
