/*
Exercise 1-8. 
    Write a program to count blanks, tabs, and newlines. 
*/

#include <stdio.h>

int main() {
    int blank, tab, newline, c;
    blank = 0;
    tab = 0;
    newline = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blank;
        }
        if (c == '\t') {
            ++tab;
        }
        if (c == '\n') {
            ++newline;
        }
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blank, tab, newline);
    
}