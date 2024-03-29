/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 6 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    judulBuku input;
    stack S1;
    stack S2;

    createEmpty(&S1);
    createEmpty(&S2);

    printf("==========================\n");

    printf("Buku di S1:\n");
    printStack(S1);
    printf("\nBuku di S2:\n");
    printStack(S2);

    printf("==========================\n");

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);

    printf("Buku di S1:\n");
    printStack(S1);
    printf("\nBuku di S2:\n");
    printStack(S2);

    printf("==========================\n");

    pop(&S1);
    pindah_pop(&S2, &S1);

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);

    pop(&S2);
    pindah_pop(&S1, &S2);

    printf("Buku di S1:\n");
    printStack(S1);
    printf("\nBuku di S2:\n");
    printStack(S2);
    
    printf("==========================\n");

    return 0;
}