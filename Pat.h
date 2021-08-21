#ifndef PAT_H
#define PAT_H
//#include "LIndice_invertido.h"
typedef enum{
    interno, externo
} TipoNo; // Identificar se o no é externo ou interno.
//Estrutura de dados Patricia
typedef struct TipoPatNo{
    TipoNo Tipono;
    union{ 
      struct{
        unsigned char indice; // essa variável guarda o indice em que o no interno se difere
        char compara; // essa variável guadra o caracter diferente, presente no indice acima
        struct TipoPatNo *Esq, *Dir;
    } NoInterno;
    char *chave; // ponteiro para char que aponta para a estring que está sendo armazenada, se o no for externo
    //Tlista *listaI;
    }PatNo;
} TipoPatNo;

char Bit(unsigned char i, char k[]);

short NoEExterno(TipoPatNo *No);

TipoPatNo *criaNoInt(int i, char c, TipoPatNo **Esq, TipoPatNo **Dir);

TipoPatNo *criaNoExt(char *string);

void SearchPat (char k[], TipoPatNo *no);

TipoPatNo *InsereEntre(char k[], char compara, TipoPatNo **no, int i);

TipoPatNo *Insere(char k[], TipoPatNo **no);

//int ContaPalavras(TipoPatNo *no);

void ImprimePalavras(TipoPatNo *no);

#endif //PAT_H