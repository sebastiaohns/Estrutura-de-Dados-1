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
        int xa, xb;
        int x=0, flag =0;
        list *c;
        node *n, *aux, *auxa, *auxb;

        n = (node*)malloc(sizeof(node));
        c = criar();


        if(c != NULL && n != NULL)
        {




            auxa = a->first;
            while(auxa->next != NULL)
            {
                xa = (int)auxa->data;
                auxb = b->first;
                while(auxb->next != NULL)
                {
                    xb = (int)auxb->data;
                    if(xa == xb)
                    {
                        flag = 1;
                        break;
                    }
                    auxb = auxb->next;

                }
                if(flag != 1)
                    {
                        inserir(c, auxa->data);
                    }
                auxa = auxa->next;
                flag=0;
            }
            if(xa != xb)
            {
                inserir(c, auxa->data);
            }

            return c;
        }

    }
    return NULL;
}

list *interesecao(list *a, list *b)
{
    if(a != NULL && b != NULL && a->first != NULL && b->first != NULL)
    {
        int xa, xb;
        int x=0, flag =0;
        list *c;
        node *n, *aux, *auxa, *auxb;

        n = (node*)malloc(sizeof(node));
        c = criar();

        if(c != NULL && n != NULL)
        {
            auxa = a->first;
            while(auxa->next != NULL)
            {
                xa = (int)auxa->data;
                auxb = b->first;
                while(auxb->next != NULL)
                {
                    xb = (int)auxb->data;
                    if(xa == xb)
                    {
                        inserir(c, auxa->data);
                        break;
                    }
                    auxb = auxb->next;

                }
                auxa = auxa->next;
                flag=0;
            }
            if(xa == xb)
            {
                inserir(c, auxa->data);
            }

            return c;
        }

    }
    return NULL;
}

list *diferenca(list *a, list *b)
{
    if(a != NULL && b != NULL && a->first != NULL && b->first != NULL)
    {
        int dataA, dataB;
        int x=0, flag=0;
        list *c;
        node *n, *auxA, *auxB, *auxc, *prev;

        n = (node*)malloc(sizeof(node));
        c = criar();

        if(c != NULL && n != NULL)
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
    return NULL;
}

list *complementar(list *a, list *b)
{
    if(a != NULL && b != NULL && a->first != NULL && b->first != NULL)
    {
        int dataA, dataB;
        int x=0, flag=0;
        list *c;
        node *n, *auxA, *auxB, *auxc, *prev;

        n = (node*)malloc(sizeof(node));
        c = criar();

        if(c != NULL && n != NULL)
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
    return NULL;
}

int contido(list *a, list *b)
{
    if(a->first != NULL && b->first != NULL)
    {
        int dataA, dataB;
        int x=0, flag=0;
        list *c;
        node *n, *auxA, *auxB, *auxc, *prev;

        n = (node*)malloc(sizeof(node));
        c = criar();

        if(c != NULL && n != NULL)
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
                if(flag == 1)
                {
                    cont++;
                }
                auxA = auxA->next;
                flag = 0;
            }
        return 1;
    }
    return 0;
}

void main(void)
{
    int i, tamA, tamB, *a, *b;
    list *listA, *listB, *listC;


    //ENTRADA DO TAMANHO DO VETOR A E CRIA플O DAO VETOR A
    printf("Tamanho de elementos do conjunto A: ");
    scanf("%d", &tamA);
    a = criar_vetor(tamA);

    //ENTRADA DO TAMANHO DO VETOR B E CRIA플O DO VETOR B
    printf("Tamanho de elementos do conjunto B: ");
    scanf("%d", &tamB);
    b = criar_vetor(tamB);

    //CRIA플O E INSER플O DE ELEMENTOS NA LISTA A
    listA = criar();
    for(i=0; i<tamA; i++)
    {
        inserir(listA, (void*)a[i]);
    }

    //CRIA플O E INSER플O DE ELEMENTOS NA LISTA B
    listB = criar();
    for(i=0; i<tamB; i++)
    {
        inserir(listB, (void*)b[i]);
    }

    //PRINTANDO OS ELEMENTOS DA LISTA A
    if(listA->first != NULL)
    {
        printf("A = ");
        mostrar(listA);
    }
    else
    {
        printf("A = %c\n", 157);
    }

    //PRINTANDO OS ELEMENTOS DA LISTA B
    if(listB->first != NULL)
    {
        printf("B = ");
        mostrar(listB);
    }
    else
    {
        printf("B = %c\n", 157);
    }

    //CRIA플O, INSER플O E PRIT DA UNIAO DOS ELEMENTOS DA LISTA A E LISTA B
    listC = criar();
    listC = uniao(listA, listB);
    if(listC != NULL)
    {
        printf("A U B = ");
        mostrar(listC);
    }
    else
    {
        printf("A U B = %c\n", 157);
    }

    //CRIA플O, INSER플O E PRIT DA INTERSE플O DOS ELEMENTOS DA LISTA A E LISTA B
    listC = interesecao(listA, listB);
    if(listC != NULL)
    {
        printf("A n B = ");
        mostrar(listC);
    }
    else
    {
        printf("A n B = %c\n", 157);
    }

    //CRIA플O, INSER플O E PRIT DA DIFERENCA DOS ELEMENTOS DA LISTA A E LISTA B
    listC = diferenca(listA, listB);
    if(listC != NULL)
    {
        printf("A - B = ");
        mostrar(listC);
    }
    else
    {
        printf("A - B = %c\n", 157);
    }

    //CRIA플O, INSER플O E PRIT DO COMPLEMENTO DOS ELEMENTOS DA LISTA A E LISTA B
    listC = complementar(listA, listB);
    if(listC != NULL)
    {
        printf("C(A,B) = ");
        mostrar(listC);
    }
    else
    {
        printf("C(A,B) = %c\n", 157);
    };


    //APAGANDO TODOS OS ELEMENTOS DAS LISTAS
    apagar(listA);
    apagar(listB);
    apagar(listC);


    system("PAUSE");
}
