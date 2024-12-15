/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally. 
*/
#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
    char s1[] = "a-e9-5";
    char s2[1000];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
            if (s1[i-1] < s1[i+1]) {
                for (char c = s1[i-1] + 1; c <= s1[i+1]; c++) {
                    s2[j++] = c;
                }
            } else {
                for (char c = s1[i-1] -1; c >= s1[i+1]; c--) {
                    s2[j++] = c;
                }
            }
            i++;
        } else {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';
}
