/*
    Saya Alif Faturahman Firdaus [2107377] mengerjakan soal TM 4 dalam 
    mata kuliah Struktur Data untuk keberkahan-Nya maka saya tidak 
    melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;

    if (L.first != NULL)
    {
        // list tidak kosong

        elemen *bantu;

        // inisialisasi
        bantu = L.first;

        while (bantu != NULL)
        {
            // proses
            hasil = hasil + 1;

            // iterasi
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nama[], int telepon, char email[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.telepon = telepon;
    strcpy(baru->kontainer.email, email);

    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *before, char nama[], int telepon, char email[], list *L)
{
    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));

        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.telepon = telepon;
        strcpy(baru->kontainer.email, email);

        if (before->next == NULL)
        {
            baru->next = NULL;
            (*L).tail = baru;
        }
        else
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addBefore(elemen *before, char nama[], int telepon, char email[], list *L)
{
    if(before != NULL){
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.telepon = telepon;
        strcpy(baru->kontainer.email, email);

        if(before->prev == NULL){
            baru->prev = NULL;
            (*L).first = baru;
        }
        else{
            baru->prev = before->prev;
            baru->prev->next = baru;
        }
        baru->next = before;
        before->prev = baru;
        baru = NULL;
    }
    else{
        printf("ga bisa nambah wleee\n");
    }
}

void addLast(char nama[], int telepon, char email[], list *L)
{
    if ((*L).first == NULL)
    {
        // jika list adalah list kosong
        addFirst(nama, telepon, email, L);
    }
    else
    {
        // jika list tidak kosong
        addAfter((*L).tail, nama, telepon, email, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        // jika list bukan list kosong
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL; // dikomen kalo masalah
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    if (before != NULL)
    {
        elemen *hapus = before->next;
        if (hapus != NULL)
        {
            if (hapus->next == NULL)
            {
                L->tail = before;
                before->next = NULL;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
            hapus->prev = NULL;
            free(hapus);
        }
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        // jika list tidak kosong
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            // jika banyak elemen
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElemen(list L)
{
    if (L.first != NULL)
    {
        // jika list tidak kosong
        // inisialisasi
        elemen *bantu = L.first;

        while (bantu != NULL)
        {
            // proses

            printf("%s %d %s\n", bantu->kontainer.nama, bantu->kontainer.telepon, bantu->kontainer.email);

            // iterasi
            bantu = bantu->next;
        }
    }
    else
    {
        // proses jika list kosong
        printf("List Kosong.\n");
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        int i;

        for (i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}

void printreverse(list L)
{
    if (L.first != NULL)
    {
        // inisialisasi
        elemen *bantu = L.tail;

        while (bantu != NULL)
        {
            // proses
            printf("%s %d %s\n", bantu->kontainer.nama, bantu->kontainer.telepon, bantu->kontainer.email);

            // iterasi
            bantu = bantu->prev;
        }
    }
    else
    {
        // jika List Kosong.
        printf("List Kosong.\n");
    }
}