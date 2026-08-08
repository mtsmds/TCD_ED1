#include <stdio.h>
#include "funcoes.h"
#include <string.h>
#include <stdlib.h>

// lista simplesmente encadeada

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir(Lista *lst, Lista *feed, char *titulo, int *status, int *nota, Fila X)
{
    if (*status == 3) // se status = lendo, insere na lista circular
    {
        inserir_feed(feed, titulo, nota, status);
    }
    else if(*status == 2) // se status == quero ler, insere na fila de leitura
    {
        
        inserir_fila(&X, titulo);
    }

    Lista aux = *lst;
    //char temp[50];
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;
    }
    strcpy(N->livro, titulo);

    N->status = *status;
    N->nota = *nota;

    if (lista_vazia(*lst) == 1)
    {
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}


int remove_lst(Lista *lst, char *titulo)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }

    Lista aux = *lst;
    if(strcmp(titulo, (*lst)->livro) == 0)
    {
        *lst = aux->prox;
        free(aux);
        return 1;
    }
    while(aux->prox != NULL && strcmp(aux->prox->livro, titulo) != 0)
    {
        aux = aux->prox;

    }
    if(aux->prox == NULL)
    {
        return 0;
    }

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

// lista circular
void exibir_feed(Lista lst)
{
    char situ[10];

    if (lst == NULL)
    {
        printf("lista vazia");
        return;
    }
    if (lst->status == 1)
    {
        strcpy(situ, "lido");
    }
    else if (lst->status == 2)
    {
        strcpy(situ, "quero ler");
    }
    else if (lst->status == 3)
    {
        strcpy(situ, "lendo");
    }
    else
    {
        strcpy(situ, " ");
    }

    printf("\nTitulo: %sStatus: %s\n", lst->livro, situ);
}

void alterar_status(Lista lst, int *status, char *titulo)
{
    while(lst != NULL)
    {
        if(strcmp(lst->livro, titulo) == 0)
        {
            lst->status = *status;
            return;
        }

        lst = lst->prox;
    }
}

void alterar_status_lstdupla(Lidup lst, int *status, char *titulo)
{
    while(lst != NULL)
    {
        if(strcmp(lst->livro , titulo) == 0)
        {
            lst->status = *status;
            return;
        }
        lst = lst->prox;
    }
}

/*void marcar_lido(Lista lst, int *nota, char *titulo)
{
    if(lst == NULL)
        return;

    Lista inicio = lst;

    do
    {
        if(strcmp(lst->livro, titulo) == 0)
        {
            lst->nota = *nota;
            lst->status = 1;
            return;
        }

        lst = lst->prox;

    }while(lst != inicio);
}
    */

void alterar_nota(Lista lst, int *nota, char *titulo)
{
    while(lst != NULL)
    {
        if(strcmp(lst->livro, titulo) == 0)
        {
            lst->nota = *nota;
            return;
        }

        lst = lst->prox;
    }
}

int inserir_feed(Lista *lst, char *titulo, int *nota, int *status)
{

    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0;
    }
    strcpy(N->livro, titulo);
    N->nota = *nota;
    N->status = *status;

    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
        return 1;
    }
    else
    {
        N->prox = (*lst)->prox;
        (*lst)->prox = N; 
        (*lst) = N;
        return 1;
    }
}
int remover_feed(Lista *lst, char *titulo)
{
    if(lista_vazia(*lst) == 1)
    {
        return 0;
    }

    Lista atual = (*lst)->prox; // primeiro nó
    Lista anterior = *lst;


    do
    {
        if(strcmp(atual->livro, titulo) == 0)
        {
            // so um elemento
            if(atual == anterior)
            {
                free(atual);
                *lst = NULL;
            }
            else
            {
                anterior->prox = atual->prox;

                // se removeu o ultimo
                if(atual == *lst)
                {
                    *lst = anterior;
                }

                free(atual);
            }

            return 1;
        }


        anterior = atual;
        atual = atual->prox;


    }while(atual != (*lst)->prox);


    return 0;
}

// lista duplamente encadeada
Lidup cria_lista_dup()
{
    return NULL;
}

