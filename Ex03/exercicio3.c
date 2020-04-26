#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 10

struct produto
{
    int codigo;
    char descricao[20];
    float preco;
};

void metodo_insercao(struct produto vetor[]);

int busca_Sequencial(struct produto vetor[], int cod);

int main() 
{    
    struct produto vetor[n];
    int cod, busca;

    for(int i = 0; i < n; i++)
	{	
        printf("Descrição Produto: ");
        fgets(vetor[i].descricao, 20, stdin);
        printf("Digite o código do produto: ");
		scanf("%d", &vetor[i].codigo);
        printf("Preco do Produto: ");
        scanf("%f", &vetor[i].preco);
        getchar();
    }

    metodo_insercao(vetor);
	
	printf("Produtos em ordem alfabética: \n");
	
    for(int i = 0; i < n; i++)
    {
        printf(" Descricao : %s ", vetor[i].descricao);
        printf("Codigo: %d\n", vetor[i].codigo);
        printf(" Preco: %.2f\n\n", vetor[i].preco);
    }

    printf("\nDigite o codigo a ser buscado: ");
    scanf("%d", &cod);
    busca = busca_Sequencial(vetor, cod);
    if(busca != -1)
    {
        printf("%d de comparacoes para achar o produto: %s", busca, vetor[busca-1].descricao);
    }
    else
    {
        printf("Produto nao encontrado");
    }

    return 0;
}

void metodo_insercao(struct produto vetor[])
{
    struct produto aux;
    int j;
    for(int i = 0; i < n; i++)
    {
        aux = vetor[i];
        for(j = i; (j > 0) && (strcmp(aux.descricao, vetor[j-1].descricao) < 0); j--)
        {
            vetor[j] = vetor[j-1];
        }
        vetor[j] = aux;
    }
}

int busca_Sequencial(struct produto vetor[], int cod){
   for(int i = 0; i < n; i++)
   {
       if(cod == vetor[i].codigo)
       {
           return i+1;
       }
   }
   return -1;
}
