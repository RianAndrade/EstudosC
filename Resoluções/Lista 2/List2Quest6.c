
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*6. Métodos: map,filter e reduce são bastante comuns em linguagens de alto nível para tratamento de Arrays.
Faça um programa que implemente o método...
FILTER => Dado um vetor V1, com N números inteiros sorteados aleatoriamente (entre 0 e 99), e um valor
inteiro X (sendo N e X informados pelo usuário), crie um novo vetor V2, preenchendo-o apenas com os valores
do primeiro vetor que são divisíveis por X. Imprima V1 e V2. */
  
void escreve(int vetor[], int tamanho)
{
	int h;
	for(h=0; h<tamanho; h++)
	{
		printf("[%d]", vetor[h]);
	}
	printf("\n");
}

int main()
{
	int i, cont=0, n, x;
	printf("Tamanho vo vetor: ");
	scanf("%d", &n);
	printf("Valor de X: ");
	scanf("%d", &x);
	srand(time(NULL));
	int v1[n];
	for(i=0; i<n; i++)
	{
		v1[i]= rand() % 99;
	}
	escreve(v1, n);
	int v2[n];
	for(i=0; i<n; i++)
	{
		if(v1[i] % x == 0)
		{
			v2[cont]= v1[i];
			cont= cont+1;
		}
	}
	escreve(v2, cont);
	return 0;
}

