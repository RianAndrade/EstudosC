#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Faça um programa que receba do usuário o comprimento de três retas. O programa deve informar ao usuário se é
possível ou não formar um triângulo com essas retas.*/

int main()
{
	int a, b,c;
	printf("Escreva o primeiro valor: ");
	scanf("%d", &a);
	printf("Escreva o segundo valor: ");
	scanf("%d", &b);
	printf("Escreva o terceiro valor: ");
	scanf("%d", &c);
	if (a+b <= c &&  b+c <= a && a+c <= b)
		printf("Pode se forma um triângulo");
	else
		printf("Não pode se forma um triângulo");
	return 0;
}

