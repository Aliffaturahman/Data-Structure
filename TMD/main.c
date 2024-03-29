/* 
    Saya Alif Faturahman Firdaus (2107377) mengerjakan evaluasi Tugas Masa Depan 
    dalam mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main(){
    tree T;                                         // Inisialisasi pohon
    data dataStr;                                   // Variabel untuk menyimpan data sementara

    char temp[200];                                 // String sementara untuk input
    char kata1[200];                                // Variabel untuk menyimpan data nama
    char kata2[200];                                // Variabel untuk menyimpan data parent
    char kata3[20];                                 // Variabel untuk menyimpan data gaji
    char kata4[20];                                 // Variabel untuk menyimpan data pengalaman
    char kata5[20];                                 // Variabel untuk menyimpan data skill
    char komponen[200];                             // Variabel untuk menyimpan komponen skill
    int angka3, angka4, angka5;                     // Variabel untuk menyimpan data numerik (mengkonversi string dari kata3/4/5 menjadi integer di angka3/4/5)
    
    simpul *find;                                   // Pointer untuk mencari simpul dalam pohon
    
    int n;                                          // Variabel Jumlah iterasi
    int j;                                          // Variabel iterasi tambahan
    int idx1, idx2, batas = 0;                      // Variabel indeks untuk pemrosesan string
    int maxLen[200];                                // Array untuk menyimpan panjang maksimum pada setiap level dalam pohon

    scanf("%d", &n);                                // Input jumlah iterasi

    // Loop untuk membaca input dan membangun pohon
    for(int i = 0; i < n; i++){
        // Lakukan input nama, parent, gaji, pengalaman, dan skill yang atributnya dibatasi oleh '#'
        scanf("%s", &temp);

        idx1 = 0;
        // Membaca nama hingga menemui karakter '#'
        while(temp[idx1] != '#'){
            kata1[idx1] = temp[idx1];
            idx1++;
        }
        kata1[idx1] = '\0';

        // Iterasi bertambah
        idx1++;
        idx2 = 0;

        // Membaca parent hingga menemui karakter '#'
        while(temp[idx1] != '#'){
            kata2[idx2] = temp[idx1];
            idx2++;
            idx1++;
        }
        kata2[idx2] = '\0';

        // Iterasi bertambah
        idx1++;
        idx2 = 0;

        // Membaca gaji hingga menemui karakter '#'
        while(temp[idx1] != '#'){
            kata3[idx2] = temp[idx1];
            idx2++;
            idx1++;
        }
        kata3[idx2] = '\0';
        
        // Inisialisasi untuk di isikan gaji
        angka3 = 0;

        // Mengkonversi string gaji menjadi integer
        for(int k = 0; kata3[k] != '\0'; ++k){
            angka3 = angka3 * 10 + kata3[k] - '0';
        }

        // Iterasi bertambah
        idx1++;
        idx2 = 0;

        // Membaca pengalaman hingga menemui karakter '#'
        while(temp[idx1] != '#'){
            kata4[idx2] = temp[idx1];
            idx2++;
            idx1++;
        }
        kata4[idx2] = '\0';
        
        // Inisialisasi untuk di isikan pengalaman
        angka4 = 0;

        // Mengkonversi string pengalaman menjadi integer
        for(int k = 0; kata4[k] != '\0'; ++k){
            angka4 = angka4 * 10 + kata4[k] - '0';
        }

        // Iterasi bertambah
        idx1++;
        idx2 = 0;

        // Membaca skill hingga menemui karakter '\0'
        while(temp[idx1] != '\0'){
            kata5[idx2] = temp[idx1];
            idx2++;
            idx1++;
        }
        kata5[idx2] = '\0';
        
        // Inisialisasi untuk di isikan skill
        angka5 = 0;

        // Mengkonversi string skill menjadi integer
        for(int k = 0; kata5[k] != '\0'; ++k){
            angka5 = angka5 * 10 + kata5[k] - '0';
        }
        
        // Meng-copy data dalam kata1 dan disimpan di nama
        strcpy(dataStr.nama, kata1);

        // Meng-copy data dalam angka3, angka4, dan angka5 dan disimpan di gaji, pengalaman, dan skill
        dataStr.gaji = angka3;
        dataStr.pengalaman = angka4;
        dataStr.skill = angka5;

        // Lakukan input komponen skill sebanyak skill
        for(int l = 0; l < angka5; l++){
            scanf("%s", &dataStr.arr_komponen[l]);
        }

        // Membangun pohon berdasarkan input
        if(strcmp(kata2, "null") == 0){
            makeTree(dataStr, &T);
        }
        else{
            find = findSimpul(kata2, T.root);
            addChild(dataStr, find);
        }
    }

    // Menghitung panjang maksimum nama di setiap level pohon
    maxLenName(T.root, 0, maxLen);
    int i = 1;
    
    // Mengakumulasi panjang maksimum untuk setiap level
    while(maxLen[i + 1] != 0){
        maxLen[i] += maxLen[i - 1];
        i++;
    }
    maxLen[i] = 0;

    // Mencetak pohon secara preorder dengan spasi yang sesuai
    int check = 0;
    printTreePreOrder(T.root, maxLen, 0, check);
    
    // Meminta inputan untuk mencari sibling dari target untuk dihapus, jika memiliki sibling
    char target[200];
    scanf("%s", target);

    simpul *targetNode = findSimpul(target, T.root);
    simpul *parentNode = findParent(T.root, target);

    // Jika simpul target ditemukan, hapus sibling dari simpul target tersebut dan cetak pohon setelah penghapusan
    if(targetNode != NULL){
        simpul *currentChild = parentNode->child;

        // Menghapus seluruh sibling dari simpul yang dicari (simpul target)
        do{
            simpul *nextSibling = currentChild->sibling;

            // Hapus sibling dari simpul target
            if(currentChild != targetNode){
                delChild(currentChild, parentNode);
            }

            currentChild = nextSibling;

        }while((currentChild->sibling != NULL) && (currentChild->sibling != parentNode->child));

        // Hapus sibling dari simpul target
        if(currentChild != targetNode){
            delChild(currentChild, parentNode);
        }

        // Setel ulang array panjang maksimum untuk setiap level
        for (int k = 0; k <= i; k++){
            maxLen[k] = 0;
        }

        // Menghitung panjang maksimum nama di setiap level pohon setelah penghapusan
        maxLenName(T.root, 0, maxLen);
        i = 1;

        // Mengakumulasi panjang maksimum untuk setiap level
        while(maxLen[i+1] != 0) {
            maxLen[i] += maxLen[i - 1];
            i++;
        }
        maxLen[i] = 0;

        // Mencetak pohon setelah penghapusan secara preorder dengan spasi yang sesuai
        check = 1;
        printTreePreOrder(T.root, maxLen, 0, check);
    } 

    return 0;
}
