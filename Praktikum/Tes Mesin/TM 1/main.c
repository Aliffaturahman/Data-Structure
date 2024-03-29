/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 1 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main(){
    list L;
    onePiece pulau[50];

    createList(&L);

    for(int i = 0; i < 5; i++){
        scanf("%s %d %f", &pulau[i].nama, &pulau[i].populasi, &pulau[i].luas);
    }

    // printf("\n");

    addFirst(pulau[0].nama, pulau[0].populasi, pulau[0].luas, &L);
    addFirst(pulau[1].nama, pulau[1].populasi, pulau[1].luas, &L);
    addAfter(L.first, pulau[2].nama, pulau[2].populasi, pulau[2].luas, &L);
    printElement(L);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    delLast(&L);
    addAfter(L.data[L.first].next, pulau[3].nama, pulau[3].populasi, pulau[3].luas, &L);
    addLast(pulau[4].nama, pulau[4].populasi, pulau[4].luas, &L);
    printElement(L);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);
    printElement(L);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    delLast(&L);
    printElement(L);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}