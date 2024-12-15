/*
Exercise 2-6. 
    Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
    position p set to the rightmost n bits of y, leaving the other bits unchanged. 
*/

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {

    int x, p, n, y;

    // printf("Enter x: ");
    // scanf("%d", &x);
    // printf("Enter p: ");
    // scanf("%d", &p);
    // printf("Enter n: ");
    // scanf("%d", &n);
    // printf("Enter y: ");
    // scanf("%d", &y);

    x = 0b1011011;
    p = 3;
    n = 4;
    y = 0b0010100;
    
    // x in decimal
    printf("x in decimal: %d\n", x);
    // x in binary
    printf("x in binary: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
    printf("\n");
    printf("result: \n");
    printf("Decimal: %d\n", setbits(x, p, n, y));
    printf("Binary: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (setbits(x, p, n, y) >> i) & 1);
    }
    printf("\n");
    return 0;
}

int setbits(int x, int p, int n, int y) {
    int mask_x, mask_y;

    mask_y = ~(~0 << n); // 0001111
    mask_y = mask_y & y; // 0000100
    mask_y = mask_y << p; // 0100000

    mask_x = ~(~0 << n); // 0001111
    mask_x = mask_x << p; // 1111000
    mask_x = ~mask_x; // 0000111
    x = x & mask_x; // 1011011 & 0000111 = 0000011

    x = x | mask_y; // 0000011 | 0100000 = 0100011

    return x;
}

