/*
Exercise 1-4. 
    Write a program to print the corresponding Celsius to Fahrenheit table. 
*/

#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    printf("Celsius\t\tFahrenheit\n");
    printf("-------\t\t----------\n");
    celsius = lower;
    while (celsius <= upper) {
        fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        printf("%3.2f\t\t%6.2f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }   

    return 0;
}