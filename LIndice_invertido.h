#ifndef LINDICE_INVERTIDO_H
#define LINDICE_INVERTIDO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int qtd;
    int idDoc;
}Tpinver;

typedef struct Tcelula{
    Tpinver *inver;
    struct Tcelula *prox;
}TcelulaInvertida;

typedef struct Lista{
    struct Tcelula *primeiro;
    struct Tcelula *ultimo;
}Tlista;

void FLvazia(Tlista *lista);
void Insere_arquivo(Tlista *lista, int id, int qtd);


#endif