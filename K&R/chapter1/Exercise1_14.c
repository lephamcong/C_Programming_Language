/*
Exercise 1-14. 
    Write a program to print a histogram of the frequencies of different characters
    in its input. 
*/

#include <stdio.h>

int main() {
    int c;

    char alphabet[36] = {0};

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (c >= 'a' && c <= 'z') {
                alphabet[c - 'a']++;
            } else if (c >= 'A' && c <= 'Z') {
                alphabet[c - 'A']++;
            } else if (c >= '0' && c <= '9') {
                alphabet[c - '0' + 26]++;
            } else {
                alphabet[36]++;
            }
        }
    } 

    for (int i = 0; i < 26; i++) {
        printf("%c     | ", 'a' + i);
        for (int j = 0; j < alphabet[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }

    for (int i = 26; i < 36; i++) {
        printf("%d     | ", i - 26);
        for (int j = 0; j < alphabet[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("%s | ", "other");
    if (alphabet[36] > 0) {
        for (int j = 0; j < alphabet[36]; j++) {
            printf("* ");
        }
    }
    printf("\n");

    return 0;
}