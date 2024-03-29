/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 6 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    int harga;
} judulBuku;

typedef struct elmt *alamatelmt;

typedef struct elmt
{
    judulBuku kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nama[], int harga, stack *S);
void pop(stack *S);
void printStack(stack S);
void pindah_pop(stack *S, stack *S2);