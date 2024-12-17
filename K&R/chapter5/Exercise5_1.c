/*
Exercise 5-1. 
    As written, getint treats a + or - not followed by a digit as a valid
    representation of zero. Fix it to push such a character back on the input. 
*/
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
char buf[BUFSIZE];  // Buffer for ungetch
int bufp = 0;       // Next free position in buf

int getch(void);
void ungetch(int);
int getint(int *pn);

int main() {
    int n;
    while (getint(&n) != EOF) {
        printf("%d\n", n);
    }
    return 0;
}

int getint(int *pn) {
    int c, sign;

    *pn = 0;  // Initialize *pn to 0

    while (isspace(c = getch()))  // Skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);              // push back non-digit
        return 0;                // not a number
    }

    sign = (c == '-') ? -1 : 1;  // define sign

    if (c == '+' || c == '-') {
        int next = getch();
        if (!isdigit(next)) {    // if + or - not followed by a digit
            ungetch(next);       // push back non-digit
            ungetch(c);          // push back + or -
            return 0;            // not a number
        }
        c = next;                // assign next to c
    }

    for (*pn = 0; isdigit(c); c = getch())  // Convert digits to integer
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;                 // Apply sign

    if (c != EOF)
        ungetch(c);              // push back non-digit

    return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
