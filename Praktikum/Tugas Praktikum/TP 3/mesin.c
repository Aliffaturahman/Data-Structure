/*
    Saya AlifFaturahman Firdaus [2107377] mengerjakan soal TP 3 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

void createEmpty(stack *S){
    (*S).top = NULL;
}

int isEmpty(stack S){
    int hasil = 0;

    if(S.top == NULL){
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S){
    int hasil = 0;

    if(S.top != NULL){
        /* stack tidak kosong */
        elemen *bantu;

        /* inisialisasi */
        bantu = S.top;

        while(bantu != NULL){
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(int kode, char judul[], stack *S){
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    baru->kontainer.kode = kode;
    strcpy(baru->kontainer.judul, judul);

    if((*S).top == NULL){
        // jika stack kosong
        baru->next = NULL;
    }
    else{
        // jika stack tidak kosong
        baru->next = (*S).top;
    }

    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S){
    if((*S).top != NULL){
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;

        if(countElement(*S) == 1){
            (*S).top = NULL;
        }
        else{
            (*S).top = (*S).top->next;
        }

        hapus->next = NULL;
        free(hapus);
    }
    else{
        printf("- Stack Kosong");
    }
}

/* prosedur untuk menampilkan stack buku fiksi untuk Rene */
void printBukuFiksi(stack S){
    printf("Buku Fiksi untuk Rene:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if(S.top != NULL){                                                                  // jika stack tidak kosong
        elemen *bantu = S.top;                                                          // deklarasi elemen bantu
        int i = 1;

        while(bantu != NULL){                                                           // selama masih ada stack di elemen bantu
            printf("%d. %s [%d]\n", i, bantu->kontainer.judul, bantu->kontainer.kode);  // print stack
            
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else{                                                                               // jika stack kosong
        printf("Rene mangambek.. Jakob pun menangis T-T.\n");
    }
}

/* prosedur untuk menampilkan stack buku non-fiksi untuk Alain */
void printBukuNonFiksi(stack S){
    printf("\nBuku Non-Fiksi untuk Alain:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if(S.top != NULL){                                                                  // jika stack tidak kosong
        elemen *bantu = S.top;                                                          // deklarasi elemen bantu
        int i = 1;

        while(bantu != NULL){                                                           // selama masih ada stack di elemen bantu
            printf("%d. %s [%d]\n", i, bantu->kontainer.judul, bantu->kontainer.kode);  // print stack

            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else{                                                                               // jika stack kosong
        printf("Alain pergi.. Huft, Ann harus mencarinya.\n");
    }
}

/* prosedur untuk memindahkan seluruh jenis buku dari stack gabungan ke stack buku fiksi atau stack non-fiksi */
void manageStack(stack *S1, stack *S2, stack *S3){
    if(isEmpty(*S1) == 0){                                                      // jika stack tidak kosong
        elemen *tunjuk = (*S1).top;                                             // membuat elemen tunjuk
        
        while(tunjuk != NULL){                                                  // selama elemen tunjuk belum habis
            int count = 0;                                                      // variabel untuk hitung jumlah huruf
            
            for(int i = 0; i < strlen(tunjuk->kontainer.judul); i++){
                count = count + tunjuk->kontainer.judul[i];                     // menyimpan jumlah ASCII
            }
            
            if(count % 2 != 0){                                                 // jika total ASCII ganjil, isi pindah ke stack buku fiksi
                push(tunjuk->kontainer.kode, tunjuk->kontainer.judul, S2);      // melakukan push ke stack buku fiksi
            }
            else{                                                               // jika total ASCII genap, isi pindah ke stack buku non-fiksi
                push(tunjuk->kontainer.kode, tunjuk->kontainer.judul, S3);      // melakukan push ke stack buku non-fiksi
            }
            tunjuk = tunjuk->next;                                              // iterasi
        }
    }
    else{                                                                       // jika stack kosong
        printf("- Stack Kosong\n");
    }
}