int lista_vaziadupl(Lidup lst)
{
    if (lst == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_dupla(Lidup *nav, char *titulo, int *nota, int *status) // copiar a lista simplesment encadeada para uma duplamente encadeada
{
    Lidup N = (Lidup)malloc(sizeof(struct dup));
    if (N == NULL)
    {
        return 0;
    }
    strcpy(N->livro, titulo);
    N->nota = *nota;
    N->status = *status;
    N->ant = NULL;
    N->prox = *nav;

    if (lista_vaziadupl(*nav) == 0)
    {
        (*nav)->ant = N;
    }
    *nav = N;
    return 1;
}

int converte_ldu(Lidup *ldu, Lista lst)
{
    while (lst != NULL)
    {
        inserir_dupla(ldu, lst->livro, &lst->nota, &lst->status);
        lst = lst->prox;
    }
    return 1;
}

void alterarnota_dupla(Lidup ldu, int *novanota, char *titulo)
{
    while(ldu != NULL)
    {
        if(strcmp(ldu->livro, titulo) == 0)
        {
            ldu->nota = *novanota;
            return;
        }

        ldu = ldu->prox;
    }
}

void exibir_lista(Lidup ldu)
{
    char situ[15];

    if (ldu == NULL)
    {
        printf("lista vazia");
        return;
    }
    if (ldu->status == 1)
    {
        strcpy(situ, "lido");
    }
    else if (ldu->status == 2)
    {
        strcpy(situ, "quero ler");
    }
    else if (ldu->status == 3)
    {
        strcpy(situ, "lendo");
    }
    else
    {
        strcpy(situ, " ");
    }

    printf("Titulo: %s - Status: %s - Nota: %d", ldu->livro, situ, ldu->nota);
}

// fila - meta de leitura

Fila cria_fila()
{
    Fila F = (Fila)malloc(sizeof(struct ini));
    if (F != NULL)
    {
        F->ini = NULL;
        F->fim = NULL;
    }
    return F;
}

int fila_vazia(Fila fila)
{
    if ( fila == NULL||fila->ini == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_fila(Fila *fla, char *titulo)
{
    struct nofila * N;
    N = (struct nofila*)malloc(sizeof(struct nofila));
    if (N == NULL)
    {
        return 0;
    }
    strcpy(N->livro, titulo);
    N->prox = NULL; //define o proximo elemento da fila como null

    if (fila_vazia(*fla) == 1)
    {
        (*fla)->ini = N;
        (*fla)->fim = N;
        return 1;
    }
    else
    {
        ((*fla)->fim)->prox = N;//fila com elementos
        (*fla)->fim = N; //fim aponta pra N 
        return 1;
    }
}

void exibir_fila(Fila fla)
{

    if(fla == NULL || fila_vazia(fla) == 1)
    {
        printf("fila vazia");
        
    }
    else
    {
            printf("Titulo: %s Status: quero ler ", (fla->ini)->livro);
    }

    
}

int remover_fila(Fila *fla)
{
    if(fila_vazia(*fla))
        return 0;

    struct nofila *aux = (*fla)->ini;

    (*fla)->ini = aux->prox;

    if((*fla)->ini == NULL)
        (*fla)->fim = NULL;

    free(aux);

    return 1;
}


// pilha


Pilha cria_pilha()
{
    return NULL;
}
int empilhar(Pilha *pi, int tipo, char *titulo,int status, int nota)
{
    Pilha no = malloc(sizeof(struct pi));

    if(no == NULL)
    {
        return 0;
    }
    no->tipo = tipo;

    strcpy(no->livro, titulo);

    no->status = status;
    no->nota = nota;

    no->prox = *pi;
    

    *pi = no;
    return 1;
}


void desempilhar( Pilha *p, Lista *lst, Lista *feed, Fila *fla)
{
    if(*p == NULL)
    {
        printf("nenhuma acao feita");
        return;

    }
        Pilha aux = *p;

switch ((*p)->tipo)
{
case 1:
    // Desfazer cadastro
    remove_lst(lst, (*p)->livro);
    printf("acao desfeita");
    break;

case 2:// desfazer remoção
    inserir(lst, NULL, (*p)->livro, &(*p)->status, &(*p)->nota, *fla);
    printf("acao desfeita");
    break;

case 3://reverter status
    alterar_status(*lst, &(*p)->status, (*p)->livro);
    inserir_feed(feed, (*p)->livro, &(*p)->nota, &(*p)->status);
    printf("acao desfeita");
    break;

case 4://reverter nota
    {
        int status = 3;
        
    alterar_nota(*lst, &(*p)->nota, (*p)->livro);
    alterar_status(*lst, &status, (*p)->livro);
   printf("acao desfeita");


    break;
    }
default:
    break;
}

*p = (*p)->prox;
free(aux);



}

   /* Pilha aux = *p;

    switch ((*p)->tipo)
    {
    case 1:
        //cadastrar = 1, excluir = 2, alterar status = 3, alterar nota = 4
        remove_lst(*lst, titulo);
        break;
    case 2:
    inserir(*lst, NULL, *titulo, status, nota, NULL);

    break;

    case 3:
        

    break;

    case 4:

    break;
    default:
        break;
    }
}
    */
