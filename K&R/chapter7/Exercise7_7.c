#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024 // Maximum line length

// Function to find the pattern in a file
void find_pattern(FILE *fp, const char *filename, const char *pattern, int print_filename) {
    char line[MAXLINE];
    int lineno = 0;

    while (fgets(line, MAXLINE, fp) != NULL) {
        lineno++;
        if (strstr(line, pattern) != NULL) {
            if (print_filename) {
                printf("%s:%d: %s\n", filename, lineno, line);
            } else {
                printf("%d: %s\n", lineno, line);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s pattern [file ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pattern = argv[1];
    int files_provided = argc > 2;

    if (files_provided) {
        // Process each file
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "Error: Could not open file %s\n", argv[i]);
                continue;
            }
            find_pattern(fp, argv[i], pattern, files_provided);
            fclose(fp);
        }
    } else {
        // Read from standard input
        find_pattern(stdin, "stdin", pattern, 0);
    }

    return 0;
}
