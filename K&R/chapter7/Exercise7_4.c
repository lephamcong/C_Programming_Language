/* Write a private version of scanf analogous to minprintf 
from the previous section*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p;

    int *ival;
    double *dval;
    char *sval;
    char *cval;

    char buffer[100];
    
    va_start(ap, fmt);
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            continue;
        }
        *p++;
        
        switch(*p) {
            case 'd':
                ival = va_arg(ap, int*);
                scanf("%d", ival);
                break;
            case 's':
                sval = va_arg(ap, char **);
                scanf("%s", sval);
                break;
            case 'f':
                dval = va_arg(ap, double*);
                scanf("%f", dval);
                break;
            case 'x':
                ival = va_arg(ap, int*);
                scanf("%x", ival);
                break;
            case 'c':
                cval = va_arg(ap, char*);
                scanf(" %c", cval);
                break;
            default:
                fprintf(stderr,"Unsupported format");
                break;
        }
    }
    va_end(ap);
}
  
int main()
{
    int i;
    float f;
    char str[100];
    char c;

    printf("Enter an integer: ");
    minscanf("%d", &i);

    printf("Enter a floating-point number: ");
    minscanf("%f", &f);

    printf("Enter a string: ");
    minscanf("%s", str);

    printf("Enter a character: ");
    minscanf("%c", &c);

    printf("\nYou entered:\n");
    printf("Integer: %d\n", i);
    printf("Floating-point: %.2f\n", f);
    printf("String: %s\n", str);
    printf("Character: %c\n", c);

    return 0;
}