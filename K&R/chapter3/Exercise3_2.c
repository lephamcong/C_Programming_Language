/*
Exercise 3-2.  
    Write a function escape(s,t) that converts characters like newline and tab
    into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
    a function for the other direction as well, converting escape sequences into the real characters. 
*/

#include <stdio.h>

int main() {
    int c;

    // escape
    /*
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\n':
                putchar('\\');
                putchar('n');
                break;
            default:
                putchar(c);
                break;
        }
    }
    */

    // unescape
    while ((c = getchar()) != EOF) {
        if (c == '\\') {
            c = getchar();
            switch (c) {
                case 't':
                    putchar('\t');
                    break;
                case 'n':
                    putchar('\n');
                    break;
                default:
                    putchar('\\');
                    putchar(c);
                    break;
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}

