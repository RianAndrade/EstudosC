#include <string.h>  
#include <stdlib.h>
#include <stdio.h>

/*Questão 01 [Listas Encadeadas]
Considere um site de busca de conteúdos que possua uma coleção de arquivos torrent disponibilizados
para download dos usuários. Considerando que as informações dos arquivos torrent (nome do conteúdo
e link para download) são armazenados em uma estrutura de dados do tipo lista simplesmente
encadeada, faça um programa que dado o nome de um conteúdo, busque e imprima o link
correspondente, e após isso, mova o nó que contém o nome buscado para o início da lista, de forma que
este possa ser encontrado mais rapidamente na próxima vez que for buscado.
Faça também uma função para cadastro de arquivos no site e uma função para imprimir todos os
arquivos da mantidos na lista */


// Definição da struct pedida 

typedef struct no{
	char nome[50]; // declaração normal de uma array como string 
	char link[100];
	struct no* prox; // declaro prox como o ponteiro para a proxima struct, deixando claro que apesar de parecer que eu declarei prox como sendo uma stuct do tipo no na verdade ele e um ponteiro que aponto para uma struct do tipo no
}No;
	
// Função para cadastrar um novo arquivo na lista

void cadastrar_arquivo(No** lista_encadeada) { // retorna o ponteiro que aponta para o ponteiro da Lista
    No* novo = (No*) malloc(sizeof(No)); // aloca memoria para armazenar mais uma strcut do tipo No na memoria ram como o nome (novo)
//      =--->  (aqui) <---=    acho bom comentar que (No*) ta ai para falar que o ponteiro que retornara será para um arquivo do tipo No
    printf("Digite o nome do conteúdo: ");
    scanf("%s", novo->nome);
    printf("Digite o link para download: ");
    scanf("%s", novo->link); // Aqui e so leitura e como estamos trabalhando com ponteiros usamos -> no lugar di . convencional

    novo->prox = *lista_encadeada; // Ou seja prox vai receber o item armazenado na lista no primeiro caso Null, depois vai ser sempre o primeiro item da lista
    *lista_encadeada = novo; // Depois Novo vira o primeiro item da lsita
}

// Função para imprimir todos os arquivos da lista

void imprimir_lista(No* lista) { // puxa o primeiro item da lista no caso o ponteiro
    printf("\n----- LISTA DE ARQUIVOS -----\n\n");

    No* atual = lista; // atual recebe o primeiro item da lista

    while (atual != NULL) { //Como null e o ultima indice da lista enquanto foi diferente de Null ele imprime
        printf("Nome: %s\n", atual->nome);  // printa o nome
        printf("Link: %s\n\n", atual->link);

        atual = atual->prox; // atual recebe o pomteire que atual esta apontando ou seja atual recebe o ponteiro do proximo item ate que seja encontrado o ultima que estra coM Null
    }
}


// Função para buscar um nó na lista pelo nome e movê-lo para o início
void buscar_e_mover(No** lista, char* nome) { // chama o ponteira que aponta para o ponteira da lista no caso o primeiro item da lisda
    No* atual = *lista; // 
    No* anterior = NULL;

    // Procura o nó com o nome informado na lista
    while (atual != NULL && strcmp(atual->nome, nome) != 0) { // Ou seja faça enquanto atual for diferente de Null ou o retorna de strmp for diferen de 0 ja que se retorna 0 ele vai ser itual
        anterior = atual;
        atual = atual->prox;
    }

    // Se o nó foi encontrado, move-o para o início da lista
    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->prox = atual->prox;
            atual->prox = *lista;
            *lista = atual;
        }
    }

    // Imprime o link correspondente ao nome buscado
    if (atual != NULL) { // se for diferen de NUll ele imprime isso
        printf("Link para download: %s\n", atual->link);
    } else { // se for igual quer dizer que não exite ai imprime o outro
        printf("Conteúdo não encontrado na lista.\n");
    }
}


int main() {
    No* lista_encadeada = NULL;  // Como eu fiz antes aqui lista_encadeada servepara apontar para a primeira struct do tipo No, como ainda n tem nenhuma cadastrada ele e inicializada com o tipo Null
    int opcao;  // Para ler a opção
    char nome_busca[50]; // para ler o nome buscado 

    do {
        printf("\n----- MENU -----\n\n");
        printf("1 - Buscar arquivo\n");
        printf("2 - Cadastrar arquivo\n");
        printf("3 - Imprimir lista de arquivos\n");
        printf("0 - Sair\n\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o nome do arquivo que deseja buscar: ");
                scanf("%s", nome_busca);

                //buscar_e_mover(&lista, nome_busca);
                break;
            case 2:
                cadastrar_arquivo(&lista_encadeada);
                printf("Arquivo cadastrado com sucesso.\n");
                break;
            case 3:
                imprimir_lista(lista_encadeada);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }

        // Limpa o buffer do teclado para evitar problemas com fgets
        while ((opcao = getchar()) != '\n' && opcao != EOF);

    } while (opcao != 0);

    return 0;
}
