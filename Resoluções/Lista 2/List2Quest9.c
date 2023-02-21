#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 9 - leia do usuário um valor X, tal que X seja um valor PAR maior ou igual a 10. Gere aleatoriamente X números inteiros
não-repetitivos e armazene-os em uma estrutura do tipo Array. Imprima os números gerados na seqüência em que
foram sorteados. Após a impressão, troque no vetor a posição da metade inicial dos números sorteados pela metade
final. Repita a impressão do vetor. */
void escreve(int vetor[], int tamanho) 
{
	int a;
	printf("\n");
	for(a=0; a<tamanho; a++)
	{
		printf("[%d]", vetor[a]);
	}
	printf("\n");
}

int main()
{
	int x, i, j, val = 0, metade, cont=0;
	while(1)
	{
		printf("Escreva um número: \n ");
		scanf("%d", &x);
		if(x % 2 == 0 && x >= 10)
		{
			break;
		}
		else
		{
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("          Número invalido \n");
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

		}
	}
	int v1[x];
	int VetAux[x];
	srand(time(NULL));
	for(i=0; i<x; i++)
	{
		val = rand() % x+1;
		for(j=0; j<x; j++)
		{
			if(val == v1[j])
			{
				j= -1;
				val = rand() % x+1;
			}
		}
		v1[i] = val;
		VetAux[i] = val;
	}
	printf("Vetor: ");
	escreve(v1, x);
	metade= x/2;
	for(i=0; i<metade; i++)
	{
		v1[i] = VetAux[metade+cont];
		cont = cont + 1;
	}
	cont= 0;
	for(i=metade; i<x; i++)
	{
		v1[i] = VetAux[cont];
		cont = cont + 1;
	}
	printf("\nVetor com as metades invertidas: \n");
	escreve(v1, x);
	return 0;
}

