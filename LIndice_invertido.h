#ifndef LINDICE_INVERTIDO_H
#define LINDICE_INVERTIDO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int qtd;
    int idDoc;
}Tupla_inver;

typedef struct ListaInvertida{
    Tupla_inver Invertida;
    struct ListaInvertida *prox;
}ListaInvertida;

/*typedef struct Lista{
    struct Tcelula *primeiro;
    struct Tcelula *ultimo;
}Tlista;*/

void FLvazia(ListaInvertida *lista);
void Insere_Iarquivo(ListaInvertida *lista, int id);
void ContaPalavras(ListaInvertida *lista, int id);
void imprimeLista(ListaInvertida *Lista);

#endif