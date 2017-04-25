#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha
{
    int max, size, beg, end;
    int* vet;

}pilha;

pilha* criar_pilha(int max);
void inserir_pilha(pilha* aux, int x);
void remover_pilha(pilha* aux);
void destruir_pilha(pilha* aux);
int mostrar_pilha(pilha* aux, int x);

void main(void)
{
    pilha *p;
    char *aux;
    int a;

    p = criar_pilha(3);
    inserir_pilha(p, 1);
    inserir_pilha(p, 2);
    inserir_pilha(p, 3);
    a = mostrar_pilha(p, 0);
    printf("%d", a);


}

pilha* criar_pilha(int max)
{
    pilha* aux;

    if(max > 0)
    {
        aux = (pilha*)malloc(sizeof(pilha));
        if(aux != NULL)
        {
            aux->vet = (int*)malloc(max*sizeof(int));
            if(aux->vet != NULL)
            {
                aux->max = max;
                aux->size = 0;
                aux->beg = 0;
                aux->end = max;

                return aux;
            }
        }
    }
    return NULL;
}

void inserir_pilha(pilha* aux, int x)
{
    if(aux != NULL && aux->vet != NULL && aux->size > aux->max)
    {
        aux->vet[aux->size] = x;
        aux->size++;

        if(aux->end < aux->size -1)
            aux->end++;
        else
            aux->end = 0;
    }
}

void remover_pilha(pilha* aux)
{
    int i;

    if(aux != NULL && aux->vet != NULL && aux->size >= 0)
    {
        aux->size--;

        if(aux->beg < aux->size -1)
            aux->beg++;
        else
            aux->beg = 0;
    }
}

void destruir_pilha(pilha* aux)
{
    if(aux != NULL && aux->size <= 0)
    {
        free(aux->vet);
        free(aux);
    }
}

int mostrar_pilha(pilha* aux, int x)
{
    if(aux != NULL && aux->vet != NULL)
    {
        return aux->vet[x];
    }
    return 0;
}
