/*
Exercise 2-8. 
    Write a function rightrot(x,n) that returns the value of the integer x rotated 
    to the right by n positions. 
*/

#include <stdio.h>
#include <math.h>

int invert(int x, int p, int n);

int rightrot(int x, int n);

int main() {
    int x, p, n;

    // printf("Enter x: ");
    // scanf("%d", &x);
    // printf("Enter p: ");
    // scanf("%d", &p);
    // printf("Enter n: ");
    // scanf("%d", &n);;

    x = 91;
    n = 3;

    int num_bits = 8 * sizeof(int);
    // x in decimal
    printf("x in decimal: %d\n", x);
    // x in binary
    printf("x in binary: ");
    for (int i = num_bits; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
    printf("result: \n");
    printf("Decimal: %d\n", rightrot(x, n));
    printf("Binary: ");
    for (int i = num_bits; i >= 0; i--) {
        printf("%d", (rightrot(x, n) >> i) & 1);
    }
    printf("\n");
    return 0;
}

int rightrot(int x, int n) {
    int mask;
  
    mask = ((1 << n) - 1) & x;  

    x = x >> n;

    mask = mask << (7 - n); 

    x = x | mask;
    return x;
}
