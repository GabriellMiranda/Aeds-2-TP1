/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#include "listadoc.h"

void inicializadocs(Ldocs *lista)
{
    lista->primeiro = (Apontadodocs)malloc(sizeof(Cdocs));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->qtddoc = 0;
}

void InsereDoc(Ldocs *lista, char *nome, int qtd, int id)
{
    Apontadodocs pAux = lista->primeiro->prox;
    Apontadodocs pAnt = lista->primeiro;
    while (pAux != NULL && pAux->id < id)
    {
        pAux = pAux->prox;
        pAnt = pAnt->prox;
    }
    if (pAux != NULL)
    {
        Apontadodocs Novo = (Apontadodocs)malloc(sizeof(Cdocs));
        strcpy(Novo->nome, nome);
        Novo->qtdpalavras = qtd;
        Novo->relevancia = 0;
        Novo->id = id;
        Novo->prox = pAux;
        pAnt->prox = Novo;
        lista->qtddoc++;
        return;
    }
    lista->ultimo->prox = (Apontadodocs)malloc(sizeof(Cdocs));
    lista->ultimo = lista->ultimo->prox;
    strcpy(lista->ultimo->nome, nome);
    lista->ultimo->qtdpalavras = qtd;
    lista->ultimo->id = id;
    lista->ultimo->relevancia = 0;
    lista->ultimo->prox = NULL;
    lista->qtddoc++;
    return;
}

void insereRelevancia(Ldocs *lista, double relevancia, char *nome, int qtd)
{
    Apontadodocs pAux = lista->primeiro->prox;
    Apontadodocs pAnt = lista->primeiro;
    while (pAux != NULL && pAux->relevancia > relevancia)
    {
        pAux = pAux->prox;
        pAnt = pAnt->prox;
    }
    if (pAux != NULL)
    {
        Apontadodocs Novo = (Apontadodocs)malloc(sizeof(Cdocs));
        strcpy(Novo->nome, nome);
        Novo->qtdpalavras = qtd;
        Novo->relevancia = relevancia;
        Novo->prox = pAux;
        pAnt->prox = Novo;
        return;
    }
    lista->ultimo->prox = (Apontadodocs)malloc(sizeof(Cdocs));
    lista->ultimo = lista->ultimo->prox;
    strcpy(lista->ultimo->nome, nome);
    lista->ultimo->qtdpalavras = qtd;
    lista->ultimo->relevancia = relevancia;
    lista->ultimo->prox = NULL;
    lista->qtddoc++;
    return;
}

void ImprimerDocumetosprioridade(Ldocs *lista)
{
    Apontadodocs Aux = lista->primeiro->prox;
    while (Aux != NULL)
    {
        printf("\n");
        printf("|--------------------------PRIORIDADE-----------------------------------|\n");
        printf("|%s => ", Aux->nome);
        printf("Relevancia:%f\n", Aux->relevancia);
        printf("|-----------------------------------------------------------------------|\n");
        Aux = Aux->prox;
    }
}

void ImprimerDocumetosprioridadeGTK(Ldocs *lista, GtkTextBuffer *buffer, GtkTextIter *iter){
   Apontadodocs Aux = lista->primeiro->prox;
    while (Aux != NULL)
    {
      //  printf("\n");
       // printf("|--------------------------PRIORIDADE-----------------------------------|\n");
      //  printf("|%s => ", Aux->nome);
       // printf("Prioridade:%f\n", Aux->relevancia);
        //printf("|-----------------------------------------------------------------------|\n");
    gtk_text_buffer_insert(buffer, iter,Aux->nome, -1);
    gtk_text_iter_forward_to_end(iter);
    gtk_text_buffer_insert(buffer, iter,"\n", -1);
    gtk_text_iter_forward_to_end(iter);
        Aux = Aux->prox;
    } 
}