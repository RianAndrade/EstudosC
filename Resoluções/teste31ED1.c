#include <stdio.h>
#include <stdlib.h>
#include <time.h>

		/*29. Gere aleatoriamente uma matriz N x N de inteiros sorteados no intervalo entre X e Y (inclusive).
Imprima-a em formato de tabela, e os valores que compõem a coluna que resulta na maior soma, e os valores da
linha que resulta na menor soma.*/

int main()
{
	int tamanho, maior, menor, maiorl, menorc, i, j, soma=0, linha, coluna;
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Qual o menor valor? \n");
	scanf("%d", &menor);
	printf("Qual o maior valor? \n");
	scanf("%d", &maior);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	srand(time(NULL));
	tamanho = 3 + rand()%(6-3+1);
	int matriz[tamanho][tamanho];
	for (i = 0; i < tamanho; i++){
		for (j = 0; j < tamanho; j++){
			matriz[i][j] = menor+rand()%(maior-menor+1);
		}
	}
	menorc = maior*(tamanho+1);
	printf("\t\tMATRIZ\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for (i = 0; i < tamanho; i++){
		printf("\t");
		for (j = 0; j < tamanho; j++ ){
			soma = soma + matriz[i][j];
			printf("[%02d] ", matriz[i][j]);
		}
		if (soma < menorc){
			menorc = soma ; 
			linha = i;
		}
		soma = 0;
		printf("\n");
	}
	maiorl = 0; 
	for (j = 0; j < tamanho; j++){
		for (i = 0; i < tamanho; i++){
			soma = soma + matriz[i][j];
		}
		if (soma > maiorl){
			maiorl = soma;
			coluna = j;
		}
		soma = 0;
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("A menor soma é: %d é esta na linha : %d \nA maior soma é: %d é está na coluna : %d\n", menorc, linha, maiorl, coluna);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("\t\tOBRIGADO!!!");

	return 0;
}
