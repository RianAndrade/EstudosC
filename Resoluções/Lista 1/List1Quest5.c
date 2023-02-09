
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Faça um programa que leia um valor inteiro N não-negativo. O programa deve calcular e imprimir o valor de N!
N Fatorial. P.Ex.: 6! == 720; 9! == 362880.*/

int main()
{
	int N = -1, j, k = 0;
	// Para que  só entre e rode com números possitivos
	while(N < 0){
		printf("Escreva o número: ");
		scanf("%d", &N);
	}
	// A varriavel k foi inserida para ajudar na contabilidade
	k = N;
	// estrutura de repetição para fazer a conta fatorial
	for(j = N-1; j > 0; j--){
		printf("%d!",j);
		printf("%d \n", k);
		k = k*j;
	}
}

