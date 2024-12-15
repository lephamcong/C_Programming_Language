/*
Exercise 1-23. 
    Write a program to remove all comments from a C program. Don't forget to
    handle quoted strings and character constants properly. C comments don't nest. 
*/

#include <stdio.h>

int main()
{
    int c;
    int c_next;
    int in_quotes = 0;
    int in_block_comment = 0;
    int in_single_line_comment = 0;
    int current_quote;

    c = getchar();
    while (c != EOF) {
        if (!in_block_comment && !in_quotes && !in_single_line_comment) {
            if (c == '\'' || c == '"') {
                in_quotes = 1;
                current_quote = c;
                putchar(c);
            }
            else if (c == '/') {
                c_next = getchar();
                if (c_next == '*') {
                    in_block_comment = 1; 
                }
                else if (c_next == '/') {
                    in_single_line_comment = 1; 
                }
                else {
                    putchar(c); 
                    c = c_next;
                    continue;
                }
            }
            else {
                putchar(c);
            }
        }
        else if (in_block_comment) {
            if (c == '*') {
                c_next = getchar();
                if (c_next == '/') {
                    in_block_comment = 0; 
                }
                else {
                    c = c_next;
                    continue;
                }
            }
        }
        else if (in_single_line_comment) {
            if (c == '\n') {
                in_single_line_comment = 0; 
                putchar(c);
            }
        }
        else if (in_quotes) {
            if (c == '\\') {
                putchar(c);
                c = getchar();
            }
            else if (c == current_quote) {
                in_quotes = 0; 
            }
            putchar(c);
        }

        c = getchar();
    }

    return 0;
}