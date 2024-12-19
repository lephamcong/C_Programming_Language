/*
Exercise 5-10. 
    Write the program expr, which evaluates a reverse Polish expression from the
    command line, where each operator or operand is a separate argument. For example,
        expr 2 3 4 + *
        evaluates 2 * (3+4).

Compile: gcc Exercise5_10.c -o Exercise5_10
Run: ./Exercise5_10 2 3 4 + * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTACK 100

double stack[MAXSTACK];
int sp = 0;

void push(double val) {
    if (sp < MAXSTACK) {
        stack[sp++] = val;
    } else {
        printf("Error: Stack overflow\n");
        exit(1);
    }
}

double pop() {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("Error: Stack underflow\n");
        exit(1);
    }
}

int is_number(char *s) {
    char *endptr;
    strtod(s, &endptr);
    return *endptr == '\0';
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: file operand operand ... operator\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        printf("Processing: %s\n", argv[i]);  // Debug log
        if (is_number(argv[i])) {
            push(atof(argv[i]));
        } else if (strcmp(argv[i], "+") == 0) {
            push(pop() + pop());
        } else if (strcmp(argv[i], "-") == 0) {
            double b = pop();
            double a = pop();
            push(a - b);
        } else if (strcmp(argv[i], "*") == 0) {
            double b = pop();
            double a = pop();
            push(a * b);
        } else if (strcmp(argv[i], "/") == 0) {
            double b = pop();
            if (b == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            double a = pop();
            push(a / b);
        } else if (strcmp(argv[i], "%") == 0) {
            double b = pop();
            if (b == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            double a = pop();
            push((int)a % (int)b);
        } else {
            printf("Error: Invalid operator '%s'\n", argv[i]);
            return 1;
        }
    }

    if (sp == 1) {
        printf("Result: %.2f\n", pop());
    } else {
        printf("Error: Invalid expression\n");
        return 1;
    }

    return 0;
}
