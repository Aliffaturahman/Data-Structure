/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 5 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct{
    simpul *first;
} graph;

void createEmpty(graph *G);                                                             // prosedur untuk membuat graph
void addSimpul(char c, graph *G);                                                       // prosedur untuk menambah simpul
void addJalur(simpul *awal, simpul *tujuan, int beban);                                 // prosedur untuk menambah jalur
simpul *findSimpul(char c, graph G);                                                    // struct untuk mencari simpul
void printGraph(graph G);                                                               // prosedur untuk print graph
void search(char cawal, char ctujuan, simpul *awal, int beban, char path[], int index); // prosedur untuk mencari jalan
void keep_route_awal(char c);                                                           // prosedur untuk print char source