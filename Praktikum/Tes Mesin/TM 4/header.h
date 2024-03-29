/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 4 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    int telepon;
    char email[50];
} Data;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    Data kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], int telepon, char email[], list *L);
void addAfter(elemen *before, char nama[], int telepon, char email[], list *L);
void addBefore(elemen *before, char nama[], int telepon, char email[], list *L);
void addLast(char nama[], int telepon, char email[], list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);
void printElemen(list L);
void printreverse(list L);