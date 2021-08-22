#include <stdio.h>
#include <stdlib.h>
#include "Pat.h"
#include "LIndice_invertido.h"
#include "tst.h"

int main(){

    printf("Lista indice invertido\n");
    Tlista *Lista = (Tlista *)malloc(sizeof(Tlista));
    Tlista *Lista2 = (Tlista *)malloc(sizeof(Tlista));
    FLvazia(Lista);
    Insere_Iarquivo(Lista, 1); //uma palavra no arquivo 1;
    Insere_Iarquivo(Lista, 2); 
    ContaPalavras(Lista, 1);
    imprimeLista(Lista);


   /* FILE *arquivo;
    TipoPatNo *Arvore = NULL;
    char palavra[50];
    arquivo = fopen("arquivo1.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        Arvore = Insere(palavra, &Arvore);
        printf("%s\n", palavra);
    }*/

    printf("\n");
    printf("--------------------------------------------\n");
    printf("\n\nArvore Patricia.\n");
    printf("--------------------------------------------\n");

    TipoPatNo *Arvore = NULL;
    Arvore = Insere("felipe", &Arvore);
    Arvore = Insere("gabriel", &Arvore);
    Arvore = Insere("erike", &Arvore);
    Arvore = Insere("mariana", &Arvore);
    printf("\n");
    ImprimePalavras(Arvore);
    printf("\n");

    printf("--------------------------------------------\n");
    printf("Arvore TST\n");
    printf("--------------------------------------------\n");

    TipoApontador *No;

    inicializaTST(&No);
    printf("inicializou na Arvore TST\n");

    insereTST(&No, "eua");
    insereTST(&No, "euc");
    insereTST(&No, "eub");
    //insereTST(&No, "eub");
    insereTST(&No, "euu");
    insereTST(&No, "euv");
    insereTST(&No, "euw");

    printf("inseriu na arvore TST\n");

    printf("\n");
    imprimeTST(No);

    return 0;
}