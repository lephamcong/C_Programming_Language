/*
Exercise 5-2. 
    Write getfloat, the floating-point analog of getint. What type does
    getfloat return as its function value?

    Answer:
    getfloat returns:
        - EOF for end of file
        - 0 if the next input is not a number
        - a positive value if the input is a valid number
    float value is returned through a pointer argument. 
*/

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
char buf[BUFSIZE];  // Buffer for ungetch
int bufp = 0;       // Next free position in buf

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main() {
    float f;
    int result;
    while ((result = getfloat(&f)) != EOF) {
        printf("%.6f\n", f);
    }
    return 0;
}

int getfloat(float *pn) {
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);              
        return 0;                
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);       
            ungetch(c);          
            return 0;            
        }
        c = next;                
    }

    for (*pn = 0.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
    }

    if (c == '.') {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
        *pn /= power;
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);              
    }

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
