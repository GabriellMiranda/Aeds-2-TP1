#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pat.h"
#include "LIndice_invertido.h"
#include "tst.h"
//#include "leitura.h"
// gcc main.c LIndice_invertido.c Pat.c tst.c -o e

int main(){
   /* Tipochave chave;
    chave.palavra = (char*)malloc(sizeof(char));
    chave.palavra = "Gabriel";
    chave.lista = (Tlista*)malloc(sizeof(Tlista));
    FLvazia(chave.lista);
    printf("PAlavra:%s",chave.palavra);
    Insere_Iarquivo(chave.lista, 1);
    ContaPalavras(chave.lista, 1);
    ContaPalavras(chave.lista, 1);
    ContaPalavras(chave.lista, 1);
    ContaPalavras(chave.lista, 1);
    ContaPalavras(chave.lista, 1);
    imprimeLista(chave.lista);*/

    TipoApontador TST;
    TipoArvore Patricia = NULL;
    inicializaTST(&TST);
    bool op1 = true;
    Patricia = patInsere(&Patricia, "gabriel");
    Patricia = patInsere(&Patricia, "mariana");
    Patricia = patInsere(&Patricia, "felipe");
    Patricia = patInsere(&Patricia, "ricardo");
    Patricia = patInsere(&Patricia, "fatima");
    pat_print(&Patricia);
   /* int opcao;
    while (op1 == true){
        printf("\n");
        printf("|-----------------------------------------------------------------------|\n");
        printf("| 1 - Construir o indice invertido usando a Patricia.                   |\n");
        printf("| 2 - Inserir as palavras do dicionario na arvore TST.                  |\n");
        printf("| 3 - Imprimir o Indice Invertido.                                      |\n");
        printf("| 4 - Imprimir as palavras da TST.                                      |\n");
        printf("| 5 - Imprimir uma palavra na Patricia, a partir do indice invertido.     |\n");
        printf("| 6 - Sair.                                                             |\n");
        printf("|-----------------------------------------------------------------------|\n");
        printf("Opcao: ");scanf("%d", &opcao);
        if(opcao == 1){
            leiturPAT(&Patricia);
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
            pat_print(&Patricia);
        }
        else if(opcao == 6){
        op1 = false;
        }else{
            printf("Opcao Invalida. Digite novamente.\n");
        }
    }*/
 return 0;
    return 0;
}