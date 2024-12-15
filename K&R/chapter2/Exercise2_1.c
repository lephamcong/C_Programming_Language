/*
Exercise 2-1. 
    Write a program to determine the ranges of char, short, int, and long
    variables, both signed and unsigned, by printing appropriate values from standard headers
    and by direct computation. Harder if you compute them: determine the ranges of the various
    floating-point types. 
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    unsigned char c_unsigned;
    char c_signed;
    unsigned short s_unsigned;
    short s_signed;
    unsigned int i_unsigned;
    int i_signed;
    unsigned long l_unsigned;
    long l_signed;

    printf("Ranges of char, short, int, and long variables\n");
    printf("------------------------------------------------\n");
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: %d to %d\n", 0, UCHAR_MAX);
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %d to %d\n", 0, USHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: %d to %u\n", 0, UINT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: %d to %lu\n", 0, ULONG_MAX);


    return 0;
}