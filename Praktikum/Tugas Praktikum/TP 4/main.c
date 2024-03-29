/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TP 4 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main(){
    tree T;                     // deklarasi bungkusan T
    isiKontainer data, parent;  // deklarasi bungkusan data dan parent
    
    char query[100];            // variabel untuk menyimpan query
    int output = 0;             // variabel untuk menyimpan output

    scanf("%s", query);         // masukan query pertama
    
    while (strcmp(query, "END;") != 0){                             // selama inputan query bukan END;
        if (strcmp(query, "MAKETREE") == 0){                        // jika querynya "MAKETREE"
            scanf("%s", data.nama);                                 // masukan nama untuk membuat tree
            int temp = strlen(data.nama);

            if (data.nama[temp - 1] == ';'){
                data.nama[temp - 1] = '\0';                         // menghilangkan karakter ';' pada nama
            }
            makeTree(data, &T);                                     // membuat tree dengan nama data
        }
        else if (strcmp(query, "CHILD") == 0){                      // jika querynya "CHILD"
            scanf("%s %s", data.nama, parent.nama);                 // masukan nama anak dan nama orang tua
            int temp = strlen(parent.nama);
            
            if (parent.nama[temp - 1] == ';'){
                parent.nama[temp - 1] = '\0';                       // menghilangkan karakter ';' pada nama orang tua
            }
            simpul *bantu = findSimpul(parent.nama, T.root);        // mencari simpul orang tua dari tree
            addChild(data, bantu);                                  // menambahkan simpul anak pada simpul orang tua
        }
        else if (strcmp(query, "PREORDER;") == 0){                  // jika querynya "PREORDER;"
            output++;                                               // output bertambah
            printf("Output %d:\n=========\n", output);              // menampilkan output
            int panah = 0;
            printTreePreOrder(T.root, panah);                       // menampilkan tree secara pre-order
        }
        else if (strcmp(query, "POSTORDER;") == 0){                 // jika querynya "POSTORDER;"
            output++;                                               // output bertambah
            printf("Output %d:\n=========\n", output);              // menampilkan output
            int panah = 0;
            printTreePostOrder(T.root, panah);                      // menampilkan tree secara post-order
        }
        else if (strcmp(query, "DELCHILD") == 0){                   // jika querynya "DELCHILD"
            scanf("%s %s", data.nama, parent.nama);                 // membaca nama anak dan nama orang tua
            int temp = strlen(parent.nama);
            
            if (parent.nama[temp - 1] == ';'){
                parent.nama[temp - 1] = '\0';                       // menghilangkan karakter ';' pada nama orang tua
            }
            simpul *cariParent = findSimpul(parent.nama, T.root);   // mencari simpul orang tua dari tree
            simpul *cariAnak = findSimpul(data.nama, T.root);       // mencari simpul anak yang akan dihapus
            delChild(cariAnak, cariParent);                         // menghapus simpul anak dari simpul orang tua
        }
        scanf("%s", query); // membaca input query selanjutnya
    }
    printf("=========\n");  // menampilkan separator akhir

    return 0;
}
