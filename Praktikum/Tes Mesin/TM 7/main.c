/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 7 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    queue Q1;
    queue Q2;
    createEmpty(&Q1);
    createEmpty(&Q2);

    game input;

    scanf("%s %s", &input.nama, &input.nomor);
    add(input.nama, input.nomor, &Q1);

    scanf("%s %s", &input.nama, &input.nomor);
    add(input.nama, input.nomor, &Q1);

    scanf("%s %s", &input.nama, &input.nomor);
    addPriority(input.nama, input.nomor, 2, &Q1);
    
    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q1);

    pindahverpointer(&Q1, &Q2);

    printf("Queue 1\n");
    printQueue(Q1);

    printf("Queue 2\n");
    printQueue(Q2);

    scanf("%s %s", &input.nama, &input.nomor);
    addPriority(input.nama, input.nomor, 1, &Q1);

    scanf("%s %s", &input.nama, &input.nomor);
    addPriority(input.nama, input.nomor, 99, &Q1);

    printf("Queue 1\n");
    printQueue(Q1);

    pindahverpointer(&Q1, &Q2);
    pindahverpointer(&Q1, &Q2);

    scanf("%s %s", &input.nama, &input.nomor);
    add(input.nama, input.nomor, &Q1);

    printf("Queue 1\n");
    printQueue(Q1);

    printf("Queue 2\n");
    printQueue(Q2);
}