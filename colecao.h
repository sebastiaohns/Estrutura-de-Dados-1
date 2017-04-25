#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef struct colecao
{
    int max;
    int tam;
    void** vet;
}col;

void* criar_colecao(int max);
int inserir_colecao(col* c, void* x);
int remover_colecao(col* c, int x);
void* mostrar_colecao(col* c, int x);
int destruir_colecao(col* c);

int cmp(const void* a, const void* b);
