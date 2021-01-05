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
int spasiLevel[100];
int masuk;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer[100];
    char bawaan[50][100]; //isi bawaaan
    char parent[100];
    int m; // banyak nya bawaan
    int level;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
    simpul *temp;
} tree;

void makeTree(char c[], tree *T);
void addChild(char c[], simpul *root, int status);
void delAll(simpul **root);
void delChild(char c[], simpul *root);
simpul *findSimpul(char c[], simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2, int status);
void addBawaan(char bawaan[], int k, int m, simpul *root);
void printBawaan(int m, simpul *root);
void ConnectSibling(simpul *root, simpul *smpl);
void sort(simpul *root);
void printSpasi(int level);
void addParent(char parent[], simpul *root);
void migrasi(simpul *root, simpul *root2, simpul *tree);
void aturSpasi(simpul *root);
void aturLevel(simpul *root, simpul *tree);

void resetSpasi(int n);