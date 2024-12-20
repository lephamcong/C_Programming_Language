/*
Exercise 6-5. 
    Write a function undef that will remove a name and definition from the table
    maintained by lookup and install.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table   */

unsigned hash(char *);
struct nlist *lookup(char *);
char *my_strdup(char *);
struct nlist *install(char *, char *);
void undef(char *name);

int main() {
    
    install("var1", "10");
    install("var2", "20");

    
    printf("var1: %s\n", lookup("var1") ? lookup("var1")->defn : "not found");
    printf("var2: %s\n", lookup("var2") ? lookup("var2")->defn : "not found");

    // delete var1
    undef("var1");

    // check after delete
    printf("var1 after delete: %s\n", lookup("var1") ? lookup("var1")->defn : "not found");
    printf("var2 after delete: %s\n", lookup("var2") ? lookup("var2")->defn : "not found");

    return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval = 0;
    for ( ; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;  /* found */
        }
    }
    return NULL;  /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = my_strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else { /* already here */
        free((void *) np->defn);  /* free previous defn */
    }

    if ((np->defn = my_strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}

/* my_strdup: make a duplicate of s */
char *my_strdup(char *s) {
    char *p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

/* undef: remove name and definition from the table */
void undef(char *name) {
    struct nlist *np, *prev = NULL;
    unsigned hashval = hash(name);

    for (np = hashtab[hashval]; np != NULL; prev = np, np = np->next) {
        if (strcmp(np->name, name) == 0) {
            if (prev == NULL) {
                hashtab[hashval] = np->next;  /* delete top element*/
            } else {
                prev->next = np->next;  /* delete midle or end element*/
            }
            free(np->name);  /* free memory for name    */
            free(np->defn);  /* free memory for definition  */
            free(np);         /* free memory for element */
            return;
        }
    }
}


