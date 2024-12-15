/*
Exercise 1-3. 
    Modify the temperature conversion program to print a heading above the table. 
*/

#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    printf("Fahrenheit\tCelsius\n");
    printf("----------\t-------\n");
    fahrenheit = lower;
    while (fahrenheit <= upper) {
        celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
        printf("%6.0f\t\t%6.2f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }

    return 0;
}