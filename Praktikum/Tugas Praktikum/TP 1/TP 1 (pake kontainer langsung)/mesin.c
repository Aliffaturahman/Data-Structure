/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 1 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

/* Prosedur Untuk Membuat List Baru */
void createList(list *L){
    (*L).first = NULL;
}

/* Prosedur Untuk Menghitung Elemen */
int countElement(list L){
    int hasil = 0;

    if(L.first != NULL){
        /*list tidak kosong*/

        elemen* tunjuk;

        /*inisialisasi*/
        tunjuk = L.first;

        while(tunjuk != NULL){
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

/* Prosedur Untuk Menambahkan Elemen Di Awal */
void addFirst(Jujutsu data, list *L){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));

    // copy data
    baru->kontainer = data;

    if((*L).first == NULL){
        baru->next = NULL;
    }
    else{
        baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL;
}

/* Prosedur Untuk Menambahkan Elemen Di Tengah */
void addAfter(elemen *prev, Jujutsu data, list *L){
    elemen *baru; // deklarasi pointer baru
    baru = (elemen *)malloc(sizeof(elemen));
    
    // copy data
    baru->kontainer = data;

    if(prev->next == NULL)  // kondisi ketika menambahkan elemen baru sebagai elemen terakhir
        baru->next = NULL;
    else{                    // kondisi ketika menambahkan elemen baru sebagai elemen pada index tertentu
        baru->next = prev->next;
    }

    prev->next = baru; // Menyesuaikan dengan perubahan struktur elemen
    baru = NULL;
}

/* Prosedur Untuk Menambahkan Elemen Di Akhir */
void addLast(Jujutsu data, list *L){
    if((*L).first == NULL){
        /*proses jika list masih kosong*/
        addFirst(data, L);
    }
    else{
        /*jika list tidak kosong
        /*mencari elemen terakhir list*/
        elemen *prev = (*L).first;
        
        while(prev->next != NULL){
            /*iterasi*/
            prev = prev->next;
        }
        addAfter(prev, data, L);
    }
}

/* Prosedur Untuk Menghapus Elemen Di Awal */
void delFirst(list *L){
    if((*L).first != NULL){
        /*jika list bukan list kosong*/
        elemen* hapus = (*L).first;
        
        if(countElement(*L) == 1){
            (*L).first = NULL;
        }
        else{
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

/* Prosedur Untuk Menghapus Elemen Di Tengah */
void delAfter(elemen *prev, list *L){
    elemen *hapus = prev->next;
    
    if(hapus != NULL){
        if(hapus->next == NULL){
            prev->next = NULL;
        }
        else{
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

/* Prosedur Untuk Menghapus Elemen Di Akhir */
void delLast(list *L){
    if((*L).first != NULL){
        /*jika list tidak kosong*/
        if(countElement(*L) == 1){
            /*list terdiri dari satu elemen*/
            delFirst(L);
        }
        else{
            /*mencari elemen terakhir list*/
            elemen *last = (*L).first;
            elemen *prev;

            while(last->next != NULL){
                /*iterasi*/
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

/* Prosedur Untuk Menghapus Seluruh Elemen */
void delAll(list *L){
    if(countElement(*L) != 0){
        int i;

        for(i = countElement(*L); i>= 1; i--){
            /*proses menghapus elemen list*/
            delLast(L);
        }
    }
}

/* Prosedur Untuk Menampilkan List Elemen */
void printElement(list L){
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* tunjuk = L.first;
    
        int i = 1;
    
        while(tunjuk != NULL){
            /*proses*/
            printf("%s %s %d\n", tunjuk->kontainer.Penyihir, tunjuk->kontainer.Technique, tunjuk->kontainer.Power);

            /*iterasi*/
            tunjuk = tunjuk->next;
            i = i + 1;
        }
    }
}

/* Prosedur Untuk Sorting Teknik Secara Ascending */
void sortingTA(list *L){
    elemen *tmp, *current, *nextone;
    int i, j;

    for(i = 0; i < countElement(*L); i++){
        current = L->first;
        
        for(j = 0; j < countElement(*L) - 1 - i; j++){
            if(strcmp(current->kontainer.Technique, current->next->kontainer.Technique) > 0){
                nextone = current->next;
                current->next = nextone->next;
                nextone->next = current;
                
                if(current == L->first){
                    L->first = nextone;
                    current = nextone;
                }
                else{
                    current = nextone;
                    tmp->next = nextone;
                }
            }
            tmp = current;
            current = current->next;
        }
    }
}

/* Prosedur Untuk Sorting Teknik Secara Descending */
void sortingTD(list *L){
    elemen *tmp, *current, *nextone;
    int i, j;

    for(i = 0; i < countElement(*L); i++){
        current = L->first;
        
        for(j = 0; j < countElement(*L) - 1 - i; j++){
            if(strcmp(current->kontainer.Technique, current->next->kontainer.Technique) < 0){
                nextone = current->next;
                current->next = nextone->next;
                nextone->next = current;
                
                if(current == L->first){
                    L->first = nextone;
                    current = nextone;
                }
                else{
                    current = nextone;
                    tmp->next = nextone;
                }
            }
            tmp = current;
            current = current->next;
        }
    }
}

/* Prosedur Untuk Sorting Power Secara Ascending */
void sortingPA(list *L){
    elemen *tmp, *current, *nextone;
    int i, j;

    for(i = 0; i < countElement(*L); i++){
        current = L->first;
        
        for(j = 0; j < countElement(*L) - 1 - i; j++){
            if(current->kontainer.Power > current->next->kontainer.Power){
                nextone = current->next;
                current->next = nextone->next;
                nextone->next = current;
                
                if(current == L->first){
                    L->first = nextone;
                    current = nextone;
                }
                else{
                    current = nextone;
                    tmp->next = nextone;
                }
            }
            tmp = current;
            current = current->next;
        }
    }
}

/* Prosedur Untuk Sorting Power Secara Descending */
void sortingPD(list *L){
    elemen *tmp, *current, *nextone;
    int i, j;

    for(i = 0; i < countElement(*L); i++){
        current = L->first;
        
        for(j = 0; j < countElement(*L) - 1 - i; j++){
            if(current->kontainer.Power < current->next->kontainer.Power){
                nextone = current->next;
                current->next = nextone->next;
                nextone->next = current;
                
                if(current == L->first){
                    L->first = nextone;
                    current = nextone;
                }
                else{
                    current = nextone;
                    tmp->next = nextone;
                }
            }
            tmp = current;
            current = current->next;
        }
    }
}