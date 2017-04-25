#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void* criar_colecao(int max)
{
    col* c;

    if(max > 0)
    {
        c = (col*)malloc(sizeof(col));
        if(c != NULL)
        {
            c->vet = (void**)malloc(max*sizeof(void*));
            if(c->vet != NULL)
            {
                c->max = max;
                c->tam = 0;
                return c;
            }
            free(c);
        }
    }
    return NULL;
}

int inserir_colecao(col* c, void* x)
{
    if(c != NULL && c->vet != NULL && c->tam < c->max)
    {
        c->vet[c->tam] = x;
        c->tam++;
        return TRUE;
    }
    return FALSE;
}

int remover_colecao(col* c, int x)
{
    int i, p;
    void* aux;

    if(c != NULL && c->vet != NULL)
    {
        for(i=x; i<c->tam; i++)
        {
            c->vet[i] = c->vet[i+1];
        }
        c->tam--;
        return TRUE;
    }
    return FALSE;
}

void* mostrar_colecao(col* c, int x)
{

    if(c != NULL && c->vet != NULL)
    {
        return c->vet[x];
    }
    return NULL;
}

int destruir_colecao(col* c)
{
    if(c != NULL && c->tam == 0)
    {
        free(c->vet);
        free(c);
        return TRUE;
    }
    return FALSE;
}
