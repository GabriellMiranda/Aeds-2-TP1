#include "LIndice_invertido.h"

void FLvazia(Tlista *lista){
    lista->primeiro = (TcelulaInvertida *)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}
/*Toda vez que se coloca uma palavra nova se cria uma celula,
 essa celula tem um id e qtd, se aparecer a mesma palavra em um
 arquivo diferente, cria-se outra celula com o id desse arquivo e
 qtd de vezes que a palavra apareceu naquele arquivo
*/
void Insere_Iarquivo(Tlista *lista, int id){ 
    lista->ultimo->prox = (TcelulaInvertida *)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->ultimo->prox;
 // lista->ultimo->prox->inver->idDoc = id;
    lista->ultimo->inver = (Tpinver*)malloc(sizeof(Tpinver));
    lista->ultimo->inver->idDoc = id;
    lista->ultimo->inver->qtd = 1;
    lista->ultimo->prox = NULL;
    printf("Inserido id:%d\n", lista->ultimo->inver->idDoc);
}

void ContaPalavras(Tlista *lista, int id){
    TcelulaInvertida *Aux = lista->primeiro->prox;
    while (Aux->inver->idDoc != id){
        Aux = Aux->prox;  
    }
    Aux->inver->qtd = Aux->inver->qtd + 1;
}

void imprimeLista(Tlista *Lista){
    printf("entrou\n");
    printf("<qtd, id>\n");
    TcelulaInvertida *Aux = Lista->primeiro->prox;
    while (Aux != NULL){
        printf("<%d, %d> ",Aux->inver->qtd, Aux->inver->idDoc);
        Aux = Aux->prox;
    }

} 