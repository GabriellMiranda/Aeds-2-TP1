#include <stdio.h>
#include <stdlib.h>
#include "Pat.h"
#include "LIndice_invertido.h"

int main(){
   
   /* Tlista *Lista = (Tlista *)malloc(sizeof(Tlista));
    Tlista *Lista2 = (Tlista *)malloc(sizeof(Tlista));
    FLvazia(Lista);
    Insere_Iarquivo(Lista, 1); //uma palavra no arquivo 1;
    Insere_Iarquivo(Lista, 2); 
    ContaPalavras(Lista, 1);
    imprimeLista(Lista);
*/

   /* FILE *arquivo;
    TipoPatNo *Arvore = NULL;
    char palavra[50];
    arquivo = fopen("arquivo1.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        Arvore = Insere(palavra, &Arvore);
        printf("%s\n", palavra);
    }*/

    TipoPatNo *Arvore = NULL;
    Arvore = Insere("gabriel", &Arvore, 3);
 //   printf("%d", (Arvore->PatNo.listaI->primeiro->inver->idDoc));
    //Arvore = Insere("gabriel", &Arvore, 3);
    Arvore = Insere("erike", &Arvore, 4);
    Arvore = Insere("mariana", &Arvore, 1);
    Arvore = Insere("felipe", &Arvore, 2);
    Arvore = Insere("Mae", &Arvore, 2);
    ImprimePalavras(Arvore);
    imprimeLista(Arvore->PatNo.listaI);
   // pclose(arquivo);
    return 0;
}