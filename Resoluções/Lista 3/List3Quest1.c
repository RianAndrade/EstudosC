#include <stdio.h>
#include <time.h>

struct horario {
    int horas;
    int minutos;
    int segundos;
};

int main() {
    struct horario horarios;
    struct tm *data_hora_atual;

    // Obtem a hora atual
    data_hora_atual = localtime(NULL);

    // Armazena na struct horario
    horarios.horas = data_hora_atual->tm_hour;
    horarios.minutos = data_hora_atual->tm_min;
    horarios.segundos = data_hora_atual->tm_sec;

    // Imprime a hora atual
    printf("A hora atual é: %02d:%02d:%02d\n", horarios.horas, horarios.minutos, horarios.segundos);

    return 0;
}
