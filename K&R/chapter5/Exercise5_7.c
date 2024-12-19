/*
Exercise 5-7. 
    Rewrite readlines to store lines in an array supplied by main, rather than
    calling alloc to maintain storage. How much faster is the program?

    Answer:
        + Before: 0.000345s
        + After:  0.000616s
        -> code run slower
*/
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXLINES 5000   /*  max #lines to be sorted */
#define MAXLEN 1000     /*  max length of any input line */
#define ALLOCSIZE 10000 /*  size of available space */

char *lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];   /*  storage for alloc */
static char *allocp = allocbuf;    /*  next free position */

int my_getline(char *, int);
char *alloc(int);
void swap(char *v[], int i, int j);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int new_readlines(char *lineptr[], char lines[][MAXLEN], int maxlines);

void qsort(char *lineptr[], int left, int right);

/*  sort input line */
int main() {
    int nlines;     /*  number of input line read   */
    time_t start, end;
    double runningTime;

    start = clock();
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    } else {
        printf("error: input too big to sort\n");
    }
    // char lines[MAXLINES][MAXLEN];
    // if ((nlines = new_readlines(lineptr, lines, MAXLINES)) >= 0) {
    //     qsort(lineptr, 0, nlines - 1);
    //     writelines(lineptr, nlines);
    // } else {
    //     printf("error: input too big to sort\n");
    // }

    end = clock();
    runningTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Running time: %f\n", runningTime);
    return 0;
}

/*  alloc: return pointer to n characters  */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /*  it fits */
        allocp += n;
        return allocp - n;  /*  old p */
    } else {    /*  not enough room */
        return 0;
    }
}

/*  afree: free storage pointed to by p */
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
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

/*  readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';   /*  delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/*  new_redline: store lines in an array supplied by main*/
int new_readlines(char *lineptr[], char lines[][MAXLEN], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = my_getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return -1;
        } else {
            line[len - 1] = '\0';   /*  delete newline */
            strcpy(lines[nlines], line);
            lineptr[nlines++] = lines[nlines];
        }
    }
    return nlines;
}


/*  writelines: write output lines  */
void writelines(char *lineptr[], int lines) {
    int i;
    for (i = 0; i < lines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

/*  qsort: sort v[left] ... v[right] into increasing order  */
void qsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right) {    /*  do nothing if array contains */
        return;             /*  fewer than two elements */
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/*  swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}