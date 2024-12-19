/*
Exercise 5-3. 
    Write a pointer version of the function strcat that we showed in Chapter 2:
    strcat(s,t) copies the string t to the end of s. 
*/

#include <stdio.h>

void my_strcat(char *s, char *t);

int main() {
    char s[100] = "Hello, ";
    char t[] = "World!";
    my_strcat(s, t);
    printf("%s\n", s);
    return 0;
}

void my_strcat(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }
    while ((*s++ = *t++) != '\0') {
        ;
    }
}
