/*
Exercise 2-2. 
    Write a loop equivalent to the for loop above without using && or ||.
*/

#include <stdio.h>

int main() {

    //  for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
    int i = 0;
    while(1){
        if(i >= lim - 1){
            break;
        }
        c = getchar();
        if(c == '\n'){
            break;
        }
        if (c == EOF){
            break;
        }
        // Loop body (code to be executed in the loop)
        ++i;
    }

    return 0;
}