/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <gtk/gtk.h>

#define MAX 50
#define TAMLINHA 100

#define MALLOC(A,B) (A) = (B *)malloc(sizeof(B)); if ((A) == NULL) return

typedef struct node {
    char c; //letra 
    unsigned ehOFimDaString: 1; //usado para o imprimeAux
    int flag: 1; //flag para o auto complete 
    struct node *Esquerda; //esquerda do no 
    struct node *Igual; //igual ao no
    struct node *Direita; //direita do no 
} TipodoNOTST;

void TSTInit(TipodoNOTST **NoO); //incializando a arvore tst

void TSTInsert(TipodoNOTST **NO, char *Letra); //inserindo na arvore tst

int auto_complite(TipodoNOTST *No, char *Letra, char *imprimir, int *i); //auto complete da tst

void impressao(TipodoNOTST *No, char *palavra, int *i); //impressao para o auto complete 

void imprimeTSTAux(TipodoNOTST *No, char* buffer, int depth); //auxiliar para imprimir a tst 

void imprimeTSTGTK(TipodoNOTST *No, GtkTextBuffer *buffer, GtkTextIter *iter); //imprime a tst 

void imprimeTSTAuxGTK(TipodoNOTST *No, char* buffer, int depth, GtkTextBuffer *bufffer,GtkTextIter *iter);


//int auto_compliteGTK(TipodoNOTST *No, char *Letra, char *imprimir, int *i, GtkTextBuffer *bufffer, GtkTextIter *iter); //auto complete da tst

//void impressaoGTK(TipodoNOTST *No, char *palavra, int *i, GtkTextBuffer *bufffer, GtkTextIter *iter); //impressao para o auto complete 