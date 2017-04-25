#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;

typedef struct _Fila_{
    int max, tam, beg, end;
    void** vet;
}Fila;

Fila* criar_fila(int max);
int destruir_fila(Fila *f);
int inserir_fila(Fila *f, void* x);
int remove_fila(Fila *f);

Fila* criar_fila(int max)
{
    Fila *f;

    if(max > 0)
    {
        f = (Fila*)malloc(sizeof(Fila));
        if(f != NULL)
        {
            f->vet = (void**)malloc(max*sizeof(void*));
            if(f->vet != NULL)
            {
                f->max = max;
                f->tam = 0;
                f->beg = 0;
                f->end = 0;
                return f;
            }
        }
        free(f) ;
    }

    return NULL;
}


int destruir_fila(Fila *f)
{
    if(f != NULL && f->tam <= 0)
    {
        free(f->vet);
        free(f);
        return TRUE;
    }
    return FALSE
}

int inserir_fila(Fila *f, void* x)
{
    if(f != NULL && f->vet != NULL && f->tam < f->max -1)
    {
        f->vet = x;
        f->tam++;

        if(f->end < f->tam -1)
            f->end++;
        else
            f->end = 0;

        return TRUE;
    }

    return FALSE;
}

int remove_fila(Fila *f)
{
    void* aux;
    int i;

    if(f != NULL && f->vet != NULL && f->tam >= 0)
    {
        aux = f->vet[0];

        for(i=0; i<f->tam-1; i++)
        {
            f->vet[i] = f->vet[i+1];
        }

        f->tam--;

        if(f->beg < f->tam -1)
            f->beg++;
        else
            f->beg = 0;

        return TRUE;
    }

    return FALSE;
}
