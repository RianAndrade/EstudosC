#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 8, 10, 29, 31 

int main()

{
	int menor, maior, tamanho, contador, contador0, menortd, indi; 
	srand(time(NULL));
	printf("Qual o menor valor? \n");
	scanf("%d", &menor);
	printf("Qual o maior valor? \n");
	scanf("%d", &maior);
	tamanho = 1+rand()%(10-1+1);
	int ma[tamanho];
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("O tamanho do vetor é = %d\n", tamanho);
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

	for (contador = 0; contador < tamanho; contador++){
		ma[contador] = 	menor+rand()%(maior-menor+1);
		printf("%d, ", ma[contador]);
	}
	printf("\n");
	menortd = ma[0];
	for (contador0 = 0; contador0 < tamanho; contador0++){
			for (contador = 0; contador < tamanho; contador++){
				if (ma[contador] <= menortd){
					menortd = ma[contador];
					indi = contador + 1;
				}
			}
			printf ("Valor: %d Indice: %d \n", menortd, indi);
			ma[indi - 1] = 10000;
			contador = 0;
			menortd = ma[0];
	}	

 	return 0;
 	
}




