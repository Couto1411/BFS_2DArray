#include "fila.h"

void FFVazia(Fila *f){
	f->first = (Block*) malloc (sizeof(Block));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila *f, Item d){
	f->last->prox = (Block*) malloc (sizeof(Block));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(Fila *f){
	Block *aux;
	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	aux = f->first;
	f->first = f->first->prox;
	free(aux);
}

void preencheMatrix(){
    FILE *f;
	char arquivo[80];
	char barreira[100];
	int barreirai,barreiraj;
	printf("Qual o nome do arquivo do labirinto? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
    if(!(f=fopen(arquivo,"r"))){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
	fscanf(f,"%d",&tamanhoMatrix);
	fclose(f);
	matrix=(int**) malloc(sizeof(int*)*(tamanhoMatrix+1));
	for (int i = 0; i < tamanhoMatrix+1; i++){
		matrix[i]=(int*)malloc(sizeof(int)*tamanhoMatrix);
		for (int j = 0; j < tamanhoMatrix; j++)
			matrix[i][j]=0;
	}
	f=fopen(arquivo,"r");
	fscanf(f,"%s",barreira);
	fscanf(f,"%s",barreira);
	while(!feof (f)){
		barreirai=barreira[0]-'0';
		barreiraj=barreira[2]-'0';
		matrix[barreirai][barreiraj]=1;
		fscanf(f,"%s",barreira);
	}
	barreirai=barreira[0]-'0';
	barreiraj=barreira[2]-'0';
	matrix[barreirai][barreiraj]=1;
    fclose(f);
}

void FImprime(Fila *f){
	Block *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d-", aux->data.val);
		aux = aux->prox;
	}
	printf("\n");
}

void printMatrix(){
	for (int i = 0; i < tamanhoMatrix; i++)
	{
		for (int j = 0; j < tamanhoMatrix; j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}