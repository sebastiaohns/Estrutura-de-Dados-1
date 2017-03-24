#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, m, p, f, i, j, k, **a, **b, **c;

    printf("Linha da matriz A: ");
    scanf("%d", &n);
    printf("Coluna da matriz A: ");
    scanf("%d", &m);
    printf("Linha da matriz B: ");
    scanf("%d", &p);
    printf("Coluna da matriz B: ");
    scanf("%d", &f);

    //Alocação da matriz A
    a = (int**)malloc(n*sizeof(int**));
    for(i=0; i<n; i++)
    {
        a[i] = (int*)malloc(m*sizeof(int*));
        for(j=0; j<m; j++)
        {
            printf("[%d][%d]-> ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    //Alocação da matriz B
    b = (int**)malloc(p*sizeof(int**));
    for(i=0; i<p; i++)
    {
        b[i] = (int*)malloc(f*sizeof(int*));
        for(j=0; j<f; j++)
        {
            printf("[%d][%d]-> ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    //Multiplicação das matrizes A e B
    if(m == p)
    {
        //Alocação da matriz C que ira conter a multiplicação das matrizes A e B
        c = (int**)malloc(n*sizeof(int**));
        for(i=0; i<n; i++)
        {
            c[i] = (int*)malloc(f*sizeof(int*));
            for(j=0; j<f; j++)
            {
                c[i][j] = 0;
            }
        }

        //Logica da Multiplicação das matrizes A e B
        for(i=0; i<n; i++)
        {
            for(j=0; j<f; j++)
            {
                for(k=0; k<p; k++)
                {
                    c[i][j] += a[i][k]*b[k][j];
                }
            }
        }

        //Impressão da multiplicação das matrizes A e B
        printf("----- Multiplicacao das Matrizes A e B -----\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<f; j++)
            {
                printf(" %d", c[i][j]);
            }
            printf("\n");
        }
    }

    //Imprime a Transposta da Matriz B
    printf("----- Transposta da Matriz B -----\n");
    for(i=0; i<p; i++)
    {
        for(j=0; j<f; j++)
        {
            printf(" %d", b[j][i]);
        }
        printf("\n");
    }

    //Imprime a Diagonal principal da matriz A
    printf("----- Elementos da Diagonal Principal da Matriz A ------\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(i == j)
            {
                printf(" %d", a[i][j]);
            }
        }
        printf("\n");
    }

    float x, y;

    x = n;
    x = ceil(x/2);

    printf("----- Elementos da Linha ceil(n/2) da Matriz A ------\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if((i+1) == x)
            {
                printf(" %d", a[i][j]);
            }
        }
        printf("\n");
    }

    y = f;
    y = floor(y/2);

    printf("----- Elementos da Coluna floor(f/2) da Matriz B ------\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if((j+1) == y)
            {
                printf(" %d", b[i][j]);
            }
        }
        printf("\n");
    }




}
