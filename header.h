/*
Saya  Muhammad Rayhan Fadillah  mengerjakan  evaluasi 
Tugas  Masa  Depan dalam  mata  kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan 
seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int totalSpasi[100];
int flag[50];

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer[100];
    char bawaan[50][100]; //isi bawaaan
    int m;                // banyak nya bawaan
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char c[], tree *T);
void addChild(char c[], simpul *root);
void delAll(simpul **root);
void delChild(char c[], simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
void addBawaan(char bawaan[], int k, int m, simpul *root);
void printBawaan(int m, simpul *root);
void ConnectSibling(simpul *root, simpul *smpl);
void sort(simpul *root);
void printSpasi();