#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*4. Faça um programa C para ler do usuário dois valores inteiros X e Y. Alimente dois vetores de tamanhos X e Y com
números inteiros aleatórios, não repetitivos, sorteados no intervalo entre 0 e X+Y (inclusive). Faça a impressão das
seguintes informações:
a) Vetores X e Y;
b) Todos os números exclusivos do vetor X;
c) Todos os números exclusivos do vetor Y;
d) Os números existentes nos dois vetores*/



void lin(int tan)
{
    int a;
    printf("\n");
    for(a=0; a<tan; a++)
    {
        printf("-=");
    }
    printf("\n\n");
}
int main()
{
    int x, k, i, j, temp, taMax;
    lin(30);
    printf("Me diga qual o tamanho do primeiro vetor: ");
    scanf("%d", &x);
    printf("Me diga qual o tamanho do segundo vetor: ");
    scanf("%d", &k);
    lin(30);
    srand(time(NULL));
    int vet1[x];
    int vet2[k];
    taMax= x+k+1;
    for(i=0; i<x; i++)
    {
        vet1[i]= taMax+1;
    }
    for(i=0; i<k; i++)
    {
        vet2[i]= taMax+1;
    }
    for(i=0; i<x; i++)
    {
        temp= rand() % taMax;
        for(j=0; j<x; j++)
        {
            if(temp == vet1[j])
            {
                temp= rand() % taMax;
                j= -1;
            }
        }
        vet1[i]= temp;
    }
    for(i=0; i<k; i++)
    {
        temp= rand() % taMax;
        for(j=0; j<k; j++)
        {
            if(temp == vet2[j])
            {
                temp= rand() % taMax;
                j= -1;
            }
        }
        vet2[i]= temp;
    }
    printf("Vetores 1 e 2: \n\n");
    for(i=0; i<x; i++)
    {
        printf("[%02d]", vet1[i]);
    }
    printf("\n\n");
    for(i=0; i<k; i++)
    {
        printf("[%02d]", vet2[i]);
    }
    printf("\n");
    lin(30);
    // Calcular os números exclusivos 
    printf("Números exclusivos de cada vetor:\n\n");
    printf("Vetor 1: \n\n");
    for(i=0; i<x; i++)
    {
		temp= 0;
		for(j=0; j<k; j++)
		{
			if (vet1[i] == vet2[j])
			{
				temp = temp+1;
				break;
			}
				}
		if (temp == 0)
		{
			printf("[%02d]", vet1[i]);
		}
	}
	printf("\n\n");
	printf("Vetor 2: \n\n");
	for(i=0; i<k; i++)
    {
		temp= 0;
		for(j=0; j<x; j++)
		{
			if (vet2[i] == vet1[j])
			{
				temp = temp+1;
				break;
			}
				}
		if (temp == 0)
		{
			printf("[%02d]", vet2[i]);
		}
	}
	printf("\n");
	lin(30);
    return 0;
}
