/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 5 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main(){
    graph G;

    createEmpty(&G);                                    // buat graph

    char start;                                         // variabel char untuk source
    char finish;                                        // variabel char untuk destination
    int i = 0;                                          // variabel untuk iterasi
    int beban;                                          // variabel untuk cost
    int buat_jalur = 0;                                 // variabel untuk masukan jalur sebanyak n
    
    scanf("%d", &buat_jalur);                           // masukan banyak jalur

    do{
        scanf(" %c %c %d", &start, &finish, &beban);    // masukan source, destination, cost
        
        simpul *begin;
        simpul *end;

        begin = findSimpul(start, G);                   // awal dimulai dari start
        end = findSimpul(finish, G);                    // akhir diakhiri dengan finish
        
        if (begin == NULL){                             // jika belum ada maka add simpul sesuai inputan source
        
            addSimpul(start, &G);                       // add simpul
            begin = findSimpul(start, G);
        }

        if (end == NULL){                               // jika belum ada maka add simpul sesuai inputan destination
            addSimpul(finish, &G);                      // add simpul
            end = findSimpul(finish, G);
        }

        /* menambah jalur */
        if ((begin != NULL) && (end != NULL)){
            addJalur(begin, end, beban);
        }

        i++;                                            // iterasi
    } while (i != buat_jalur);                          // selama i tidak sama dengan inputan buat jalur

    char awal;                                          // variabel awal node
    char tujuan;                                        // variabel tujuan node
    
    scanf(" %c %c", &awal, &tujuan);                    // masukan
    
    simpul *mulai = findSimpul(awal, G);

    char path[150];                                     // variabel tampungan
    search(awal, tujuan, mulai, 0, path, 0);            // mencari jalur dan print jalur serta cost

    return 0;
}