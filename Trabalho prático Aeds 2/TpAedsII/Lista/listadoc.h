/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#ifndef LISTADOC
#define LISTADOC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct docs *Apontadodocs;

typedef struct docs
{
    int id;
    int qtdpalavras;
    char nome[50];
    double relevancia;
    struct docs *prox;
} Cdocs;

typedef struct
{
    int qtddoc;
    Cdocs *primeiro;
    Cdocs *ultimo;
} Ldocs;

void inicializadocs(Ldocs *lista);

void InsereDoc(Ldocs *lista, char *nome, int qtd, int id);

void insereRelevancia(Ldocs *lista, double relevancia, char *nome, int qtd);

void ImprimerDocumetosprioridade(Ldocs *lista);

void ImprimerDocumetosprioridadeGTK(Ldocs *lista, GtkTextBuffer *buffer, GtkTextIter *iter);
#endif