/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 7 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nama[50];  // variabel untuk nama anggota dari Survey Corps
    char nomor[20]; // variabel untuk nomor induk anggota
}game;

typedef struct elm *alamatelmt;
typedef struct elm{
    game kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen *first;
    elemen *last;
}queue;

void createEmpty(queue *Q1);
int isEmpty(queue Q1);
int countElement(queue Q1);

/* Prosedur untuk memasukan data ke antrian 1 */
void add(char nama[], char nomor[], queue *Q1);
void addPriority(char nama[], char nomor[], int priority, queue *Q1);   // berdasarkan prioritas

void del(queue *Q1);
void printQueue(queue Q1);                                              // menampilkan antrian

/* Prosedur untuk memindahkan data dari antrian 1 ke antrian 2 */
void pindah(queue *Q1, queue *Q2);
void pindahverpointer(queue *Q1, queue *Q2);