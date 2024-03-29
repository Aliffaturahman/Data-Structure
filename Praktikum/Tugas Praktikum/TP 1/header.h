/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 1 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char Penyihir[100];     // variabel untuk nama penyihir
    char Technique[100];    // variabel untuk teknik kutukan
    int Power;              // variabel untuk kekuatan penyihirnya
}Jujutsu;                   // bungkusan untuk kontainer

typedef struct elmt *elAdd; // bungkusan untuk alamat elemen

typedef struct elmt{
    Jujutsu kontainer;
    elAdd next;
}elemen;                    // bungkusan untuk elemen

typedef struct{
    elemen *first;
}list;                      // bungkusan untuk list

void createList(list *L);                                                           // Prosedur Untuk Membuat List Baru
int countElement(list L);                                                           // Prosedur Untuk Menghitung Elemen

void addFirst(char Penyihir[], char Technique[], int Power, list *L);               // Prosedur Untuk Menambahkan Elemen Di Awal
void addAfter(elemen *prev, char Penyihir[], char Technique[], int Power, list *L); // Prosedur Untuk Menambahkan Elemen Di Tengah
void addLast(char Penyihir[], char Technique[], int Power, list *L);                // Prosedur Untuk Menambahkan Elemen Di Akhir

void delFirst(list *L);                                                             // Prosedur Untuk Menghapus Elemen Di Awal
void delAfter(elemen *prev, list *L);                                               // Prosedur Untuk Menghapus Elemen Di Tengah
void delLast(list *L);                                                              // Prosedur Untuk Menghapus Elemen Di Akhir
void delAll(list *L);                                                               // Prosedur Untuk Menghapus Seluruh Elemen

void printElement(list L);                                                          // Prosedur Untuk Menampilkan List Elemen

/* Sorting Menggunakan Bubble Sort */

void sortingTA(list *L);    // Prosedur Untuk Sorting Teknik Secara Ascending
void sortingTD(list *L);    // Prosedur Untuk Sorting Teknik Secara Descending
void sortingPA(list *L);    // Prosedur Untuk Sorting Power Secara Ascending
void sortingPD(list *L);    // Prosedur Untuk Sorting Power Secara Descending