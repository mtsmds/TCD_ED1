#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//estrutura da lista
typedef struct no{
    char livro[50];
    int status; //1 = lido, 2 = quero ler, 3 = lendo
    int nota;   //0-5
    struct no *prox;
}*Lista;

typedef struct dup{
    struct dup *ant;
    char livro[50];
    int status;
    int nota;
    struct dup *prox;
}*Lidup;

typedef struct nofila{

    char livro[50];
    
    struct nofila *prox;

}*nofila;

typedef struct ini{
    struct nofila *ini;
    struct nofila *fim;
}*Fila;

typedef struct pi{
    int tipo; // cadastrar = 1, excluir = 2, alterar status = 3, alterar nota = 4
    char livro[50];
    int status;
    int nota;
    struct pi *prox;
    Lista lst;
    Lidup ldp;
    Fila fla;

}*Pilha;



// fila estatica - notificacoes
#define MAX 10 // maximo de notificacoes
#define MSG 100 // tamanho da msg

typedef struct {
    char mensagens[MAX][MSG];
    int inicio;
    int fim;
    int total; // contador de elementos
} FilaNotificacoes;

void inicializar_fila_notif(FilaNotificacoes *f);

int fila_notif_vazia(FilaNotificacoes *f);

int fila_notif_cheia(FilaNotificacoes *f);

int enfileirar_notif(FilaNotificacoes *f, const char *msg);


int desenfileirar_notif(FilaNotificacoes *f, char *saida);

void exibir_notif(FilaNotificacoes *f);


void exibir_feed(Lista lst);

int inserir(Lista *lst, Lista *circular, char *titulo,  int *status, int *nota, Fila X);
int remover_feed(Lista *lst, char *titulo);

void marcar_lido(Lista lst, int *nota, char * titulo);

int lista_vazia(Lista lst);

void alterar_nota(Lista lst, int *nota, char *titulo);

int inserir_feed(Lista *lst, char *titulo, int *nota, int *status); 

Lista cria_lista();

void alterar_status(Lista lst, int *status, char *titulo);

//estrutura lista dupla


int inserir_dupla(Lidup *nav,  char *titulo, int *nota, int *status);

int converte_ldu(Lidup *ldu, Lista lst);

void exibir_lista(Lidup ldu);

void alterar_status_lstdupla(Lidup lst, int *status, char *titulo);

void alterarnota_dupla(Lidup ldu, int *novanota, char *titulo);

Lidup cria_lista_dup();

void alterar_nota_dupla(Lidup ldu, int nova_nota, char *titulo);

int lista_vaziadupl(Lidup lst);
int remover_lista(Lista *lst, char *titulo);

//estrutura fila



Fila cria_fila();

int inserir_fila(Fila *fla, char *titulo);

int remover_fila(Fila *fla);

void exibir_fila(Fila fla);


void desempilhar( Pilha *p, Lista *lst, Lista *feed, Fila *fla);

int empilhar(Pilha *pi, int tipo, char *titulo,int status, int nota);

Pilha cria_pilha();








