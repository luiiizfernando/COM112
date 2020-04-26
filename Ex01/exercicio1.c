#include <stdio.h>
#include <stdlib.h>

void metodoBolha(int V[]);

int main()
{
	int V[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &V[i]);
	}
	
	metodoBolha(V);
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", V[i]);
	}
	
	return 0;
}

void metodoBolha(int V[])
{
	int aux;
	
	for (int j = 0; j < 10 ; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if(V[i] < V[i+1])
			{
				aux = V[i];
				V[i] = V[i+1];
				V[i+1] = aux;
			}
		}
	}
}
