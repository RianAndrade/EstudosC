#include <stdio.h>
#include <time.h>

/* Faça um programa em C que cria uma struct Horário, contendo informações de Horas, Minutos e
Segundos. Utilizando a constante __TIME__ faça a alimentação de uma variável do tipo Horário.
Imprima na tela a hora atual com base na struct preenchida */

struct Horario {
    int hora;
    int minuto;
    int segundo;
};

int main() {
    struct Horario hora_atual;

    sscanf(__TIME__, "%d:%d:%d", &hora_atual.hora, &hora_atual.minuto, &hora_atual.segundo);

    printf("Hora atual: %02d:%02d:%02d\n", hora_atual.hora, hora_atual.minuto, hora_atual.segundo);

    return 0;
}
