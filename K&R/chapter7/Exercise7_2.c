/* Print arbitraty input in a sensible way. 
    - Print non-graphic characters in octal or hexadecimal
    - Break long text lines
*/
#include <stdio.h>
#include <ctype.h>

#define LINE_WIDTH 80

void print_input(FILE*);

int main(){
    printf("Enter input (Ctrl+D) to stop:\n");
    print_input(stdin);
    return 0;
}

void print_input(FILE *input){
    int c;
    int column = 0;

    while ((c = fgetc(input)) != EOF){
        if(isprint(c)){
            putchar(c);
            column++;
        } else {
            printf("\\%03o", c);
            column += 4;
        }
        if (column >= LINE_WIDTH){
            putchar('\n');
            column = 0;
        }
    }

    if (column > 0){
        putchar('\n');
    }
}