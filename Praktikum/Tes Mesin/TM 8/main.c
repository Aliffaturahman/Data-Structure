/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 8 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

int main(){
    tree T;
    char A, B, C, D, E, F, G, H, I, J, K, L, M, N;

    scanf(" %c", &A);
    makeTree(A, &T);

    scanf(" %c", &B);
    addRight(B, T.root);
    
    scanf(" %c", &C);
    addLeft(C, T.root);
    
    scanf(" %c", &D);
    addLeft(D, T.root->right);
    
    scanf(" %c", &E);
    addRight(E, T.root->left);
    
    scanf(" %c", &F);
    addRight(F, T.root->right);
    
    scanf(" %c", &G);
    addLeft(G, T.root->left->right);
    
    scanf(" %c", &H);
    addRight(H, T.root->right->left);
    
    scanf(" %c", &I);
    addRight(I, T.root->left->right);
    
    scanf(" %c", &J);
    addRight(J, T.root->right->right);
    
    scanf(" %c", &K);
    addLeft(K, T.root->right->right);
    
    scanf(" %c", &L);
    addLeft(L, T.root->left->right->left);
    
    scanf(" %c", &M);
    addLeft(M, T.root->right->left->right);
    
    scanf(" %c", &N);
    addRight(N, T.root->right->left->right);

    printf("Pre Order:\n");
    printTreePreOrder(T.root, T.root);
    printf("\n");
    delLeft(T.root->left->right->left);

    printf("In Order:\n");
    printTreeInOrder(T.root);
    printf("\n");
    delRight(T.root->right->right);

    printf("Post Order:\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");

    return 0;
}