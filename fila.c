#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;

typedef struct _Fila_{
    int max;
    int tam;
    void** vet;
}Fila;

Fila* criar_fila(int max);
int destruir_fila(Fila *f);
int inserir_fila(Fila *f, void* x);
int remove_fila(Fila *f);

void main(void)
{

}

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
        f->vet[f->tam] = x;
        f->tam++;

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

        return TRUE;
    }

    return FALSE;
}
