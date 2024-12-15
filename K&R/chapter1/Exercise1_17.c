/*
Exercise 1-17. 
    Write a program to print all input lines that are longer than 80 characters
*/

#include <stdio.h>

#define MINLINE 10
#define MAXLINE 1000
#define MAXLENGTH 50000


int my_getline(char line[], int maxline);
int concat(char line[], char base[], int position, int length);

int main() {
    int length;
    char line[MAXLINE];
    char base[MAXLENGTH];

    int position = 0;

    while ((length = my_getline(line, MAXLINE)) > 0) {
        if (length > MINLINE) {
            position = concat(line, base, position, length);
        }
    }
    printf("Text:\n%s", base);
    return 0;
}

int my_getline(char line[], int maxline) {
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

int concat(char line[], char base[], int position, int length) {
    int i;
    for (i = 0; i < length && position < MAXLENGTH; i++) {
        base[position] = line[i];
        position++;
    }
    return position;
}