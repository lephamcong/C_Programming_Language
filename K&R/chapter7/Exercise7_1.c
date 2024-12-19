#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lower(){
    int c;
    while((c = getchar()) != EOF)
        putchar(tolower(c));
}

void upper(){
    int c;
    while((c = getchar()) != EOF)
        putchar(toupper(c));
}

/* Convert upper case to lower or lower to upper, depending on 
the name it is invoked with, as found in argv[0]*/
int main(int argc, char *argv[]){
    char *prog = strrchr(argv[0],'/');
    prog++;

    if (strcmp(prog, "toupper") == 0){
        upper();
    } else if (strcmp(prog, "tolower") == 0){
        lower();
    } else {
        printf("Error: Program must be 'toupper' or 'tolower'\n");
        return 1;
    }

    return 0;
}