#include <stdio.h>
#include <stdlib.h>
#include <time.h>

		/*Um baralho tem N cartas, não-repetidas, numeradas entre 1 e N. Faça um programa que leia o valor de N e imprima
o resultado do “embaralhamento” das cartas.*/

int main() {
    int n, i, j, temp;

    printf("Informe o numero de cartas: ");
    scanf("%d", &n);

    int cartas[n];

    for (i = 0; i < n; i++) {
        cartas[i] = i + 1;
    }
    printf("Cartas em sequência: \n\n");
	for (i = 0; i < n; i++) {
        printf("%d  ", cartas[i]);
    }
    
    printf("\n\n");
    
    srand(time(NULL));

    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = temp;
    }

    printf("Resultado do embaralhamento: \n\n");
    for (i = 0; i < n; i++) {
        printf("%d  ", cartas[i]);
    }

    return 0;
}
