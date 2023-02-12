#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void lin(int tan)
{
	int a;
	printf("\n");
	for(a=0; a<tan; a++)
	{
		printf("-=");
	}
	printf("\n\n");
}
int main()
{
	int x, k, i, j, temp, taMax;
	lin(30);
	printf("Me diga qual o tamanho do primeiro vetor: ");
	scanf("%d", &x);
	printf("Me diga qual o tamanho do segundo vetor: ");
	scanf("%d", &k);
	lin(30);
	srand(time(NULL));
	int vet1[x];
	int vet2[x];
	taMax= x+k+1;
	for(i=0; i<x; i++)
	{
		vet1[i]= taMax+1;
	}
	for(i=0; i<k; i++)
	{
		vet2[i]= taMax+1;
	}
	for(i=0; i<x; i++)
	{
		temp= rand() % taMax;
		for(j=0; j<x; j++)
		{
			if(temp == vet1[j])
			{
				temp= rand() % taMax;
				j= -1;
			}
			
		}
		vet1[i]= temp;
	}
	for(i=0; i<k; i++)
	{
		temp= rand() % taMax;
		for(j=0; j<k; j++)
		{
			if(temp == vet2[j])
			{
				temp= rand() % taMax;
				j= -1;
			}
		}
		vet2[i]= temp;
	}
	for(i=0; i<x; i++)
	{
		printf("[%02d]", vet1[i]);
	}
	printf("\n\n");
	for(i=0; i<k; i++)
	{
		printf("[%02d]", vet2[i]);
	}
	printf("\n");
	lin(30);
	return 0;
}

