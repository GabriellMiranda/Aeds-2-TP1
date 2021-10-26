/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#include "indiceInvertido.h"

void FLvazia(Tlista *lista)
{
    lista->tamanho = 0;
    lista->primeiro = (Apontador)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

/*Toda vez que se coloca uma palavra nova se cria uma celula,
 essa celula tem um id e qtd, se aparecer a mesma palavra em um
 arquivo diferente, cria-se outra celula com o id desse arquivo e
 qtd de vezes que a palavra apareceu naquele arquivo
*/

void Insere_Iarquivo(Tlista *lista, int id)
{
    Apontador pAux = lista->primeiro->prox;
    Apontador pAnt = lista->primeiro;
    while (pAux != NULL && pAux->inver.idDoc < id)
    {
        pAux = pAux->prox;
        pAnt = pAnt->prox;
    }
    if (pAux != NULL)
    {
        Apontador Novo = (Apontador)malloc(sizeof(TcelulaInvertida));
        Novo->inver.idDoc = id;
        Novo->inver.qtd = 1;
        Novo->prox = pAux;
        pAnt->prox = Novo;
        return;
    }
    lista->ultimo->prox = (Apontador)malloc(sizeof(TcelulaInvertida));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->inver.idDoc = id;
    lista->ultimo->inver.qtd = 1;
    lista->ultimo->prox = NULL;
    lista->tamanho = lista->tamanho + 1;
    return;
}

int ContaPalavras(Tlista *lista, int id)
{
    TcelulaInvertida *Aux = lista->primeiro->prox;
    while (Aux != NULL)
    {
        if (Aux->inver.idDoc == id)
        {
            (Aux->inver.qtd)++;
            break;
        }
        else
        {
            Aux = Aux->prox;
        }
    }
    if (Aux == NULL)
    {
        Insere_Iarquivo(lista, id);
        return 0;
    }
    return 1;
}

int retonarQuantidadePalavras(Tlista *lista, int id)
{
    Apontador Aux = lista->primeiro->prox;
    while (Aux != NULL)
    {
        if (Aux->inver.idDoc == id)
        {
            return Aux->inver.qtd;
        }
        Aux = Aux->prox;
    }
    return 0;
}

int retornaTermos(Tlista *Lista, int id)
{
    Apontador Aux = Lista->primeiro->prox;
    while (Aux != NULL)
    {
        if (Aux->inver.idDoc == id)
        {
            return 1;
        }
        Aux = Aux->prox;
    }
    return 0;
}

void imprimeLista(Tlista *Lista)
{
    Apontador Aux = Lista->primeiro->prox;
    while (Aux != NULL)
    {
        printf("|<%d, %d>| ", Aux->inver.qtd, Aux->inver.idDoc);
        Aux = Aux->prox;
    }
}

void imprimelistaIndiceGTK(Tlista *Lista,GtkTextBuffer *buffer, GtkTextIter *iter){
    Apontador Aux = Lista->primeiro->prox;
    char valor[5];
    while (Aux != NULL)
    {
         /*printf("|<%d, %d>| ", Aux->inver.qtd, Aux->inver.idDoc);
         gtk_text_buffer_insert(buffer, iter,"|<", -1);
         gtk_text_iter_forward_to_end(iter);
         char charValue = (Aux->inver.qtd) +'0';*/
         gtk_text_buffer_insert(buffer, iter,"|<", -1);
         gtk_text_iter_forward_to_end(iter);

         sprintf(valor,"%d",Aux->inver.qtd);
         gtk_text_buffer_insert(buffer, iter,valor, -1);
         gtk_text_iter_forward_to_end(iter);
        
         gtk_text_buffer_insert(buffer, iter,",", -1);
         gtk_text_iter_forward_to_end(iter);

        
         sprintf(valor,"%d",Aux->inver.idDoc);
         gtk_text_buffer_insert(buffer, iter,valor, -1);
         gtk_text_iter_forward_to_end(iter);

         gtk_text_buffer_insert(buffer, iter,">| ", -1);
         gtk_text_iter_forward_to_end(iter);
         Aux = Aux->prox;
        
    }
}