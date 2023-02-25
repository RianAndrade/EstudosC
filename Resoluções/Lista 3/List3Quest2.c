#include <stdio.h>
#include <time.h>

/* 1 Faça um programa em C que cria uma struct Horário, contendo informações de Horas, Minutos e
Segundos. Utilizando a constante __TIME__ faça a alimentação de uma variável do tipo Horário.
Imprima na tela a hora atual com base na struct preenchida,
*  2 Continue o desenvolvimento do Problema #01, agora fazendo com que o usuário também alimente um
horário. Após isto, o programa deve preencher uma terceira variável do tipo Horário contendo a
diferença entre a hora atual e a hora cadastrada pelo usuário. Imprima na tela o resultado do cálculo.*/

struct Horario {
    int horas;
    int minutos;
    int segundos;
};


void segundos(struct Horario h, int *segs)
{
	*segs = (h.horas*3600) + (h.minutos*60) + h.segundos;
}


int main() {
	int segs1=0, segs2=0;
    struct Horario agora, lido, diferença;
    // pegar a hora atual e ecrevela
	sscanf(__TIME__, "%d:%d:%d", &agora.horas, &agora.minutos, &agora.segundos);
    printf("Hora atual: %02d:%02d:%02d\n", agora.horas, agora.minutos, agora.segundos);
    // ler a hora do usuario 
	printf("Agora me fale um horario seguindo o padrão: (24:60:60) \n");
	printf("Horas: ");
	scanf("%d", &lido.horas); 
	printf("Minutos: ");
	scanf("%d", &lido.minutos); 
	printf("Segundos: ");
	scanf("%d", &lido.segundos); 
	printf("Horario escrito pelo usuario: %02d:%02d:%02d\n", lido.horas, lido.minutos, lido.segundos);
	segundos(agora, &segs1);
	segundos(lido, &segs2);
	segs1= segs1 - segs2;
	if(segs1 < 0)
	{
		segs1= segs1*(-1);
	}
	
	diferença.segundos = diferença.minutos = diferença.horas = 0;
	while(1)
	{
		if(diferença.segundos < 60)
		{
			diferença.segundos = diferença.segundos+1;
			segs1 = segs1-1;
		}
		else if(diferença.minutos <59 )
		{
			diferença.segundos= 0;
			diferença.minutos = diferença.minutos +1;
		}
		else 
		{
			diferença.segundos= 0;
			diferença.minutos = 0;
			diferença.horas = diferença.horas + 1;
		}
		if (segs1 <= 0)
		{
			break;
		}
	}
	printf("Diferença dos horarios : %02d:%02d:%02d\n", diferença.horas, diferença.minutos, diferença.segundos);
    return 0;
}
