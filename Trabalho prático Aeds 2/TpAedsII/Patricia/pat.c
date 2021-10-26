/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#include "pat.h"

//Operação que retorna o menor valor entre dois valores a e b
int min(int a, int b)
{
  return (a < b ? a : b);
}

//Operação interna que retorna o caractere que será armazenado em um nó interno
tupla_t Definenointerno(char *a, char *b)
{
  size_t item_a = strlen(a);
  size_t item_b = strlen(b);

  tupla_t tupla;

  int m = min(item_a, item_b);

  /*percorre a palavra até encontrar o caratere em que se diferem,
  ao encontrar escolhe o menor caractere entre os dois ou o \0 e 
  retorna a posição em que se encontram e também o caractere, como tupla*/

  for (int i = 0; i < m; i++)
  {
    if (a[i] == '\0')
    {
      tupla.letra = a[i];
      tupla.indice = i;
      return tupla;
    }
    else if (b[i] == '\0')
    {
      tupla.letra = b[i];
      tupla.indice = i;
      return tupla;
    }
    else if (a[i] != b[i])
    {
      if (a[i] <= b[i])
      {
        tupla.letra = a[i];
      }
      else
      {
        tupla.letra = b[i];
      }
      tupla.indice = i;
      return tupla;
    }
  }
}

//Operação que retorna o tipo do nó, interno(0) ou externo(1)
int TipodeNO(TipoArvorePat t)
{
  return (t->nt);
}

//Operação interna para inicialização de um novo nó interno
TipoArvorePat CriaNoInt(TipoArvorePat *Esq, TipoArvorePat *Dir, tupla_t tupla)
{
  TipoArvorePat no;
  (no) = (TipoArvorePat)malloc(sizeof(TipoPatNo));
  (no)->NO.Ninterno.letra = tupla.letra;
  (no)->NO.Ninterno.indice = tupla.indice;
  (no)->NO.Ninterno.Esq = *Esq;
  (no)->NO.Ninterno.Dir = *Dir;
  (no)->nt = interno;
  return no;
}

//Operação interna para inicialização de um novo nó externo
void CriaNoExt(TipoArvorePat *no, char *k, int id)
{
  Tipochave chave;
  chave.palavra = (char *)malloc(sizeof(char));
  chave.lista = (Tlista *)malloc(sizeof(Tlista));
  strcpy(chave.palavra, k);
  FLvazia(chave.lista);
  Insere_Iarquivo(chave.lista, id);
  (*no) = (TipoArvorePat)malloc(sizeof(TipoPatNo));
  (*no)->nt = externo;
  (*no)->NO.chave = chave;
}

//Operação interna para inserção de novo nó interno
TipoArvorePat patInsereEntre(TipoArvorePat *no, char *k, tupla_t tupla, int id)
{
  TipoArvorePat Aux;
  //Se o nó atual for um nó externo ou se a palavra for menor que o indice do interno atual
  if (TipodeNO(*no) == externo || tupla.indice < (*no)->NO.Ninterno.indice)
  {
    CriaNoExt(&Aux, k, id); //Cria nó externo para armazer palavra
    //escolhe se a string será inserida a esquerda ou a direita do novo nó interno
    if (k[tupla.indice] > tupla.letra)
    {
      return CriaNoInt(no, &Aux, tupla); //Aux para a Dir
    }
    else
    {
      return CriaNoInt(&Aux, no, tupla); //Aux para a esq
    }
  }
  else
  {
    /*Caso contrário, compara-se até que encontre a posição onde será inserida a palavra
    comparando sempre se será inserida a esquerda ou a direita do nó atual
    e chamando recursivamente a função*/

    if (k[(*no)->NO.Ninterno.indice] > (*no)->NO.Ninterno.letra)
    {
      (*no)->NO.Ninterno.Dir = patInsereEntre(&(*no)->NO.Ninterno.Dir, k, tupla, id);
    }
    else
    {
      (*no)->NO.Ninterno.Esq = patInsereEntre(&(*no)->NO.Ninterno.Esq, k, tupla, id);
    }
    return (*no); // retorna Patricia com nova palavra
  }
}

