/*
Exercise 5-6. 
    Rewrite appropriate programs from earlier chapters and exercises with pointers
    instead of array indexing. Good possibilities include getline 
    (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), 
    reverse (Chapter 3), and strindex and getop (Chapter 4). 
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h> // for atof()
#include <ctype.h> // for isdigit()

#define MAXLINE 1000

int my_getline(char *line, int maxline);
int my_atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);

int main() {
    // my_getline
    // char line[MAXLINE];
    // while (my_getline(line, MAXLINE) > 0) {
    //     printf("%s", line);
    // }

    // my_atoi
    // char s[] = "  -12356";
    // printf("%d\n", my_atoi(s));

    // itoa
    // char s1[MAXLINE];
    // itoa(INT_MIN, s1);
    // printf("%s\n", s1);

    // reverse
    // char s2[] = "hello";
    // printf("%s\n", s2);
    // reverse(s2);
    // printf("%s\n", s2);

    // strindex
    // char s3[] = "hello";
    // char t[] = "ll";
    // printf("%s\n", s3);
    // printf("%s\n", t);
    // printf("%d\n", strindex(s3, t));

    // getop
    char s4[MAXLINE];
    int type;
    while ((type = getop(s4)) != EOF) {
        printf("%s\n", s4);
    }



    return 0;
}

/*  my_getline: get line into line, return length*/
int my_getline(char *line, int maxline) {
    int c, i;
    i = 0;
    while (--maxline > 0 && (c = getchar()) != EOF && c != '\n') {
        *line++ = c;
        i++;
    }
    if (c == '\n') {
        *line++ = c;
        i++;
    }
    *line = '\0';
    return i;

}

/*  my_atoi: convert s to integer; version 2*/
int my_atoi(char *s) {
    int n, sign;
    while (*s == ' ' || *s == '\t') {
        s++;
    }
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
        s++;
    }
    for (n = 0; *s >= '0' && *s <= '9'; s++) {
        n = 10 * n + (*s - '0');
    }
    return sign * n;
}

/*  itoa: convert n to characters in s*/
void itoa(int n, char *s) {
    int sign;
    char *s_start = s;
    if (n == INT_MIN) {
        *s++ = '-';
        *s++ = '2';
        n = 147483648;
        do {
            *s++ = n % 10 + '0';
        } while ((n /= 10) > 0);
        *s = '\0';
        reverse(s_start+2);
    } else {
        if ((sign = n) < 0) {
            n = -n;
        }
        do {
            *s++ = n % 10 + '0';
        } while ((n /= 10) > 0);
        if (sign < 0) {
            *s++ = '-';
        }
        *s = '\0';
        reverse(s_start);
    }
}

/* reverse: reverse string s in place */
void reverse(char *s) {
    char *t;
    for (t = s; *t != '\0'; t++) {
        ;
    }
    for (t--; s < t; s++, t--) {
        char temp = *s;
        *s = *t;
        *t = temp;
    }
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
    for (int i = 0; *s != '\0'; s++, i++) {
        char *s_temp = s;
        char *t_temp = t;

        while (*s_temp == *t_temp && *t_temp != '\0') {
            s_temp++;
            t_temp++;
        }
        if (*t_temp == '\0') {
            return i;
        }
    }
    return -1;
}

/* getop: get next operator or numeric operand */
int getop(char *s) {
    int c;
    while ((*s = c = getchar()) == ' ' || c == '\t') {
        ;
    }
    // handle negative numbers
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c; // not a number
    }
    if (c == '-') {
        if (isdigit(c = getchar()) || c == '.') {
            *(++s) = c;
        } else {
            if (c != EOF) {
                ungetc(c, stdin);
            }
            return '-';
        }
    }
    if (isdigit(c)) { // collect integer part
        while (isdigit(*(++s) = c = getchar())) {
            ;
        }
    }
    if (c == '.') { // collect fraction part
        while (isdigit(*(++s) = c = getchar())) {
            ;
        }
    }
    *s = '\0';
    if (c != EOF) {
        ungetc(c, stdin);
    }
    return 0;
}