/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 1 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main(){
    list L;         // bungkusan list
    Jujutsu data;   // bungkusan kontainer data

    int totalPower = 0; // variabel untuk menampung jumlah power seluruhnya

    createList(&L); // membuat list

    do{                                                             // lakukan input data ...
        scanf(" %s", data.Penyihir);                                // meminta masukkan nama penyihir    
        
        if(strcmp(data.Penyihir, "DOMAIN_EXPANSION") != 0){         // jika nama penyihir tidak sama dengan "DOMAIN_EXPANSION"
            scanf("%s %d", data.Technique, &data.Power);            // masukkan masukan selanjutnya

            addLast(data, &L); // memanggil prosedur addlast untuk penambahan list di akhir
            totalPower += data.Power;                               // menjumlahkan data power kedalam total power
        }
    }while(strcmp(data.Penyihir, "DOMAIN_EXPANSION") != 0);         // ... selama nama penyihir bukan "DOMAIN_EXPANSION" 

    char sorting[10];           // variabel untuk jenis sorting berdasarkan "Technique" atau "Power"
    scanf("%s", &sorting);      // masukkan jenis sortingnya

    char sort_method[10];       // variabel untuk metode sorting berupa "Ascending" atau "Descending"
    scanf("%s", &sort_method);  // masukkan metode sortingnya

    if(strcmp(sorting, "Technique") == 0){              // jika list di sorting berdasarkan "Technique"
        if(strcmp(sort_method, "Ascend") == 0){         // dan jika di sorting secara "Ascending"
            sortingTA(&L);                              // memanggil prosedur "sorting technique ascend"
        }
        else if(strcmp(sort_method, "Descend") == 0){   // dan jika di sorting secara "Descending"
            sortingTD(&L);                              // memanggil prosedur "sorting technique descend"
        }
    }
    else if(strcmp(sorting, "Power") == 0){             // jika list di sorting berdasarkan "Power"
        if(strcmp(sort_method, "Ascend") == 0){         // dan jika di sorting secara "Ascending"
            sortingPA(&L);                              // memanggil prosedur "sorting power ascend"
        }
        else if(strcmp(sort_method, "Descend") == 0){   // dan jika di sorting secara "Descending"
            sortingPD(&L);                              // memanggil prosedur "sorting power descend"
        }
    }
    printElement(L);    // memanggil prosedur untuk menampilkan seluruh elemen

    if(totalPower % 2 == 0){        // jika total powernya genap
        printf("LOSE\n");           // maka penyihir akan kalah
    }
    else if(totalPower % 2 != 0){   // jika total powernya ganjil
        printf("WIN\n");            // maka penyihir akan menang
    }
    
    return 0;
}