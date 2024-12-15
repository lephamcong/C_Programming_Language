/*
Exercise 1-18. 
    Write a program to remove trailing blanks and tabs from each line of input,
    and to delete entirely blank lines. 
*/

#include <stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 50000

int my_getline(char line[], int maxline);
int concat(char line[], char base[], int position, int length);

int main() {
    int length, position = 0;
    char line[MAXLINE];
    char base[MAXLENGTH] = {0}; 

    while ((length = my_getline(line, MAXLINE)) > 0) {
        for (length = length -2; length >= 0 && (line[length] == ' ' || line[length] == '\t'); length--) {
            ;
        }
        ++length;
        line[length] = '\n';
        ++length;
        line[length] = '\0';
        if (length > 1) {
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