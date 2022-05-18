#include "fila.h"

int main()
{
	int iteracoes;
	Fila f;
	preencheMatrix();
	printMatrix();
	FFVazia(&f);
	iteracoes=BFS(&f);
	printf("Foram necessarias %d iteracoes para chegar a essa conclusao.\n",iteracoes);
	printMatrix();

	return 0;
}