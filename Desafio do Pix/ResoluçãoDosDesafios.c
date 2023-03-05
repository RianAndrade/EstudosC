#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define max 100
struct ContaBancaria{
	
	int numConta;
	char nomeTitular[max];
	float limiteCredito;
	float saldoTotal;
	
};

struct chavesPix{
	int TipoChave;
	int chave;
	int numConta;

};


void linha(int tamanho)
{
	printf("\n"); 
	for(int n =0; n<tamanho; n++)
	{
		printf("-=");
	}
	printf("\n");
}

void cadastraPessoas(struct ContaBancaria Contas[], int *contador)
{
	srand(time(NULL));
	linha(40);
	printf("\n                                     Cadastro\n");
	linha(40);
	*contador = *contador+1;
	Contas[*contador].numConta = *contador;
	printf("Seu numero da conta será: %d",  Contas[*contador].numConta);
	printf("\nQual o seu nome: ");
	fgets(Contas[*contador].nomeTitular, max, stdin);
	printf("O nome cadastrado na sua conta sera : %s",  Contas[*contador].nomeTitular);
	Contas[*contador].limiteCredito = rand() % 4900 + 100;
	printf("Seu limite de credito é: R$: %.2f", Contas[*contador].limiteCredito);
	Contas[*contador].saldoTotal = rand() % 180 + 20;
	printf("\nSeu Saldo atual é: R$: %.2f", Contas[*contador].saldoTotal);
	linha(40);
	printf("\n                                Encerrado Cadastro\n");
	linha(40);
	

}


void consultarconta(struct ContaBancaria Contas[], int num)
{
	linha(25);
	printf("\n***Aqui estão os dados da sua Conta***\n\n");
	printf("Seu numero da conta e: %d",  Contas[num].numConta);
	printf("\nO nome cadastrado na sua conta e: %s",  Contas[num].nomeTitular);
	printf("Seu limite de credito é: R$: %.2f", Contas[num].limiteCredito);
	printf("\nSeu Saldo atual é: R$: %.2f", Contas[num].saldoTotal);
	printf("\n\n              ***fim***\n\n");
	linha(25);
}

void cadastrachaves(struct chavesPix pix[], int *contadorpix, int numero, struct ContaBancaria Contas[])
{
    srand(time(NULL));
    int existe = 0;
    linha(40);
    printf("\n                                 Cadastro Pix\n");
    linha(40);
    linha(25);
    printf("\n                       Olá %s", Contas[numero].nomeTitular );
    printf("\n\n           ***Qual o tipo da Chave:*** \n\n            1 - CPF.\n            2 - Telefone.\n            3 - Chave Aleatoria.\n");
    linha(25);
    scanf("%d", &pix[*contadorpix].TipoChave);
    getchar();
    pix[*contadorpix].numConta = numero;
    int resp = pix[*contadorpix].TipoChave;
    int val = *contadorpix;
    *contadorpix = *contadorpix + 1;
    if(resp == 1 || resp == 2)
    {
        while(1)
        {
            existe = 0;
            printf("Qual será a chave: ");
            scanf("%d", &pix[val].chave);
            for(int n = 0; n < val; n++)
            {
                if (pix[n].chave == pix[val].chave && pix[n].TipoChave == pix[val].TipoChave)
                {
                    existe = 1;
                    printf("\n\nEssa Chave ja Existe Tente novamente!!!\n\n");
                    break;
                }
            }
            if(!existe)
            {
                break;
            }
        }
    }

	if(resp  == 3)
	{
		while(1)
		{
			existe = 0;
			for(int n = -1; n < val; n++)
			{
				pix[*contadorpix].chave = rand() % 8999 + 1000;
				if (pix[n].chave == pix[val].chave && pix[n].TipoChave == pix[val].TipoChave)
				{
					existe = 1;
					break;
				}
			}
			if(!existe)
			{
				printf("Sua chave Aleatoria será: %d", pix[*contadorpix].chave);
				break;
			}

		}
	}

}

