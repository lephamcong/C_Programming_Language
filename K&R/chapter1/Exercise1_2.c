/*
Exercise 1-2. 
    Experiment to find out what happens when prints's argument string contains
    \c, where c is some character not listed above.
*/

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

/*
    Error: unknown escape sequence '\c'
    Compiler don't unserstand the '\c'
*/

