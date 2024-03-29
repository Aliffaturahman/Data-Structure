/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 3 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    /* deklarasi stack */
    stack S;                                        // stack untuk semua jenis buku
    stack S2;                                       // stack untuk buku fiksi
    stack S3;                                       // stack untuk buku non-fiksi
    
    /* membuat stack kosong */
    createEmpty(&S);
    createEmpty(&S2);
    createEmpty(&S3);
    
    buku input;                                     // tampungan untuk kode dan judul buku

    int n = 0;                                      // variabel untuk jumlah masukan
    scanf("%d", &n);                                // masukan banyak buku
    
    for (int i = 0; i < n; i++){                    // perulangan sebanyak jumlah buku
        scanf("%d %s", &input.kode, &input.judul);  // masukan kode dan judul buku
        push(input.kode, input.judul, &S);          // melakukan push ke stack semua jenis musik
    }

    manageStack(&S, &S2, &S3);                      // memanggil prosedur untuk memindahkan stack sesuai syarat

    printBukuFiksi(S2);                             // menampilkan stack buku fiksi
    printBukuNonFiksi(S3);                          // menampilkan stack buku non-fiksi

    return 0;
}