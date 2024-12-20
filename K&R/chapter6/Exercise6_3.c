/*
Exercise 6-3. 
    Write a cross-referencer that prints a list of all words in a document, and for
    each word, a list of the line numbers on which it occurs. Remove noise words like ``the,''
    ``and,'' and so on.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

// List of noise words to exclude
const char *noise_words[] = {"the", "and", "is", "in", "at", "of", "on", "to", "a", NULL};

struct lnode { /* line number list node */
    int line;
    struct lnode *next;
};

struct tnode { /* the tree node */
    char *word; /* points to the text */
    struct lnode *lines; /* list of line numbers */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

struct tnode *addtree(struct tnode *, char *, int);
struct tnode *talloc(void);
struct lnode *addline(struct lnode *, int);
struct lnode *lalloc(int);
char *my_strdup(char *);
void treeprint(struct tnode *);
int getword(char *, int);
int is_noise_word(const char *);

int current_line = 1; /* tracks the current line number */

/* word cross-referencer */
int main(void) {
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && !is_noise_word(word)) {
            root = addtree(root, word, current_line);
        }
    }
    treeprint(root);
    return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int line) {
    int cond;

    if (p == NULL) { /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = my_strdup(w);
        p->lines = lalloc(line); /* create a new line number list */
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) { /* repeated word */
        p->lines = addline(p->lines, line); /* add line number */
    } else if (cond < 0) { /* less than into left subtree */
        p->left = addtree(p->left, w, line);
    } else { /* greater than into right subtree */
        p->right = addtree(p->right, w, line);
    }
    return p;
}

/* addline: add a line number to the line list */
struct lnode *addline(struct lnode *l, int line) {
    struct lnode *current = l;
    while (current != NULL) {
        if (current->line == line) {
            return l; /* line number already exists */
        }
        if (current->next == NULL) {
            break;
        }
        current = current->next;
    }
    current->next = lalloc(line); /* append new line number */
    return l;
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* lalloc: allocate a line number node */
struct lnode *lalloc(int line) {
    struct lnode *ln = (struct lnode *)malloc(sizeof(struct lnode));
    ln->line = line;
    ln->next = NULL;
    return ln;
}

/* my_strdup: make a duplicate of s */
char *my_strdup(char *s) {
    char *p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%s: ", p->word);
        struct lnode *ln = p->lines;
        while (ln != NULL) {
            printf("%d ", ln->line);
            ln = ln->next;
        }
        printf("\n");
        treeprint(p->right);
    }
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getchar())) {
        if (c == '\n') {
            current_line++;
        }
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

/* is_noise_word: check if a word is in the noise list */
int is_noise_word(const char *word) {
    for (int i = 0; noise_words[i] != NULL; i++) {
        if (strcmp(word, noise_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
