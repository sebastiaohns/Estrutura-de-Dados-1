#include <stdio.h>
#include <stdlib.h>
#include "List_TAD.c"

list *uniao(list *a, list *b)
{
    list *c;
    node *auxA, *auxB;
    c = criar();

    if(vazio(a) == 1 && vazio(b) == 1)
    {
        if(c != NULL)
        {
            auxA = a->first;
            while(auxA->next != NULL)
            {
                inserir(c, auxA->data);
                auxA = auxA->next;
            }
            inserir(c, auxA->data);

            auxB = b->first;
            while(auxB->next != NULL)
            {
                inserir(c, auxB->data);
                auxB = auxB->next;
            }
            inserir(c, auxB->data);

            return c;
        }

    }
    if(vazio(a) == 1 && vazio(b) == 0)
    {
        if(c != NULL)
        {
            auxA = a->first;
            while(auxA->next != NULL)
            {
                inserir(c, auxA->data);
                auxA = auxA->next;
            }
            inserir(c, auxA->data);
        }
        return c;
    }
    if(vazio(a) == 0 && vazio(b) == 1)
    {
        if(c != NULL)
        {
            auxB = b->first;
            while(auxB->next != NULL)
            {
                inserir(c, auxB->data);
                auxB = auxB->next;
            }
            inserir(c, auxB->data);
        }
        return c;
    }
    return NULL;
}

list *interesecao(list *a, list *b)
{
    if(vazio(a) == 1 && vazio(b) == 1)
    {
        int xA, xB, flag =0;
        list *c;
        node *aux, *auxA, *auxB;
        c = criar();

        if(c != NULL)
        {
            auxB = b->first;
            while(auxB->next != NULL)
            {
                if(pesquisar(a, auxB->data) == 1)
                {
                    inserir(c, auxB->data);
                }
                auxB = auxB->next;
            }
            return c;

        }
    }
    return NULL;
}

list *diferenca(list *a, list *b)
{
    int dataA, dataB, flag=0;
    list *c;
    node *auxA, *auxB;
    c = criar();

    if(vazio(a) == 1 && vazio(b) == 1)
    {
        if(c != NULL)
        {
            auxA = a->first;
            while(auxA->next != NULL)
            {
                dataA = (int)auxA->data;
                auxB = b->first;
                while(auxB->next != NULL)
                {
                    dataB = (int)auxB->data;
                    if(dataA == dataB)
                    {
                        flag = 1;
                    }
                    auxB = auxB->next;
                }
                if(flag != 1)
                {
                    inserir(c, auxA->data);
                }
                auxA = auxA->next;
                flag = 0;
            }

            return c;
        }

    }
    if(vazio(a) == 1 && vazio(b) == 0)
    {
        if(c != NULL)
        {
            auxA = a->first;
            while(auxA->next != NULL)
            {
                inserir(c, auxA->data);
                auxA = auxA->next;
            }
            inserir(c, auxA->data);

            return c;
        }
    }
    return NULL;
}

list *complementar(list *a, list *b)
{
    int dataA, dataB, flag=0;
    list *c;
    node *auxA, *auxB;
    c = criar();

    if(vazio(a) == 1 && vazio(b) == 1)
    {
        if(c != NULL)
        {
            auxA = b->first;
            while(auxA->next != NULL)
            {
                dataA = (int)auxA->data;
                auxB = a->first;
                while(auxB->next != NULL)
                {
                    dataB = (int)auxB->data;
                    if(dataA == dataB)
                    {

                        flag = 1;
                    }
                    auxB = auxB->next;
                }
                if(flag != 1)
                {
                    inserir(c, auxA->data);
                }
                auxA = auxA->next;
                flag = 0;
            }

            return c;
        }

    }
    if(vazio(a) == 0 && vazio(b) == 1)
    {
        if(c != NULL)
        {
            auxB = b->first;
            while(auxB->next != NULL)
            {
                inserir(c, auxB->data);
                auxB = auxB->next;
            }
            inserir(c, auxB->data);

            return c;
        }
    }

    return NULL;
}

list *contido(list *a, list *b)
{
    int dataA, dataB, flag=0;
    list *c;
    node *auxA, *auxB;
    c = criar();

    if(vazio(a) == 1 && vazio(b) == 1)
    {
        if(c != NULL)
        {

            auxA = b->first;
            while(auxA->next != NULL)
            {
                dataA = (int)auxA->data;
                auxB = a->first;
                while(auxB->next != NULL)
                {
                    dataB = (int)auxB->data;
                    pesquisar(a, auxB->data);
                    if(dataA == dataB)
                    {
                        flag = 1;
                    }
                    auxB = auxB->next;
                }
                if(flag == 1)
                {
                    inserir(c, auxA->data);
                }
                auxA = auxA->next;
                flag = 0;
            }

            return c;
        }

    }
}
