/*
Gabrie Miranda - 3857
Mariana Sousa - 3867
Felipe Stenner - 3888
*/
#ifndef PAT_H
#define PAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LIndice_invertido.h"

typedef struct {
  int indice;
  char letra;
} tupla_t;

//Enumeração que define o tipo de um nó, interno(0) ou externo(1)
typedef enum {
  interno, externo
} TipoNo;

/*
estrutura base utilizada por uma árvore Patricia, a partir da implementação proposta por Ziviani
Modificações: armazena caracter para comparação e índice em nós internos
*/
typedef struct TipoPatNo* TipoArvore;
typedef struct TipoPatNo {
  TipoNo nt;
  union {
    //nó interno
    struct {
      char letra; //armazena o caracter a ser comparado
      int indice; //armazena o índice a ser comparado
      TipoArvore Esq, Dir;
    }Ninterno;
    //nó externo
    char *palavra; //armazena palavra
   // Tlista *Lista;
  }NO;
} TipoPatNo;

int TipodeNO(TipoArvore t);
TipoArvore CriaNoInt(TipoArvore* Esq, TipoArvore *Dir, tupla_t tupla);
void CriaNoExt(TipoArvore *no, char *k);
int PesquisaPat(TipoArvore t, char *k);
TipoArvore patInsere(TipoArvore* t, char *k);
TipoArvore patInsereEntre(TipoArvore* patricia, char *k, tupla_t tupla);
void pat_print(TipoArvore* t);

#endif