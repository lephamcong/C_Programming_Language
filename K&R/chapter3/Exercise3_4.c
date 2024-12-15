/*
Exercise 3-4. 
    In a two's complement number representation, our version of itoa does not
    handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
    not. Modify it to print that value correctly, regardless of the machine on which it runs.

    Answer:
        a 32-bit integer can represent numbers from -2^31 to 2^31 - 1 (from -2147483648 to 2147483647).
        when n = -2147483648, n = -n => n = 2147483648, which is out of the range of a 32-bit integer.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void my_itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    char s[100];
    int n = 2147483647;
    my_itoa(n, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void my_itoa(int n, char s[]) {
    int i, sign;
    if (n == INT_MIN) {
        s[0] = '-';
        s[1] = '2';
        n = 147483648;
        i = 2;
        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
        s[i] = '\0';
        reverse(s+2);
    } else {
        if ((sign = n) < 0) {
            n = -n;
        }
        i = 0;
        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
        if (sign < 0) {
            s[i++] = '-';
        }
        s[i] = '\0';
        reverse(s);
    }
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
