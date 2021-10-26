/*
Gabriel Miranda - 3857
Mariana souza - 3898
*/

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "Patricia/pat.h"
#include "TST/tst.h"
#include "IndiceInvertido/indiceInvertido.h"
#include "Lista/listadoc.h"

//código terminado entrega segunda - Fim
/*Comando para execução no terminal:
gcc main.c Patricia/pat.c TST/tst.c IndiceInvertido/indiceInvertido.c Lista/listadoc.c -o e 
*/

/*Executando com o gtk:
gcc `pkg-config --cflags gtk+-3.0` -o r main.c ./Patricia/pat.c ./Lista/listadoc.c ./TST/tst.c ./IndiceInvertido/indiceInvertido.c `pkg-config --libs gtk+-3.0`
*/

GtkBuilder *builder;//projeto
GtkWidget *window, *textviapont, *textopat, *textautocomplete, *textrelevancia;//janela
GtkStack *stack;
GtkListStore *modelodeArmazenamento;
GtkTextBuffer *buffer, *buffer2, *buffer3, *buffer4;
GtkTextIter iter, iter2, iter3, iter4;
TipoArvorePat patriciaInterface;
TipodoNOTST *TSTinterface;
Ldocs *ListadedocInterface, *Listaderelevancia;
palavraprio *palavrasinterface;

void erike(GtkTextBuffer *buffer, GtkTextIter *iter){
    for(int i=0; i<10; i++){
      gtk_text_buffer_insert(buffer, &(*iter),"asdfkjhas\n", -1);
      gtk_text_iter_forward_to_end(&(*iter));
    }
}

//abertura da pagina principal
void main_window_destroy_cb(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

//primeiro botao clicado e abertura da inserção do arquivo
void botao_1_clicked_cb(GtkWidget *widget, gpointer data){
    //gtk_main_quit();
    gtk_stack_set_visible_child_name(stack, "patiarquivo");
}

//abertura da parte da tst e inserção do arquivo no dicionario de palavras
void botao_2_clicked_cb(){
    gtk_stack_set_visible_child_name(stack, "paginaTSTinserearquivo");
}

//aperta o botao 3 e mostra os indices da patricia e imprime as palavras
void botao_3_clicked_cb(GtkWidget *widget, gpointer data){
    
    gtk_text_buffer_set_text(buffer2, "",-1);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(buffer2), &iter2, 0);

    gtk_text_buffer_insert(buffer2, &iter2,"Palavras => < qtd, id >\n\n", -1);
    gtk_text_iter_forward_to_end(&iter2);

    imprimePatGTK(&patriciaInterface, buffer2, &iter2);
    gtk_stack_set_visible_child_name(stack, "paginadaimpressaodapat");
}
//aperta o botao 4 para a impressão da arvore tst
void botao_4_clicked_cb(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack,"paginadaimpressaotst");
    gtk_text_buffer_set_text(buffer, "",-1);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(buffer), &iter, 0);
    imprimeTSTGTK(TSTinterface, buffer, &iter);  
}

//aperta o botao 5 e pesquisa na patricia a palavra e retorna os arquivos
void botao_5_clicked_cb(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack,"paginadepesquisapalavrapatricia");
}
//aperta este botao e volta para o menu principal
void voltar_patArqu_clicked_cb(GtkWidget *widget, gpointer data){
     gtk_stack_set_visible_child_name(stack, "pageinicial");
}

//botao para voltar ao menu da tst
void button_volta_tst_menu_clicked_cb(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "pageinicial");
}
//botao impressao da patricia e mostrando seus indices invertidos
void botaovoltaimpressapat_clicked_cb(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "pageinicial");
}
void botavoltamenuimpressaotst_clicked_cb(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "pageinicial");
}

void botaopesquisapatvoltamenu_clicked_cb(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "pageinicial");
}

