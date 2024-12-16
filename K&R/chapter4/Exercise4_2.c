/*
Exercise 4-2. 
    Extend atof to handle scientific notation of the form
        123.45e-6
    where a floating-point number may be followed by e or E and an optionally signed exponent. 
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main() {
    char s[] = "123.45e-6";
    double atof(char []);
    printf("%.10f\n", atof(s));
    return 0;
}

double atof(char s[]) {
    double val, pow;
    int i, sign, exp_sign, exp_val;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') // skip sign
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') // skip decimal point
        i++;
    for (pow = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        pow *= 10.0;
    }
    val = sign * val / pow;
    
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') // skip sign
            i++;
        for (exp_val = 0; isdigit(s[i]); i++)
            exp_val = 10 * exp_val + (s[i] - '0');
        if (exp_sign == -1)
            while (exp_val-- > 0)
                val /= 10;
        else
            while (exp_val-- > 0)
                val *= 10;
    }
    return val;
}
