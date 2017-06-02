#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev, *next;
}node;

typedef struct List
{
    node *first, *cur, *last;
}list;

list *criar();
int inserir(list*, int);
int remover(list*, int);
int apagar(list*);
int contar(list*);
node *pegar_primeiro(list*);
node *pegar_proximo(list*);
int pesquisar(list*, int);
void mostrar(list*);
