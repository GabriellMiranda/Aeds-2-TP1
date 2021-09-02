/*
Gabrie Miranda - 3857
Mariana Sousa - 3867
Felipe Stenner - 3888
*/
#include "pat.h"

//Operação que retorna o menor valor entre dois valores a e b
int min(int a, int b) {
  return (a < b ? a : b);
}

//Operação interna que retorna o caractere que será armazenado em um nó interno 
tupla_t get_char(char *a, char *b) {
  size_t item_a = strlen(a);
  size_t item_b = strlen(b);

  tupla_t tupla;

  int m = min(item_a, item_b);

  /*percorre a palavra até encontrar o caratere em que se diferem,
  ao encontrar escolhe o menor caractere entre os dois ou o \0 e 
  retorna a posição em que se encontram e também o caractere, como tupla*/
  for(int i=0; i<m; i++) {
    if (a[i] == '\0') {
      tupla.letra = a[i];
      tupla.indice = i;
      return tupla;
    } else if(b[i] == '\0') {
      tupla.letra = b[i];
      tupla.indice = i;
      return tupla;
    } else if (a[i] != b[i]) {
      if (a[i] <= b[i]) {
        tupla.letra = a[i];
      } else {
        tupla.letra = b[i];
      }      
      tupla.indice = i;
      return tupla;
    }
  }
}

//Operação que retorna o tipo do nó, interno(0) ou externo(1)
int TipodeNO(TipoArvore t) {
  return (t->nt);
}

//Operação interna para inicialização de um novo nó interno 
TipoArvore CriaNoInt(TipoArvore* Esq, TipoArvore *Dir, tupla_t tupla) { 
  TipoArvore no;
  (no) = (TipoArvore)malloc(sizeof(TipoPatNo));
  (no)->NO.Ninterno.letra = tupla.letra;
  (no)->NO.Ninterno.indice = tupla.indice;
  (no)->NO.Ninterno.Esq = *Esq;
  (no)->NO.Ninterno.Dir = *Dir;
  (no)->nt = interno;
  return no;
}

//Operação interna para inicialização de um novo nó externo
void CriaNoExt(TipoArvore *no, char *k) {
  Tipochave chave;
  chave.palavra = (char*)malloc(sizeof(char));
  chave.lista = (Tlista*)malloc(sizeof(Tlista));
  strcpy(chave.palavra, k);
  FLvazia(chave.lista);
  Insere_Iarquivo(chave.lista, 1);
  (*no) = (TipoArvore) malloc(sizeof(TipoPatNo));
  (*no)->nt = externo;
  (*no)->NO.chave = chave;
  printf("%s\n", (*no)->NO.chave.palavra);

}

//Operação de pesquisa em uma árvore Patricia
int PesquisaPat(TipoArvore no, char *k) {
  if (TipodeNO(no) == externo) { //Caso base: Quando as chamadas recursivas chegam a um nó externo

    return strcmp(k, no->NO.chave.palavra) == 0 ? 1:0; //Retorna 1 se a palavra procurada for igual a palavra salva no nó externo atual
  }

  /*Executa as comparações dos nós internos com a palavra procurada, chamando recursivamente
  a operação para a esquerda se a palavra tiver um caracter menor que o comparado ou para 
  a direita caso contrário*/
  if (k[no->NO.Ninterno.indice] <= no->NO.Ninterno.letra){

    return PesquisaPat(no->NO.Ninterno.Esq, k);
  } else {

    return PesquisaPat(no->NO.Ninterno.Dir, k);
  }
}


//Operação interna para inserção de novo nó interno
TipoArvore patInsereEntre(TipoArvore* no, char *k, tupla_t tupla) {
  TipoArvore Aux;
  //Se o nó atual for um nó externo ou se a palavra for menor que o indice do interno atual
  if (TipodeNO(*no) == externo || tupla.indice < (*no)->NO.Ninterno.indice) {
    
    CriaNoExt(&Aux, k); //Cria nó externo para armazer palavra
    //escolhe se a string será inserida a esquerda ou a direita do novo nó interno
    if (k[tupla.indice] > tupla.letra) {
      return CriaNoInt(no, &Aux, tupla);//Aux para a Dir
    } else {
      return CriaNoInt(&Aux, no, tupla); //Aux para a esq
    }
  } else {
    /*Caso contrário, compara-se até que encontre a posição onde será inserida a palavra
    comparando sempre se será inserida a esquerda ou a direita do nó atual
    e chamando recursivamente a função*/

    if (k[(*no)->NO.Ninterno.indice] >  (*no)->NO.Ninterno.letra) {
      (*no)->NO.Ninterno.Dir = patInsereEntre(&(*no)->NO.Ninterno.Dir, k, tupla);
    } else {
      (*no)->NO.Ninterno.Esq = patInsereEntre(&(*no)->NO.Ninterno.Esq, k, tupla);
    }
    return (*no); // retorna Patricia com nova palavra
  }
}

//Operação para inserção de uma nova palavra em uma árvore Patricia
TipoArvore patInsere(TipoArvore* no, char *k) {
  Tipochave chave;

  if((*no) == NULL) {
    CriaNoExt(no, k); //Caso base: árvore vazia, inicia novo nó externo e armazena a palavra nele
    return (*no);
  } 
  
  TipoArvore aux = *no;

  /*Enquanto não é encontrado um nó externo, percorre-se a ávore comparando
  a palavra em determinado índice com o caracter salvo naquele nó interno,
  chamando a operação recursivamente para a direita caso o caracter possua
  um valor maior, ou para a esquerda caso possua um valor menor que o comparado*/
  while (TipodeNO(aux) != externo) {
    if (k[aux->NO.Ninterno.indice] > aux->NO.Ninterno.letra) { //k[indice] > aux->letra?
      aux = aux->NO.Ninterno.Dir;
    } else {
      aux =  aux->NO.Ninterno.Esq;
    }
  }
  if (strcmp(aux->NO.chave.palavra, k) == 0) {
    return (*no);
  }

  tupla_t tupla = get_char(k, aux->NO.chave.palavra);
  return patInsereEntre(no, k, tupla); //Chama operação para criação de nó interno e armazenar palavra
}

//Operação que imprime uma árvore Patricia em Ordem
void pat_print(TipoArvore *no) {
  if ((*no) == NULL) return;
  
  //Faz um percurso em ordem: vai primeiro nos nós a esquerda e depois nos nós a direita recursivamente
  if (TipodeNO(*no) == interno) pat_print(&(*no)->NO.Ninterno.Esq);
  if (TipodeNO(*no) == externo) puts((*no)->NO.chave.palavra); imprimeLista((*no)->NO.chave.lista); //Imprime apenas quando se encontra um nó externo
  if (TipodeNO(*no) == interno) pat_print(&(*no)->NO.Ninterno.Dir);
}


void minusculo(char *s1, char *s2){
    int i = 0;
    while (s1[i] != '\0'){
        s2[i] = tolower(s1[i]);
        i++;
    }
    s2[i] = '\0';
}
   
void leiturPAT(TipoArvore *patricia){
    FILE *arquivo;
    char palavra[50], palavra2[50];
    arquivo = fopen("arquivo1.txt","r");
    while (!feof(arquivo)) {
        fscanf(arquivo,"%s ", palavra);
        minusculo(palavra, palavra2);
        /*printf("%s\n", palavra);
        printf("%s\n", palavra2);*/
        (*patricia) = patInsere(patricia, palavra2);
    }

}