/*  CODIGO ANTIGO

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

*/

#include <stdio.h>
#include <stdlib.h>

int* aloca_vetor(int n);
void preenche_vetor(int* aux, int n);
void mostra_vetor(int* aux, int n);
int maior_do_vetor(int* aux, int n);
float media_vetor(int* aux, int n);
void maior_media_vetor(int* aux, int n, int media);

int main()
{
    int n, maior, *vet;
    float media;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    vet = aloca_vetor(n);
    if(vet != NULL)
    {
        preenche_vetor(vet, n);
        mostra_vetor(vet, n);
        maior = maior_do_vetor(vet, n);
        printf("Maior elemento do vetor: %d\n", maior);
        media = media_vetor(vet, n);
        printf("Media dos elementos do vetor: %.1f\n", media);
        maior_media_vetor(vet, n, media);


    }
    else
    {
        printf("--- Erro ao criar vetor ---");
    }
    return 0;
}

int* aloca_vetor(int n)
{
    int* aux;

    aux = (int*)malloc(n*sizeof(int));

    if(aux != NULL)
    {
        printf("--- Vetor criado ---\n\n");
        return aux;
    }

    free(aux);
    return NULL;
}

void preenche_vetor(int* aux, int n)
{
    int i;

    printf("--- Preencha o vetor ---\n");
    for(i=0; i<n; i++)
    {
        printf("[%d] -> ", i+1);
        scanf("%d", &aux[i]);
    }
}

void mostra_vetor(int* aux, int n)
{
    int i;

    printf("--- Vetor ---\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", aux[i]);
    }
}

int maior_do_vetor(int* aux, int n)
{
    int i, maior;

    maior = aux[0];

    for(i=0; i<n; i++)
    {
        if(aux[i] > maior)
        {
            maior = aux[i];
        }
    }

    return maior;
}

float media_vetor(int* aux, int n)
{
    int i;
    float media;

    for(i=0; i<n; i++)
    {
        media += (float)aux[i];
    }

    return media/2;
}

void maior_media_vetor(int* aux, int n, int media)
{
    int i;

    printf("--- Elementos do vetor maior que a media ---\n");
    for(i=0; i<n; i++)
    {
        if(aux[i] > media)
        {
            printf("%d ", aux[i]);
        }
    }
}
