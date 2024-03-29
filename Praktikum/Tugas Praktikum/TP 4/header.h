/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 4 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nama[100];
} isiKontainer;

typedef struct smp *alamatsimpul;
typedef struct smp{
    isiKontainer kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct{
    simpul *root;
} tree;

void makeTree(isiKontainer kontainer, tree *T);         // prosedur untuk membuat tree
void addChild(isiKontainer kontainer, simpul *root);    // prosedur untuk menambahkan node pada tree
void delAll(simpul *root);                              // prosedur untuk menghapus semua node dibawahnya dari suatu node
void delChild(simpul *tujuan, simpul *root);            // prosedur untuk menghapus child dari suatu node
simpul *findSimpul(char tujuan[], simpul *root);        // fungsi untuk mencari suatu node
void printTreePreOrder(simpul *root, int panah);        // prosedur untuk menampilkan tree secara pre order
void printTreePostOrder(simpul *root, int n);           // prosedur untuk menampilkan tree secara post order 