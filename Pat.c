#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pat.h"
//oi
//Essa função retorna o caracter na posição i do vetor k[]
char Bit(unsigned char i, char k[]){
    return(k[i]);
}

//NoEExterno recebe um no e verifica se ele é externo
short NoEExterno(TipoPatNo *No){
    return(No->Tipono == externo);
}
//Essa funcão cria um nó interno 
TipoPatNo *criaNoInt(int i, char c, TipoPatNo **Esq, TipoPatNo **Dir){
    TipoPatNo *no;
    no = (TipoPatNo *)malloc(sizeof(TipoPatNo));
    no->Tipono = interno;
    no->PatNo.NoInterno.Esq = *Esq;
    no->PatNo.NoInterno.Dir = *Dir;
    no->PatNo.NoInterno.indice = i;
    no->PatNo.NoInterno.compara = c;
    return no;
}
//Essa função cria um nó externo
TipoPatNo *criaNoExt(char *string, int id){
    TipoPatNo *no;
    no = (TipoPatNo *)malloc(sizeof(TipoPatNo));
    no->Tipono = externo;
    no->PatNo.chave = malloc(50 * sizeof(char));
   // strcpy(no->PatNo.chave, string); aqui deu um erro muito estranho que so jesus sabe explicar.
   // printf("%s\n", no->PatNo.chave);
    //cria lista e aponta para NULL
    no->PatNo.listaI = (Tlista *)malloc(sizeof(Tlista));
    FLvazia(&(no->PatNo.listaI));
    //cria a primeira lista onde se insere o primeiro elemento
    Insere_Iarquivo(&(no->PatNo.listaI), id);
    strcpy(no->PatNo.chave, string);
    printf("%s\n", no->PatNo.chave);
    return no;
}

void SearchPat (char k[], TipoPatNo *no){
    if (NoEExterno(no)){
        if(strcmp(k, no->PatNo.chave) == 0){
            printf("Palavra encontrada: %s\n", no->PatNo.chave);
        }
        else{
            printf("Palavra %s nao encontrado\n");
        }
        return;
    }
    if(Bit(no->PatNo.NoInterno.indice, k) < no->PatNo.NoInterno.compara){
        SearchPat(k, no->PatNo.NoInterno.Esq);
    }
    else{
        SearchPat(k, no->PatNo.NoInterno.Dir);
    }
}

TipoPatNo *InsereEntre(char k[], char compara, TipoPatNo **no, int i, int id){
    TipoPatNo *Auxno;
    if(NoEExterno(*no)){
        Auxno = criaNoExt(k, id);
        if(Bit(i, k) > Bit(i, (*no)->PatNo.chave)){
            return criaNoInt(i, k[i], no, &Auxno);
        }else{
            return criaNoInt(i, (*no)->PatNo.chave[i], &Auxno, no);
        }
    }
    else if( i == (*no)->PatNo.NoInterno.indice){
        Auxno = criaNoExt(k, id);
        if(Bit(i, k) > (*no)->PatNo.NoInterno.compara){
            return criaNoInt(i, k[i], no, &Auxno);
        }else{
            (*no)->PatNo.NoInterno.Esq = InsereEntre(k, compara, &(*no)->PatNo.NoInterno.Esq, i, id);
             return (*no);
        }
    }
    else if( i < (*no)->PatNo.NoInterno.indice){
        Auxno = criaNoExt(k, id);
        if(Bit(i, k) > compara){
            return criaNoInt(i, k[i], no, &Auxno);
        }else{
            return criaNoInt(i, compara, &Auxno, no);
        }
    }
    else{
        if(Bit((*no)->PatNo.NoInterno.indice, k) == (*no)->PatNo.NoInterno.compara){
            (*no)->PatNo.NoInterno.Dir = InsereEntre(k, compara, &(*no)->PatNo.NoInterno.Dir, i, id);
        }else{
            (*no)->PatNo.NoInterno.Esq = InsereEntre(k, compara, &(*no)->PatNo.NoInterno.Esq, i, id);
        }
        return (*no);
    }
}

TipoPatNo *Insere(char k[], TipoPatNo **no, int id){
    TipoPatNo *Auxno;
    int i;
    if (*no == NULL){ // arvore vazia insere no externo
        return criaNoExt(k, id);
    }else{
        Auxno = *no;
        while (!NoEExterno(Auxno)){
            if(Bit(Auxno->PatNo.NoInterno.indice, k) == Auxno->PatNo.NoInterno.compara){
                Auxno = Auxno->PatNo.NoInterno.Dir;
            }else{
                Auxno = Auxno->PatNo.NoInterno.Esq;
            }// caso nao aconteca isso percorre a arvore pela esquerda
        }
        i = 0;
        while (Bit((int)i, k) == Bit((int)i, Auxno->PatNo.chave) && i <strlen(k)) i++;
        if(strcmp(k, Auxno->PatNo.chave) == 0){
           printf("A palavra ja esta na arvore");
            //Nessa parte que vamos colocar o contador pra mostra quantas palavras iguais foram inseridas na arvore
            ContaPalavras(Auxno->PatNo.listaI, id);
            return(*no);
        }else{// Entra nesse else quando encontra um letra diferente 
            return (InsereEntre(k, Auxno->PatNo.chave[i], no, i, id));
        }
    }
}

//int ContaPalavras(TipoPatNo *no);

void ImprimePalavras(TipoPatNo *no){
    if(no->Tipono == externo){
        printf("%s ", no->PatNo.chave);
        //imprimeLista(no->PatNo.listaI);

    }
    else{
        ImprimePalavras(no->PatNo.NoInterno.Esq);
        ImprimePalavras(no->PatNo.NoInterno.Dir);
    }
}