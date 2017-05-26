#include <stdio.h>
#include <stdlib.h>
#include "List_TAD.h"

list *criar()
{
    list *l;

    l = (list*)malloc(sizeof(list));

    if(l != NULL)
    {
        l->first = NULL;

        return l;
    }
    return NULL;
}

int inserir(list *l, void* data)
{
    if(l != NULL)
    {
        node *n, *aux;

        n = (node*)malloc(sizeof(node));

        if(n != NULL)
        {
            if(l->first != NULL)
            {
                aux = l->first;
                while(aux->next != NULL)
                {
                    aux = aux->next;
                }
                n->data = data;
                n->next = NULL;
                aux->next = n;

                return 1;
            }
            else
            {
                n->data = data;
                n->next = NULL;
                l->first = n;

                return 1;
            }
        }
    }
    return 0;
}

int cmp(void* a, void* b) {
	int* pA = a;
	int* pB = b;

	if(*pA == *pB) {
		return 1;
	} else {
		return 0;
	}
}

int pesquisar(list *l, void* data)
{
    if(l != NULL)
    {
        int list_data, dado;
        node* aux;

        if(l->first != NULL)
        {
            aux = l->first;
            dado = (int)data;
            while(aux->next != NULL)
            {
                list_data = (int)aux->data;
                if(list_data == dado)
                {
                    return 1;
                }
                aux = aux->next;
            }
            list_data = (int)aux->data;
            if(list_data == dado)
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }


    }
    return 0;
}

int remover(list *l, int k)
{
    if(l != NULL && l->first != NULL)
    {
        int i=0;
        node *aux, *prev;

        aux = l->first;
        while(aux->next != NULL && i < k)
        {
            prev = aux;
            aux = aux->next;
            i++;
        }
        prev->next = aux->next;

        return 1;
    }
    return 0;
}

int apagar(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        l->first = NULL;
        return 1;
    }
    return 0;
}

void mostrar(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        int x;
        node *aux;
        aux = l->first;
        x = (int)aux->data;
        printf("{");
        while(aux->next != NULL)
        {
            printf("%d, ", x);
            aux = aux->next;
            x = (int)aux->data;
        }
        printf("%d}\n", x);
    }
}

int contador(list *l)
{
    int cont=1;
    node *aux;

    if(l != NULL && l->first != NULL)
    {
        aux = l->first;
        while(aux->next != NULL)
        {
            cont++;
            aux = aux->next;
        }
        return cont;
    }
    return 0;
}

int compara_listas(list *l1, list *l2)
{
    if(l1 != NULL || l2 != NULL)
    {
        int cont1=0, cont2=0;

        cont1 = contador(l1);
        cont2 = contador(l2);

        if(cont1 == cont2)
            return 0;

        if(cont1 > cont2)
            return 1;

        if(cont1 < cont2)
            return -1;

    }
    return 0;

}

int vazio(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        return 1;
    }
    return 0;
}
