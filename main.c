#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.c"

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

int main(void)
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

    if(listA->first != NULL)
    {
        printf("A = ");
        mostrar(listA);
    }
    else
    {
        printf("A = %c\n", 157);
    }

    if(listB->first != NULL)
    {
        printf("B = ");
        mostrar(listB);
    }
    else
    {
        printf("B = %c\n", 157);
    }

    listC = criar();
    listC = uniao(listA, listB);
    if(listC != NULL)
    {
        if(listC->first != NULL)
        {
            printf("A U B = ");
            mostrar(listC);
        }
        else
        {
            printf("A U B = %c\n", 157);
        }

    }
    else
    {
        printf("A U B = %c\n", 157);
    }

    listC = interesecao(listA, listB);
    if(listC != NULL)
    {
        if(listC->first != NULL)
        {
            printf("A n B = ");
            mostrar(listC);
        }
        else
        {
            printf("A n B = %c\n", 157);
        }
    }
    else
    {
        printf("A n B = %c\n", 157);
    }

    listC = diferenca(listA, listB);
    if(listC != NULL)
    {
        if(listC->first != NULL)
        {
            printf("A - B = ");
            mostrar(listC);
        }
        else
        {
            printf("A - B = %c\n", 157);
        }
    }
    else
    {
        printf("A - B = %c\n", 157);
    }

    listC = complementar(listA, listB);
    if(listC != NULL)
    {
        if(listC->first != NULL)
        {
            printf("C(A,B) = ");
            mostrar(listC);
        }
        else
        {
            printf("C(A,B) = %c\n", 157);
        }
    }
    else
    {
        printf("C(A,B) = %c\n", 157);
    }

    listC = contido(listA, listB);
    if(listC != NULL)
    {
        if(listC->first != NULL)
        {
            printf("A esta contido B\n");
        }
        else
        {
            printf("A nao esta contido B\n");
        }
    }
    else
    {
        printf("A nao esta contido B\n");
    }

    apagar(listA);
    apagar(listB);
    apagar(listC);

    system("PAUSE");
}
