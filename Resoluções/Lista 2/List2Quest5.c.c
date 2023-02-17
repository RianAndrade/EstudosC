
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Métodos: map,filter e reduce são bastante comuns em linguagens de alto nível para tratamento de Arrays.
Faça um programa que implemente o método...
MAP => Dado um vetor V1, com N números inteiros sorteados aleatoriamente (entre 0 e 20), e um valor inteiro X
(sendo N e X informados pelo usuário), crie um novo vetor V2, preenchendo-o com os valores do primeiro vetor
elevado à potência X. Imprima V1 e V2. */

int main()
{
	int i, n, x;
	printf("Diga o tamanho do vetor: ");
	scanf("%d", &n);
	printf("Você quer elevar o vetor a que número: ");
	scanf("%d", &x);
	srand(time(NULL));
	int v1[n];
	int v2[n];
	printf("\n");
	for(i=0; i<n; i++)
	{
		v1[i]= rand() % 20;
		printf("[%02d]", v1[i]);
	}
	printf("\n");
	for(i=0; i<n; i++)
	{
		int temp, j;
		temp= v1[i];
		for(j=1; j<x; j++)
		{
			temp= temp*v1[i];
		}
		v2[i]= temp;
		printf("[%02d]", v2[i]);
	}
	return 0;
}

