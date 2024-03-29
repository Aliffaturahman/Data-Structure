/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 4 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

void makeTree(isiKontainer kontainer, tree *T){ // prosedur untuk membuat tree
    /* alokasi memori */
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    
    /* copy data */
    node->kontainer = kontainer;
    
    /* setting pointer */
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(isiKontainer kontainer, simpul *root){    // prosedur untuk menambahkan node ke tree
    if (root != NULL){                                  // jika simpul root tidak kosong, berarti dapat ditambahkan simpul anak
        /* alokasi memori */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        
        /* copy data */
        baru->kontainer = kontainer;
        baru->child = NULL;
        if (root->child == NULL){                       // jika simpul root belum memiliki child
            baru->sibling = NULL;
            root->child = baru;
        }
        else{                                           // jika simpul root sudah memiliki child
            if (root->child->sibling == NULL){          // jika child dari simpul root belum memiliki sibling
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else{
                simpul *last = root->child;
                
                /*mencari node child terakhir untuk mengaitkan node baru sebagai child
                terakhir dan child terakhir ini siblingnya nyambung ke node child pertama*/
                while (last->sibling != root->child){
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul *root){                                                          // prosedur untuk menghapus semua node dibawahnya dari suatu node
    if (root != NULL){                                                              // jika node root bukan NULL
        if (root->child != NULL){
            if (root->child->sibling == NULL){                                      // jika hanya memiliki 1 child
                delAll(root->child);
                free(root);
            }
            else{                                                                   // jika childnya banyak
                simpul *last = root->child;

                while (last->sibling != root->child){                               // mencari node child terakhir
                    last = last->sibling;
                }

                /* inisialisasi pointer */
                simpul *bantu;
                simpul *proses;
                bantu = root->child;
                
                while (bantu->sibling != root->child && bantu->sibling != NULL){    // untuk menghapus child banyak dari suatu node
                    proses = bantu;
                    bantu = bantu->sibling;
                    root->child = proses->sibling;
                    proses->sibling = NULL;
                    
                    if (last == root->child){
                        last->sibling = NULL;
                    }
                    else{
                        last->sibling = root->child;
                    }
                    delAll(proses);
                }
                if (bantu != NULL){
                    root->child = NULL;
                    proses = bantu;
                    delAll(proses);
                }
                free(root);
            }
        }
        else{
            free(root);
        }
    }
}

void delChild(simpul *tujuan, simpul *root){                                                // prosedur untuk menghapus child dari suatu node
    if (root != NULL){
        simpul *hapus = root->child;
        if (hapus != NULL){
            if (hapus->sibling == NULL){                                                    // jika hanya memiliki 1 child
                if (root->child == tujuan){
                    delAll(root->child);
                    root->child = NULL;
                }
            }
            else{                                                                           // jika childnya banyak
                simpul *prev = NULL;
                int ketemu = 0;
                
                while ((hapus->sibling != root->child) && (ketemu == 0)){                   // mencari simpul yang akan dihapus
                    if (hapus == tujuan){
                        ketemu = 1;
                    }
                    else{
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                if ((ketemu == 0) && (hapus == tujuan)){                                    // untuk child terakhir
                    ketemu = 1;
                }
                if (ketemu == 1){                                                           // jika node yg mau dihapus ketemu
                    simpul *last = root->child;
                    
                    /* mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir */
                    while (last->sibling != root->child){
                        last = last->sibling;
                    }
                    if (prev == NULL){                                                      // jika node yang dihapus child pertama
                        if ((hapus->sibling == last) && (last->sibling == root->child)){    // jika node childnya ada 2
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else{                                                               // jika node childnya banyak
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                            hapus->sibling = NULL;                                          // tambahan (!)
                        }
                    }
                    else{                                                                   // jika node yang dihapus bukan child pertama
                        /* jika node childnya ada 2 dan yg dihapus adalah child ke 2 */
                        if ((prev == root->child) && (last->sibling == root->child) && (hapus == last)){
                            root->child->sibling = NULL;
                            hapus->sibling = NULL;                                          // tambahan (!)
                        }

                        /* jika node yang dihapus bukan child pertama dan node childnya ada banyak */
                        else{
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                }
            }
        }
    }
}

simpul *findSimpul(char tujuan[], simpul *root){                                // fungsi untuk mencari suatu node
    simpul *hasil = NULL;
    if (root != NULL){
        if (strcmp(root->kontainer.nama, tujuan) == 0){                         // jika ketemu di root
            hasil = root;
        }
        else{                                                                   // jika bukan di root maka akan dicari ke anak dan sibling dari anak
            simpul *bantu = root->child;
            if (bantu != NULL){
                if (bantu->sibling == NULL){                                    // jika hanya memiliki 1 node child
                    if (strcmp(bantu->kontainer.nama, tujuan) == 0){
                        hasil = bantu;
                    }
                    else{
                        hasil = findSimpul(tujuan, bantu);
                    }
                }
                else{                                                           // jika node childnya banyak
                    int ketemu = 0;

                    while ((bantu->sibling != root->child) && (ketemu == 0)){   // mencari node ke setiap anaknya
                        if (strcmp(bantu->kontainer.nama, tujuan) == 0){
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else{
                            hasil = findSimpul(tujuan, bantu);
                            bantu = bantu->sibling;
                            if (hasil != 0){
                                ketemu = 1;
                            }
                        }
                    }
                    if (ketemu == 0){                                           // jika masih belum ditemukan
                        if (strcmp(bantu->kontainer.nama, tujuan) == 0){
                            hasil = bantu;
                        }
                        else{
                            hasil = findSimpul(tujuan, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void printTreePreOrder(simpul *root, int panah){        // prosedur untuk menampilkan tree secara preorder
    if (root != NULL){
        for (int i = 0; i < panah; i++){                // untuk panah tanda level dari node
            printf("->");
        }
        printf("%s\n", root->kontainer.nama);
        simpul *bantu = root->child;
        if (bantu != NULL){
            if (bantu->sibling == NULL){                // jika memiliki satu simpul anak
                printTreePreOrder(bantu, ++panah);
                --panah;
            }
            else{
                while (bantu->sibling != root->child){  // jika memiliki banyak simpul anak
                    printTreePreOrder(bantu, ++panah);  // mencetak simpul anak
                    --panah;
                    bantu = bantu->sibling;
                }
                
                printTreePreOrder(bantu, ++panah);      // memproses simpul anak terakhir karena belum terproses dalam pengulangan
                --panah;
            }
        }
    }
}

void printTreePostOrder(simpul *root, int panah){       // prosedur untuk menampilkan tree secara preorder
    if (root != NULL){
        simpul *bantu = root->child;
        if (bantu != NULL){
            if (bantu->sibling == NULL){                // jika memiliki satu simpul anak
                printTreePostOrder(bantu, ++panah);
                --panah;
            } 
            else{
                while (bantu->sibling != root->child){  // jika memiliki banyak simpul anak
                    printTreePostOrder(bantu, ++panah); // mencetak simpul anak
                    --panah;
                    bantu = bantu->sibling;
                }
                
                printTreePostOrder(bantu, ++panah);     // memproses simpul anak terakhir karena belum terproses dalam pengulangan
                --panah;
            }
        }

        for (int i = 0; i < panah; i++){                // mencetak -> sesuai level
            printf("->");
        }
        printf("%s\n", root->kontainer.nama);
    } 
    else{
        printf("Kosong\n");
    }
}
