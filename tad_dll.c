#include <stdio.h>
#include <stdlib.h>
#include "tad_dll.h"

list *criar()
{
    list *l;

    l = (list*)malloc(sizeof(list));

    if(l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        l->last = NULL;

        return l;
    }
    return NULL;
}

int inserir(list *l, int data)
{
    if(l != NULL)
    {
        int i=1;
        node *n, *aux, *prev;

        n = (node*)malloc(sizeof(node));

        if(l->first != NULL)
        {
            n->data = data;
            aux = l->first;
            while(aux->next != NULL)
            {
                aux = aux->next;
                i++;
            }
            n->prev = l->last;
            n->next = aux->next;
            l->last->next = n;
            l->last = n;

            return 1;
        }
        else
        {
            n->data = data;
            n->prev = NULL;
            n->next = NULL;
            l->first = n;
            l->last = n;

            return 1;
        }
    }
    return 0;
}

int remover(list *l, int data)
{
    if(l != NULL && l->first != NULL)
    {
        node *aux, *prev;
        aux = l->first;
        while(aux->next != NULL)
        {
            if(aux->data == data)
            {
                if(aux->prev == NULL)
                {
                    l->first = aux->next;
                    aux->next->prev = NULL;
                }
                else
                {
                    aux->next->prev = prev;
                    prev->next = aux->next;
                }
                return data;
            }
            prev = aux;
            aux = aux->next;
        }
        if(aux->data == data)
        {
            aux->prev = NULL;
            prev->next = NULL;
            return data;
        }
    }
    return 0;

}

int apagar(list *l)
{
    if(l != NULL)
    {
        l->first = NULL;
        return 1;
    }
    return 0;
}

int contar(list* l)
{
    if(l != NULL & l->first != NULL)
    {
        int cont=1;
        node *aux;
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

node *pegar_primeiro(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        node *aux;
        aux = l->first;
        l->cur = l->first->next;
        return l->first;
    }
    return NULL;
}

node *pegar_proximo(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        node *aux;
        if(l->cur == l->last)
        {
            return l->last;
        }
        {
            aux = l->first;
            while(aux->next != l->cur->next)
            {
                aux = aux->next;
            }
            l->cur = aux->next;
            return aux;
        }

    }
    return NULL;
}

int pesquisar(list *l, int data)
{
    if(l != NULL && l->first != NULL)
    {
        node *aux, *prev;
        aux = l->first;
        while(aux->next != NULL)
        {
            if(aux->data == data)
            {
                return data;
            }
            aux = aux->next;
        }
        if(aux->data == data)
        {
            return data;
        }
    }
    return 0;
}

void mostrar(list *l)
{
    if(l != NULL)
    {
        node *aux;

        aux = l->first;
        while(aux->next != NULL)
        {
            printf("%d, ", aux->data);
            aux = aux->next;
        }
        printf("%d}\n", aux->data);
    }
}
