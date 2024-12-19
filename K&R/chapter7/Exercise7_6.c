#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024 // Maximum line length

void compare_files(const char *file1, const char *file2) {
    FILE *fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];
    int line_number = 0;

    // Open files
    if ((fp1 = fopen(file1, "r")) == NULL) {
        perror("Error opening first file");
        exit(EXIT_FAILURE);
    }

    if ((fp2 = fopen(file2, "r")) == NULL) {
        perror("Error opening second file");
        fclose(fp1);
        exit(EXIT_FAILURE);
    }

    // Read and compare lines
    while (fgets(line1, MAXLINE, fp1) != NULL && fgets(line2, MAXLINE, fp2) != NULL) {
        line_number++;

        // Compare lines
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %d:\n", line_number);
            printf("File 1: %s", line1);
            printf("File 2: %s", line2);
            fclose(fp1);
            fclose(fp2);
            return;
        }
    }

    // Check for EOF mismatch
    if (fgets(line1, MAXLINE, fp1) != NULL || fgets(line2, MAXLINE, fp2) != NULL) {
        line_number++;
        printf("Files differ at line %d:\n", line_number);
        if (line1[0] != '\0') {
            printf("File 1: %s", line1);
        } else {
            printf("File 1: (no more lines)\n");
        }
        if (line2[0] != '\0') {
            printf("File 2: %s", line2);
        } else {
            printf("File 2: (no more lines)\n");
        }
        fclose(fp1);
        fclose(fp2);
        return;
    }

    // Files are identical
    printf("The files are identical.\n");

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    compare_files(argv[1], argv[2]);
    return 0;
}
