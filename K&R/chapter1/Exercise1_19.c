/*
Exercise 1-19. 
    Write a function reverse(s) that reverses the character string s. 
    Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLINE 1000
#define MAXLENGTH 50000

int my_getline(char line[], int maxline);
int concat(char line[], char base[], int position, int length);
int reverse(char str[], int length);

int main() {
    int length, position = 0;
    char line[MAXLINE];
    char base[MAXLENGTH] = {0};

    while ((length = my_getline(line, MAXLINE)) > 0) {
        length = reverse(line, length);
        position = concat(line, base, position, length);
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

int reverse(char str[], int length) {
    int i, j;

    i = 0;
    j = length - 2;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return length;
}


