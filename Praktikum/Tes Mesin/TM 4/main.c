/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 4 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{

    Data input;
    list L;

    createList(&L);

    printf("Data Kontak\n");
    printf("()()()()()()()()()()()()()()()()\n");

    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addLast(input.nama, input.telepon, input.email, &L);
    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addFirst(input.nama, input.telepon, input.email, &L);
    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addBefore(L.first->next, input.nama, input.telepon, input.email, &L);

    printElemen(L);
    printf("()()()()()()()()()()()()()()()()\n");

    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addAfter(L.first->next, input.nama, input.telepon, input.email, &L);

    delAfter(L.first, &L);

    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addAfter(L.first, input.nama, input.telepon, input.email, &L);
    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addBefore(L.tail, input.nama, input.telepon, input.email, &L);
    
    delFirst(&L);

    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addAfter(L.tail, input.nama, input.telepon, input.email, &L);
    
    printElemen(L);
    printf(")()()()()()()()()()()()()()()()(\n");

    delLast(&L);

    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addBefore(L.first, input.nama, input.telepon, input.email, &L);
    
    delAfter(L.first, &L);

    scanf("%s %d %s", &input.nama, &input.telepon, &input.email);
    addLast(input.nama, input.telepon, input.email, &L);
    
    printreverse(L);
    printf("()()()()()()()()()()()()()()()()\n");

    delAll(&L);
    printElemen(L);

    return 0;
}