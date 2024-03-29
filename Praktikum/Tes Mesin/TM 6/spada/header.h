#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
    float nilai;
}nilaiMatKul;

typedef struct elmt *alamatelmt;

typedef struct elmt{
    nilaiMatKul kontainer;
    alamatelmt next;
}elemen;

typedef struct {
    elemen* top;
}stack;

void createEmpty(stack *S);
int countElement(stack S);
void push(char nim[], char nama[], float nilai, stack *S );
void pop(stack *S);
void printStack(stack S);
