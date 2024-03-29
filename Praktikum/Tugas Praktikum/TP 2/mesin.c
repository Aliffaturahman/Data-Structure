/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 2 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;

    if (L.first != NULL)
    {
        // list tidak kosong

        elemen *bantu;

        // inisialisasi
        bantu = L.first;

        while (bantu != NULL)
        {
            // proses
            hasil = hasil + 1;

            // iterasi
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char makanan[], float rating, int harga, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.makanan, makanan);
    baru->kontainer.rating = rating;
    baru->kontainer.harga = harga;

    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        // jika list bukan list kosong
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    if (before != NULL)
    {
        elemen *hapus = before->next;
        if (hapus != NULL)
        {
            if (hapus->next == NULL)
            {
                L->tail = before;
                before->next = NULL;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
            hapus->prev = NULL;
            free(hapus);
        }
    }
}

/* Prosedur untuk mensorting list berdasarkan Rating */
void sortRating(list *L){
    elemen *current, *nextone; 
    int i, j;
    
    if(countElement(*L) == 2){  // jika hanya terdapat dua elemen dalam list
        current = (*L).first;   // L.first ditandai dengan current
        
        // proses menukar pointernya
        if((*L).first->kontainer.rating > (*L).tail->kontainer.rating){ // jika elemen awal lebih besar dari elemen akhir
            (*L).tail->next = (*L).first;
            (*L).first->next = NULL;
            (*L).first->prev = (*L).tail;
            (*L).tail->prev = NULL;
            (*L).first = (*L).tail;
            (*L).tail = (*L).first->next;
        }
    }
    else{
        for(i = 0; i < countElement(*L); i++){  // jika terdapat lebih dari dua elemen
            current = (*L).first;               // L.first ditandai dengan current
            
            for(j = 0; j < countElement(*L) - 1 - i; j++){                          // perulangan sebanyak banyak elemen
                if(current->kontainer.rating > current->next->kontainer.rating){    // jika elemen rating lebih besar dari elemen rating setelahnya
                    nextone = current->next;                                        // nextone ditandai dengan next nya si current
                    
                    if(current == (*L).first){         // jika current berada di L.first maka prosesnya seperti yang dibawah
                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = NULL;
                        current->prev = nextone;
                        current->next->prev = current;
                        (*L).first = nextone;
                        current = nextone;
                    }
                    else if(nextone->next != NULL){    // menukar pointer ketika nextone->next tidak null
                        current->prev->next = nextone;
                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        current->next->prev = current;
                        current = nextone;
                    }
                    else if(nextone == (*L).tail){     // menukar pointer ketika nextone berada di tail
                        current->prev->next = nextone;
                        nextone->next = nextone->prev;
                        current->next = NULL;
                        current->prev = current->prev->next;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        (*L).tail = current;
                    }
                }
                current = current->next;    // current nya maju
            }
        }
    }
}

/* Prosedur untuk mensorting list berdasarkan Harga */
void sortHarga(list *L){
    elemen *current, *nextone; 
    int i, j;
    
    if(countElement(*L) == 2){  // jika hanya terdapat dua elemen dalam list
        current = (*L).first;   // L.first ditandai dengan current
        
        if(current->kontainer.harga > current->next->kontainer.harga){  // proses menukar pointer jika harga sekarang lebih besar dari harga next
            (*L).tail->next = (*L).first;
            (*L).first->next = NULL;
            (*L).first->prev = (*L).tail;
            (*L).tail->prev = NULL;
            (*L).first = (*L).tail;
            (*L).tail = (*L).first->next;
        }
    }
    else{
        for(i = 0; i < countElement(*L); i++){  // jika terdapat lebih dari dua elemen
            current = (*L).first;               // L.first ditandai dengan current
            
            for(j = 0; j < countElement(*L) - 1 - i; j++){                     // perulangan sebanyak banyak elemen
                if(current->kontainer.harga > current->next->kontainer.harga){ // proses menukar pointer jika harga sekarang lebih besar dari harga next
                    nextone = current->next;                                    // nextone ditandai dengan next nya si current
                    
                    if(current == (*L).first){         // jika current berada di L.first maka prosesnya seperti yang dibawah
                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = NULL;
                        current->prev = nextone;
                        current->next->prev = current;
                        (*L).first = nextone;
                        current = nextone;
                    }
                    else if(nextone->next != NULL){    // menukar pointer ketika nextone->next tidak null
                        current->prev->next = nextone;
                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        current->next->prev = current;
                        current = nextone;
                    }
                    else if(nextone == (*L).tail){     // menukar pointer ketika nextone berada di tail
                        current->prev->next = nextone;
                        nextone->next = nextone->prev;
                        current->next = NULL;
                        current->prev = current->prev->next;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        (*L).tail = current;
                    }
                }
                current = current->next;    // current nya maju
            }
        }
    }
}

/* Prosedur untuk menampilkan Elemen */
void printElemen(list L){
    if(L.tail != NULL){
        // jika list tidak kosong
        // inisialisasi
        elemen *bantu = L.tail;

        while(bantu != NULL){
            // proses
            printf(" %s - Rp%d - Rating:%.1f\n", bantu->kontainer.makanan, bantu->kontainer.harga, bantu->kontainer.rating);

            // iterasi
            bantu = bantu->prev;
        }
    }
    else{
        // proses jika list kosong
        printf(" -\n");
    }
}

/* Prosedur untuk menghapus elemen yang panjang kata makanannya ganjil */
void delElemen(list *L){
    elemen *current;
    current = (*L).tail;          // tail dimasukan kedalam current agar pengecekan dimulai dari belakang
    int batas = countElement(*L); // countelement dimasukkan ke batas karena jika countelemen dimasukkan ke for akan berubah lantaran adanya proses penghapusan

    for(int i = 0; i < batas; i++){                                     // perulangan sebanyak batas atau banyaknya elemen
        if(strlen(current->kontainer.makanan) % 2 != 0){                // jika panjang nama makanannya ganjil
            printf(" %s telah dihapus.\n", current->kontainer.makanan); // tampilkan keluaran nama makanan dihapus
            if(current != (*L).first){                                  // jika currentnya bukan di awal
                current = current->prev;                                // currentnya mundur
                delAfter(current, L);                                   // lalu lakukan del after
            }
            else if(current == (*L).first){                             // jika currentnya berada di awal
                delFirst(L);                                            // lakukan delfirst
            }
        }
        else{                                                           // jika panjang makanannya genap
            current = current->prev;                                    // current nya mundur
        }
    }

    if(countElement(*L) == batas){  // jika count element sama dengan jumlah batas
        printf(" -\n");             // tampilkan kosong (-)
    }
}

/* Prosedur untuk menampilkan elemen yang sudah difilter */
void afterFiltered(list L){
    if(L.first != NULL){
        // inisialisasi
        elemen *bantu = L.first;

        while(bantu != NULL){
            printf(" %s - Rp%d - Rating:%.1f\n", bantu->kontainer.makanan, bantu->kontainer.harga, bantu->kontainer.rating);

            // iterasi
            bantu = bantu->next;
        }
    }
    else{
        printf(" Yahh ujang gabisa icip icip makanan...\n");
    }
}