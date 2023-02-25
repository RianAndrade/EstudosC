#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Escreva um programa em C para ler uma frase. A seguir, imprima a frase com: (a) todas as letras maiúsculas, (b)
todas as letras minúsculas, (c) início de cada palavra em maiúsculo. */

int main()
{
    int tamanho = 100;
    char frase[tamanho];
    
    printf("Digite uma frase: ");
    fgets(frase, tamanho, stdin);
    
    // Imprimir todas as letras maiúsculas
    printf("Frase em letras maiusculas: ");
    for (int i = 0; frase[i] != '\0'; i++) {
        printf("%c", toupper(frase[i]));
    }
    
    // Imprimir todas as letras minúsculas
    printf("\nFrase em letras minusculas: ");
    for (int i = 0; frase[i] != '\0'; i++) {
        printf("%c", tolower(frase[i]));
    }
    
    // Imprimir início de cada palavra em maiúsculo
    printf("\nFrase com inicio de cada palavra em maiusculo: ");
    int inicio_palavra = 1; // Flag para indicar início de palavra
    for (int i = 0; frase[i] != '\0'; i++) {
        if (inicio_palavra && isalpha(frase[i])) {
            printf("%c", toupper(frase[i]));
            inicio_palavra = 0;
        } else {
            printf("%c", tolower(frase[i]));
        }
        if (isspace(frase[i])) {
            inicio_palavra = 1;
        }
    }
    
    return 0;
}


