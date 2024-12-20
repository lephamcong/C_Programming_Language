/* Revise minprintf to handle more of the other facilities of printf
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p;

    int width;
    int precision;
    int left_align = 0;
    
    int ival;
    double dval;
    char *sval;

    
    va_start(ap, fmt);
    for(p = fmt; *p; p++) {
        if(*p != '%') {
                putchar(*p);
                continue;
        }
        if(*++p == '\0')
            return;
        if(*p == '-') {
            left_align = 1;
            if(*++p == '\0')
            return;
        } else 
            left_align = 0;
        width = precision = 0;
        if(isdigit(*p) && *p) 
            while(isdigit(*p)) {
                width = width * 10 + *p - '0';
                p++;
            }
        if(*p == '\0')
            return;
        if(*p == '.') 
            while(isdigit(*++p) && *p) 
                precision = precision * 10 + *p - '0';
        if(*p == '\0')
            return;
            
        
        switch(*p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                
                if(left_align == 1) 
                    printf("%-*.*d", width, precision, ival);
                else 
                    printf("%*.*d", width, precision, ival);
                break;
            case 's':
                sval = va_arg(ap, char *);
                char *str = sval;
                if (precision){
                    if(left_align == 1) 
                        printf("%-*.*s", width, precision, sval);
                    else 
                        printf("%*.*s", width, precision, sval);
                    break;
                }
                else {
                    if(left_align == 1) 
                        printf("%-*s", width, sval);
                    else 
                        printf("%*s", width, sval);
                    break;
                }
            case 'f':
                dval = va_arg(ap, double);
                if(left_align == 1) 
                    printf("%-*.*f", width, precision, dval);
                else 
                    printf("%*.*f", width, precision, dval);
                break;
            case 'x':
                ival = va_arg(ap, int);
                if(left_align == 1) 
                    printf("%-*.*x", width, precision, ival);
                else 
                    printf("%*.*x", width, precision, ival);
                break;
            default:
                    putchar(*p);
                    break;
        }
    }
    va_end(ap);
}
  
int main()
{
    minprintf("Integer: %5d\n", 42);
    minprintf("Left-justified integer: %-5d\n", 42);
    minprintf("Floating-point: %.2f\n", 3.14159);
    minprintf("String: %10s\n", "hello");
    minprintf("Left-justified string: %-10s\n", "hello");
    minprintf("Hexadecimal: %8x\n", 255);
    minprintf("Character: %c\n", 'A');
    return 0;
}