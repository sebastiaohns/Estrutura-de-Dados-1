#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** aloca_matriz(int l, int c);
void preenche_matriz(int** aux, int l, int c);
void mostra_matriz(int** aux, int l, int c);
void multiplica_matriz(int** a, int** b, int** c, int l1, int c1, int l2, int c2);

int main()
{
    int lA, cA, lB, cB, **a, **b, **c;

    printf("Linha da Matriz A: ");
    scanf("%d", &lA);
    printf("Coluna da Matriz A: ");
    scanf("%d", &cA);
    printf("Linha da Matriz B: ");
    scanf("%d", &lB);
    printf("Coluna da Matriz B: ");
    scanf("%d", &cB);

    a = aloca_matriz(lA, cA);
    b = aloca_matriz(lB, cB);
    if(a != NULL && b != NULL)
    {
        preenche_matriz(a, lA, cA);
        mostra_matriz(a, lA, cA);
        preenche_matriz(b, lB, cB);
        mostra_matriz(b, lB, cB);

        c = aloca_matriz(lA, cB);
        if(c != NULL)
        {
            multiplica_matriz(a, b, c, lA, cA, lB, cB);
            mostra_matriz(c, lA, cB);
        }
        else
        {
            printf("--- Erro ao multiplicar matrizes ---");
        }

    }
    else
    {
        printf("--- Erro ao criar matriz ---");
    }

    return 0;
}

int** aloca_matriz(int l, int c)
{
    int i, j, **aux;

    aux = (int**)malloc(l*sizeof(int*));

    if(aux != NULL)
    {
        for(i=0; i<l; i++)
        {
            aux[i] = (int*)malloc(l*sizeof(int));
            if(aux[i] != NULL)
            {
                for(j=0; j<c; j++)
                {
                    aux[i][j] = 0;
                }
            }
            else
            {
                free(aux);
                return NULL;
            }

        }
        printf("--- Matriz criada ---\n\n");
        return aux;
    }

    free(aux);
    return NULL;
}

void preenche_matriz(int** aux, int l, int c)
{
    int i, j;

    printf("--- Preencha a matriz ---\n");
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("[%d][%d] -> ", i+1, j+1);
            scanf("%d", &aux[i][j]);
        }
    }
}

void mostra_matriz(int** aux, int l, int c)
{
    int i, j;

    printf("--- Matriz ---\n");
    for(i=0; i<l; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }
}

void multiplica_matriz(int** a, int** b, int** c, int lA, int cA, int lB, int cB)
{
    int i, j, k;

    if(cA == lB)
    {
        if(c != NULL)
        {
            for(i=0; i<lA; i++)
            {
                for(j=0; j<cB; j++)
                {
                    for(k=0; k<lB; k++)
                    {
                        c[i][j] += a[i][k]*b[k][j];
                    }
                }
            }
        }
    }

}