void trasferencia(int NumConta, struct ContaBancaria Contas[], struct chavesPix pix[], int totalChaves)
{
	linha(25);
    printf("\n                       Olá %s", Contas[NumConta].nomeTitular );
    printf("\n             ***Para que tipo de chave você quer enviar***\n");
    printf("\n\n           ***Qual o tipo da Chave:*** \n\n            1 - CPF.\n            2 - Telefone.\n            3 - Chave Aleatoria.\n");
    linha(25);
    int tipochave, chavepix;
    float valor;
    int numcontarecebe;
   // Esse while aqui validaaaa
    while(1)
    {
		printf("\n             ***Para que tipo de chave você quer enviar***\n");
		printf("\n\n           ***Qual o tipo da Chave:*** \n\n            1 - CPF.\n            2 - Telefone.\n            3 - Chave Aleatoria.\n");
		linha(25);
		scanf("%d", &tipochave);
		printf("Qual a Chave Pix? ");	
		scanf("%d", &chavepix);
		int existe = 0;
        for(int n = -1; n <= totalChaves; n++)
        {
			if (chavepix == pix[n].chave && tipochave == pix[n].TipoChave)
            {
				numcontarecebe = n;
				existe = 1;
                break;
            }
        }
        if(existe)
        {
            break;
        }
        else 
        {
			printf("\n\nChave Inexistente tente novamente!!!\n\n");
		}
    }
	int trasferenciaFeita = 0, valoraux;
    while(1)
    {
		printf("***Aqui esta seu Credito e Saldo Atual***\n\n");
		printf("Seu limite de credito é: R$: %.2f", Contas[NumConta].limiteCredito);
		printf("\nSeu Saldo atual é: R$: %.2f\n\n", Contas[NumConta].saldoTotal);
		linha(25);
		printf("Qual o valor você deseja trasferir para a Chave Pix: %d: \n R$: ", chavepix);
		scanf("%f", &valor);
		while(1)
		{
			int resp = 0;
			if (Contas[NumConta].saldoTotal < valor)
			{
				printf("Seu saldo atual e menor que o valor de trasferencia, deseja usar seu limite de credito? SIm(0) Não(1) ");
				scanf("%d", &resp);
				if(resp)
				{
					break;
				}
				else
				{
					valoraux = (Contas[NumConta].saldoTotal - valor) * -1;
					if(valoraux > Contas[NumConta].limiteCredito)
					{
						printf("Vocẽ não tem limite para essa trasferencia trasferencia");
						break;

					}
					else
					{
						Contas[NumConta].saldoTotal = 0;
						Contas[pix[numcontarecebe].numConta].saldoTotal = Contas[pix[numcontarecebe].numConta].saldoTotal + valor;
						Contas[NumConta].limiteCredito = Contas[NumConta].limiteCredito - valoraux;
						trasferenciaFeita = 1;
						break;
					}
				}

			}
			else
			{
				Contas[NumConta].saldoTotal = Contas[NumConta].saldoTotal - valor;
				Contas[pix[numcontarecebe].numConta].saldoTotal = Contas[pix[numcontarecebe].numConta].saldoTotal + valor;
				trasferenciaFeita = 1;
				break;
			}
		}
		if(trasferenciaFeita == 1)
		{
			break;
		}
	}

}


int main()
{
	int contador = 0, contadorpix = 0, opc, opc2, numCon = 0;
	struct ContaBancaria Contas[100];
	struct chavesPix pix[100];
	while(1)
	{	
		linha(25);
		printf("\n\n           ***Oque você deseja:*** \n\n            1 - Cadastrar Pessoa.\n            2 - Consultar Conta.\n            3 - sair.\n");
		linha(25);
		scanf("%d", &opc);
		getchar();
		linha(25);
		if (opc == 1)
		{
			cadastraPessoas(Contas, &contador);
		}
		if (opc == 2)
		{
			linha(25);
			printf("\n Qual o número da sua conta: ");
			scanf("%d", &numCon);
			while(1)
			{
				consultarconta(Contas, numCon);
				linha(25);
				printf("\n\n           ***Oque você deseja:*** \n\n            1 - Cadastrar Chave Pix.\n            2 - Realizar trasferencia.\n            3 - Voltar Para o Menu.\n");
				linha(25);
				scanf("%d", &opc2);
				getchar();
				linha(25);
				if (opc2 == 1)
				{
					cadastrachaves(pix, &contadorpix, numCon,Contas);
				}
				if (opc2 == 2)
				{
					trasferencia(numCon, Contas, pix, contadorpix);
				}
				if (opc2 == 3)
				{
					break;
				}
			}
		}
		if (opc == 3)
		{
			break;
		}

	}
	return 0;
}

