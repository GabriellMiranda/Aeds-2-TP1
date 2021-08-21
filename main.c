#include <stdio.h>
#include <stdlib.h>
#include "Pat.h"
#include "LIndice_invertido.h"

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
    printf("\n\nArvore Patricia.\n");
    TipoPatNo *Arvore = NULL;
    Arvore = Insere("felipe", &Arvore);
    Arvore = Insere("gabriel", &Arvore);
    Arvore = Insere("erike", &Arvore);
    Arvore = Insere("mariana", &Arvore);
    printf("\n");
    ImprimePalavras(Arvore);

    return 0;
}