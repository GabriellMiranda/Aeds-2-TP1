#include "LIndice_invertido.h"

void FLvazia(Tlista *lista){
    lista->primeiro = (TcelulaInvertida *)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}
void Insere_Iarquivo(Tlista *lista, int id){
    lista->ultimo->prox = (TcelulaInvertida *)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->inver = (Tpinver*)malloc(sizeof(Tpinver));
    lista->ultimo->inver->idDoc = id;
    lista->ultimo->inver->qtd = 1;
    lista->ultimo->prox = NULL;
    printf("Inserido:%d\n", lista->ultimo->inver->idDoc);
}

void ContaPalavras(Tlista *lista, int id){
    TcelulaInvertida *Aux = lista->primeiro;
    while (Aux->inver->idDoc != id){
        Aux = Aux->prox;  
    }
    Aux->inver->qtd = Aux->inver->qtd + 1;
}

void imprimeLista(Tlista *Lista){
    printf("entrou\n");
    TcelulaInvertida *Aux;
    Aux = Lista->primeiro->prox;
    while (Aux != NULL){
        printf("<%d, %d> ", Aux->inver->qtd, Aux->inver->idDoc);
        Aux = Aux->prox;
    }
    
}