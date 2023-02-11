#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 Gere dois vetores, V1 e V2, cada um com K valores aleatórios sorteados no intervalo entre 0 e X (0 < K < X). O
usuário deve informar o valor de K e X, desde que K < X. O programa NÃO deverá aceitar números repetidos no
mesmo vetor, e nem o mesmo número no mesmo índice dos dois vetores. Imprima os valores sorteados nos dois
vetores, e o resultado da multiplicação dos valores dos índices de V1 e V2. */

// so uma função para facilitar a escrita da linha

void lin(int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("-=");
    }
    printf("\n");
}

// corpo do projeto

int main()
{
	int k, x, i, j, temp, cont = 0, mult1, mult2;
	printf("Me diga qual o valor maximo: " );
	scanf("%d", &x);
	k = x + 1;
	while(k > x){
		printf("O tamanho do vetor ");
		scanf("%d", &k);
	lin(20);
	} 
	srand(time(NULL));
	printf("\n");
	int vet1[k];
	int vet2[k];
// para tornar o vetor maior que o numero maximo assim facilitando a verificação de números repetidos

	for(i = 0; i < k; i++){
		vet1[i] = x+1;
		vet2[i] = x+1;
	}

// Não deixar números repetidos no vetor 1

	for(i = 0; i < k; i++)
	{
		temp = rand() % x+1;
		for(j=0; j<k; j++)
		{
			if (temp == vet1[j])
			{
				j = -1;
				temp= rand() % x+1;
			}	
		}
		vet1[i] = temp;
	}
	
// Não deixar números repetidos no vetor 2

	for(i=0; i<k; i++)
	{
		temp=rand() % x+1;
		for(j=0; j<k; j++)
		{
			if (temp == vet2[j])
			{
				j= -1;
				temp=rand() % x+1;
			}
		}
		vet2[i]=temp;
	}
// verificar  se os dois vetores tenham o mesmo número no mesmo indice 
	for(i=0; i<k; i++)
		{
			if (vet1[i] == vet2[i])
			{
				printf("Indice [%d] repetiu\n", i+1);
				cont++;
			}
		}
	printf("Total de indices repetidos: %d", cont);
	printf("\n\n");
// ESCREVER O VETOR com incie repetido
	for(i = 0; i < k; i++){
		printf("[%02d] ", vet1[i]);
	}
	printf("\n");
	for(i = 0; i < k; i++){
		printf("[%02d] ", vet2[i]);
	}
 	printf("\n\n");
// corrigir se tiver numero igual no mesmo indice	
	
	for(i=0; i<k; i++)
		{
						if (vet1[i] == vet2[i])
			{
				temp= vet2[i];
				if(i == k-1)
				{
					vet2[i]= vet2[i-1];
					vet2[i-1]= temp;
				}	
				else 
				{
					vet2[i]= vet2[i+1];
					vet2[i+1]= temp;
				}
				i= -1;
			}
		}
// escrever p vetor  corretamente
	printf("\n");
	lin(20);
	printf("\n\n");
	printf("Este são os vetores  sem números repetidos no mesmo indice: \n\n");
	for(i = 0; i < k; i++){
		printf("[%02d] ", vet1[i]);
	}
	printf("\n");
	for(i = 0; i < k; i++){
		printf("[%02d] ", vet2[i]);
	}
//multiplicação dos indices 
	mult1= vet1[1];
	mult2= vet1[1];
	for(i=0; i<k; i++)
	{
		mult1= mult1* vet1[i];
		mult2= mult2* vet2[i];
	}
	printf("\n\n\n");
	lin(20);
	printf("\n\n");
	printf("A multiplicação dos indices do vetor 1 é: [%d]\n", mult1);
	printf("A multiplicação dos indices do vetor 2 é: [%d]\n", mult2);
	printf("\n\n");
	lin(20);
	return 0;
}

