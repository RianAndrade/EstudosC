#include <stdio.h>

typedef struct ponto {
    float x;
    float y;
} Ponto;

typedef struct reta2d {
    Ponto a;
    Ponto b;
} Reta2D;

int main() {
    Reta2D reta1, reta2;

    // Cadastro da primeira reta
    printf("Entre com as coordenadas do ponto A da reta 1:\n");
    printf("Xa: ");
    scanf("%f", &reta1.a.x);
    printf("Ya: ");
    scanf("%f", &reta1.a.y);

    printf("Entre com as coordenadas do ponto B da reta 1:\n");
    printf("Xb: ");
    scanf("%f", &reta1.b.x);
    printf("Yb: ");
    scanf("%f", &reta1.b.y);

    // Cadastro da segunda reta
    printf("Entre com as coordenadas do ponto A da reta 2:\n");
    printf("Xa: ");
    scanf("%f", &reta2.a.x);
    printf("Ya: ");
    scanf("%f", &reta2.a.y);

    printf("Entre com as coordenadas do ponto B da reta 2:\n");
    printf("Xb: ");
    scanf("%f", &reta2.b.x);
    printf("Yb: ");
    scanf("%f", &reta2.b.y);

    // Verificando se as retas são paralelas, perpendiculares ou nenhuma das duas
    float m1 = (reta1.b.y - reta1.a.y) / (reta1.b.x - reta1.a.x);
    float m2 = (reta2.b.y - reta2.a.y) / (reta2.b.x - reta2.a.x);

    if (m1 == m2) {
        printf("As duas retas sao paralelas.\n");
    } else if (m1 * m2 == -1) {
        printf("As duas retas sao perpendiculares.\n");
    } else {
        printf("As duas retas nao sao paralelas nem perpendiculares.\n");
    }

    return 0;
}
