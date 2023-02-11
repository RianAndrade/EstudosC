#include <stdio.h>
#include <stdlib.h>
#include <time.h>

		/*Gere um vetor de K posições (0 < K < 1000) com valores aleatórios entre 0 e 1000. Conte e escreva quantos valores
pares e ímpares ele possui. Imprima o maior, o menor valor e a média aritmética*/


int main()
{
	
	int i, k;
	srand(time(NULL));
	// fiz o rand com o número 10 e não 1000 como a questão pede para facilitar na correção do codigo, recomendo também fazer com 10 como e só um exercicio
	k = rand() % 10;
	printf("Tamanho do vetor %d: \n\n", k);
	int vetor[k];
	for(i = 0; i < k; i++){
		vetor[i] = rand() % 11 ;
    } 
    for(i = 0; i < k; i++){
		printf("[%d] ", vetor[i]);
	}

	return 0;
}

