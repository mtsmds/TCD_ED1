#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>

int main()
{
    int opcao = 0;
    Lista listasimples = cria_lista(); 
    Lista circular = cria_lista();
    Fila fla = cria_fila();
    Pilha pi = cria_pilha();
    do
    {
        printf("[1] - cadastrar livro\n[2] - ver livros\n[3] - feed de livros em andamento\n[4] - gerenciar meta de leitura\n[5] - desfazer ultima acao\n[6] - sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            int status;
            char titulo[50];
            int nota = 00;

            printf("Digite o titulo do livro:  ");
            while (getchar() != '\n') //tirar o \n do scanf
                ;
            fgets(titulo, sizeof(titulo), stdin);

            printf("[1] - lido\n[2] - quero ler\n[3] - lendo\n");
            scanf("%d", &status);
            if (status > 3)
            {
                printf("digite um valor valido\n");
                break;
            }
            else if (status == 1)
            {
                printf("Digite a nota do livro (1-5):  ");

                scanf("%d", &nota);
            }
            else
            {
                nota = 0;
            }

            if (inserir(&listasimples, &circular, titulo, &status, &nota, fla) == 1)
            {
                printf("registro inserido!\n");
                

                empilhar(&pi, 1, titulo, 0, 0);
            }
            break;
        }

        case 2:
        {
            Lidup listadupla = cria_lista_dup();
            int navegar = 0;
            converte_ldu(&listadupla, listasimples);
            do
            {
                exibir_lista(listadupla);
                printf("\n\n[1] - proximo  [2] - anterior  [3] - alterar nota [4] - parar\n");

                scanf("%d", &navegar);

                if (navegar == 1)
                {
                    if (listadupla->prox == NULL)
                    {
                        printf("nao ha proximo livro\n");
                    }
                    else
                    {
                        listadupla = listadupla->prox;
                    }
                }
                else if (navegar == 2)
                {
                    if (listadupla->ant == NULL)
                    {
                        printf("nao ha livro anterior\n");
                    }
                    else
                    {
                        listadupla = listadupla->ant;
                    }
                }
                else if(navegar == 3)
                {
                    int novanota = 0;
                    int novostatus = 1;
                    printf("\ndigite a nota nova: ");
                    scanf("%d", &novanota);
                    empilhar(&pi, 4, listadupla->livro, 0, listadupla->nota);
                    alterar_nota(listasimples, &novanota, listadupla->livro);
                    alterarnota_dupla(listadupla , &novanota,  listadupla->livro);
                    alterar_status_lstdupla(listadupla, &novostatus, listadupla->livro);
                    alterar_status(listasimples, &novostatus, listadupla->livro);
                }

                if (navegar == 4)
                {
                    free(listadupla);
                }
            } while (navegar != 4);
            break;
        }
        case 3:
        {
            int x = 0;
            int add_nota = 0;
            Lista aux = circular; //aux para n perder a referncia do ponteiro
            do
            {
                if (circular == NULL)
                {
                    printf("nao ha outros livros\n");
                    break;
                }
                else
                {
                    printf("\n[1] - proximo livro em andamento [2] - marcar como lido  [3] - sair\n");
                    scanf("%d", &x); // x armazena o numero escolhido pelo usuaio para avancar ou sair do submenu
                    if (x == 2)
                    {
                        printf("digite a nota desejada:  ");

                        scanf("%d", &add_nota);

                       
                        char titulo[50];
                        strcpy(titulo, aux->livro);
                        int novostatus = 1;
                        empilhar(&pi,3, aux->livro, aux->status, aux->nota);
                        
                        aux->nota = add_nota;
                        alterar_status(listasimples, &novostatus, aux->livro);
                     
                        remover_feed(&circular, titulo);
                    }
                    else if (x == 1)
                    {
                       
                         aux = aux->prox;
                        exibir_feed(aux);
                       
                    }
                    else if (x != 3)
                    {

                        printf("digite um valor valido");
                    }
                }
            } while (x != 3);
            break;
        }
        case 4:
        {
            int x = 0;
            do
            {

                exibir_fila(fla);
                printf("\n[1] - alterar status para lendo  [2] - sair\n");
                scanf("%d", &x);
                if (fla->ini == NULL)
                {
                    printf("\nfila vazia, saindo...\n");
                    break;
                }
                if (x == 1)
                {

                    int titu = 3;
                    int nota = 0;
                    empilhar(&pi, 3, (fla->ini)->livro, 2, 0);
                    inserir_feed(&circular, (fla->ini)->livro, &nota, &titu);
                    int statusnovo = 3; 
                    alterar_status(listasimples, &statusnovo, fla->ini->livro);
                    remover_fila(&fla);
                    printf("\nregistro inserido ao feed de livros em andamento!\n");
                }
            } while (x != 2);
            break;
        }
        case 5:
              desempilhar(&pi, &listasimples, &circular, &fla);
              printf("\n ultima acao desfeita\n");
              break;

        default:
            break;
        }

    } while (opcao != 6);
}
