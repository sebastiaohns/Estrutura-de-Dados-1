#include <stdio.h>
#include <stdlib.h>
#include "List_TAD.c"

int *criar_vetor(int tam)
{
    int i, *aux;

    if(tam > 0)
    {
        aux = (int*)malloc(tam*sizeof(int));
        if(aux != NULL)
        {
            printf("\nPreencha o vetor: \n");
            for(i=0; i<tam; i++)
            {
                printf("[%d]-> ", i+1);
                scanf("%d", &aux[i]);
            }
            printf("\n");
            return aux;
        }

    }
    return NULL;
}

list *uniao(list *a, list *b)
{
    if(a != NULL && b != NULL && a->first != NULL && b->first != NULL)
    {
        int dataA, dataB;
        int x=0, flag=0;
        list *c;
        node *n, *auxA, *auxB, *auxc, *prev;

        n = (node*)malloc(sizeof(node));
        c = criar();

        if(n != NULL && c != NULL)
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


            return c;
        }

    }
    return NULL;
}

void main(void)
{
    int i, tamA, tamB, *a, *b;
    list *listA, *listB, *listC;

    printf("Tamanho de elementos do conjunto A: ");
    scanf("%d", &tamA);
    a = criar_vetor(tamA);

    printf("Tamanho de elementos do conjunto B: ");
    scanf("%d", &tamB);
    b = criar_vetor(tamB);

    listA = criar();
    for(i=0; i<tamA; i++)
    {
        inserir(listA, (void*)a[i]);
    }

    listB = criar();
    for(i=0; i<tamB; i++)
    {
        inserir(listB, (void*)b[i]);
    }

    printf("A = ");
    mostrar(listA);

    printf("B = ");
    mostrar(listB);

    listC = criar();
    listC = uniao(listA, listB);
    printf("A U B = ");
    mostrar(listC);
}
