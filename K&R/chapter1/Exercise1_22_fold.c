/*
Exercise 1-22. 
    Write a program to ``fold'' long input lines into two or more shorter lines after
    the last non-blank character that occurs before the n-th column of input. Make sure your
    program does something intelligent with very long lines, and if there are no blanks or tabs
    before the specified column.
*/

#include <stdio.h>

#define MAXLINE 100
#define MAXLENGTH 50000

#define FOLD 4

int get_line(char line[], int maxline);
int concat(char line[], char base[], int position, int length);
void fold(char line[], int length);


int main() {
    int length, pos_cat = 0;
    char line[MAXLINE];
    char base[MAXLENGTH];

    while ((length = get_line(line, MAXLINE)) > 0) {
        fold(line, length);
        pos_cat = concat(line, base, pos_cat, length);
    }
    printf("Text: \n%s", base);

    return 0;

}

int get_line(char line[], int maxline) {
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
    for (int i = 0; i < length && position < MAXLENGTH; i++) {
        base[position++] = line[i];
    }
    return position;
}

void fold(char line[], int length) {
    int col = 0;              
    int lastBlank = -1;      
    int current_length = 0;   

    for (int i = 0; i < length; ++i, ++col) {
        char c = line[i];
        ++current_length;

        if (c == ' ' || c == '\t') {
            lastBlank = col;
        }

        if (current_length > FOLD) {
            if (lastBlank != -1) {
                line[lastBlank] = '\n';
                current_length = col - lastBlank; 
                lastBlank = -1;  
            } else {

                for (int j = length; j > col; --j) {
                    line[j] = line[j - 1]; 
                }
                line[col] = '\n';  
                ++length;         
                current_length = 0;  
            }
        }
    }
}


