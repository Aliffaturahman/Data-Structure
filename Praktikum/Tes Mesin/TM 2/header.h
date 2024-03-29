/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 2 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nama[100];
    char grupband[100];
    int tahun;
}isiKontainer;

typedef struct elmt *elAdd;

typedef struct elmt{
    isiKontainer kontainer;
    elAdd next;
}elemen;

typedef struct{
    elemen *first;
}list;

void createList(list *L);
int countEl(list L);
void addFirst(char nama[], char grupband[], int tahun, list *L);
void addAfter(elemen *prev, char nama[], char grupband[], int tahun, list *L);
void addLast(char nama[], char grupband[], int tahun, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);