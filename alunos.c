#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.c"

typedef struct Aluno
{
    int matricula;
    float media;
    char nome[15];
}aluno;

col* c;

aluno* criar_aluno()
{
    aluno* aux;

    aux = (aluno*)malloc(sizeof(aluno));

    if(aux != NULL)
    {
        aux->matricula = 0;
        strcpy(aux->nome, "");
        aux->media = 0;

        return aux;
    }
    return NULL;
}

void mostrar_aluno(aluno *aux)
{
    int i;

    for(i=0; i<c->tam; i++)
    {
        aux = (aluno*)mostrar_colecao(c, i);

        printf("Matricula: %d\tNome: %s\tMedia: %.1f\n", aux->matricula, aux->nome, aux->media);
    }
}

void pesquisar_matricula(aluno* aux, int matricula)
{
    int i, flag=0;

    for(i=0; i<c->tam; i++)
    {
        aux = (aluno*)mostrar_colecao(c, i);

        if(aux->matricula == matricula)
        {
            printf("-- Aluno encontrado --\n");
            printf("Matricula: %d\tNome: %s\tMedia: %.1f\n", aux->matricula, aux->nome, aux->media);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("-- Aluno nao encontrado --\n");
    }
}

void pesquisar_nome(aluno* aux, char* nome)
{
    int i, flag=0;
    char *saux;

    for(i=0; i<c->tam; i++)
    {
        aux = (aluno*)mostrar_colecao(c, i);

        saux = strstr(aux->nome, nome);

        if(saux != NULL)
        {
            printf("-- Aluno encontrado --\n");
            printf("Matricula: %d\tNome: %s\tMedia: %.1f\n", aux->matricula, aux->nome, aux->media);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("-- Aluno nao encontrado --\n");
    }

}

void pesquisar_media(aluno* aux, float media)
{
    int i, flag=0;
    for(i=0; i<c->tam; i++)
    {
        aux = (aluno*)mostrar_colecao(c, i);

        if(aux->media == media)
        {
            printf("-- Aluno encontrado --\n");
            printf("Matricula: %d\tNome: %s\tMedia: %.1f\n", aux->matricula, aux->nome, aux->media);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("-- Aluno nao encontrado --\n");
    }
}

void remover_matricula(aluno* aux, int matricula)
{
    int i, flag = 0;

    for(i=0; i<c->tam; i++)
    {
        aux = (aluno*)mostrar_colecao(c, i);

        if(aux->matricula == matricula)
        {
            remover_colecao(c, i);
            printf("-- Aluno removido --\n");
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("-- Aluno nao removido --\n");
    }
}

void remover_nome(aluno* aux, char* nome)
{
    int i, flag = 0;
    char *saux;

    for(i=0; i<c->tam; i++)
    {
        aux = (aluno*)mostrar_colecao(c, i);

        saux = strstr(aux->nome, nome);

        if(saux != NULL)
        {
            remover_colecao(c, i);
            printf("-- Aluno removido --\n");
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("-- Aluno nao removido --\n");
    }
}

void remover_media(aluno* aux, float media)
{
    int i, flag = 0;

    for(i=0; i<c->tam; i++)
    {
        aux = (aluno*)mostrar_colecao(c, i);

        if(aux->media == media)
        {
            remover_colecao(c, i);
            printf("-- Aluno removido --\n");
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("-- Aluno nao removido --\n");
    }
}

int main()
{
    aluno *a, *b;

    int i, num, matricula, op, loop=1;
    char nome[15];
    float media;
    
    printf("Entre com o numero de alunos: ");
    scanf("%d", &num);

    c = criar_colecao(num);
    
    if(c != NULL)
    {

        printf("\t-- Inserir Alunos --\n");
        for(i=0; i<num; i++)
        {
            a = criar_aluno();
            if(a != NULL)
            {
                a->matricula = i+1;
                printf("Nome -> ");
                scanf("%s", &a->nome);
                printf("Media -> ");
                scanf("%f", &a->media);
                inserir_colecao(c, (void*)a);
            }
            else
            {
                printf("Impossivel fazer operacao!\n");
                system("pause");
                return 0;
            }
    
            fflush(stdin);
        }
    
        mostrar_aluno(a);
    
        while(loop != 0)
        {
    
            printf("\n-- Pesquisar por --\n");
            printf("(1)matricula\t(2)nome\t(3)media\n-> ");
            scanf("%d", &op);
    
            switch(op)
            {
                case 1:
                    printf("Matricula -> ");
                    scanf("%d", &matricula);
                    pesquisar_matricula(a, matricula);
                    break;
                case 2:
                    printf("Nome -> ");
                    scanf("%s", &nome);
                    pesquisar_nome(a, nome);
                    break;
                case 3:
                    printf("Media -> ");
                    scanf("%f", &media);
                    pesquisar_media(a, media);
                    break;
                default:
                    printf("opcao invalida!");
                    break;
            }
            printf("\nDeseja fazer outra pesquisa?\n 1 - continua\t0 - termina\n-> ");
            scanf("%d", &loop);
        }
    
        loop = 1;
    
        while(loop != 0)
        {
            printf("\n\t-- Remover por --\n");
            printf("(1)matricula\t (2)nome\t (3)media\n->");
            scanf("%d", &op);
    
            switch(op)
            {
                case 1:
                    printf("Matricula -> ");
                    scanf("%d", &matricula);
                    remover_matricula(a, matricula);
                    break;
                case 2:
                    printf("Nome -> ");
                    scanf("%s", &nome);
                    remover_nome(a, nome);
                    break;
                case 3:
                    printf("Media -> ");
                    scanf("%f", &media);
                    remover_media(a, media);
                    break;
                default:
                    printf("opcao invalida!");
                    break;
            }
            printf("\nDeseja fazer outra pesquisa?\n 1 - continua\t0 - termina\n-> ");
            scanf("%d", &loop);
        }
    
        mostrar_aluno(a);
    }
    else
    {
        printf("Impossivel fazer operacao!\n");
        system("pause");
        return 0;
    }
    
    system("pause");
    return 0;
}
