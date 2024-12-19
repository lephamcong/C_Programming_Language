/*
Exercise 5-4. 
    Write the function strend(s,t), which returns 1 if the string t occurs at the
    end of the string s, and zero otherwise. 
*/

#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char s[] = "Hello, World!";
    char t[] = "World!";
    printf("%d\n", strend(s, t));
    return 0;
}

int strend(char *s, char *t) {
    char *s_ptr = s;
    char *t_ptr = t;
    while (*s_ptr != '\0') {
        s_ptr++;
    }
    while (*t_ptr != '\0') {
        t_ptr++;
    }
    while (t_ptr >= t) {
        if (s_ptr < s || *s_ptr != *t_ptr) {
            return 0;
        }
        s_ptr--;
        t_ptr--;
    }
    return 1;
}