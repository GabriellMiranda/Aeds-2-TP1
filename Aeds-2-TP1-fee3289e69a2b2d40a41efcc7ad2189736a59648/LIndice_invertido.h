#ifndef LINDICE_INVERTIDO_H
#define LINDICE_INVERTIDO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int qtd;
    int idDoc;
}Tpinver;

typedef struct TcelulaInvertida *Apontador;

typedef struct TcelulaInvertida{
    Tpinver inver;
    struct TcelulaInvertida *prox;
}TcelulaInvertida;


typedef struct Lista{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho;
}Tlista;

void FLvazia(Tlista *lista);
void Insere_Iarquivo(Tlista *lista, int id);
void ContaPalavras(Tlista *lista, int id);
void imprimeLista(Tlista *Lista);

#endif