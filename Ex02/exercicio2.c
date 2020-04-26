#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 10

struct funcionario
{
	char nome[25];
	float salario;
};

void ordenacao_salario(struct funcionario vetor[]);

void ordenacao_alfabetica(struct funcionario vetor[]);

int main()
{	
	struct funcionario vetor[n];
	
	for (int i = 0; i < n; i++)
	{
		 printf("Digite o %d nome e tecle enter: ", i+1);
		 fgets(vetor[i].nome, 25, stdin);
		 printf("Digite o salario do %d funcionario e digite enter: ", i+1);
		 scanf("%f", &vetor[i].salario);
		 getchar();
	}
	
	ordenacao_salario(vetor);
	
	printf("Ordem decrescente de salario: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%.2f - %s", vetor[i].salario, vetor[i].nome);
	}
	
	ordenacao_alfabetica(vetor);
	
	printf("Ordem alfabetica: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%.2f - %s", vetor[i].salario, vetor[i].nome);
	}
	
	return 0;
}

void ordenacao_salario(struct funcionario vetor[])
{
	int menor;
	struct funcionario troca;
	
	for(int i = 0; i < n-1; i++)
	{
		menor = i;
		for(int j = i+1; j < n; j++)
		{
			if(vetor[j].salario > vetor[menor].salario)
			{
				menor = j;
			}
		}
		
		if(i != menor)
		{
			troca = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = troca;
		}
	}
}

void ordenacao_alfabetica(struct funcionario vetor[])
{
	int menor;
	struct funcionario troca;
	
	for (int i = 0; i < n-1; i++)
	{
		menor = i;
		for(int j = i+1; j < n; j++)
		{
			if(strcasecmp(vetor[j].nome, vetor[menor].nome) < 0)
			{
				menor = j;
			}
		}
		if(i != menor)
		{
			troca = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = troca;
		}
	}
}

