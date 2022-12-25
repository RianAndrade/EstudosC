#include <stdio.h>

/* Faça um programa que leia um par de valores inteiros (X,Y), tal que, obrigatoriamente Y >= X. O programa deve
calcular e imprimir o valor da soma de todos os números inteiros do intervalo X,Y (inclusive). A operação deve ser
repetida até que os dois valores (X e Y) informados sejam negativos. (P.ex.: (7,11)==45; (53,68)==968).
*/

int main()
{ 	
	int x = 1, y = 1, z, xaux ;
	while (x && y > 0)
	{
		x = y = 1;
		printf("Digite o primeiro número: ");
		scanf(" %d", &x);
		while (1)
		{
		printf("Digite o segundo número: ");
		scanf(" %d", &y);	
		if (y >= x)
			break;
		else 
			printf("Número inválido \n ");
		}
		z = x;
		xaux = x;
		while(xaux < y)
		{
			xaux += 1;
			z += xaux;	
		}
		if (x && y > 0)
		{
		printf("-=-=-=-=-=-=-=-=-=-=-=\n");
		printf(" X = %d\n Y= %d\n Soma = %d \n", x, y, z);
		printf("-=-=-=-=-=-=-=-=-=-=-=\n");
		}
	}
	
	return 0;
}


