/*
Exercise 3-5. 
    Write the function itob(n,s,b) that converts the integer n into a base b
    character representation in the string s. In particular, itob(n,s,16) formats s as a
    hexadecimal integer in s.
*/
#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    char s[100];
    int n = 123456;
    int b = 16;
    itob(n, s, b);
    printf("%s\n", s);
    return 0;
}

void itob(int n, char s[], int b) {
    int i, d, c;
    switch (b) {
        case 16:
            i = 0;
            do {
                d = n % b;
                c = d + '0';
                if (d > 9) {
                    c = d - 10 + 'A';
                }
                s[i++] = c;
            } while ((n /= b) > 0);
            s[i] = '\0';
            reverse(s);
            break;
        case 8:
        case 2:
            i = 0;
            do {
                s[i++] = n % b + '0';
            } while ((n /= b) > 0);
            s[i] = '\0';
            reverse(s);
            break;
        
        default:
            break;
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
