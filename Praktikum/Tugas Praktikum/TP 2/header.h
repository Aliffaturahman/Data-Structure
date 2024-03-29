/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 2 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char makanan[50];   // variabel untuk nama makanan
    float rating;       // variabel untuk rating makanan
    int harga;          // variabel untuk harga makanan
} data;

typedef struct elmt *alamatelmt;

typedef struct elmt{
    data kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char makanan[], float rating, int harga, list *L);

void delFirst(list *L);
void delAfter(elemen *before, list *L);

void sortRating(list *L);   // prosedur untuk sort berdasarkan rating
void sortHarga(list *L);    // prosedur untuk sort berdasarkan harga

void printElemen(list L);   // prosedur untuk menampilkan elemen
void delElemen(list *L);    // prosedur untuk menghapus elemen yang panjang katanya ganjil
void afterFiltered(list L); // prosedur untuk menampilkan elemen yang sudah di filter (genap)