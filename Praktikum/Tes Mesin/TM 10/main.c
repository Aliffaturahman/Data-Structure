/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 10 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);
    int i = 1;
    
    do
    {
        addSimpul(i, &G);
        i++;
    } while (i != 9);

    // memasukan jalur ke simpul simpul
    simpul *begin = findSimpul(1, G);       // node = 1
    simpul *end = findSimpul(2, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(7, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(5, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(4, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(2, G);               // node = 2
    end = findSimpul(3, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(6, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    
    begin = findSimpul(3, G);               // node = 3
    end = findSimpul(8, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(4, G);               // node = 4
    end = findSimpul(7, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(6, G);               // node = 6
    end = findSimpul(8, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    printGraph(G);
    printf("==============\n");

    int hapus;
    scanf("%d", &hapus);

    begin = findSimpul(hapus, G);
    if (begin != NULL)
    {
        delSimpul(hapus, &G);
    }
    printGraph(G);
    return 0;
}