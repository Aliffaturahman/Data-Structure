/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 3 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    list L;
    infoKendaraan data[100];

    createList(&L);

	for(int i = 0; i < 7; i++){
    	scanf("%s %s %d %s", &data[i].kendaraan, &data[i].plat, &data[i].tahun, &data[i].pemilik);
    }

    printf("Data Kendaraan\n");

    addFirst(data[0].kendaraan, data[0].plat, data[0].tahun, data[0].pemilik, &L);

    addLast(data[1].kendaraan, data[1].plat, data[1].tahun, data[1].pemilik, &L);
	
    addAfter(L.first, data[2].kendaraan, data[2].plat, data[2].tahun, data[2].pemilik, &L);
	
    printElemen(L);
    printf("========================================\n");

    delAfter(L.data[L.first].next, &L);

	addAfter(L.first, data[3].kendaraan, data[3].plat, data[3].tahun, data[3].pemilik, &L);

	addAfter(L.data[L.tail].prev, data[4].kendaraan, data[4].plat, data[4].tahun, data[4].pemilik, &L);

	delFirst(&L);

    printElemen(L);
    printf("========================================\n");

    addFirst(data[5].kendaraan, data[5].plat, data[5].tahun, data[5].pemilik, &L);
    
    addAfter(L.data[L.first].next, data[6].kendaraan, data[6].plat, data[6].tahun, data[6].pemilik, &L);
    
	delLast(&L);
    printreverse(L);
    printf("****************************************\n");

    delAll(&L);
    printElemen(L);
    printf("========================================\n");

    return 0;
}