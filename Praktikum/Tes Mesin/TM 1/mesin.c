/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 1 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/
#include "header.h"

/* Prosedur Untuk Membuat List Baru */
void createList(list *L){
    (*L).first = -1;
    int i;

    for(i = 0; i < 5; i++){

        /*proses menginisialisasi isi array*/
        (*L).data[i].next = -2;
    }
}

/* Prosedur Untuk Menghitung Elemen */
int countElement(list L){
    int hasil = 0;

    if(L.first != -1){

        /*list tidak kosong*/
        int hitung;

        /*inisialisasi*/
        hitung = L.first;

        while(hitung != -1){
            
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

/* Prosedur Untuk Mengosongkan Elemen */
int emptyElement(list L){
    int hasil = -1;

    if(countElement(L) < 5){
        int ketemu = 0;
        int i = 0;

        while((ketemu == 0)&&(i < 5)){
            if(L.data[i].next == -2){
                hasil = i;
                ketemu = 1;
            }
            else{
                i += 1;
            }
        }
    }

    return hasil;
}

/* Prosedur Untuk Menambahkan Elemen Di Awal */
void addFirst(char nama[], int populasi, float luas, list *L){
    
    if(countElement(*L) < 5){
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        (*L).data[baru].kontainer.populasi = populasi;
        (*L).data[baru].kontainer.luas = luas;
        // strcpy((*L).data[baru].kontainer.populasi, populasi);
        // strcpy((*L).data[baru].kontainer.luas, luas);

        if((*L).first == -1){
            /*jika list kosong*/
            (*L).data[baru].next = -1;
        }
        else{
            /*jika list tidak kosong*/
            (*L).data[baru].next = (*L).first;
        }

        (*L).first = baru;
    }
    else{
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

/* Prosedur Untuk Menambahkan Elemen Di Tengah */
void addAfter(int prev, char nama[], int populasi, float luas, list *L){
    if(countElement(*L) < 5){
        int baru = emptyElement(*L);
        
        strcpy((*L).data[baru].kontainer.nama, nama);
        (*L).data[baru].kontainer.populasi = populasi;
        (*L).data[baru].kontainer.luas = luas;
        // strcpy((*L).data[baru].kontainer.populasi, populasi);
        // strcpy((*L).data[baru].kontainer.luas, luas);

        if((*L).data[prev].next == -1){
            (*L).data[baru].next = -1;
        }
        else{
            (*L).data[baru].next =
            (*L).data[prev].next;
        }
        
        (*L).data[prev].next = baru;
    }
    else{
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

/* Prosedur Untuk Menambahkan Elemen Di Akhir */
void addLast(char nama[], int populasi, float luas, list *L){
    if((*L).first == -1){
        /*proses jika list masih kosong*/
        addFirst(nama, populasi, luas, L);
    }
    else{
        /*proses jika list telah berisi elemen*/
        if(countElement(*L) < 5){
        
        /*proses jika array belum penuh*/
        /*proses mencari elemen terakhir*/
        /*inisialisasi*/
        int prev = (*L).first;

        while((*L).data[prev].next != -1){
            /*iterasi*/
            prev = (*L).data[prev].next;
        }
        
        addAfter(prev, nama, populasi, luas, L);
        }
        else{
            /*proses jika array penuh*/
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

/* Prosedur Untuk Menghapus Elemen Di Awal */
void delFirst(list *L){
    if((*L).first != -1){
        int hapus = (*L).first;
        if(countElement(*L) == 1){
            (*L).first = -1;
        }
        else{
            (*L).first = (*L).data[hapus].next;
        }
        
        /*elemen awal sebelumnya dikosongkan*/
        (*L).data[hapus].next = -2;
    }
    else{
        /*proses jika list kosong*/
        printf("Li$t Ko$ong\n");
    }
}

/* Prosedur Untuk Menghapus Elemen Di Tengah */
void delAfter(int prev, list *L){
    int hapus = (*L).data[prev].next;

    if(hapus != -1){
        if((*L).data[hapus].next == -1){
            (*L).data[prev].next = -1;
        }
        else{
            (*L).data[prev].next = (*L).data[hapus].next;
        }
    
        /*pengosongan elemen*/
        (*L).data[hapus].next = -2;
    }
}

/* Prosedur Untuk Menghapus Elemen Di Akhir */
void delLast(list *L){
    if((*L).first != -1){
        if(countElement(*L) == 1){
            /*proses jika list hanya berisi satu elemen*/
            delFirst(L);
        }
        else{
            int hapus = (*L).first;
            int prev;

            while((*L).data[hapus].next != -1){
                /*iterasi*/
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }

            /*elemen sebelum elemen terakhir
            menjadi elemen terakhir*/
            delAfter(prev, L);
        }
    }
    else{
        /*proses jika list kosong*/
        printf("Li$t Ko$ong\n");
    }
}

/* Prosedur Untuk Menampilkan List Elemen */
void printElement(list L){
    if(L.first != -1){
        /*inisialisasi*/
        int tunjuk = L.first;
        int i = 1;

        while(tunjuk != -1){
            
            /*proses*/
            printf("%s - %d orang - %.2f km2\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.populasi, L.data[tunjuk].kontainer.luas);

            // printf("elemen ke : %d\n", i);
            // printf("nama     : %s\n", L.data[tunjuk].kontainer.nama);
            // printf("populasi    : %s\n", L.data[tunjuk].kontainer.populasi);
            // printf("luas   : %s\n", L.data[tunjuk].kontainer.luas);
            // printf("next    : %d\n", L.data[tunjuk].next);
            // printf("------------\n");
            
            /*iterasi*/
            tunjuk = L.data[tunjuk].next;
            i = i + 1;
        }
    }
    else{
        /*proses jika list kosong*/
        printf("Li$t Ko$ong\n");
    }
}

/* Prosedur Untuk Menghapus Seluruh Elemen */
void delAll(list *L){
    int i;
    
    for(i=countElement(*L);i>=1;i--){
        /*proses menghapus elemen list*/
        delLast(L);
    }
}