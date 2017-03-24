#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *vet;
    int maior=-9999, media=0;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int*)malloc(n*sizeof(int*));

    printf("-- Preencha o vetor --\n");

    for(i=0; i<n; i++)
    {
        printf("[%d] -> ", i+1);
        scanf("%d", &vet[i]);
    }

    for(i=0; i<n; i++)
    {
        if(vet[i] > maior)
        {
            maior = vet[i];
        }
    }

    for(i=0; i<n; i++)
    {
        media += vet[i];
    }

    printf("\nMaior: %d", maior);
    printf("\nMedia: %d", media/n);

    for(i=0; i<n; i++)
    {
        if(vet[i] > (media/n))
        {
            printf("\nValor maior que a media: %d", vet[i]);
        }
    }


}
