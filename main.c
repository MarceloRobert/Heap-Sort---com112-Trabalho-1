#include <stdio.h>
#include <stdlib.h>
#include "ordIO.h"
#include "heap.h"

int main(void) {
  char nome[100] = "arq.txt";
	int quantidade;
	/*printf("Dê o nome do arquivo:\n");
	scanf("%s", nome);*/
	printf("Dê a quantidade:\n");
	scanf("%d", &quantidade);

	geraNumerosAleatorios(quantidade, nome);

	int *vetor;
	vetor = (int*) malloc(quantidade*sizeof(int));

	carregaVetor(vetor, quantidade, nome);
	imprimeVetor(vetor, quantidade);
	
	heapSort(vetor, quantidade);
	imprimeVetor(vetor, quantidade);


  return 0;
}