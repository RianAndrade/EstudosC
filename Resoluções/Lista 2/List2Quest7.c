#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 7 - Métodos: map,filter e reduce são bastante comuns em linguagens de alto nível para tratamento de Arrays.
Faça um programa que implemente o método...
REDUCE => Dado um vetor V, com N números inteiros sorteados aleatoriamente (entre 0 e 9), imprima a média
dos valores sorteados, excluindo-se do cálculo o menor e o maior valor sorteado. */
void escreve(int vetor[], int tamanho)
{
	int j;
	for(j=0; j<tamanho; j++)
	{
		printf("[%02d]", vetor[j]);
	}
	printf("\n");
}

int main()
{   
	int i, n, maior, menor, soma=0;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	srand(time(NULL));
	int v1[n];
	for(i=0; i<n; i++)
	{
		v1[i]= rand() % 10;
	}
	maior= v1[1];
	menor= v1[1];
	for(i=0; i<n; i++)
	{ 
		if(v1[i] < menor)
		{
			menor= v1[i];
		}
		if(v1[i] > maior)
		{
			maior= v1[i];
		}
		soma= soma+v1[i];
	}
	soma = soma - (maior + menor);
	escreve(v1, n);
	printf("Media: %d", soma/n);
	return 0;
}