void mensagem(char text[100], char secondary_text[100], char icon_name[100]){
    GtkMessageDialog *mensagem_dialogo = gtk_builder_get_object(builder,"msgparaadicionarArqpat");
    g_object_set(mensagem_dialogo, "text", text, NULL);
    g_object_set(mensagem_dialogo, "secondary_text", secondary_text, NULL);
    g_object_set(mensagem_dialogo, "icon_name", icon_name, NULL);
    
    gtk_widget_show_all(mensagem_dialogo);//abrindo mensagem
    gtk_dialog_run     (mensagem_dialogo);//esperando o usuário digitar
    gtk_widget_hide    (mensagem_dialogo);//fechar mensagem
}
//insere arquivo na patricia
void InsereArquivo_GTK_PAT(char *id, char *Narquivo){
    FILE *arquivo;
    int a = atoi(id);
    arquivo = fopen(Narquivo,"r");
    if(arquivo == NULL){
         mensagem("Arquivo Inexistente"," digite outro","dialog-error");
         gtk_stack_set_visible_child_name(stack, "patiarquivo");
    }else{
        leiturPAT(&patriciaInterface, Narquivo, a,ListadedocInterface);
        mensagem("Arquivo Inserido na Patricia"," Inserção concluida","emblem-default");
        gtk_stack_set_visible_child_name(stack, "patiarquivo");

    }
}
//botao para adicionar o arquivo na patricia
void adicionarpatarqu_clicked_cb(GtkWidget *widget, gpointer data){
    char *id  = gtk_entry_get_text(gtk_builder_get_object(builder,"id"));
    char *nomeArq = gtk_entry_get_text(gtk_builder_get_object(builder, "nomearquivo"));
    
    InsereArquivo_GTK_PAT(id, nomeArq);
    
}
//botao para inserir aquivo na TST
void on_butaoinserearquivonatst_clicked_cb(GtkWidget *widget, gpointer data){
    char *nomeArquivo = gtk_entry_get_text(gtk_builder_get_object(builder, "insercaoArquivoTSTd"));
    insercaoArquivoTST(nomeArquivo);
}

//funcção para a inserçao de um arquivo na tst
void insercaoArquivoTST(char *nomear){
    FILE *arquivo;
    arquivo = fopen(nomear,"r");
    if(arquivo == NULL){
        mensagem("Arquivo Inexistente"," digite outro","dialog-error");
        gtk_stack_set_visible_child_name(stack, "paginaTSTinserearquivo");
    }else{
        FILE *arquivo;
        char palavra[50];
        arquivo = fopen(nomear, "r");

        while (!feof(arquivo))
        {
            fscanf(arquivo, "%s", palavra);
            for(int i = 0; palavra[i]; i++){
                palavra[i] = tolower(palavra[i]);
            }
            TSTInsert(&TSTinterface, palavra);
        }
       mensagem("Arquivo Inserido na TST"," Inserção concluida","emblem-default");
       gtk_stack_set_visible_child_name(stack, "paginaTSTinserearquivo");
    }
}

void botaoAucomplete_clicked_cb(GtkWidget *widget, gpointer data){
    char *palavra = gtk_entry_get_text(gtk_builder_get_object(builder, "completepat"));
    gtk_text_buffer_set_text(buffer3, "",-1);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(buffer3), &iter3, 0);
    int i = 0;
   // char palavra[50];
   g_print(palavra);
    char saida[50];
     // printf("Digite o prefixo desejado: ");
        //    scanf("%s", palavra);
            for(int i = 0; palavra[i]; i++){
                palavra[i] = tolower(palavra[i]);
            }
            //if (auto_compliteGTK(TSTinterface, palavra, saida, &i, buffer3, &iter3) == 0)
            {
                printf("Nao existe palavras com essa prefixacao na biblioteca\n");
            }
            i = 0;
}

void botaorelevancia_clicked_cb(GtkWidget *widget, gpointer data){
     char *valor = gtk_entry_get_text(gtk_builder_get_object(builder, "quantidapta"));
     char *palavra =  gtk_entry_get_text(gtk_builder_get_object(builder, "palavapesquisa"));
    gtk_text_buffer_set_text(buffer4, "",-1);
    gtk_text_buffer_get_iter_at_offset(GTK_TEXT_BUFFER(buffer4), &iter4, 0);
     int qtd = atoi(valor);
    
        palavrasinterface = (palavraprio *)malloc(qtd * sizeof(palavraprio));
        for (int i = 0; i < qtd; i++)
        {
           // char *palavra =  gtk_entry_get_text(gtk_builder_get_object(builder, "palavapesquisa"));
            strcpy(palavrasinterface[i].nome, palavra);
            palavrasinterface[i].dj = 0;
        }
        //relevancia(&patriciaInterface, palavrasinterface, ListadedocInterface, Listaderelevancia, qtd);
        g_print("asdfasdfasdfasdfasdfasdfasdfsdf");
        for(int i =0; i<10; i++){
            insereRelevancia(Listaderelevancia, 1, "arquivo1.txt", 2);
        }
        ImprimerDocumetosprioridadeGTK(Listaderelevancia, buffer4, &iter);
     
}



