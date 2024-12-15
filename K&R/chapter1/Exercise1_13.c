/*
Exercise 1-13. 
    Write a program to print a histogram of the lengths of words in its input. 
    It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 
*/

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 10

int main() {
    int c, state, length;
    int histogram[MAX_WORD_LENGTH+1] = {0};
    state = OUT;
    length = 0;
    size_t size = sizeof(histogram)/sizeof(histogram[0]);
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
            }
            if (length > 0 && length <= MAX_WORD_LENGTH) {
                histogram[length]++;
            }
            length = 0;
        } else {
            state = IN;
            length++;
        }
    }
    
    if (length > 0 && length <= MAX_WORD_LENGTH) {
        histogram[length]++;
    }

    for (int i = 1; i < size; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < histogram[i]; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    printf("    +");
    for (int i = 1; i < size; ++i) {
        printf("- ");
    }
    printf("\n");

    printf("     ");
    for (int i = 1; i < size; ++i) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}