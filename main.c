#include <stdio.h>
#include <stdlib.h>
#include "Pat.h"
#include "LIndice_invertido.h"
#include "tst.h"
// gcc main.c LIndice_invertido.c Pat.c tst.c -o e

void minusculo(char *s1, char *s2){
    int i = 0;
    while (s1[i] != '\0'){
        s2[i] = tolower(s1[i]);
        i++;
    }
    s2[i] = '\0';
    
}
int main(){

   /* printf("Lista indice invertido\n");
    Tlista *Lista = (Tlista *)malloc(sizeof(Tlista));
    Tlista *Lista2 = (Tlista *)malloc(sizeof(Tlista));
    FLvazia(Lista);
    Insere_Iarquivo(Lista, 1); //uma palavra no arquivo 1;
    Insere_Iarquivo(Lista, 2); 
    ContaPalavras(Lista, 1);
    imprimeLista(Lista);*/

    TipoArvore patricia = NULL;
    /*FILE *arquivo;
    TipoPatNo *Arvore = NULL;
    char palavra[50], palavra2[50];
    arquivo = fopen("arquivo1.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        minusculo(palavra, palavra2);
        /*printf("%s\n", palavra);
        printf("%s\n", palavra2);*/
  //      patricia = patInsere(&patricia, palavra2);
   // }*/

    printf("\n");
    printf("--------------------------------------------\n");
    printf("\n\nArvore Patricia.\n");
    printf("--------------------------------------------\n");

    

    patricia = patInsere(&patricia, "marianac");
    patricia = patInsere(&patricia, "gabriel");
    patricia = patInsere(&patricia, "felipe");
    patricia = patInsere(&patricia, "erike");
    patricia = patInsere(&patricia, "caio");
    patricia = patInsere(&patricia, "fulano");
    patricia = patInsere(&patricia, "bruna");
    patricia = patInsere(&patricia, "marianap");
    printf("\n\n\n");
    pat_print(&patricia);
   

   /* printf("--------------------------------------------\n");
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
*/
    return 0;
}