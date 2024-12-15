/*
Exercise 1-20. 
    Write a program detab that replaces tabs in the input with the proper number
    of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
    Should n be a variable or a symbolic parameter? 
*/

#include <stdio.h>

#define TABSTOP 8       
#define MAXLINE 1000    
#define MAXLENGTH 50000 

int get_line(char line[], int maxline);
int concat(char line[], char base[], int position, int length);

int main() {
    int length;               
    char line[MAXLINE];       
    char base[MAXLENGTH];     
    int position = 0;         

    while ((length = get_line(line, MAXLINE)) > 0) {
        position = concat(line, base, position, length);
    }

    printf("Text: \n%s", base);

    return 0;
}


int get_line(char line[], int maxline) {
    int c, i, position;
    int num_blanks;

    position = 0; 
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ) {
        ++position;
        if (c == '\t') {
            num_blanks = TABSTOP - ((position-1) % TABSTOP);
            for (int j = 0; j < num_blanks; ++j) {
                line[i++] = '*'; 
                ++position;      
            }
            --position; 
        } else {
            line[i++] = c; 
        }
    }

    if (c == '\n') {
        line[i++] = c; 
    }

    line[i] = '\0'; 
    return i;       
}


int concat(char line[], char base[], int position, int length) {
    for (int i = 0; i < length && position < MAXLENGTH; i++) {
        base[position++] = line[i];
    }
    return position;
}
