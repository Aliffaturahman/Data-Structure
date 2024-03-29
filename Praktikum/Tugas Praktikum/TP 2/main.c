/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 2 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main(){
    data input; // kontainer input yang berisi makanan, rating, dan harga
    list L;     // list l yang berisikan elemen
    
    createList(&L); // membuat list
    
    do{
        scanf("%s", &input.makanan);                                // meminta masukkan nama makanan

        if(strcmp(input.makanan, "udah") != 0){                     // jika syarat belum tercapai atau nama makanan bukan akhir ("udah") 
            scanf("%f %d", &input.rating, &input.harga);            // meminta masukkan rating dan harga
            addFirst(input.makanan, input.rating, input.harga, &L); // masuk prosedur addfirst
        }
    } while(strcmp(input.makanan, "udah") != 0);                    // perulangan ketika makanan belum mencapai akhir


    printf("===========================================\n");
    printf("|----- List Makanan Sebelum difilter -----|\n");        // syarat pertama
    sortRating(&L);                                                 // sorting list berdasarkan rating
    printElemen(L);                                                 // menampilkan seluruh elemen

    printf("|--------- Makanan yang dihapus ----------|\n");        // syarat kedua
    delElemen(&L);                                                  // menghapus elemen yang panjang katanya ganjil

    printf("|----- List Makanan Setelah difilter -----|\n");        // syarat ketiga
    sortHarga(&L);                                                  // sorting berdasarkan harga
    afterFiltered(L);                                               // menampilkan elemen sisa setelah di filter
    printf("===========================================\n");

    return 0;
}