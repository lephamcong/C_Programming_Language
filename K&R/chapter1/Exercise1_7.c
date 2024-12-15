/*
Exercise 1-7. 
    Write a program to print the value of EOF. 
*/

#include <stdio.h>

int main() {
    int c;

    c = getchar();
    
    printf("EOF: %d\n", EOF);
    return 0;
}