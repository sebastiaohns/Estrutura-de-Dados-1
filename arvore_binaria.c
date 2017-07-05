#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma=0;

typedef struct Tnode
{
    int data;
    struct Tnode* l;
    struct Tnode* r;
}tnode;

tnode* criar()
{
    return NULL;
}

void insert(tnode** t, int num)
{
    if(*t == NULL)
    {
        *t = (tnode*)malloc(sizeof(tnode));
        (*t)->r = NULL;
        (*t)->l = NULL;
        (*t)->data = num;
    }
    else
    {
        if(num >= (*t)->data)
        {
            insert (&(*t)->r, num);
        }
        if(num < (*t)->data)
        {
            insert (&(*t)->l, num);
        }
    }
}

void abPreOrdem(tnode *t)
{
    if(t != NULL)
    {
        printf("%d ", t->data);
        abPreOrdem(t->l);
        abPreOrdem(t->r);
    }
}

void abPosOrdem(tnode *t)
{
    if(t != NULL)
    {
        abPosOrdem(t->l);
        abPosOrdem(t->r);
        printf("%d ", t->data);
    }
}

void abSimetrica(tnode *t)
{
    if(t != NULL)
    {
        abSimetrica(t->l);
        printf("%d ", t->data);
        abSimetrica(t->r);
    }
}

int altura(tnode *t)
{
    int hl, hr;
    if(t != NULL)
    {
        hl = altura(t->l);
        hr = altura(t->r);
        if(hl > hr)
            return hl+1;
        else
            return hr+1;
    }
    return 0;
}

int contarFolhas(tnode *t)
{
    if(t == NULL)
        return 0;
    if(t->l == NULL && t->r == NULL)
        return 1;
    return contarFolhas(t->l) + contarFolhas(t->r);
}

int contarNosCom1Filho(tnode *t)
{
    if(t == NULL)
        return 0;
    if(t->l != NULL && t->r == NULL || t->l != NULL && t->r == NULL)
        return 1;
    return contarNosCom1Filho(t->l) + contarNosCom1Filho(t->r);
}

int nosComAlturaX(tnode *t, int x)
{
    static int cont=0;
    if(t != NULL)
    {
        nosComAlturaX(t->l, x);
        nosComAlturaX(t->r, x);
        int y = altura(t);
        if(x == y)
        {
            cont++;
        }
    }
    return cont;
}

int noMaiorQueX(tnode *t, int x)
{
    static int cont=0;
    if(t != NULL)
    {
        noMaiorQueX(t->l, x);
        noMaiorQueX(t->r, x);
        if(t->data > x)
        {
            cont++;
        }
    }
    return cont;
}

int ehABP(tnode *t)
{
    if(t != NULL)
    {
        if(t->l != NULL && t->r != NULL)
        {
            if(t->l->data < t->data && t->r->data >= t->data)
            {
                ehABP(t->l);
                ehABP(t->r);
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

int ehHeap(tnode *t)
{
    if(t != NULL)
    {
        if(t->l != NULL && t->r != NULL)
        {
            if(t->l->data < t->data && t->r->data < t->data)
            {
                ehHeap(t->l);
                ehHeap(t->r);
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

void main(void)
{
    int i, h, x=1, v[]={ 8, 3, 1, 6, 4, 7, 10, 14, 13};
    char str[10];
    tnode *t;

    t = criar();

    for(i=0; i<9; i++)
    {
        insert(&t, v[i]);
    }

    printf("\tVisitacao\nPre Ordem -> ");
    abPreOrdem(t);
    printf("\n\nSimetrico -> ");
    abSimetrica(t);
    printf("\n\nPos Ordem -> ");
    abPosOrdem(t);
    printf("\n\n");

    if(ehABP(t) == 1)
        printf("Eh ABP\n");
    else
        printf("Nao eh ABP\n");

    if(ehHeap(t) == 1)
        printf("Eh Heap\n");
    else
        printf("Nao eh Heap\n");

    printf("Altura da ABP = %d\n", altura(t));
    printf("Numero de folhas da ABP = %d\n", contarFolhas(t));
    printf("Numero de nos com 1 filho da ABP = %d\n", contarNosCom1Filho(t));
    printf("Numero de nos com altura igual a %d = %d\n", x, nosComAlturaX(t, x));
    printf("Numero de nos maiores que %d = %d\n", x, noMaiorQueX(t, x));

    system("PAUSE");
}

