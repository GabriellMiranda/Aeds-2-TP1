#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
#define TAMLINHA 100

typedef int TipoInteiro;
typedef unsigned char TipoChave;

typedef struct TipodoNO *TipoApontador;
typedef struct TipodoNO{
    TipoChave Letra;
    unsigned ehOFimDaString: 1; 
    TipoApontador Esquerda, Igual, Direita; 
}TipodoNO;

void inicializaTST(TipoApontador *No);
void insereTST(TipoApontador *No, char *Letra);

void insereTSTAux(TipoApontador *No, char *Letra);
void imprimeTST(TipoApontador No);

void imprimeTSTAux(TipoApontador No, char* buffer, int depth);

int pesquisarTST(TipoApontador *No, char *Palavra);


//int abrirArquivo(TipoApontador *Arvore,char *nomeArq, int *Comparacoes, int *Memoria);
//void contarPalavrasTST(TipoApontador No);
//int contarPalavrasTSTAux(TipoApontador No);
//char* tranformarPalavra(char *palavra);
