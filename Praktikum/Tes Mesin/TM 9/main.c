/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 9 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main()
{
    tree T;
    data input;
    scanf("%s %s", input.nama, &input.size);
    makeTree(input.nama, input.size, &T);

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root);

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root);

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root);

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root->child->sibling);

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root->child->sibling);

    printf("Pohon Data Merchandise:\n");
    printf("================================\n");
    printTreePreOrder(T.root, T.root);
    printf("\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");

    delChild(T.root->child->sibling->child->sibling, T.root->child->sibling);

    printTreePreOrder(T.root, T.root);
    printf("\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root->child);

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root->child->sibling->sibling);

    scanf("%s %s", input.nama, &input.size);
    addChild(input.nama, input.size, T.root->child);

    printTreePreOrder(T.root, T.root);
    printf("\n");
    
    printf("\nArsip Pohon Data Merchandise :\n");
    printf("================================\n");
    printf("Salinan Pohon :\n");

    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 0)
    {
        printTreePreOrder(T.root, T.root);
        printf("\nSama\n");
    }
    else
    {
        printf("Tidak Sama\n");
    }
    printf("\nData yang dicari:\n");
    printf("================================\n");

    char cari[50];
    scanf("%s", &cari);

    simpul *find1 = findSimpul(cari, T.root->child->child);

    if (find1 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }

    simpul *find2 = findSimpul(cari, T.root->child->sibling);

    if (find2 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }

    simpul *find3 = findSimpul(cari, T.root);

    if (find3 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }

    return 0;
}