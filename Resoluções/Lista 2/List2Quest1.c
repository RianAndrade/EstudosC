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
    /*Optei por uma descrição mais detalhada pois utilizei um mecanismo um pouco diferente do convencinal as praticas inicias da programação, este é o loop que realiza o embaralhamento das cartas. Ele começa na última posição do array cartas (n - 1) e termina na primeira posição (0). 
    Gera uma posição aleatória j: a função rand() gera um número inteiro aleatório. O operador % é usado para obter um número aleatório entre 0 e i (inclusive).
    Armazena a carta na posição i na variável temporária temp.
    Troca as cartas na posição i e j: a carta na posição i é atribuída à posição j, e a carta anteriormente na posição j é armazenada na posição i usando a variável temporária temp.  */
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
