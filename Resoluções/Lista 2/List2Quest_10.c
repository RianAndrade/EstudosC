#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_lista(int* lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int n, x, y;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    printf("Digite o valor de X: ");
    scanf("%d", &x);
    printf("Digite o valor de Y: ");
    scanf("%d", &y);

    int* lista = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % (y - x + 1) + x;
    }

    printf("Original: ");
    imprimir_lista(lista, n);

    int* trocados = (int*) calloc(n, sizeof(int));
    int pode_trocar = 1;
    while (pode_trocar) {
        int idx_max = 0;
        int idx_min = 0;
        for (int i = 1; i < n; i++) {
            if (lista[i] > lista[idx_max] && !trocados[i]) {
                idx_max = i;
            }
            if (lista[i] < lista[idx_min] && !trocados[i]) {
                idx_min = i;
            }
        }
        if (idx_max == idx_min) {
            pode_trocar = 0;
        } else {
            int temp = lista[idx_max];
            lista[idx_max] = lista[idx_min];
            lista[idx_min] = temp;
            trocados[idx_max] = 1;
            trocados[idx_min] = 1;
            printf("Iteração: ");
            imprimir_lista(lista, n);
        }
    }

    free(lista);
    free(trocados);
    return 0;
}
