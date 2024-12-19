/*
Exercise 5-5. 
    Write versions of the library functions strncpy, strncat, and strncmp, which
    operate on at most the first n characters of their argument strings. For example,
    strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B. 
*/

#include <stdio.h>

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main() {
    char s[100] = "Hello";
    char t[100] = "World";
    int n = 3;
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    // my_strncpy(s, t, n);
    // printf("s: %s\n", s);
    // my_strncat(s, t, n);
    // printf("s: %s\n", s)
    printf("my_strncmp: %d\n", my_strncmp(s, t, n));

    return 0;
}

/*  my_strcpy: copy at most n characters of string t to s; return s. 
    Pad with '\0''s if t has fewer than n characters.  */
void my_strncpy(char *s, char *t, int n) {
    while (n-- > 0 && (*s++ = *t++) != '\0') {
        ;
    }
    if (n > 0) {
        while (n-- > 0) {
            *s++ = '\0';
        }
    } else {
        *s = '\0';
    }
}

/*  my_strncat: concatenate at most n characters of string t to string s,
    terminate s with '\0'; return s. */
void my_strncat(char *s, char *t, int n) {
    char *s_str = s;
    char *t_str = t;
    while (*s_str != '\0') {
        s_str++;
    }
    *s_str++ = ' ';
    while (n-- > 0 && (*s_str++ = *t_str++) != '\0') {
        ;
    }
    if (n > 0) {
        while (n-- > 0) {
            *s_str++ = '\0';
        }
    } else {
        *s_str = '\0';
    }
}

/*  my_strncmp: compare at most n characters of string s to string t; 
    return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct*/
int my_strncmp(char* s, char *t, int n) {
    for ( ; n > 0; s++, t++, n--) {
        if (*s != *t) {
            return *s - *t;
        }
    }
    return 0;
}