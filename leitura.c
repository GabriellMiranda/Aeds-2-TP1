#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pat.h"
#include "LIndice_invertido.h"
#include "tst.h"

void minusculo(char *s1, char *s2){
    int i = 0;
    while (s1[i] != '\0'){
        s2[i] = tolower(s1[i]);
        i++;
    }
    s2[i] = '\0';
    
}

void InsereArquivoPAt(TipoArvore* patricia){
    FILE *arquivo;
    char palavra[50], palavra2[50];
    arquivo = fopen("arquivo1.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        minusculo(palavra, palavra2);
        (*patricia) = patInsere(patricia, palavra2);
    }
    fclose(arquivo);
}


void InsereArquivoTST(TipoApontador *TST){
    FILE *arquivo;
    char palavra[50], palavra2[50];
    arquivo = fopen("dicionarioAleatorio.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        minusculo(palavra, palavra2);
        printf("%s\n", palavra);
        printf("%s\n", palavra2);
        insereTST(&TST, palavra2);
    }
    fclose(arquivo);
}

void BuscaPorTexto(){
    int q;
    printf("Digite a quantidade de termos:\n");
    for(int i = 0; i <q; i++){
        printf("Digite o termo:\n");
    }
}