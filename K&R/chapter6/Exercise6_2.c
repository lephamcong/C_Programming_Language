/*
Exercise 6-2. 
    Write a program that reads a C program and prints in alphabetical order each
    group of variable names that are identical in the first 6 characters, but different somewhere
    thereafter. Don't count words within strings and comments. Make 6 a parameter that can be
    set from the command line.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode { /* the tree node */
    char *word; /* points to the text */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
char *my_strdup(char *); 
void treeprint_prefix(struct tnode *, int);
int getword(char *, int);
int prefix_length;

int main(int argc, char *argv[]) {
    struct tnode *root = NULL;
    char word[MAXWORD];
    
    if (argc != 2) {
        printf("Usage: ./Exercise6_2 <number>\n");
        return 1;
    } else {
        prefix_length = atoi(argv[1]);
        if (prefix_length < 1) {
            printf("Usage: ./Exercise6_2 <number>\n");
            return 1;
        }

        // Read words and add them to the tree
        while (getword(word, MAXWORD) != EOF) {
            if (isalpha(word[0])) {  // Only add alphabetic words
                root = addtree(root, word);
            }
        }

        treeprint_prefix(root, prefix_length);  // Print words based on prefix length
        return 0;
    }
}

/*  addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) { /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = my_strdup(w);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) { /* repeated word */
        return p;
    } else if (cond < 0) { /* less than, go to left subtree */
        p->left = addtree(p->left, w);
    } else { /* greater than, go to right subtree */
        p->right = addtree(p->right, w);
    }
    return p;
}

/* treeprint_prefix: print words with common prefix */
void treeprint_prefix(struct tnode *p, int prefix_length) {
    static char last_prefix[MAXWORD] = {0};  // Static to maintain the prefix across recursive calls
    if (p != NULL) {
        treeprint_prefix(p->left, prefix_length);  // Traverse left subtree

        char prefix[MAXWORD];
        strncpy(prefix, p->word, prefix_length);
        prefix[prefix_length] = '\0';

        // Compare prefix with last processed prefix
        if (strncmp(prefix, last_prefix, prefix_length) == 0) {
            printf("%s\n", p->word);
        } else if (last_prefix[0] != '\0') {
            printf("\n");  // New group of words with different prefix
        }

        strncpy(last_prefix, prefix, prefix_length);  // Update last_prefix

        treeprint_prefix(p->right, prefix_length);  // Traverse right subtree
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* my_strdup: make a duplicate of s */
char *my_strdup(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;
    int in_string = 0, in_comment = 0;

    while (isspace(c = getchar())) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (c == '"') {  // Handle string literals
        in_string = 1;
        while ((c = getchar()) != EOF) {
            if (c == '"') {
                in_string = 0;
                break;
            }
            *w++ = c;
        }
    } else if (c == '/' && (c = getchar()) == '*') {  // Handle block comments
        in_comment = 1;
        while ((c = getchar()) != EOF) {
            if (c == '*' && (c = getchar()) == '/') {
                in_comment = 0;
                break;
            }
        }
    } else if (c == '/' && (c = getchar()) == '/') {  // Handle line comments
        in_comment = 1;
        while ((c = getchar()) != EOF) {
            if (c == '\n') {
                in_comment = 0;
                break;
            }
        }
    }

    if (!in_string && !in_comment && !isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getchar()) && *w != '_') {
            ungetc(*w, stdin);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
