#include "LIndice_invertido.h"

void FLvazia(Tlista *lista){
    /*lista->primeiro = NULL;
    lista->ultimo = lista->primeiro;
    lista->tamanho = 0;*/
    lista->primeiro = (Apontador)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->primeiro;
    lista->primeiro = NULL;
}
/*Toda vez que se coloca uma palavra nova se cria uma celula,
 essa celula tem um id e qtd, se aparecer a mesma palavra em um
 arquivo diferente, cria-se outra celula com o id desse arquivo e
 qtd de vezes que a palavra apareceu naquele arquivo
*/
void Insere_Iarquivo(Tlista *lista, int id){ 
   /* if(lista->ultimo == NULL){
        lista->ultimo = (Apontador)malloc(sizeof(TcelulaInvertida));
        lista->primeiro = lista->ultimo;
    }else{
        lista->ultimo->prox = (Apontador)malloc(sizeof(TcelulaInvertida));
        lista->ultimo = lista->ultimo->prox; 
    }*/
    lista->ultimo->prox = (Apontador)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->inver.idDoc = id;
    lista->ultimo->inver.qtd = 1;
    lista->ultimo->prox = NULL;
    printf("Inserido id:%d\n", lista->ultimo->inver.idDoc);
    lista->tamanho++;
}

void ContaPalavras(Tlista *lista, int id){
    Apontador Aux = lista->primeiro;
    while (Aux->inver.idDoc != id){
        Aux = Aux->prox;  
    }
    Aux->inver.qtd = Aux->inver.qtd + 1;
}

void imprimeLista(Tlista *Lista){
    Apontador Aux = Lista->primeiro->prox;
    printf("%d", Lista->tamanho);
    while (Aux != NULL){
        printf("<%d, %d> ",Aux->inver.qtd, Aux->inver.idDoc);
        Aux = Aux->prox;
    }

} 