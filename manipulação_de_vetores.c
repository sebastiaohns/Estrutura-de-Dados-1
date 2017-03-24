#include <stdio.h>
#include <stdlib.h>

int *cria_vetor(int n)
{
    int i, *aux;

    aux = (int*)malloc(n*sizeof(int));

    printf("-- Preencha o vetor --\n");

    for(i=0; i<n; i++)
    {
        printf("[%d] -> ", i+1);
        scanf("%d", &aux[i]);
    }

    return aux;
}

int pega_maior(int* vet, int n)
{
    int i, aux =0;

    aux = vet[0];
    for(i=0; i<n; i++)
    {
        if(vet[i] > aux)
        {
            aux = vet[i];
        }
    }

    return aux;
}

int pega_media(int* vet, int n)
{
    int i, aux=0;

    for(i=0; i<n; i++)
    {
        aux += vet[i];
    }

    return aux/n;
}

int maior_que_media(int* vet, int n, int aux)
{
    int i;

    for(i=0; i<n; i++)
    {
        if(vet[i] > aux)
        {
            printf("\nValor maior que a media: %d", vet[i]);
        }
    }
}

int main()
{
    int n, i, *vet;
    int maior=0, media=0;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    vet = cria_vetor(n);

    maior = pega_maior(vet, n);
    media = pega_media(vet, n);

    printf("\nMaior: %d", maior);
    printf("\nMedia: %d", media);

    maior_que_media(vet, n, media);

    return 0;
}
