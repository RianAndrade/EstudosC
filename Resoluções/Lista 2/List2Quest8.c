#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre X e Y. O
programa deve informar a posição (índice) onde se encontra o menor número sorteado, seguido da posição onde se
encontra o segundo menor número sorteado, e assim sucessivamente...  */
void esc(int vetor[], int tamanho)
{
	int k;
	for(k=0; k<tamanho; k++)
	{
		printf("[%02d]", vetor[k]);
	}
	printf("\n");
}

void lin(int tamanho)
{
	int k; 
	printf("\n");
	for(k=0; k<tamanho; k++)
	{
		printf("-="); 
	}
	printf("\n\n");
}

int main()
{
	int n, i, j, x, y, menor, indice;
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	printf("\n");
	printf("X: ");
	scanf("%d", &x);
	printf("\n");
	printf("Y: ");
	scanf("%d", &y);
	printf("\n");
	int v1[n];
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		v1[i]= x+rand()%(y-x+1);
	}
	lin(35);
	printf("Vetor: ");
	esc(v1, n);
	lin (35);
// Mostrar o menor númemero por indice 
	menor = y+1;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(v1[j] < menor)
			{
				menor= v1[j];
				indice= j;
			}
		}
		printf("[%d] indice: %d", menor, indice+1);
		v1[indice]= y+10;
		menor= y+1;
		printf("\n");
	}
	lin(35);
	return 0;
}

