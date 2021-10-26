/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#include <string.h>
#include "tst.h"

//incializando uma arvore tst
void TSTInit(TipodoNOTST **NoO)
{
    *NoO = NULL;
}

//inserindo uma palavra na tst
void TSTInsert(TipodoNOTST **NO, char *Letra)
{
    if (*NO == NULL)
    {
        MALLOC(*NO, TipodoNOTST);
        (*NO)->c = *Letra;
        (*NO)->flag = 0;
        (*NO)->Esquerda = NULL;
        (*NO)->Igual = NULL;
        (*NO)->Direita = NULL;
    }
    if (*Letra < (*NO)->c)
        TSTInsert(&((*NO)->Esquerda), Letra);
    else if (*Letra > (*NO)->c)
        TSTInsert(&((*NO)->Direita), Letra);
    else if (*(Letra + 1))
        TSTInsert(&((*NO)->Igual), Letra + 1);
    else
        (*NO)->flag = 1;
}

//auto complete
int auto_complite(TipodoNOTST *No, char *Letra, char *imprimir, int *i)

//verifica o inicio do termo de acordo com o dicionario inserido
{
    if (No == NULL)
        return 0;
    else if (*Letra < No->c)
        return auto_complite(No->Esquerda, Letra, imprimir, i);
    else if (*Letra > No->c)
        return auto_complite(No->Direita, Letra, imprimir, i);
    else
    {
        if (*(Letra + 1))
        {
            imprimir[*i] = No->c;
            *i += 1;
            if (No->flag == -1)
            {
                int j;
                for (j = 0; j < *i; j++)
                {
                    printf("%c", imprimir[j]);
                }
                printf("\n");
            }
            auto_complite(No->Igual, Letra + 1, imprimir, i);
            return 1;
        }
        else
        {
            imprimir[*i] = No->c;
            *i += 1;
            if (No->flag == -1)
            {
                int j;
                for (j = 0; j < *i; j++)
                {
                    printf("%c", imprimir[j]);
                }
                printf("\n");
            }
            impressao(No->Igual, imprimir, i);
            return 1;
        }
    }
}

//impressao do auto complete
void impressao(TipodoNOTST *No, char *palavra, int *i)
{
    if (No == NULL)
    {
        return;
    }
    if (No->flag == -1)
    {
        int j = 0;
        palavra[*i] = No->c;
        *i += 1;
        for (j = 0; j < *i; j++)
        {
            printf("%c", palavra[j]);
        }
        printf("\n");
        palavra[*i] = palavra[*i + 1];
        *i -= 1;
    }
    if (No->Esquerda != NULL)
    {
        impressao(No->Esquerda, palavra, i);
    }
    if (No->Direita != NULL)
    {
        impressao(No->Direita, palavra, i);
    }
    if (No->Igual != NULL)
    {
        palavra[*i] = No->c;
        *i += 1;
        impressao(No->Igual, palavra, i);
        palavra[*i] = palavra[*i + 1];
        *i -= 1;
    }
}

//auxiliar para imprimir tst
void imprimeTSTAux(TipodoNOTST *No, char *buffer, int depth)
{
    //percorre a árvore e vai guardando no vetor buffer as palavras, caso seja o
    //fim da palavra na árvore, o que está dentro do buffer é printado
    //dependendo do formato da árvore
    //tem que aumentar o define MAX que se usa no buffer
    if (No)
    {
        imprimeTSTAux(No->Esquerda, buffer, depth);

        buffer[depth] = No->c;

        if (No->flag)
        {
            buffer[depth + 1] = '\0';
            printf("%s\n", buffer);
        }

        imprimeTSTAux(No->Igual, buffer, depth + 1);

        imprimeTSTAux(No->Direita, buffer, depth);
    }
}

//imprimir a tst
void imprimeTST(TipodoNOTST *No)
{
    char buffer[MAX];
    imprimeTSTAux(No, buffer, 0);
}

