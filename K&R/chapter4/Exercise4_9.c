/*
Exercise 4-9. 
    Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
    what their properties ought to be if an EOF is pushed back, then implement your design. 

Compile: gcc Exercise4_9.c -o Exercise4_9 -lm
Run: ./Exercise4_9
*/

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h> // for isdigit()
#include <math.h> // for sin(), exp(), pow()

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found
#define MAXVAL 100 // maximum depth of val stack
#define BUFSIZE 100 // buffer for ungetch
#define VARIABLE '1' // signal that a variable was found

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

int eof_flag = 0;


int main() {
    int type;
    double op2;
    char s[MAXOP];
    double variables[26] = {-1};
    double last_printed = -1;
    char var = 1;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case VARIABLE:
            var = s[0];
            push(variables[var - 'A']);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((int)pop() % (int)op2);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '=':
            if (isupper(var)) {
                pop();
                variables[var - 'A'] = pop();
            } else {
                printf("error: invalid variable name\n");
            }
            break;
        case '\n':
            if (sp > 0) {
                last_printed = val[sp - 1];
                printf("\t%.8g\n", last_printed); 
            } else {
                printf("error: stack empty\n");
            }
            break;
        case 'S':
            push(sin(pop()));
            break;
        case 'E':
            push(exp(pop()));
            break;
        case 'P':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 'p':
            print_top();
            break;
        case 'd':
            duplicate_top();
            break;
        case 's':
            swap_top_two();
            break;
        case 'c':
            clear_stack();
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
/* print_top: print top element without popping */
void print_top(void) {
    if (sp > 0) {
        printf("Top element of the stack: %.8g\n", val[sp - 1]);
    } else {
        printf("error: stack empty\n");
    }
}

/*  */
void duplicate_top(void) {
    if (sp > 0 && sp < MAXVAL) {
        val[sp] = val[sp - 1];
        sp++;
    } else {
        printf("error: can't duplicate\n");
    }
}

/* swap_top_two: swap the top two elements */
void swap_top_two(void) {
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else {
        printf("error: can't swap\n");
    }
}

/* clear_stack: clear the stack */
void clear_stack(void) {
    sp = 0;
    printf("Stack cleared\n");
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    // handle negative numbers
    s[1] = '\0';

    if (isupper(c)) {
        return VARIABLE;
    }

    if (!isdigit(c) && c != '.' && c != '-') {
        return c; // not a number
    }
    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }
    }
    if (isdigit(c)) { // collect integer part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') { // collect fraction part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

int getch(void) {
    if (eof_flag) {
        eof_flag = 0;
        return EOF;
    }
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if ( c == EOF) {
        if (eof_flag) {
            printf("ungetch: too many EOF\n");
        } else {
            eof_flag = 1;
        }
    } else if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
