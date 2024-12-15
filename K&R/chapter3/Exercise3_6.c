/*
Exercise 3-6. 
    Write a version of itoa that accepts three arguments instead of two. The third
    argument is a minimum field width; the converted number must be padded with blanks on the
    left if necessary to make it wide enough. 
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void my_itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
    char s[100];
    int n = -2147483647;
    my_itoa(n, s, 15);
    printf("%s\n", s);
    return 0;
}

void my_itoa(int n, char s[], int w) {
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
    int len = strlen(s);
    if (len < w) {
        int diff = w - len;
        for (int j = len; j >= 0; j--) {
            s[j+diff] = s[j];
        }
        for (int j = 0; j < diff; j++) {
            s[j] = ' ';
        }
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