//auxiliar para imprimir tst
void imprimeTSTAuxGTK(TipodoNOTST *No, char* buffer, int depth, GtkTextBuffer *bufffer,GtkTextIter *iter)
{
    //percorre a árvore e vai guardando no vetor buffer as palavras, caso seja o
    //fim da palavra na árvore, o que está dentro do buffer é printado
    //dependendo do formato da árvore
    //tem que aumentar o define MAX que se usa no buffer
    if (No)
    {
        imprimeTSTAuxGTK(No->Esquerda, buffer, depth, bufffer, iter);

        buffer[depth] = No->c;

        if (No->flag)
        {
            buffer[depth + 1] = '\0';
            printf("%s\n", buffer);
             gtk_text_buffer_insert(bufffer, iter,buffer, -1);
             gtk_text_iter_forward_to_end(iter);
             gtk_text_buffer_insert(bufffer, iter,"\n", -1);
             gtk_text_iter_forward_to_end(iter);
        }

        imprimeTSTAuxGTK(No->Igual, buffer, depth + 1, bufffer, iter);

        imprimeTSTAuxGTK(No->Direita, buffer, depth, bufffer, iter);
    }
}

//imprimir a tst
void imprimeTSTGTK(TipodoNOTST *No, GtkTextBuffer *bufffer, GtkTextIter *iter)
{
    char buffer[MAX];
    imprimeTSTAuxGTK(No, buffer, 0, bufffer, iter);
}

/*
//auto complete
int auto_compliteGTK(TipodoNOTST *No, char *Letra, char *imprimir, int *i, GtkTextBuffer *bufffer,GtkTextIter *iter)

//verifica o inicio do termo de acordo com o dicionario inserido
{
    if (No == NULL)
        return 0;
    else if (*Letra < No->c)
        return auto_compliteGTk(No->Esquerda, Letra, imprimir, i, bufffer, iter);
    else if (*Letra > No->c)
        return auto_compliteGTk(No->Direita, Letra, imprimir, i, bufffer, iter);
    else
    {
        if (*(Letra + 1))
        {
            imprimir[*i] = No->c;
            *i += 1;
            if (No->flag == -1)
            {
                int j;
                for (j = 0; j < *i; j++)
                {
                    printf("%c", imprimir[j]);
                }
                printf("\n");
            }
            auto_compliteGTk(No->Igual, Letra + 1, imprimir, i, bufffer, iter);
            return 1;
        }
        else
        {
            imprimir[*i] = No->c;
            *i += 1;
            if (No->flag == -1)
            {
                int j;
                for (j = 0; j < *i; j++)
                {
                    printf("%c", imprimir[j]);
                   // gtk_text_buffer_insert(bufffer, iter,imprimir[j], -1);
                    gtk_text_iter_forward_to_end(iter);
                   
                }
                gtk_text_buffer_insert(bufffer, iter,"\n", -1);
                gtk_text_iter_forward_to_end(iter);
                printf("\n");
            }
            impressaoGTK(No->Igual, imprimir, i, bufffer, iter);
            return 1;
        }
    }
}

//impressao do auto complete
void impressaoGTK(TipodoNOTST *No, char *palavra, int *i, GtkTextBuffer *bufffer,GtkTextIter *iter)
{
    if (No == NULL)
    {
        return;
    }
    if (No->flag == -1)
    {
        int j = 0;
        palavra[*i] = No->c;
        *i += 1;
        for (j = 0; j < *i; j++)
        {
            printf("%c", palavra[j]);
        }
        printf("\n");
        palavra[*i] = palavra[*i + 1];
        *i -= 1;
    }
    if (No->Esquerda != NULL)
    {
        impressaoGTK(No->Esquerda, palavra, i, bufffer, iter);
    }
    if (No->Direita != NULL)
    {
        impressaoGTK(No->Direita, palavra, i, bufffer, iter);
    }
    if (No->Igual != NULL)
    {
        palavra[*i] = No->c;
        *i += 1;
        impressaoGTK(No->Igual, palavra, i, bufffer, iter);
        palavra[*i] = palavra[*i + 1];
        *i -= 1;
    }
}
*/