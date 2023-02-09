
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Faça um programa que leia um valor inicial N e uma razão R. Imprima uma sequência em P.A. contendo 10 valores,
e uma sequência em P.G. contendo 10 valores. P.Ex.: N == 3 e R == 2.
PA = 3 - 5 - 7 - 9 - 11 - 13 - 15 - 17 - 19 - 21
PG = 3 - 6 - 12 - 24 - 48 - 96 - 192 - 384 - 768 - 1536*/

int main()
{
	int N, R, valor, j;	printf("Me diga o valor inicial: \n");
	scanf("%d", &N);
	printf("Me de uma razão: \n");
	scanf("%d", &R);
	valor = N;
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for(j = 10; j > 0; j--) {
		printf("%d - ", valor);
		valor += R;
	}
	valor = N;
	printf("\n");
	for(j = 10; j > 0; j--) {
		printf("%d - ", valor);
		valor = valor*R;
	}
	printf("\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	return 0;
}

