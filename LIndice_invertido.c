#include "LIndice_invertido.h"

void FLvazia(ListaInvertida *lista){
    (lista) = NULL;
}
void Insere_Iarquivo(ListaInvertida *lista, int id){
   lista = (ListaInvertida*)malloc(sizeof(ListaInvertida));
   lista->Invertida.idDoc = id;
   lista->Invertida.qtd = 1;
   lista->prox = NULL;
}

void ContaPalavras(ListaInvertida *lista, int id){
    ListaInvertida *Aux = lista;
    while (Aux->Invertida.idDoc != id){
        Aux = Aux->prox;  
    }
    Aux->Invertida.qtd = Aux->Invertida.qtd + 1;
}

void imprimeLista(ListaInvertida *Lista){
    printf("entrou\n");
    ListaInvertida*Aux;
    Aux = Lista->prox;
    while (Aux != NULL){
        printf("<%d, %d> ", Aux->Invertida.qtd, Aux->Invertida.idDoc);
        Aux = Aux->prox;
    }
    
}