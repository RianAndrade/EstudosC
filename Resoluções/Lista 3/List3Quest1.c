#include <stdio.h>
#include <time.h>

/* Faça um programa em C que cria uma struct Horário, contendo informações de Horas, Minutos e
Segundos. Utilizando a constante __TIME__ faça a alimentação de uma variável do tipo Horário.
Imprima na tela a hora atual com base na struct preenchida */

struct Horario {
    int horas;
    int minutos;
    int segundos;
};

int main() {
    struct Horario agora;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    agora.horas = tm.tm_hour;
    agora.minutos = tm.tm_min;
    agora.segundos = tm.tm_sec;

    printf("Horario atual: %02d:%02d:%02d\n", agora.horas, agora.minutos, agora.segundos);

    return 0;
}
