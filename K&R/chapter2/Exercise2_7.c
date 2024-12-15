/*
Exercise 2-7. 
    Write a function invert(x,p,n) that returns x with the n bits that begin at
    position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    int x, p, n;

    // printf("Enter x: ");
    // scanf("%d", &x);
    // printf("Enter p: ");
    // scanf("%d", &p);
    // printf("Enter n: ");
    // scanf("%d", &n);;

    x = 0b1011011;
    p = 3;
    n = 4;

    
    // x in decimal
    printf("x in decimal: %d\n", x);
    // x in binary
    printf("x in binary: ");
    for (int i = 6; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
    printf("result: \n");
    printf("Decimal: %d\n", invert(x, p, n));
    printf("Binary: ");
    for (int i = 6; i >= 0; i--) {
        printf("%d", (invert(x, p, n) >> i) & 1);
    }
    printf("\n");
    return 0;
}

int invert(int x, int p, int n) {
    unsigned int mask;

    mask = ~(~0U << n) << p;
    return x ^ mask;
}