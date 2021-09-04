#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pat.h"
#include "LIndice_invertido.h"
#include "tst.h"
//#include "leitura.h"
// gcc main.c LIndice_invertido.c Pat.c tst.c -o e
typedef struct consulta{
   char palavra[50];
}consulta;

int main(){
    int qtd;
   // consulta Palavra[qtd];
    TipoApontador TST;
    TipoArvore Patricia = NULL;
    inicializaTST(&TST);
    printf("oii");
    bool op1 = true;
    char palavra[50];
    
    int opcao;
    while (op1 == true){
        printf("\n");
        printf("|-----------------------------------------------------------------------|\n");
        printf("| 1 - Construir o indice invertido usando a Patricia.                   |\n");
        printf("| 2 - Inserir as palavras do dicionario na arvore TST.                  |\n");
        printf("| 3 - Imprimir o Indice Invertido.                                      |\n");
        printf("| 4 - Imprimir as palavras da TST.                                      |\n");
        printf("| 5 - Buscar por uma palavra na PATRICIA, a partir do indice construido.|\n");
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
            printf("<qtd, id>\n");
           ImprimePalavrasPat(&Patricia);
        }
        else if(opcao == 4){
            imprimeTST(TST);
        }
        else if(opcao == 5){
             printf("Digite a quantidade de palavras que deseja buscar:\n");
             scanf("%d", &qtd);
             for(int i = 0; i <qtd; i++){
                 printf("Digite o primeiro termo da pesquisa:\n");
                // scanf("%s", Palavra[i].palavra);
             }
        }
        else if(opcao == 6){
        op1 = false;
        }else{
            printf("Opcao Invalida. Digite novamente.\n");
        }
    }
 
  return 0;
}