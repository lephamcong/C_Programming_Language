/*
Exercise 1-11. 
    How would you test the word count program? What kinds of input are most
    likely to uncover bugs if there are any? 
*/

#include <stdio.h>

#define IN 1 /* Inside a word */
#define OUT 0 /* Outside a word */

int main() {
    int c, nl, nw, nc, state;

    state = OUT;

    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
    return 0;
}
/*
Test cases:
1. Input: 
            "Hello"
   Output:  
            Lines: 1
            Words: 1
            Characters: 5
2. Input: 
            "Hello World"
   Output:  
            Lines: 1
            Words: 2
            Characters: 11
3. Input:
            "Hello World
            This is a test"
   Output:  
            Lines: 2
            Words: 6
            Characters: 24
*/