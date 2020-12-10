#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer[100];
    char bawaan[50][100];
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char c[], tree *T);
void addChild(char c[], simpul *root);
void delAll(simpul *root);
void delChild(char c[], simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root, int m);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
void addBawaan(char bawaan[], int k, simpul *root);
void printBawaan(int m, simpul *root);