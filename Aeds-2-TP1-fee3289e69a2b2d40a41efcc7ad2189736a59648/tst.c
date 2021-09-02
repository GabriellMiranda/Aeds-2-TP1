#include "tst.h"
#include <stdio.h>

//Inicializando uma árvore TST
void inicializaTST(TipoApontador *No){
    *No = NULL;
}

void insereTST(TipoApontador *No, char *Letra){
    
    //condição para saber se a palavra está ou não na árvore, pesquisar ela na árvore
   if(pesquisarTST(&(*No),Letra)){
        //(*Comparacoes)++;
        printf("A palavra %s ja esta na arvore.\n",Letra);
        return;
    }
    //Se não tiver, entra na função de inserir
    else{
        //(*Comparacoes)++;
        insereTSTAux(&(*No),Letra);
        return;
    }
}

void imprimeTST(TipoApontador No){
    char buffer[MAX]; 
    imprimeTSTAux(No, buffer, 0); 
}

void insereTSTAux(TipoApontador *No, char *Letra){
     
        //percorre a árvore comparando cada letra da palavra que vai ser inserida
        //com a letra que está dentro de cada nó, até que todas as letras sejam inseridas
        //e caso isso aconteça, ehOFimDaString recebe valor 1 (TRUE)
    
    
    if(!(*No)){
        //(*Comparacoes)++;
        *No = (TipoApontador)malloc(sizeof(TipodoNO));
        //(*Memoria) += sizeof(*No);
        (*No)->Letra = *Letra;
        (*No)->Esquerda = NULL;
        (*No)->Direita = NULL;
        (*No)->Igual = NULL;
        (*No)->ehOFimDaString = 0;
    }

    if ((*Letra) < (*No)->Letra){
        //(*Comparacoes)++;
        insereTSTAux(&((*No)->Esquerda), Letra);
    } 
    else if ((*Letra) > (*No)->Letra){
        //(*Comparacoes)++;
        insereTSTAux(&((*No)->Direita), Letra);
    } 
    else{
        //(*Comparacoes)++;
        if (*(Letra+1)){
            //(*Comparacoes)++;
            insereTSTAux(&((*No)->Igual ), Letra+1);
        }
        else {
            //(*Comparacoes)++;
            (*No)->ehOFimDaString = 1;
            return;
        }
    } 
             
}



void imprimeTSTAux(TipoApontador No, char* buffer, int depth){
    
        //percorre a árvore e vai guardando no vetor buffer as palavras, caso seja o 
        //fim da palavra na árvore, o que está dentro do buffer é printado
        //dependendo do formato da árvore, tenho que aumentar o define MAX que se usa no buffer
    
    if (No){   
        imprimeTSTAux(No->Esquerda, buffer, depth); 
        
        buffer[depth] = No->Letra; 
        if (No->ehOFimDaString) 
        { 
            buffer[depth+1] = '\0'; 
            printf( "%s\n", buffer); 
        } 
    
        imprimeTSTAux(No->Igual, buffer, depth + 1); 
  
        imprimeTSTAux(No->Direita, buffer, depth); 
        
    } 
} 

int pesquisarTST(TipoApontador *No, char *Palavra) {
    
        //percorre a arvore comparando as letras de Palavra com as letras dentro de cada nó, se eu chegar
        //no fim de Palavra, quer dizer que a Palavra está na árvore
    

    if (!*No) {
        //(*Comparacoes)++;
        return 0;
    }
  
    if (*Palavra < (*No)->Letra){
        //(*Comparacoes)++;
        return pesquisarTST(&(*No)->Esquerda, Palavra);
    }
  
    else if (*Palavra > (*No)->Letra) {
        //(*Comparacoes)++;
        return pesquisarTST(&(*No)->Direita, Palavra);
    }
  
    else
    {
        //(*Comparacoes)++;
        if (*(Palavra+1) == '\0') {
            //(*Comparacoes)++;
            return (*No)->ehOFimDaString;
        }
        return pesquisarTST(&(*No)->Igual, Palavra+1);
    } 
} 

void minuscu(char *s1, char *s2){
    int i = 0;
    while (s1[i] != '\0'){
        s2[i] = tolower(s1[i]);
        i++;
    }
    s2[i] = '\0';
}
   
void InsereArquivoTST(TipoApontador *NO){
    FILE *arquivo;
    char palavra[50], palavra2[50];
    arquivo = fopen("dicionarioAleatorio.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        minusculo(palavra, palavra2);
        /*printf("%s\n", palavra);
        printf("%s\n", palavra2);*/
        insereTST(NO, palavra2);
    }

}
/*void contarPalavrasTST(TipoApontador No){
    int count = 0;
    count = contarPalavrasTSTAux(No);
    printf("A arvore contem %d palavra(s).\n",count);
}

int contarPalavrasTSTAux(TipoApontador No){
    /*
        percorro a árvore e faço a comparação se é o fim da palavra naquele nó (o que me diz que tem uma
        palavra que foi formada) se for verdade, soma um, e no final da recursão tenho a resposta de quantos 
        ehOFimDaString eu tenho, ou seja, quantas palavras eu tenho na árvore
    
    if(No == NULL){
        return 0;
    }
    else
    {
       return (No-> ehOFimDaString == 1) + contarPalavrasTSTAux(No->Igual) + contarPalavrasTSTAux(No->Direita) + contarPalavrasTSTAux(No->Esquerda);
    }     
}

int abrirArquivo(TipoApontador *Arvore,char *nomeArq,int *Comparacoes, int *Memoria){
    /*
        função para abrir o arquivo, percorro linha por linha do arquivo e utilizo o strtok 
        para "dividir essas linhas" sendo que o critério usado para dividir é o o espaço contido entre uma palavra e outra
        TOMAR CUIDADO COM O TAMANHO DA LINHA
   
    FILE *pont_arq;
    char Linha[TAMLINHA];
    const char s[2] = " ";
    char *token;
    char aux[30];

    pont_arq = fopen(nomeArq, "r");

    if(pont_arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    }

    while (!feof(pont_arq))
    {
        fscanf(pont_arq,"%s",Linha);

        if (Linha){
            token = strtok(Linha, s);
            while(token != NULL) {
                insereTST(&(*Arvore),tranformarPalavra(token));
                token = strtok(NULL, s);
            }
        }
    }
    fclose(pont_arq);
}

char* tranformarPalavra(char *palavra){
    int TamStr = strlen(palavra);
    for(int i=0; i<TamStr; i++)
    {                            
     palavra[i] = tolower(palavra[i]);  
    }
    return palavra;
}*/