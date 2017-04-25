#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b )
        return -1;

    if ( *(int*)a == *(int*)b )
        return 0;

    if ( *(int*)a >  *(int*)b )
        return 1;
}

void main(void)
{
    int i;
    int vet[] = {96, 33, 45, 5, 23, 21, 8, 11, 76, 14, 2, 38, 22, 1, 18, 34, 94, 30, 7, 47};

    printf("Vetor nao ordenado\n");
    for(i=0; i<20; i++)
    {
        printf("[%d]-> %d\n", i+1, vet[i]);
    }

    qsort(vet, 20, sizeof(int), cmp);

    printf("Vetor ordenado\n");
    for(i=0; i<20; i++)
    {
        printf("[%d]-> %d\n", i+1, vet[i]);
    }

}
