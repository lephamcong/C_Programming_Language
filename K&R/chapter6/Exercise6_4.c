/*
Exercise 6-4. 
    Write a program that prints the distinct words in its input sorted into decreasing
    order of frequency of occurrence. Precede each word by its count. 
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXNODES 1000

struct tnode { /* the tree node */
    char *word; /* points to the text */
    int count; /* number of occurrences */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);

char *my_strdup(char *); 
void treeprint(struct tnode *);
void sortprint(struct tnode *);
int getword(char *, int);
int compare(const void *, const void *);
void addnode(struct tnode *);

struct tnode *nodes[MAXNODES];
int node_count = 0;

/* word frequency count */
int main() {
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    printf("\n\n");
    sortprint(root);
    return 0;
}

/*  addtree: add a node with w, at or below p   */
struct tnode *addtree (struct tnode *p, char *w) {
    int cond;

    if (p == NULL) { /* a new word has arrived*/
        p = talloc(); /* make a new node */
        p->word = my_strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) { /* repeated word */
        p->count++;
    } else if (cond < 0) { /* less than into left subtree */
        p->left = addtree(p->left, w);
    } else {    /* greater than into right subtree */
        p->right = addtree(p->right, w);
    }
    return p;
}

/*  treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* addnode: add node to list nodes */
void addnode(struct tnode *p) {
    if (node_count < MAXNODES) {
        if (p != NULL) {
            nodes[node_count++] = p;
            addnode(p->left);
            addnode(p->right);
        }
    } else {
        printf("Error: MAXNODES exceeded\n");
        exit(1);
    }
}

/*  sortprint: prints the distinct words in its input sorted into decreasing order of count */
void sortprint(struct tnode *root) {
    addnode(root);
    qsort(nodes, node_count, sizeof(struct tnode *), compare);
    for (int i = 0; i < node_count; i++) {
        printf("%4d %s\n", nodes[i]->count, nodes[i]->word);
    }
}


/* compare: compare function for qsort */
int compare(const void *a, const void *b) {
    struct tnode *node1 = *(struct tnode **) a;
    struct tnode *node2 = *(struct tnode **) b;
    return node2->count - node1->count;
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

/*  getword: get next word or character from input  */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getchar())) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c) && c != '_' && c != '#') {
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
