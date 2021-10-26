/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#ifndef LINDICE_INVERTIDO_H
#define LINDICE_INVERTIDO_H
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int qtd;
    int idDoc;
} Tpinver;

typedef struct TcelulaInvertida *Apontador;

typedef struct TcelulaInvertida
{
    Tpinver inver;
    struct TcelulaInvertida *prox;
} TcelulaInvertida;

typedef struct Lista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho;
} Tlista;

void FLvazia(Tlista *lista); //fazendo a lista vazia

void Insere_Iarquivo(Tlista *lista, int id); //Função que insere um arquivo

int ContaPalavras(Tlista *lista, int id); //Conta palavras

void ContaPalav(Tlista *lista, int id);

void imprimeLista(Tlista *Lista); //imprime Lista

int retonarQuantidadePalavras(Tlista *lista, int id); //Quantidade de palavras que foram contadas

int retornaTermos(Tlista *Lista, int id);

void imprimelistaIndiceGTK(Tlista *Lista,GtkTextBuffer *buffer, GtkTextIter *iter);
#endif