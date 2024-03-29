/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 5 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

void createEmpty(graph *G){
    (*G).first = NULL;
}

void addSimpul(char c, graph *G){
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;

    if ((*G).first == NULL){
        /* jika graf kosong */
        (*G).first = baru;
    }

    else{
        /* menambahkan simpul baru pada akhir graph */
        simpul *last = (*G).first;

        while (last->next != NULL){
            last = last->next;
        }
        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan, int beban){
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    
    baru->kontainer_jalur = beban;
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;
    
    if (awal->arc == NULL){
        /* jika list jalur kosong */
        awal->arc = baru;
    }

    else{
        /* menambahkan jalur baru pada akhir list jalur */
        jalur *last = awal->arc;

        while (last->next_jalur != NULL){
            last = last->next_jalur;
        }
        last->next_jalur = baru;
    }
}

simpul *findSimpul(char c, graph G){
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    
    int ketemu = 0;

    while ((bantu != NULL) && (ketemu == 0)){
        if (bantu->kontainer == c){
            hasil = bantu;
            ketemu = 1;
        }
        else{
            bantu = bantu->next;
        }
    }
    return hasil;
}

void printGraph(graph G){
    simpul *bantu = G.first;
   
    if (bantu != NULL){                                 // cek apakah graf kosong
        while (bantu != NULL){                          // iterasi semua simpul dalam graf  
            printf("Node %c\n", bantu->kontainer);      // print simpul saat ini
            
            jalur *bantu_jalur = bantu->arc;
            
            while (bantu_jalur != NULL){
                /* print tentang jalur, tujuan, dan bobotnya */
                printf("- Jalur %c ke %c bebannya %d\n", bantu->kontainer, bantu_jalur->tujuan->kontainer, bantu_jalur->kontainer_jalur);
                
                bantu_jalur = bantu_jalur->next_jalur;  // pindah ke jalur berikutnya
            }
            bantu = bantu->next;                        // pindah ke simpul berikutnya
        }
    }   
    else{                                               // print teks jika graf kosong
        printf("graf kosong\n");
    }
}


void search(char cawal, char ctujuan, simpul *awal, int beban, char path[], int index){
    jalur *bantu_jalur;

    if (awal != NULL){
        bantu_jalur = awal->arc;
        
        while (bantu_jalur != NULL){
            path[index] = bantu_jalur->tujuan->kontainer;                       // menamnpung jalur
            index++;
            beban += bantu_jalur->kontainer_jalur;                              // menjumlahkan beban sesuai node yang dilewati
            
            if (bantu_jalur->tujuan->kontainer == ctujuan){                     // jika source == destination
                printf("%c ", cawal);                                           // print node awal
                
                for (int j = 0; j < index; j++){
                    printf("%c ", path[j]);                                     // print node selanjutnya sampai tujuan
                }
                printf("%d\n", beban);
            }

            search(cawal, ctujuan, bantu_jalur->tujuan, beban, path, index);    // rekursif
            beban -= bantu_jalur->kontainer_jalur;                              // reset beban
            bantu_jalur = bantu_jalur->next_jalur;                              // iterasi next
            index--;                                                            // index next
        }
    }
    else{                                                                       // print teks jika graf kosong
        printf("ga ada\n");
    }
}

void keep_route_awal(char c){
    printf("%c ", c);
}