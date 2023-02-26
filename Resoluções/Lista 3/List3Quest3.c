#include <stdio.h>
/*Faça um programa que realize simulações de empréstimo financeiro. Modele a struct Proposta: Valor
Emprestado (f), Prazo (i) e Taxa de juros (f). Calcule o valor de cada parcela e o valor total pago ao final
do empréstimo. Faça novas simulações até que o usuário informe o Valor de Empréstimo negativo. */

struct emp
{
	float val_emp;
	int prazo;
	float taxa_juro;
};


int main()
{
	float m, i;
	struct emp emp1;
	/* formula do juros compostos 
	    M = C (1+i)t

Nesta equação, cada letra significa um valor: 

    M é o montante acumulado, o total da aplicação
    C é o capital investido
    i é a taxa de juros
    t é o período de tempo */
	
	while(1)
	{
		printf("Qual o valor emprestado: (Valor negativo encerrra o programa)");
		scanf("%f", &emp1.val_emp);
		if(emp1.val_emp < 0)
		{
			break;
		}
		printf("Qual o prazo: (Em anos)");
		scanf("%d", &emp1.prazo);
		printf("Qual a taxa de juros: (Em porcentagem)");
		scanf("%f", &emp1.taxa_juro);
		float juros = 1;
        for(i = 0; i < emp1.prazo; i++)
        {
            juros *= 1 + emp1.taxa_juro;
        }
        
        m = emp1.val_emp * juros;
		printf("Valor de cada parcela: %.2f \n Valor total pago ao final: %.2f \n", m/(12*emp1.prazo) ,m);
	}
	return 0;
}

