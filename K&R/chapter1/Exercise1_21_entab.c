/*
Exercise 1-21. 
    Write a program entab that replaces strings of blanks by the minimum
    number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
    When either a tab or a single blank would suffice to reach a tab stop, which should be given
    preference? 
*/

#include <stdio.h>

#define TABSTOP 8       
#define MAXLINE 1000    
#define MAXLENGTH 50000 

int get_line(char line[], int maxline);
int concat(char line[], char base[], int pos_cat, int length);

int main() {
    int length;               
    char line[MAXLINE];       
    char base[MAXLENGTH];     
    int pos_cat = 0;         

    while ((length = get_line(line, MAXLINE)) > 0) {
        pos_cat = concat(line, base, pos_cat, length);
    }

    printf("Text: \n%s", base);

    return 0;
}

int get_line(char line[], int maxline) {
    int c, i, pos_get;
    int num_blanks = 0;
    int num_tabs = 0;
    pos_get = 0; 
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n';) {
        ++pos_get;
        if (c == '*') {
            if (pos_get % TABSTOP != 0) {
                ++ num_blanks;
            }
            else {
                num_blanks = 0;
                ++num_tabs;
            }
        } else {
            for (int j = 0; j < num_tabs; ++j) {
                line[i++] = '\t'; 
            }
            num_tabs = 0;
            if (c == '\t') {
                num_blanks = 0;
                pos_get = pos_get + (TABSTOP - (pos_get % TABSTOP));
            }

            for (int j = 0; j < num_blanks; ++j) {
                line[i++] = '*'; 
            }
            num_blanks = 0;

            line[i++] = c;

            if (c == '\n') {
                pos_get = 0;
            }
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
