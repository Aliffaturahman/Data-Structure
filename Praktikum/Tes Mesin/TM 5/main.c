/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 5 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    box input;
    barang input2;
    list L;
    
    createList(&L);
    
    int i;
    int n;
    
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%s %s", input.label, input.kode);
        addLastB(input.label, input.kode, &L);
        
        eBaris *pointer;

        if(i == 0){
            pointer = L.first;
        }
        else{
            pointer = pointer->next;
        }

        scanf("%s", &input2.nama);
        addFirstK(input2.nama, pointer);
        scanf("%s", &input2.nama);
        addLastK(input2.nama, pointer);
        scanf("%s", &input2.nama);
        addAfterK(pointer->col->next_kol, input2.nama);
        scanf("%s", &input2.nama);
        addFirstK(input2.nama, pointer);
    }

    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);
    delAllB(&L);
    printElement(L);
    return 0;
}