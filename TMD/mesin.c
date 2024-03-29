/* 
    Saya Alif Faturahman Firdaus (2107377) mengerjakan evaluasi Tugas Masa Depan 
    dalam mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// Prosedur untuk membuat pohon dengan simpul root yang berisi data tertentu
void makeTree(data c, tree *T){
    // Mengalokasikan memori untuk simpul baru
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));

    // Mengisi data simpul dengan nilai dari data c
    strcpy(node->kontainer.nama, c.nama);
    node->kontainer.skill = c.skill;
    
    // Mengisi array komponen skill pada simpul
    for(int i = 0; i < c.skill; i++){
        strcpy(node->kontainer.arr_komponen[i], c.arr_komponen[i]);
    }
    
    // Mengisi atribut lainnya pada simpul
    node->kontainer.gaji = c.gaji;
    node->kontainer.pengalaman= c.pengalaman;
    node->parent = NULL;
    node->sibling = NULL;
    node->child = NULL;

    // Menetapkan simpul baru sebagai root dari pohon T
    (*T).root = node;
}

// Prosedur untuk menambahkan simpul anak ke simpul root dengan data tertentu
void addChild(data c, simpul *root){
    if(root != NULL){
        // Mengalokasikan memori untuk simpul baru
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));

        // Mengisi data simpul dengan nilai dari data c
        strcpy(baru->kontainer.nama, c.nama);
        baru->kontainer.skill = c.skill;
        baru->kontainer.gaji = c.gaji;
        baru->kontainer.pengalaman = c.pengalaman;
        
        // Mengisi array komponen skill pada simpul
        for(int i = 0; i < c.skill; i++){
            strcpy(baru->kontainer.arr_komponen[i], c.arr_komponen[i]);
        }

        // Menetapkan simpul baru sebagai child dari root
        baru->child = NULL;
        baru->parent = root;

        // Menambahkan simpul baru ke dalam anak-anak root
        if(root->child == NULL){
            baru->sibling = NULL;
            root->child = baru;
        }
        else{
            if(root->child->sibling == NULL){
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else{
                // Menemukan simpul terakhir pada sibling list
                simpul *last = root->child;
                while(last->sibling != root->child){
                    last = last->sibling;
                }

                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

// Prosedur untuk menghapus seluruh simpul dalam pohon dimulai dari simpul root
void delAll(simpul *root){
    if(root != NULL){
        if(root->child != NULL){
            if(root->child->sibling == NULL){
                // Rekursif menghapus child dan kemudian melepaskan memori root
                delAll(root->child);
                free(root);
            }
            else{
                simpul *bantu;
                simpul *proses;
                bantu = root->child;

                // Menghapus setiap child dalam sibling list
                while(bantu->sibling != root->child){
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }

                // Melepaskan memori root
                free(root);
            }
        }
        else{
            // Melepaskan memori root jika tidak memiliki child
            free(root);
        }
    }
}

// Prosedur untuk menghapus simpul anak tertentu dari simpul root
void delChild(simpul *del, simpul *root){
    // Memastikan root tidak kosong
    if(root != NULL){
        // Pointer untuk mengakses anak pertama dari root
        simpul *hapus = root->child;

        // Memeriksa apakah root memiliki anak
        if(hapus != NULL){
            // Kasus jika hanya ada satu anak
            if(hapus->sibling == NULL){
                if(strcmp(root->child->kontainer.nama, del->kontainer.nama) == 0){
                    // Jika nama anak sama dengan yang akan dihapus, maka hapus semua anak
                    delAll(root->child);
                    root->child = NULL;
                }
            }
            else{
                // Jika ada lebih dari satu anak
                simpul *prev = NULL;
                int ketemu = 0;

                // Mencari simpul yang akan dihapus dalam sibling list
                while((hapus->sibling != root->child) && (ketemu == 0)){
                    if(strcmp(hapus->kontainer.nama, del->kontainer.nama) == 0){
                        ketemu = 1;
                    }
                    else{
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }

                // Kasus jika simpul yang akan dihapus terletak pada simpul terakhir sibling list
                if((ketemu == 0) && (strcmp(hapus->kontainer.nama, del->kontainer.nama) == 0)){
                    ketemu = 1;
                }

                // Jika simpul yang akan dihapus ditemukan
                if(ketemu == 1){
                    simpul *last = root->child;

                    // Menemukan simpul terakhir dalam sibling list
                    while(last->sibling != root->child){
                        last = last->sibling;
                    }

                    // Menghapus simpul dari sibling list
                    if(prev == NULL){
                        // Jika simpul yang akan dihapus berada di awal sibling list
                        if((hapus->sibling == last) && (last->sibling == root->child)){
                            root->child = last;
                            hapus->sibling = NULL;
                            last->sibling = NULL;
                        }
                        else{
                            root->child = hapus->sibling;
                            hapus->sibling = NULL;
                            last->sibling = root->child;
                        }
                    }
                    else{
                        // Jika simpul yang akan dihapus berada di tengah atau akhir sibling list
                        if((prev == root->child) && (last->sibling == root->child)){
                            root->child->sibling = NULL;
                            prev->sibling = NULL;
                        }
                        else{
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    // Menghapus simpul dan anak-anaknya
                    delAll(hapus);
                }
            }
        }
    }
}

// Fungsi untuk mencari simpul dengan nama tertentu dalam pohon dimulai dari simpul root
simpul *findSimpul(char cari[], simpul *root){
    simpul *hasil = NULL;
    
    // Memastikan root tidak kosong
    if(root != NULL){
        // Memeriksa apakah nama root sama dengan yang dicari
        if((strcmp(root->kontainer.nama, cari) == 0)){
            hasil = root;
        }
        else{
            simpul *bantu = root->child;
            
            // Memeriksa apakah root memiliki anak
            if(bantu != NULL){
                // Kasus jika hanya ada satu anak
                if(bantu->sibling == NULL){
                    if((strcmp(bantu->kontainer.nama, cari) == 0)){
                        hasil = bantu;
                    }
                    else{
                        hasil = findSimpul(cari, bantu);
                    }
                }
                else{
                    int ketemu = 0;
                    
                    // Mencari simpul pada sibling list
                    while((bantu->sibling != root->child) && (ketemu == 0)){
                        if((strcmp(bantu->kontainer.nama, cari) == 0)){
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else{
                            hasil = findSimpul(cari, bantu);
                            bantu = bantu->sibling;
                            
                            // Memeriksa apakah simpul sudah ditemukan
                            if(hasil != 0){
                                ketemu = 1;
                            }
                        }
                    }
                    
                    // Kasus jika simpul terakhir sibling list belum ditemukan
                    if(ketemu == 0){
                        if((strcmp(bantu->kontainer.nama, cari) == 0)){
                            hasil = bantu;
                        }
                        else{
                            hasil = findSimpul(cari, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

// Fungsi untuk mencari simpul parent dari simpul anak berdasarkan nama anak
simpul *findParent(simpul *root, const char *childName) {
    // Memastikan root tidak kosong
    if (root != NULL) {
        simpul *bantu = root->child;

        // Memeriksa apakah root memiliki anak
        if (bantu != NULL) {
            // Kasus jika hanya ada satu anak
            if (bantu->sibling == NULL) {
                // Memeriksa apakah nama anak pertama sama dengan yang dicari
                if (strcmp(bantu->kontainer.nama, childName) == 0) {
                    return root;
                } else {
                    // Jika tidak, mencari parent pada anak pertama
                    simpul *parent = findParent(bantu, childName);
                    if (parent != NULL) {
                        return parent;
                    }
                }
            } else {
                // Jika ada lebih dari satu anak
                while (bantu->sibling != root->child) {
                    // Memeriksa apakah nama anak dalam sibling list sama dengan yang dicari
                    if (strcmp(bantu->kontainer.nama, childName) == 0) {
                        return root;
                    } else {
                        // Jika tidak, mencari parent pada anak dalam sibling list
                        simpul *parent = findParent(bantu, childName);
                        if (parent != NULL) {
                            return parent;
                        }
                        bantu = bantu->sibling;
                    }
                }
                
                // Memeriksa apakah nama anak terakhir dalam sibling list sama dengan yang dicari
                if (strcmp(bantu->kontainer.nama, childName) == 0) {
                    return root;
                } else {
                    // Jika tidak, mencari parent pada anak terakhir dalam sibling list
                    simpul *parent = findParent(bantu, childName);
                    if (parent != NULL) {
                        return parent;
                    }
                }
            }
        }
    }
    return NULL;  // Jika tidak ditemukan
}

// Prosedur untuk mencetak pohon secara preorder dengan kedalaman tertentu dan jumlah spasi pada setiap level
void printTreePreOrder(simpul *root, int depth[], int n, int check){
    // Memastikan root tidak kosong
    if(root != NULL){
        // Menampilkan newline sesuai dengan kebutuhan
        if(n != 0){
            printf("\n");
        }
        if(check == 1){
            printf("\n");
        }

        // Menampilkan spasi sesuai dengan kedalaman simpul dalam pohon
        if(n > 0){
            for(int i = 0; i < depth[n - 1]; i++){
                printf(" ");
            }
        }

        // Menampilkan informasi nama simpul dan jumlah digit gaji
        int digitGaji = 0;
        int tempDigit = root->kontainer.gaji;
        
        // Menghitung digit gaji dimulai dari satuan juta
        while(totalAngka(tempDigit) > 6) {
            tempDigit /= 10;
            digitGaji++;
        }
        printf("|%s - %d digit\n", root->kontainer.nama, digitGaji);

        check = 2;

        // Menampilkan informasi nominal gaji
        if(n > 0){
            for(int i = 0; i < depth[n - 1]; i++){
                printf(" ");
            }
        }
        printf(" - %d\n", root->kontainer.gaji);

        // Menampilkan informasi pengalaman
        if(n > 0){
            for(int i = 0; i < depth[n - 1]; i++){
                printf(" ");
            }
        }
        printf(" - %d tahun\n", root->kontainer.pengalaman);

        // Menampilkan informasi seluruh skill
        for(int i = 0; i < root->kontainer.skill; i++){
            if(n > 0){
                for(int i = 0; i < depth[n - 1]; i++){
                    printf(" ");
                }
            }
            printf(" - %s\n", root->kontainer.arr_komponen[i]);
        }

        // Mengakses anak pertama dari root
        simpul *bantu = root->child;

        if(bantu != NULL){
            // Kasus jika hanya ada satu anak
            if(bantu->sibling == NULL){
                n++;
                printTreePreOrder(bantu, depth, n, check);
                n--;
            }
            // Kasus jika ada lebih dari satu anak
            else{
                // Perulangan sebanyak jumlah anak
                while(bantu->sibling != root->child){
                    n++;
                    printTreePreOrder(bantu, depth, n, check);
                    n--;
                    bantu = bantu->sibling;
                }
                n++;
                printTreePreOrder(bantu, depth, n, check);
                n--;
            }
        }
    }
    else{
        printf("Kosong\n");
    }
}

// Prosedur untuk mencetak pohon secara postorder dengan kedalaman tertentu
void printTreePostOrder(simpul *root, int n) {
    // Memastikan root tidak kosong
    if(root != NULL){
        // Memeriksa apakah gaji pada simpul root memenuhi syarat
        if(root->kontainer.gaji >= n){
            // Mengakses anak pertama dari root
            simpul *bantu = root->child;

            // Menjalankan rekursi pada anak-anak root
            if(bantu != NULL){
                // Kasus jika hanya ada satu anak
                if(bantu->sibling == NULL){
                    printTreePostOrder(bantu, n);
                }
                else{
                    // Kasus jika ada lebih dari satu anak
                    while(bantu->sibling != root->child){
                        printTreePostOrder(bantu, n);
                        bantu = bantu->sibling;
                    }
                    printTreePostOrder(bantu, n);
                }
            }

            // Memeriksa apakah gaji pada root lebih kecil dari n
            if(n > root->kontainer.gaji){
                printf("[hapus] ");
            }
            printf("%s %d\n", root->kontainer.nama, root->kontainer.gaji);
        }
        else{
            // Jika gaji pada root tidak memenuhi syarat, hapus semua anak
            delAll(root);
        }
    }
    else{
        printf("Kosong\n");
    }
}

// Prosedur untuk menghitung panjang nama terpanjang dalam pohon
void maxLenName(simpul *root, int level, int len[]) {
    // Memastikan root tidak kosong
    if(root != NULL){
        int curLen = strlen(root->kontainer.nama) + totalAngka(root->kontainer.gaji) + 5;

        // Memeriksa panjang setiap skill pada root
        for(int i = 0; i < root->kontainer.skill; i++){
            if(strlen(root->kontainer.arr_komponen[i]) > curLen){
                curLen = strlen(root->kontainer.arr_komponen[i]) + 5;
            }
        }

        // Memeriksa dan menyimpan panjang maksimum pada level tertentu
        if(len[level] < curLen){
            len[level] = curLen;
        }

        // Mengakses anak pertama dari root
        simpul *bantu = root->child;

        // Jika root memiliki simpul anak
        if(bantu != NULL){
            // Kasus jika hanya ada satu simpul anak
            if(bantu->sibling == NULL){
                // Telusuri simpul anak dan rekursi ke level berikutnya
                maxLenName(bantu, ++level, len);
                --level;
            }
            // Jika memiliki banyak simpul anak
            else{
                // Telusuri semua simpul anak dan rekursi ke level berikutnya
                while(bantu->sibling != root->child){
                    maxLenName(bantu, ++level, len);
                    --level;
                    bantu = bantu->sibling;
                }

                // Memproses simpul anak terakhir dan rekursi ke level berikutnya
                maxLenName(bantu, ++level, len);
                --level;
            }
        }
    }
    else{
        printf("Kosong\n");
    }
}

// Fungsi bantu untuk menghitung jumlah digit pada suatu angka
int totalAngka(int num) {
    int digit = 0;

    // Perulangan sebanyak angka
    while(num != 0){
        num /= 10;
        digit++;
    }

    // Mengembalikan jumlah digit dari suatu angka
    return digit;
}