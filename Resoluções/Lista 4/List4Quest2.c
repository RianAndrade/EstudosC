#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Artigo {
    char autor[50];
    char titulo[100];
    char area[50];
    int ano;
    struct Artigo *prox;
} Artigo;

Artigo *criar_registro() {
    Artigo *art = (Artigo*) malloc(sizeof(Artigo));
    if (art == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    printf("Digite o nome do autor: ");
    fgets(art->autor, 50, stdin);
    printf("Digite o titulo do artigo: ");
    fgets(art->titulo, 100, stdin);
    printf("Digite a area de conhecimento: ");
    fgets(art->area, 50, stdin);
    printf("Digite o ano de publicacao: ");
    scanf("%d", &art->ano);
    getchar(); // consumir o caractere \n deixado pelo scanf
    art->prox = NULL;
    return art;
}

void inserir_registro(Artigo **inicio) {
    Artigo *art = criar_registro();
    if (*inicio == NULL) {
        *inicio = art;
    } else {
        Artigo *aux = *inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = art;
    }
}

int contar_registros(Artigo *inicio) {
    int cont = 0;
    Artigo *aux = inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void imprimir_registro(Artigo *inicio) {
    int n = contar_registros(inicio);
    int meio = n / 2;
    int i = 0;
    Artigo *aux = inicio;
    while (aux != NULL) {
        if (i == meio) {
            printf("Autor: %s", aux->autor);
            printf("Titulo: %s", aux->titulo);
            printf("Area de conhecimento: %s", aux->area);
            printf("Ano de publicacao: %d\n", aux->ano);
            break;
        }
        i++;
        aux = aux->prox;
    }
}

void imprimir_registros(Artigo *inicio, int inicio_ano, int fim_ano) {
    Artigo *aux = inicio;
    while (aux != NULL) {
        if (aux->ano >= inicio_ano && aux->ano <= fim_ano) {
            printf("Autor: %s", aux->autor);
            printf("Titulo: %s", aux->titulo);
            printf("Area de conhecimento: %s", aux->area);
            printf("Ano de publicacao: %d\n", aux->ano);
        }
        aux = aux->prox;
    }
}

void excluir_registro(Artigo **inicio) {
    if (*inicio == NULL) {
        printf("Nao ha registros para excluir!\n");
        return;
    }
    char titulo[100];
    printf("Digite o titulo do artigo a ser excluido: ");
    fgets(titulo, 100, stdin);
    Artigo *aux = *inicio;
    Artigo *ant = NULL;
    while (aux != NULL && strcmp(aux->titulo, titulo) != 0) {
        ant = aux;
        aux = aux->prox;
    }
       
	if (ant == NULL) {
		*inicio = aux->prox;
	} else {
		ant->prox = aux->prox;
	}
	free(aux);
	printf("Artigo excluido com sucesso!\n");
	
	}

void liberar_memoria(Artigo **inicio) {
	Artigo *aux = *inicio;
	while (aux != NULL) {
		Artigo *temp = aux->prox;
		free(aux);
		aux = temp;
	}
	*inicio = NULL;
}

void imprimir_todos_registros(Artigo *inicio) {
    Artigo *aux = inicio;
    while (aux != NULL) {
        printf("Autor: %s", aux->autor);
        printf("Titulo: %s", aux->titulo);
        printf("Area de conhecimento: %s", aux->area);
        printf("Ano de publicacao: %d\n", aux->ano);
        aux = aux->prox;
    }
}


int main() {
	Artigo *inicio = NULL;
	int opcao, inicio_ano, fim_ano;
	do {
		printf("\n1 - Inserir registro");
		printf("\n2 - Excluir registro");
		printf("\n3 - Imprimir registro do meio");
		printf("\n4 - Imprimir registros por ano");
		printf("\n5 - Imprimir todos os registros");
		printf("\n6 - Sair\n");
		printf("Digite uma opcao: ");
		scanf("%d", &opcao);
		getchar(); // consumir o caractere \n deixado pelo scanf
	switch (opcao) {
		case 1:
			inserir_registro(&inicio);
		break;
		case 2:
			excluir_registro(&inicio);
		break;
		case 3:
			imprimir_registro(inicio);
		break;
		case 4:
			printf("Digite o ano de inicio: ");
			scanf("%d", &inicio_ano);
			printf("Digite o ano de fim: ");
			scanf("%d", &fim_ano);
			getchar(); // consumir o caractere \n deixado pelo scanf
			imprimir_registros(inicio, inicio_ano, fim_ano);
		break;
		case 5:
			 imprimir_todos_registros(inicio);
		break;
		case 6:
			liberar_memoria(&inicio);
			printf("Programa encerrado.\n");
		break;
		default:
			printf("Opcao invalida!\n");
		}
	} while (opcao != 6);
	return 0;
}
