#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pat.h"
#include "LIndice_invertido.h"
#include "tst.h"
#include "leitura.c"
// gcc main.c LIndice_invertido.c Pat.c tst.c leitura.c -o e


int main(){
    printf("oi");
    TipoArvore Patricia = NULL;
    TipoApontador *TST;
    inicializaTST(&TST);
    bool op1 = true;
    int opcao;
    while (op1 == true){
        printf("\n|---------------------------------------------------------------------|\n");
        printf("| 1 - Construir o indice invertido usando a Patricia.                   |\n");
        printf("| 2 - Inserir as palavras do dicionario na arvore TST.                  |\n");
        printf("| 3 - Imprimir o Indice Invertido.                                      |\n");
        printf("| 4 - Imprimir as palavras da TST.                                      |\n");
        printf("| 5 - Buscar uma palavra na Patricia, a partir do indice invertido.     |\n");
        printf("| 6 - Sair.                                                             |\n");
        printf("|-----------------------------------------------------------------------|\n");
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
            imprimeTST(&TST);
        }
        else if(opcao == 5){

        }
        else if(opcao == 6){
        op1 = false;
        }else{
            printf("Opcao Invalida. Digite novamente.\n");
        }
    }
 return 0;
}

    