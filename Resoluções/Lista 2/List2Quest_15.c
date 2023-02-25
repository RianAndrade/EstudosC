#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
/*15. Faça um programa que leia várias strings até que o usuário informe 
 * uma contendo apenas letras (‘A’-’Z’ ou ‘a’-’z’). */
int main()
{
	int tamanho=100, i, a=1;
	char vetstr[tamanho]; 
	do
	{
		fgets(vetstr, tamanho, stdin);
		for(i=0; vetstr[i] !=  '\n'; i++) 
		{
			if(!isalpha(vetstr[i]))
			{
				printf("Strig invalida!!!\n");
				a=1;
				break;
			}
			a=0;
		}
	}while (a);
	printf("String válida: %s\n", vetstr);
	return 0;
}