//Operação para inserção de uma nova palavra em uma árvore Patricia
TipoArvorePat patInsere(TipoArvorePat *no, char *k, int id)
{
  Tipochave chave;
  int verifica;
  if ((*no) == NULL)
  {
    CriaNoExt(no, k, id); //Caso base: árvore vazia, inicia novo nó externo e armazena a palavra nele
    return (*no);
  }

  TipoArvorePat aux = *no;

  /*Enquanto não é encontrado um nó externo, percorre-se a ávore comparando
  a palavra em determinado índice com o caracter salvo naquele nó interno,
  chamando a operação recursivamente para a direita caso o caracter possua
  um valor maior, ou para a esquerda caso possua um valor menor que o comparado*/
  while (TipodeNO(aux) != externo)
  {
    if (k[aux->NO.Ninterno.indice] > aux->NO.Ninterno.letra)
    { //k[indice] > aux->letra?
      aux = aux->NO.Ninterno.Dir;
    }
    else
    {
      aux = aux->NO.Ninterno.Esq;
    }
  }
  if (strcmp(aux->NO.chave.palavra, k) == 0)
  {
    Tlista *lista = aux->NO.chave.lista;
    verifica = ContaPalavras(lista, id);
    return (*no);
  }

  tupla_t tupla = Definenointerno(k, aux->NO.chave.palavra);
  return patInsereEntre(no, k, tupla, id); //Chama operação para criação de nó interno e armazenar palavra
}

//Operação que imprime uma árvore Patricia em Ordem
void ImprimePalavrasPat(TipoArvorePat *no)
{
  if (TipodeNO(*no) == externo)
  {
    printf("\n");
    printf("[%s] =>", (*no)->NO.chave.palavra); //se o no for externo, imprime a chave dele
    imprimeLista((*no)->NO.chave.lista);
    printf("\n");
  }
  else
  { //e se nao, chama recursivamente para os filhos a esquerda e a direita
    ImprimePalavrasPat(&(*no)->NO.Ninterno.Esq);
    ImprimePalavrasPat(&(*no)->NO.Ninterno.Dir);
  }
}

//Leitura do arquivo Patricia 
void leiturPAT(TipoArvorePat *patricia, char *nomeArquivo, int id, Ldocs *larquivos)
{
  FILE *arquivo;
  int contador = 0;
  char palavra[50];
  arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL)
  {
    printf("O arquivo digitado nao existe!\n");
    return;
  }
  printf("%s\n", nomeArquivo);
  while (!feof(arquivo))
  {
    fscanf(arquivo, "%s ", palavra);
    for(int i = 0; palavra[i]; i++){
         palavra[i] = tolower(palavra[i]);
    }
    contador++;
    (*patricia) = patInsere(patricia, palavra, id);
  }
  printf("Palavras inseridas da Patricia ...\n");
  //ImprimePalavrasPat(patricia);
  if (arquivo != NULL)
  {
    InsereDoc(larquivos, nomeArquivo, contador, id);
  }
  fclose(arquivo);
}

void relevancia(TipoArvorePat *no, palavraprio *palavras, Ldocs *larquivo, Ldocs *Lprio, int qtd)
{
  Apontadodocs Aux;
  //aloca a quantidade de espaços para relevância e peso
  double *r = (double *)malloc(larquivo->qtddoc * sizeof(double));
  double *peso = (double *)malloc(larquivo->qtddoc * sizeof(double));
  for (int i = 0; i < larquivo->qtddoc; i++)
  {
    peso[i] = 0;
  }
  //contf cada posição representa o numero de ocorências em um determinado arquivo
  int cont = 0;
  for (int i = 0; i < qtd; i++)
  {
    Aux = larquivo->primeiro;
    //cada palavra passada vai ter a quantidade de contf para a quantidade de arquivos
    palavras[i].contf = (double *)malloc(larquivo->qtddoc * sizeof(double));
    palavras[i].W = (double *)malloc(larquivo->qtddoc * sizeof(double));
    for (int j = 0; j < larquivo->qtddoc; j++)
    {
      Aux = Aux->prox;
      /*o contf recebe a quantidade de vezes que uma palavras apareceu no primeiro arquivo, isto na posição i
          como por exemplo se forem inseridos dois arquivos esses dois arquivos seram inseridos na listadoc ordenados,
          então a posição i de uma palavra na posição j de um contf recebe o numero de vezes que um termo aparece em um arquivo,
          cujo está na lista com o id mais baixo
          */
      contpalavras(no, palavras[i].nome, Aux->id, &cont);
      palavras[i].contf[j] = cont;
      printf("Palavra:%s aparece:%lf no arqID:%d\n", palavras[i].nome, palavras[i].contf[j], Aux->id);
      if (palavras[i].contf[j] != 0)
      {                                      //se o contf == 0, significa que na posição i, o arquivo não contem esta palavra
        palavras[i].dj = palavras[i].dj + 1; // se for diferente de 0 soma-se 1 no dj, mostrando que aquele primeiro arquivo que representa uma posição no contf tem palavras deste termo, então soma-se 1 no dj
      }
    }
    printf("Palavra: %s,DJ:%d\n", palavras[i].nome, palavras[i].dj);
  }
  //nesta parte calcula-se o peso do termo tj no documento i
  for (int i = 0; i < qtd; i++)
  {
    for (int j = 0; j < larquivo->qtddoc; j++)
    {
      palavras[i].W[j] = palavras[i].contf[j] * lg(larquivo->qtddoc) / (palavras[i].dj);
      //printf("W:%lf*log(%d)/%d\n", palavras[i].contf[j], larquivo->qtddoc, palavras[i].dj);
      //printf("ContaW:%lf\n", palavras[i].W[i]);
      peso[j] = peso[j] + palavras[i].W[j];
      //printf("PESO:%lf\n", peso[j]);
     // printf("PALAVRA:[%d].w[%d] = %lf\n",i, j, palavras[i].W[j]);
    }
  }
  //nesta para calcula-se as relevâncias
  cont = 0;
  Aux = larquivo->primeiro;
  for (int i = 0; i < larquivo->qtddoc; i++)
  {
    Aux = Aux->prox;
    contaTermos(no, Aux->id, &cont);
    // printf("Quantidade de termos:%d\n", cont);
    r[i] = (double)(1 / ((double)cont)) * (peso[i]);
    printf("r = 1/%d * %lf\n", cont, peso[i]);
    printf("r:%lf\n", r[i]);
    insereRelevancia(Lprio, r[i], Aux->nome, cont);
    cont = 0;
  }
}

