/*
Exercise 1.15. 
    Rewrite the temperature conversion program of Section 1.2 to use a function
    for conversion.
*/

#include <stdio.h>
#include <stdlib.h>

float convert_FtoC(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float convert_CtoF(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

int main() {
    int option;
    float fahrenheit, celsius;

    do {
        system("clear"); // Xóa màn hình terminal
        printf("Choose option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("0. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            system("clear");
            printf("Fahrenheit to Celsius\n");
            printf("Enter Fahrenheit (°F): ");
            scanf("%f", &fahrenheit);
            printf("Celsius: %.2f (°C)\n", convert_FtoC(fahrenheit));
            printf("\nPress Enter to return to menu...");
            getchar(); getchar(); 
            break;

        case 2:
            system("clear");
            printf("Celsius to Fahrenheit\n");
            printf("Enter Celsius (°C): ");
            scanf("%f", &celsius);
            printf("Fahrenheit: %.2f (°F)\n", convert_CtoF(celsius));
            printf("\nPress Enter to return to menu...");
            getchar(); getchar(); 
            break;

        case 0:
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid option. Please try again.\n");
            printf("\nPress Enter to return to menu...");
            getchar(); getchar(); 
            break;
        }
    } while (option != 0); 

    return 0;
}
