/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 1 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    int populasi;
    float luas;
}onePiece;

typedef struct{
    onePiece kontainer;
    int next;
}elemen;

typedef struct{
    int first;
    elemen data[5];
}list;

/* Prosedur Untuk Membuat List Baru */
void createList(list *L);
/* Prosedur Untuk Menghitung Elemen */
int countElement(list L);
/* Prosedur Untuk Mengosongkan Elemen */
int emptyElement(list L);
/* Prosedur Untuk Menambahkan Elemen Di Awal */
void addFirst(char nama[], int populasi, float luas, list *L);
/* Prosedur Untuk Menambahkan Elemen Di Tengah */
void addAfter(int prev, char nama[], int populasi, float luas, list *L);
/* Prosedur Untuk Menambahkan Elemen Di Akhir */
void addLast(char nama[], int populasi, float luas, list *L);
/* Prosedur Untuk Menghapus Elemen Di Awal */
void delFirst(list *L);
/* Prosedur Untuk Menghapus Elemen Di Tengah */
void delAfter(int prev, list *L);
/* Prosedur Untuk Menghapus Elemen Di Akhir */
void delLast(list *L);
/* Prosedur Untuk Menampilkan List Elemen */
void printElement(list L);
/* Prosedur Untuk Menghapus Seluruh Elemen */
void delAll(list *L);