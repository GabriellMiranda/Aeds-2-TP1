#include "LIndice_invertido.h"

void FLvazia(Tlista *lista){
    lista->primeiro = (TcelulaInvertida *)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}
void Insere_arquivo(Tlista *lista, int id, int qtd){
    lista->ultimo->prox = (TcelulaInvertida *)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox->inver->idDoc = id;
}
