/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 3 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    int kode;       // variabel untuk kode buku
    char judul[50]; // variabel untuk judul buku
}buku;

typedef struct elmt *alamatelmt;
typedef struct elmt{
    buku kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen *top;
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);

void push(int kode, char judul[], stack *S);        // prosedur untuk melakukan push (menambahkan) buku kedalam stack
void pop(stack *S);                                 // prosedur untuk melakukan pop (menghapus) buku dari stack

void printBukuFiksi(stack S);                       // prosedur untuk menampilkan stack buku fiksi untuk Rene
void printBukuNonFiksi(stack S);                    // prosedur untuk menampilkan stack buku non-fiksi untuk Alain

void manageStack(stack *S1, stack *S2, stack *S3);  // prosedur untuk memindahkan seluruh jenis buku dari stack gabungan ke stack buku fiksi atau stack non-fiksi