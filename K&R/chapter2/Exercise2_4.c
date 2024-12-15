/*
Exercise 2-4. 
    Write an alternative version of squeeze(s1,s2) that deletes each character in
    s1 that matches any character in the string s2.
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {

    char s1[] = "Hello, World!";
    char s2[] = "World";

    squeeze(s1, s2);
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                break;
            }
        }
        if (s2[k] == '\0') {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

