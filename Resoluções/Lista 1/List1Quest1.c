#include <stdio.h>
/* 1. Faça um programa que leia um número indeterminado de valores inteiros. A leitura somente será interrompida
	quando o usuário informar o valor zero. Valores negativos devem ser ignorados para os cálculos. O programa deve
	gerar os seguintes resultados (ignorando valor 0 e negativos): Soma dos números lidos, Média dos números lidos,
	Maior valor informado, Menor valor informado, Percentual de números pares e o Percentual de Números ímpares.
 */


int main()
{
	int num = 1, soma = 0, maior, menor, contador = 0, contpar = 0,contimp;
	while(num != 0)
	{	 
		printf("Digite um número:");
		scanf("%d", &num);
		// para só utilizar números positivos 
		if (num > 0)
		{
			 soma += num;
			 contador += 1;
			// para evitar ganbirras na declaração de maior e menor 
			if (contador == 1)
			{
				maior = num;
				menor = num;
			}
			// descobrir o maior e o menor 
			if (num > maior)
				maior = num;
			if (num < menor)
				menor = num;
			// descobri se o número e par ou inpar 
			if (num%2 == 0)
				contpar += 1;
			if (num%2 != 0)
				contimp += 1;		
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("A soma é: %d\nA média dos números é: %d\nO maior valor informado: %d\nO menor valor informado: %d\nPercentual de números pares: %d\nPercentual de números ímpares: %d\n", soma, soma/contador, maior, menor, contpar*100/contador, contimp*100/contador);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

	return 0;
}

