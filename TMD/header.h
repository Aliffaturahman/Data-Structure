/* 
    Saya Alif Faturahman Firdaus (2107377) mengerjakan evaluasi Tugas Masa Depan 
    dalam mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak melakukan 
    kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Mendefinisikan struktur untuk merepresentasikan data pada setiap simpul
typedef struct {
    char nama[200];                 // Variabel untuk menyimpan nama node
    char arr_komponen[200][200];    // Variabel untuk menyimpan parent dari suatu node
    int gaji;                       // variabel untuk menyimpan nominal gaji
    int pengalaman;                 // Variabel untuk menyimpan lama pengalaman dalah tahun 
    int skill;                      // Variabel untuk menyimpan banyak skill dari suatu node
} data;

// Mendefinisikan struktur untuk simpul dalam pohon, menggunakan pointer untuk merepresentasikan hubungan parent, sibling, dan child
typedef struct smp *alamatsimpul;
typedef struct smp {
    data kontainer;
    alamatsimpul parent;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

// Mendefinisikan struktur untuk pohon
typedef struct {
    simpul *root;
} tree;

// Prosedur untuk membuat pohon dengan simpul root yang berisi data tertentu
void makeTree(data c, tree *T);

// Prosedur untuk menambahkan simpul anak ke simpul root dengan data tertentu
void addChild(data c, simpul *root);

// Prosedur untuk menghapus seluruh simpul dalam pohon dimulai dari simpul root
void delAll(simpul *root);

// Prosedur untuk menghapus simpul anak tertentu dari simpul root
void delChild(simpul *del, simpul *root);

// Fungsi untuk mencari simpul dengan nama tertentu dalam pohon dimulai dari simpul root
simpul *findSimpul(char cari[], simpul *root);

// Fungsi untuk mencari simpul parent dari simpul anak berdasarkan nama anak
simpul *findParent(simpul *root, const char *childName);

// Prosedur untuk mencetak pohon secara preorder dengan kedalaman tertentu dan jumlah spasi pada setiap level
void printTreePreOrder(simpul *root, int depth[], int n, int check);

// Prosedur untuk mencetak pohon secara postorder dengan kedalaman tertentu
void printTreePostOrder(simpul *root, int n);

// Prosedur untuk menghitung panjang nama terpanjang dalam pohon
void maxLenName(simpul *root, int n, int len[]);

// Fungsi bantu untuk menghitung jumlah digit suatu angka
int totalAngka(int num);