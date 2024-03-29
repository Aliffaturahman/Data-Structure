/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 7 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

void createEmpty(queue *Q1){
    (*Q1).first = NULL;
    (*Q1).last = NULL;
}

int isEmpty(queue Q1){
    int hasil = 0;

    if(Q1.first == NULL){
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q1){
    int hasil = 0;
    
    if(Q1.first != NULL){
        /* queue tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = Q1.first;

        while(bantu != NULL){
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(char nama[], char nomor[], queue *Q1){
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nomor, nomor);
    // baru->kontainer.nomor = nomor;
    baru->next = NULL;
    
    if((*Q1).first == NULL){
        (*Q1).first = baru;
    }
    else{
        (*Q1).last->next = baru;
    }
    
    (*Q1).last = baru;
    baru = NULL;
}

void addPriority(char nama[], char nomor[], int priority, queue *Q1){
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nomor, nomor);
    // baru->kontainer.nomor = nomor;
    baru->next = NULL;
    
    if((*Q1).first == NULL){
        (*Q1).first = baru;
        (*Q1).last = baru;
    }
    else{
        if(priority == 1){
            baru->next = (*Q1).first;
            (*Q1).first = baru;
        }
        else if(priority > countElement(*Q1)){
            add(nama, nomor, Q1);
        }
        else{
            elemen *bantu = (*Q1).first;
            int i = 1;
            
            while(bantu != NULL){
                if(i == priority - 1){
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                bantu = bantu->next;
                i++;
            }
        }
    }
    baru = NULL;
}

void del(queue *Q1){
    if((*Q1).first != NULL){
        /* jika queue bukan queue kosong */
        elemen *hapus = (*Q1).first;
        
        if(countElement(*Q1) == 1){
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else{
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void pindah(queue *Q1, queue *Q2){
    if((*Q1).first != NULL){
        elemen *hapus = (*Q1).first;
        add(hapus->kontainer.nama, hapus->kontainer.nomor, Q2);
        
        if(countElement(*Q1) == 1){
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else{
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void pindahverpointer(queue *Q1, queue *Q2){
    if(Q1->first != NULL){
        /* jika queue bukan queue kosong */
        elemen *hapus = Q1->first;
        
        if(countElement(*Q1) == 1){
            Q1->first = NULL;
            Q1->last = NULL;
        }
        else{
            Q1->first = Q1->first->next;
            hapus->next = NULL;
        }

        if((*Q2).first == NULL){
            (*Q2).first = hapus;
        }
        else{
            (*Q2).last->next = hapus;
        }

        (*Q2).last = hapus;
        hapus = NULL;
    }
}

void printQueue(queue Q1){
    if(Q1.first != NULL){
        elemen *bantu = Q1.first;

        while(bantu != NULL){
            printf("%s ", bantu->kontainer.nama);
            printf("%s\n", bantu->kontainer.nomor);

            /* iterasi */
            bantu = bantu->next;
        }
        printf("******************\n");
    }
    else{
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}