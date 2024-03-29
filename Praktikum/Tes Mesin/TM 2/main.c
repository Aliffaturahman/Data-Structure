/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 2 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main(){
    list L;
    isiKontainer data[50];

    createList(&L);
    
    for(int i = 0; i < 6; i++){
        scanf("%s %s %d", &data[i].nama, &data[i].grupband, &data[i].tahun);
    }
    
    addFirst(data[0].nama, data[0].grupband, data[0].tahun, &L);
    addLast(data[1].nama, data[1].grupband, data[1].tahun, &L);
    addAfter(L.first->next, data[2].nama, data[2].grupband, data[2].tahun, &L);
    
    printf(":) :) :) :) :) :) :) :) :) :)\n");
    printElement(L);
    printf(":) :) :) :) :) :) :) :) :) :)\n");
        
    delAfter(L.first->next, &L);
    delLast(&L);

    printElement(L);
    printf(":( :( :( :( :( :( :( :( :( :(\n");
    
    delAll(&L);
    printElement(L);
    printf(":) :) :) :) :) :) :) :) :) :)\n");
    
    addLast(data[3].nama, data[3].grupband, data[3].tahun, &L);
    addFirst(data[4].nama, data[4].grupband, data[4].tahun, &L);
    delFirst(&L);

    printElement(L);
    printf(":) :) :) :) :) :) :) :) :) :)\n");
    
    
    addFirst(data[5].nama, data[5].grupband, data[5].tahun, &L);
    printElement(L);

    return 0;
}