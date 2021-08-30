#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void InsereArquivoPAt(TipoArvore *patricia){
    FILE *arquivo;
    char palavra[50], palavra2[50];
    arquivo = fopen("arquivo1.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        minusculo(palavra, palavra2);
        /*printf("%s\n", palavra);
        printf("%s\n", palavra2);*/
        (*patricia) = patInsere(&(*patricia), palavra2);
    }
}

/*void InsereArquivoTST(TipoApontador *TST){
    FILE *arquivo;
    char palavra[50], palavra2[50];
    arquivo = fopen("dicionarioAleatorio.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        minusculo(palavra, palavra2);
        /*printf("%s\n", palavra);
        printf("%s\n", palavra2);*/
       /* insereTST(&TST, palavra2);
    }
}*/
int main(){

   /* printf("Lista indice invertido\n");
    Tlista *Lista = (Tlista *)malloc(sizeof(Tlista));
    Tlista *Lista2 = (Tlista *)malloc(sizeof(Tlista));
    FLvazia(Lista);
    
    Insere_Iarquivo(Lista, 1); //uma palavra no arquivo 1; id = 1
    Insere_Iarquivo(Lista, 2); //uma palavra no arquivo 2; id = 2
    ContaPalavras(Lista, 1);//contando que existe mais uma palavra no arquivo 1
    ContaPalavras(Lista, 2);

    FLvazia(Lista2);
    imprimeLista(Lista);
    Insere_Iarquivo(Lista2, 1); //uma palavra no arquivo 1; id = 1
    Insere_Iarquivo(Lista2, 2); //uma palavra no arquivo 2; id = 2
    ContaPalavras(Lista2, 1);//contando que existe mais uma palavra no arquivo 1
    ContaPalavras(Lista2, 2);
    imprimeLista(Lista);
    TipoArvore patricia = NULL;*/
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
    TipoArvore patricia = NULL;
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
   

   /*printf("--------------------------------------------\n");
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
    
    /*TipoArvore Patricia = NULL;
    TipoApontador *TST;
    inicializaTST(&TST);
    bool op1 = true;
    int opcao;
    while (op1 == true){
        printf("\n|---------------------------------------------------------------------\n");
        printf("| 1 - Construir o indice invertido usando a Patricia\n");
        printf("| 2 - Inserir as palavras do dicionario na arvore TST.\n");
        printf("| 3 - Imprimir o Indice Invertido.\n");
        printf("| 4 - Imprimir as palavras da TST.\n");
        printf("| 5 - Buscar uma palavra na Patricia, a partir do indice invertido.\n");
        printf("| 6 - Sair.\n");
        printf("|--------------------------------------------------------------------\n");
        printf("Opcao: ");scanf("%d", &opcao);
        if(opcao == 1){
            InsereArquivoPAt(&Patricia);
        }
        else if(opcao == 2){
            InsereArquivoTST(&TST);
        }
        else if(opcao == 3){
            pat_print(&Patricia);
        }
        else if(opcao == 4){
            imprimeTST(TST);
        }
        else if(opcao == 5){

        }
        else if(opcao == 6){
        op1 = false;
        }else{
            printf("Opcao Invalida. Digite novamente.\n");
        }
    }*/
 return 0;
}