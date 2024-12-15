/*
Exercise 1-5. 
    Modify the temperature conversion program to print the table in reverse order,
    that is, from 300 degrees to 0. 
*/

#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    float lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    printf("Fahrenheit\tCelsius\n");
    for ( fahrenheit = upper; fahrenheit >= lower; fahrenheit -= step) {
        celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
        printf("%6.2f\t\t%3.2f\n", fahrenheit, celsius);
    }

    return 0;
}