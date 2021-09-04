#include "LIndice_invertido.h"

void FLvazia(Tlista *lista){
    lista->primeiro = NULL;
    lista->ultimo = lista->primeiro;
    lista->tamanho = 0;
}
/*Toda vez que se coloca uma palavra nova se cria uma celula,
 essa celula tem um id e qtd, se aparecer a mesma palavra em um
 arquivo diferente, cria-se outra celula com o id desse arquivo e
 qtd de vezes que a palavra apareceu naquele arquivo
*/
void Insere_Iarquivo(Tlista *lista, int id){ 
    /*if(lista->ultimo == NULL){
        lista->ultimo = (Apontador)malloc(sizeof(TcelulaInvertida));
        lista->primeiro = lista->ultimo;
    }*/
    Apontador pAux = lista->primeiro->prox;
    Apontador pAnt = lista->primeiro;
    while (pAnt != NULL && pAnt < id){
        pAux = pAux->prox;
        pAnt = pAnt->prox;
    }
    if(pAnt != NULL){
        Apontador Novo = (Apontador)malloc(sizeof(TcelulaInvertida));
        Novo->inver.idDoc = id;
        Novo->inver.qtd = 1;
        Novo->prox = pAux;
        pAnt->prox = Novo;
        return;
    }
    //lista->ultimo->prox = 
    
    /*
    else{
        lista->ultimo->prox = (Apontador)malloc(sizeof(TcelulaInvertida));
        lista->ultimo = lista->ultimo->prox; 
    }
    lista->ultimo->inver.idDoc = id;
    lista->ultimo->inver.qtd = 1;
    lista->ultimo->prox = NULL;
    lista->tamanho++;*/
}

int ContaPalavras(Tlista *lista, int id){
   TcelulaInvertida *Aux = lista->primeiro;
    while (Aux != NULL){
        if(Aux->inver.idDoc == id){ 
            (Aux->inver.qtd)++;
            break;
        }else{
            Aux = Aux->prox;
        }
    }
    if(Aux == NULL){
        Insere_Iarquivo(lista, id);
        return 0;
    }
    return 1;
}

void imprimeLista(Tlista *Lista){
    Apontador Aux = Lista->primeiro;
    while (Aux != NULL){
        printf("|<%d, %d>| ",Aux->inver.qtd, Aux->inver.idDoc);
        Aux = Aux->prox;
    }

} 