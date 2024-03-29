/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 9 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char size[50];
} data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    data kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char nama[], char size[], tree *T);
void addChild(char nama[], char size[], simpul *root);
void delAll(simpul *root);
void delChild(simpul *delelte, simpul *root);
simpul *findSimpul(char cari[], simpul *root);
void printTreePreOrder(simpul *root, simpul *root2);
void printTreePostOrder(simpul *root, simpul *root2);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);