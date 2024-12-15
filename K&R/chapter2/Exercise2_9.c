/*
Exercise 2-9. 
    In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
    in x. Explain why. Use this observation to write a faster version of bitcount.

    Answer:
        x &= (x-1)
            x - 1: all bits from the rightmost 1-bit to the right are flipped.
            x = 0b0101100 
            x - 1 = 0b0101011
            0101100 - 0000001 = 0101011
            x &= (x-1) = x & x-1 = 0101100 & 0101011 = 0101000
*/

#include <stdio.h>

int bitcount(unsigned x);
int bitcount_faster(unsigned x);

int main() {
    int x; 
    x = 0b1011011;
    printf("%b\n", x);
    // printf("%d\n", bitcount(x));
    printf("%d\n", bitcount_faster(x));
    return 0;
}

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }
    return b;
}

int bitcount_faster(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x-1)) {
        b++;
    }
    return b;
}
