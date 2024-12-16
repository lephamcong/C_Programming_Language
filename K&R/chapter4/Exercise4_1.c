/*
Exercise 4-1.
    Write the function strindex(s,t) which returns the position of the rightmost
    occurrence of t in s, or -1 if there is none. 
*/

#include <stdio.h>

int stringdex(char s[], char t[]);

int main() {
    char s[] = "Hello, World!";
    char t[] = "ld";
    printf("%d\n", stringdex(s, t));
    return 0;
}

int stringdex(char s[], char t[]) {
    int i, j;
    int index = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; t[j] != '\0' && s[i+j] == t[j]; j++)
            ;
        if (t[j] == '\0')
            index = i;
    }
    return index;
}