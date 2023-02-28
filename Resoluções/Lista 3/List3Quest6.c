#include <stdio.h>
#include <string.h>
#define max 100
/*6 - Uma pequena mercearia deseja informatizar o seu processo de estoque e vendas. Faça um programa
que alimente um vetor com até 100 registros de Produto: Código de Barras (i), Descrição (s), Qtde. em
Estoque (i), Valor Unitário (f).
Após cadastrar o estoque, o programa entrará em modo de venda, neste modo, o programa segue o
seguinte fluxo:
● Usuário informa o Código de Barra do produto a ser vendido;
● Programa imprime as informações do produto (ou se ele não existe);
● Usuário informa a Quantidade que deseja comprar deste item;
● Programa verifica se possui em estoque a quantidade desejada;
● Caso seja possível a venda, o programa contabiliza o valor a ser pago e atualiza a quantidade no
estoque;
O Programa repete o processo de vendas, até que Código de Barras informado seja um valor negativo;
Caso seja informado um código negativo, o programa imprime o valor total da venda realizada, o valor
pago e o troco a ser devolvido. */

struct mt 
{
	int cb, qtde, sto;
	char desc[max];
	float valor;
};
	
void linha(int tamanho)
{
	int n;
	printf("\n");
	for(n=0; n<tamanho; n++)
	{
		printf("-=");
	}
	printf("\n");
}

void escEsto(struct mt produto[])
{
	int i;
	i=0;
	while(1)
	{
		if(produto[i].cb < 0)
		{
			break;
		}
		printf("Codigo de barras do Produto: ");
		printf("%d - ", produto[i].cb);
		printf("Descrição: ");
		printf("%s", produto[i].desc);
		printf("\nQuantidade em Estoque: "); 
		printf("%d - ", produto[i].qtde);
		printf("Valor: ");
		printf("R$: %.2f", produto[i].valor);
		i = i+1;
		linha(30);
	}
}

void escUni(struct mt produto[], int i)
{
		linha(30);
		printf("Codigo de barras do Produto: ");
		printf("%d - ", produto[i].cb);
		printf("Descrição: ");
		printf("%s", produto[i].desc);
		printf("\nQuantidade em Estoque: "); 
		printf("%d - ", produto[i].qtde);
		printf("Valor: ");
		printf("R$: %.2f", produto[i].valor);
		i = i+1;
		linha(30);
}

void cadastro(struct mt produto[], int *quant )
{
	linha(40);
	printf("\n                                   Cadastro\n");
	linha(40);
	while(1)
	{
		printf("Codigo de barras do Produto: ");
		scanf("%d", &produto[*quant].cb);;
		if(produto[*quant].cb < 0)
		{
			break;
		}
		getchar();
		printf("Descrição: ");
		fgets(produto[*quant].desc, max, stdin);
		printf("Quantidade em Estoque: "); 
		scanf("%d", &produto[*quant].qtde);
		printf("Qual o valor: ");
		scanf("%f", &produto[*quant].valor);
		linha(30);
		*quant = *quant + 1;
		
	}
	linha(40);
	printf("\n                           Cadastro encerrado\n");
	linha(40);
}


void venda(struct mt produto[], int quant, float *total_pagar)
{
	linha(40);
	printf("\n                           Venda\n");
	linha(40);
	int cd_us, qtde_us, n, existe = 1, indice;
	float valor_total_us=0;
	// repetição ate que termine as vendas
	while(1)
	{
	// codigo de barras e exibir imformação
		while(1)
		{
		 printf("\nCodigo de Barras do Produto: ");
		 scanf("%d", &cd_us);
		 if(cd_us < 0)
		 {
			linha(40);
			printf("\n                           Cadastro encerrado\n");
			linha(40);
			 break;
		 }
		 for(n=0; n<= quant; n++)
		 {
			 if(cd_us == produto[n].cb)
			 {
				 linha(30);
				 printf("\n                   Produto solicitador:\n");
				 escUni(produto, n);
				 existe = 0;
				 indice = n;
				 break;
			 }
		 }
		 if(!existe)
		 {
			break;
		 }
		 
		 else{
			linha(40);
			printf("\nCodigo de Barras Inexistente\n");
			linha(40);
		 }
		 existe= 1;
		}
		if(cd_us < 0)
		 {
			 break;
		 }
		// Perguntar a quantidade e ver se tem no estoque
		while(1)
		{
			printf("Qual a quantiade você deseja: ");
			scanf("%d", &qtde_us);
			linha(30);
			if( qtde_us <= produto[indice].qtde)
			{
				produto[indice].qtde = produto[indice].qtde - qtde_us;
				valor_total_us = qtde_us * produto[indice].valor + valor_total_us;
				printf("O valor total a ser pago será: R$: %.2f\n", valor_total_us);
				linha(30);
				break;
			}
			else 
			{
				printf("\nEssa Quantidade excede nosso estoque, tente novamente!\n");
			}
			
		}
	}
	*total_pagar = valor_total_us; 
}
void troco(float total)
{
	float pago, troco;
	printf("Qual foi o valor pago pelo cliente: ");
	scanf("%f", &pago);
	troco = pago - total;
	printf("O valor entregue foi: %.2f\nO total comprado foi: %.2f\nO troco será: %.2f\n", pago, total, troco);
	
	
}
int main()
{
	int quant = 0;
	float total_pagar;
	struct mt produto[100];
	cadastro(produto, &quant);
	escEsto(produto);
	venda(produto, quant, &total_pagar);
	troco(total_pagar);
	linha(40);
	return 0;
}

