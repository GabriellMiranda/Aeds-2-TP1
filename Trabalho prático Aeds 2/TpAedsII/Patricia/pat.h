/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#ifndef PAT_H
#define PAT_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "../IndiceInvertido/indiceInvertido.h"
#include "../Lista/listadoc.h"

typedef struct
{
  int indice;
  char letra;
} tupla_t;

typedef struct
{
  char nome[50]; //palavra
  double *contf;    //numero de ocorrencia do termo tj no documento i
  int dj;        //numero de documento na coleção
  double *W;     // peso do termo tj no documento i
} palavraprio;

typedef enum
{ //Enumeração que define o tipo de um nó, interno(0) ou externo(1)
  interno,
  externo
} TipoNo;

typedef struct
{
  char *palavra;
  Tlista *lista;
} Tipochave;

/*
estrutura base utilizada por uma árvore Patricia, a partir da implementação proposta por Ziviani
Modificações: armazena caracter para comparação e índice em nós internos
*/

typedef struct TipoPatNo *TipoArvorePat;

typedef struct TipoPatNo
{
  TipoNo nt;
  union
  {
    //nó interno
    struct
    {
      char letra; //armazena o caracter a ser comparado
      int indice; //armazena o índice a ser comparado
      TipoArvorePat Esq, Dir;
    } Ninterno;
    Tipochave chave;
  } NO;
} TipoPatNo;

int TipodeNO(TipoArvorePat t);

TipoArvorePat CriaNoInt(TipoArvorePat *Esq, TipoArvorePat *Dir, tupla_t tupla);

void CriaNoExt(TipoArvorePat *no, char *k, int id);

TipoArvorePat patInsere(TipoArvorePat *t, char *k, int id);

TipoArvorePat patInsereEntre(TipoArvorePat *patricia, char *k, tupla_t tupla, int id);

void minusculo(char *s1, char *s2);

tupla_t Definenointerno(char *a, char *b);

void leiturPAT(TipoArvorePat *pat, char *nomeARquivo, int id, Ldocs *Larquivo);

void ImprimePalavrasPat(TipoArvorePat *no);

void Pat_indice(TipoArvorePat *no);

void relevancia(TipoArvorePat *no, palavraprio *palavras, Ldocs *larquivo, Ldocs *Lprio, int qtd);

void contpalavras(TipoArvorePat *no, char *k, int id, int *cont);

void contaTermos(TipoArvorePat *no, int id, int *cont);

void existenaPAt(TipoArvorePat *no, char *k, int *exist);

void imprimePatGTK(TipoArvorePat *no, GtkTextBuffer *buffer, GtkTextIter *iter);

int lg (int N);

#endif