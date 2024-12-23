/*
Exercise 1-16. 
    Revise the main routine of the longest-line program so it will correctly print
    the length of arbitrary long input lines, and as much as possible of the text. 
*/

#include <stdio.h>
#define MAXLINE 25

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        /*my code*/
        if (line[len - 1] != '\n' && line[len - 1] != EOF) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                len++;
            }
        }
        /*my code*/
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("Longest line: %s\n", longest);
        printf("Length: %d\n", max);
    }
    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}