int main(int argc, char **argv){

    
   patriciaInterface = NULL;
   Listaderelevancia = (Ldocs*)malloc(sizeof(Ldocs));
   ListadedocInterface = (Ldocs*)malloc(sizeof(Ldocs));
   inicializadocs(ListadedocInterface);
   inicializadocs(Listaderelevancia);
   TSTInit(&TSTinterface);
   GtkWidget *botao3, *botao4, *botaoAucomplete, *botaorelevancia;
  

   gtk_init(&argc, &argv);
   builder = gtk_builder_new_from_file("ui.glade");


    botao3 = GTK_WIDGET(gtk_builder_get_object(builder, "botao-3"));
    textviapont = GTK_WIDGET(gtk_builder_get_object(builder, "impressaotstid"));
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textviapont));

    botao4 = GTK_WIDGET(gtk_builder_get_object(builder, "botao-4"));
    textopat = GTK_WIDGET(gtk_builder_get_object(builder, "imprimepatriciaidgabriel"));
    buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textopat));

    botaoAucomplete = GTK_WIDGET(gtk_builder_get_object(builder, "Autocompletebuton"));;
    textautocomplete = GTK_WIDGET(gtk_builder_get_object(builder, "autocomplete"));
    buffer3 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textautocomplete));


    botaorelevancia = GTK_WIDGET(gtk_builder_get_object(builder, "chamaarquivos"));;
    textrelevancia = GTK_WIDGET(gtk_builder_get_object(builder, "imprimirarquivos"));
    buffer4 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textrelevancia));

   gtk_builder_add_callback_symbols(builder, 
   "main_window_destroy_cb",  G_CALLBACK(main_window_destroy_cb), 
   "botao_1_clicked_cb"   ,   G_CALLBACK(botao_1_clicked_cb),
   "botao_2_clicked_cb",      G_CALLBACK(botao_2_clicked_cb),
   "botao_5_clicked_cb",      G_CALLBACK(botao_5_clicked_cb),
   "voltar_patArqu_clicked_cb", G_CALLBACK(voltar_patArqu_clicked_cb),
   "adicionarpatarqu_clicked_cb", G_CALLBACK(adicionarpatarqu_clicked_cb),
   "button_volta_tst_menu_clicked_cb", G_CALLBACK(button_volta_tst_menu_clicked_cb),
   "botaovoltaimpressapat_clicked_cb", G_CALLBACK(botaovoltaimpressapat_clicked_cb),
   "botavoltamenuimpressaotst_clicked_cb", G_CALLBACK(botavoltamenuimpressaotst_clicked_cb),
   "botaopesquisapatvoltamenu_clicked_cb", G_CALLBACK(botaopesquisapatvoltamenu_clicked_cb),
   "on_butaoinserearquivonatst_clicked_cb", G_CALLBACK(on_butaoinserearquivonatst_clicked_cb),
    NULL);

    g_signal_connect(G_OBJECT(botao3), "clicked", G_CALLBACK(botao_3_clicked_cb), NULL);
    g_signal_connect(G_OBJECT(botao4), "clicked", G_CALLBACK(botao_4_clicked_cb), NULL);
    g_signal_connect(G_OBJECT(botaoAucomplete), "clicked", G_CALLBACK(botaoAucomplete_clicked_cb), NULL);
    g_signal_connect(G_OBJECT(botaorelevancia), "clicked", G_CALLBACK(botaorelevancia_clicked_cb), NULL);
    gtk_builder_connect_signals(builder, NULL);
    stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    modelodeArmazenamento = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore1"));

    gtk_widget_show_all(window);
    gtk_main();


    Ldocs *LArquivos, *LArquivosPrio;
    LArquivos = (Ldocs *)malloc(sizeof(Ldocs));
    LArquivosPrio = (Ldocs *)malloc(sizeof(Ldocs));
    int qtd;
    int id;
    inicializadocs(LArquivos);
    inicializadocs(LArquivosPrio);
    palavraprio *palavras;
    TipodoNOTST *TST;
    TSTInit(&TST);
    TipoArvorePat Patricia = NULL;
    bool op1 = true;
    char palavra[50], saida[50];
    char nomeArqui[50];
    int opcao;
    int i = 0;

    while (op1 == true)
    {
        printf("\n");
        printf("|-------------------------------MENU------------------------------------|\n");
        printf("| 1 - Construir o indice invertido usando a Patricia.                   |\n");
        printf("| 2 - Inserir as palavras do dicionario na arvore TST.                  |\n");
        printf("| 3 - Imprimir o Indice Invertido.                                      |\n");
        printf("| 4 - Imprimir as palavras da TST.                                      |\n");
        printf("| 5 - Buscar por uma palavra na PATRICIA, a partir do indice construido.|\n");
        printf("| 6 - Auto Complete.                                                    |\n");
        printf("| 7 - Sair.                                                             |\n");
        printf("|-----------------------------------------------------------------------|\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Digite o id:\n");
            scanf("%d", &id);
            printf("Digite o nome do arquivo:\n");
            scanf("%s", nomeArqui);
            leiturPAT(&Patricia, nomeArqui, id, LArquivos);
            //ImprimerDocumetosprioridade(LArquivos);
        }
        else if (opcao == 2)
        {
            FILE *arquivo;
            char palavra[50];

            printf("Digite o nome do arquivo:\n");
            scanf("%s", nomeArqui);
            arquivo = fopen(nomeArqui, "r");

            while (!feof(arquivo))
            {
                fscanf(arquivo, "%s", palavra);
                for(int i = 0; palavra[i]; i++){
                    palavra[i] = tolower(palavra[i]);
                }
                TSTInsert(&TST, palavra);
            }
        }

        else if (opcao == 3)
        {
            printf("<qtd, id>\n");
            ImprimePalavrasPat(&Patricia);
        }
        else if (opcao == 4)
        {
            printf("imprimindo as palavras da tst...\n");
            imprimeTST(TST);
        }
        else if (opcao == 5)
        {
            if(Patricia == NULL){
                printf("Insira Arquivos na Patricia!!!\n");
            }else{
            int existe = 0;
            printf("Digite a quantidade de palavras que deseja buscar:\n");
            scanf("%d", &qtd);
            palavras = (palavraprio *)malloc(qtd * sizeof(palavraprio));
            for (int i = 0; i < qtd; i++)
            {
                printf("Digite o primeiro termo da pesquisa:\n");
                setbuf(stdin, 0);
                scanf("%s", palavras[i].nome);
                fflush(stdin);
                /*while (existe == 0){
                    printf("Digite o %d termo da pesquisa:\n", i+1);
                   // setbuf(stdin, 0);
                    scanf("%s", palavras[i].nome);
                    existenaPAt(&Patricia, palavras[i].nome, &existe);
                    if(existe == 0){
                        printf("Esta palavra nao existe na patricia Digite novamente!!\n");
                    }else{
                        break;
                    }
                }*/
                palavras[i].dj = 0;
            }
            relevancia(&Patricia, palavras, LArquivos, LArquivosPrio, qtd);
            ImprimerDocumetosprioridade(LArquivosPrio);
            inicializadocs(LArquivosPrio);
        }
        }
        else if (opcao == 6)
        {
            printf("Digite o prefixo desejado: ");
            scanf("%s", palavra);
            for(int i = 0; palavra[i]; i++){
                palavra[i] = tolower(palavra[i]);
            }
            if (auto_complite(TST, palavra, saida, &i) == 0)
            {
                printf("Nao existe palavras com essa prefixacao na biblioteca\n");
            }
            i = 0;
        }

        else if (opcao == 7)
        {
            op1 = false;
        }
        else
        {
            printf("Opcao Invalida. Digite novamente.\n");
        }
    }
    return 0;
}

//gcc `pkg-config --cflags gtk+-3.0` -o r main.c `pkg-config --libs gtk+-3.0`
//gcc `pkg-config --cflags gtk+-3.0` -o r main.c ./Patricia/pat.c ./Lista/listadoc.c ./TST/tst.c ./IndiceInvertido/indiceInvertido.c `pkg-config --libs gtk+-3.0`