/*
Exercise 2-3. 
    Write a function htoi(s), which converts a string of hexadecimal digits
    (including an optional 0x or 0X) into its equivalent integer value. 
    The allowable digits are 0 through 9, a through f, and A through F. 
*/

#include <stdio.h>


int htoi(char s[], int length);
int exponent(int base, int power);


int main() {
    char s[] = "0x1F";

    int length = sizeof(s) / sizeof(s[0]) -1;
    printf("%d\n", htoi(s, length));
    return 0;
}

int htoi(char s[], int length) {
    int i = length - 1, result_value = 0, digit_value = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        while (i > 1) {
            if (s[i] >= '0' && s[i] <= '9') {
                digit_value = s[i] - '0';
            } else if (s[i] >= 'a' && s[i] <= 'f') {
                digit_value = s[i] - 'a' + 10;
            } else if (s[i] >= 'A' && s[i] <= 'F') {
                digit_value = s[i] - 'A' + 10;
            } else {
                return -1;
            }
            result_value += digit_value * exponent(16, length -1 - i);
            --i;
        }
    } else {
        while (i >= 0) {
            if (s[i] >= '0' && s[i] <= '9') {
                digit_value = s[i] - '0';
            } else if (s[i] >= 'a' && s[i] <= 'f') {
                digit_value = s[i] - 'a' + 10;
            } else if (s[i] >= 'A' && s[i] <= 'F') {
                digit_value = s[i] - 'A' + 10;
            } else {
                return -1;
            }
            result_value += digit_value * exponent(16, length -1 - i);
            --i;
        }
    }

    return result_value;    
}

int exponent(int base, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= base;
    }
    return result;
}

