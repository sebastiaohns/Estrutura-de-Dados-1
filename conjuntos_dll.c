#include <stdio.h>
#include <stdlib.h>
#include "tad_dll.c"

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

list *uniao(list* a, list *b)
{
    list *c;
    node *aux;

    c = criar();

    if(c != NULL)
    {
        if(a->first != NULL && b->first != NULL)
        {
            aux = pegar_primeiro(a);
            while(aux->next != NULL)
            {
                if(pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }

            aux = pegar_primeiro(b);
            while(aux->next != NULL)
            {
                if(pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }

            return c;
        }
        if(a->first != NULL && b->first == NULL)
        {
            aux = pegar_primeiro(a);
            while(aux->next != NULL)
            {
                if(pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }
            return c;
        }
        if(a->first == NULL && b->first != NULL)
        {
            aux = pegar_primeiro(b);
            while(aux->next != NULL)
            {
                if(pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }
            return c;
        }
    }
    return NULL;
}

list *intersecao(list *a, list *b)
{
    list *c = criar();
    node *aux;

    if(c != NULL)
    {
        if(a->first != NULL && b->first != NULL)
        {
            aux = pegar_primeiro(a);
            while(aux->next != NULL)
            {
                if(pesquisar(b, aux->data) != 0 && pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(b, aux->data) != 0 && pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }

            return c;
        }
    }
    return NULL;
}

list *diferenca(list* a, list *b)
{
    list *c;
    node *aux;

    c = criar();

    if(c != NULL)
    {
        if(a->first != NULL && b->first != NULL)
        {
            aux = pegar_primeiro(a);
            while(aux->next != NULL)
            {
                if(pesquisar(b, aux->data) == 0 && pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(b, aux->data) == 0 && pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }

            return c;
        }
        if(a->first != NULL && b->first == NULL)
        {
            aux = pegar_primeiro(a);
            while(aux->next != NULL)
            {
                if(pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }
            return c;
        }
    }
    return NULL;
}

list *complemento(list* a, list *b)
{
    list *c;
    node *aux;

    c = criar();

    if(c != NULL)
    {
        if(a->first != NULL && b->first != NULL)
        {
            aux = pegar_primeiro(b);
            while(aux->next != NULL)
            {
                if(pesquisar(a, aux->data) == 0 && pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(a, aux->data) == 0 && pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }

            return c;
        }
        if(a->first == NULL && b->first != NULL)
        {
            aux = pegar_primeiro(b);
            while(aux->next != NULL)
            {
                if(pesquisar(c, aux->data) == 0)
                {
                    inserir(c, aux->data);
                }
                aux = aux->next;
            }
            if(pesquisar(c, aux->data) == 0)
            {
                inserir(c, aux->data);
            }
            return c;
        }
    }
    return NULL;
}

int contido(list *a, list *b)
{
    node *aux;
    if(a->first != NULL && b->first != NULL)
    {
        aux = pegar_primeiro(a);
        while(aux->next != NULL)
        {
            if(pesquisar(b, aux->data) == 0)
            {
                return 1;
            }
            aux = aux->next;
        }
        if(pesquisar(b, aux->data) == 0)
        {
            return 1;
        }
    }
    if(a->first == NULL && b->first != NULL)
    {
        return 1;
    }
    if(a->first != NULL && b->first == NULL)
    {
        return 1;
    }
    return 0;
}

void main(void)
{
    int tamA, tamB, *vetA, *vetB, i;
    list *a, *b, *c;

    printf("Tamanho do vetor A: ");
    scanf("%d", &tamA);
    vetA = criar_vetor(tamA);

    printf("Tamanho do vetor B: ");
    scanf("%d", &tamB);
    vetB = criar_vetor(tamB);

    a = criar();
    b = criar();
    c = criar();

    //Preenchendo Lista A
    for(i=0; i<tamA; i++)
    {
        inserir(a, vetA[i]);
    }

    //Preenchendo Lista B
    for(i=0; i<tamB; i++)
    {
        inserir(b, vetB[i]);
    }

    //Mostrando Lista A
    if(a != NULL)
    {
        if(a->first != NULL)
        {
            printf("A = {");
            mostrar(a);
        }
        else
        {
            printf("A = %c\n", 157);
        }
    }
    else
    {
        printf("A = %c\n", 157);
    }

    //Mostrando Lista B
    if(b != NULL)
    {
        if(b->first != NULL)
        {
            printf("B = {");
            mostrar(b);
        }
        else
        {
            printf("B = %c\n", 157);
        }
    }
    else
    {
        printf("B = %c\n", 157);
    }

    //Uniao da Lista A com B
    c = uniao(a, b);
    if(c != NULL)
    {
        if(c->first != NULL)
        {

            printf("Uniao = {");
            mostrar(c);
        }
        else
        {
            printf("Uniao = %c\n", 157);
        }
    }
    else
    {
        printf("Uniao = %c\n", 157);
    }

    //Intersecao da Lista A com B
    c = intersecao(a, b);
    if(c != NULL)
    {
        if(c->first != NULL)
        {
            printf("Intersecao = {");
            mostrar(c);
        }
        else
        {
            printf("Intersecao = %c\n", 157);
        }
    }
    else
    {
        printf("Intersecao = %c\n", 157);
    }

    //Diferenca da Lista A com B
    c = diferenca(a, b);
    if(c != NULL)
    {
        if(c->first != NULL)
        {
            printf("Diferenca = {");
            mostrar(c);
        }
        else
        {
            printf("Diferenca = %c\n", 157);
        }
    }
    else
    {
        printf("Diferenca = %c\n", 157);
    }

    //Complemento da Lista A com B
    c = complemento(a, b);
    if(c != NULL)
    {
        if(c->first != NULL)
        {
            printf("Complemento = {");
            mostrar(c);
        }
        else
        {
            printf("Complemento = %c\n", 157);
        }
    }
    else
    {
        printf("Complemento = %c\n", 157);
    }

    //Verificando se A esta contido em B
    if(contido(a, b) == 0)
    {
        printf("A esta contido em B");
    }
    else
    {
        printf("A nao esta contido em B");
    }

    //Apagando as lista A, B e C
    apagar(a);
    apagar(b);
    apagar(c);
}
