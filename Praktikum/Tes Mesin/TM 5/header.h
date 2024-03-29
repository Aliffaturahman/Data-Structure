/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 5 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char label[50];
    char kode[50];
} box;

typedef struct
{
    char nama[50];

} barang;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    barang kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr
{
    box kontainer;
    eKolom *col;
    alamatebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char label[], char kode[], list *L);
void addFirstK(char nama[], eBaris *L);
void addAfterB(eBaris *prev, char label[], char kode[]);
void addAfterK(eKolom *prev, char nama[]);
void addLastB(char label[], char kode[], list *L);
void addLastK(char nama[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);