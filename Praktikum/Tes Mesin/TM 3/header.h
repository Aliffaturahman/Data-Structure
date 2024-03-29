/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 3 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char kendaraan[100];
    char plat[100];
    int tahun;
    char pemilik[100];
} infoKendaraan;

typedef struct
{
    infoKendaraan kontainer;
    int prev;
    int next;
} elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char kendaraan[], char plat[], int tahun, char pemilik[], list *L);
void addAfter(int before, char kendaraan[], char plat[], int tahun, char pemilik[], list *L);
void addLast(char kendaraan[], char plat[], int tahun, char pemilik[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElemen(list L);
void delAll(list *L);
void printreverse(list L);