//função que conta quantas vezes uma paralavra aparece em um determinado arquivo.
void contpalavras(TipoArvorePat *no, char *k, int id, int *cont)
{
  // printf("palavra passada:%s", k);
  if (TipodeNO(*no) == externo)
  {
    if (strcmp(k, (*no)->NO.chave.palavra) == 0)
    {
      Tlista *Lista = (*no)->NO.chave.lista;
      *cont = retonarQuantidadePalavras(Lista, id);
      //*cont = 1;
    }
  }
  else
  { //e se nao, chama recursivamente para os filhos a esquerda e a direita
    contpalavras(&(*no)->NO.Ninterno.Esq, k, id, cont);
    contpalavras(&(*no)->NO.Ninterno.Dir, k, id, cont);
  }
}

//função que calcula quantos termos existem em determinado arquivo
void contaTermos(TipoArvorePat *no, int id, int *cont)
{
  // printf("palavra passada:%s", k);
  if (TipodeNO(*no) == externo)
  {
    Tlista *Lista = (*no)->NO.chave.lista;
    *cont = *cont + retornaTermos(Lista, id);
  }
  else
  {
    contaTermos(&(*no)->NO.Ninterno.Esq, id, cont);
    contaTermos(&(*no)->NO.Ninterno.Dir, id, cont);
  }
}

//função para verificar se uma palavra existe na patricia
void existenaPAt(TipoArvorePat *no, char *k, int *existe)
{
  if (TipodeNO(*no) == externo)
  {
    if (strcmp((*no)->NO.chave.palavra, k) == 0)
    {
       *existe = 1;
    }
  }
  else
  {
    existenaPAt(&(*no)->NO.Ninterno.Esq, k, existe);
    existenaPAt(&(*no)->NO.Ninterno.Dir, k, existe);
  }
}
//função para imprimir a patricia no gtk
void imprimePatGTK(TipoArvorePat *no, GtkTextBuffer *buffer, GtkTextIter *iter){
    if (TipodeNO(*no) == externo)
  {
    printf("\n");
    printf("[%s] =>", (*no)->NO.chave.palavra); //se o no for externo, imprime a chave dele
    gtk_text_buffer_insert(buffer, iter,(*no)->NO.chave.palavra, -1);
    gtk_text_iter_forward_to_end(iter);
    gtk_text_buffer_insert(buffer, iter,"  =>  ", -1);
    gtk_text_iter_forward_to_end(iter);
    imprimelistaIndiceGTK((*no)->NO.chave.lista, buffer, iter);
    gtk_text_buffer_insert(buffer, iter,"\n\n", -1);
    gtk_text_iter_forward_to_end(iter);
    printf("\n");
  }
  else
  { //e se nao, chama recursivamente para os filhos a esquerda e a direita
    imprimePatGTK(&(*no)->NO.Ninterno.Esq, buffer, iter);
    imprimePatGTK(&(*no)->NO.Ninterno.Dir, buffer, iter);
  }
}


// função para calculo de logaritmo
int lg (int N)
{  
   int i = 0;
   int n = N;
   while (n > 1) {
      n = n / 2;
      i += 1;
   }
   return i;    
}