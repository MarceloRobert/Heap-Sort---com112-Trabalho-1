#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordIO.h"

/*
	char nome[100];
	int quantidade;
	printf("Dê o nome do arquivo:\n");
	scanf("%s", nome);
	printf("Dê a quantidade:\n");
	scanf("%d", &quantidade);

	geraNumerosAleatorios(quantidade, nome);

	int *vetor;
	vetor = (int*) malloc(quantidade*sizeof(int));

	carregaVetor(vetor, quantidade, nome);
	imprimeVetor(vetor, quantidade);
*/

//função que gera números aleatórios e os coloca no arquivo de nome correspondente
void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]){
	FILE *arquivo;
	int random;
	srand(time(NULL));

	arquivo = fopen(nomeArquivo, "w");
	for(int i=0; i<qtNumeros;i++){
		random = rand()%qtNumeros;
		fprintf(arquivo, "%d ", random);
	}

	fclose(arquivo);

	return;
}

//função que lê o arquivo e coloca os dados no vetor
void carregaVetor(int vet[], int tam, char nomeArquivo[]){
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "r");

	for(int i=0; i<tam; i++){
		fscanf(arquivo, "%d", &vet[i]);
	}

	fclose(arquivo);

	return;
}


//função para imprimir o vetor
void imprimeVetor(int vet[], int tam){
	for(int i=0; i<tam; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");

	return;
}

//função de busca sequencial
int buscaSeq(int vet[], int tam, int elemento){

	for(int i=0; i<tam; i++){
		if(vet[i] == elemento){
			return 1;
		} else {
			i++;
		}
	}

	return 0;
}

//função de busca binária
int buscaBin(int vet[], int tam, int elemento){
	int inicio = 0;
	int meio;
	int fim = tam;

	int i=0;

	while(inicio != fim){
		meio = (inicio+fim)/2;
		if(vet[meio] > elemento){
			fim = meio;
		} else {
			if(vet[meio] < elemento){
				inicio = meio+1;
			} else {
				//encontrado
				return 1;
			}
		}
	}

	return 0;

}
