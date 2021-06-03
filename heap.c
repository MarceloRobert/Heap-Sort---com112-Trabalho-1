#include <stdio.h>
#include "heap.h"

void heapSort(int *vet, int n, float *qt){
	int i, aux;
	for(i=(n-1)/2; i >= 0; i--){
		criaHeap(vet, i, n-1, qt); //aqui ele cria a árvore Heap ("ordena", só que no modelo de árvore)
	}
	for(i=(n-1); i>=1; i--){ //aqui ele ordena de verdade, pega o modelo de árvore e o organiza no modelo de vetor. Joga o maior elemento pro final e faz a heap denovo sem o final para achar o novo maior elemento
		qt[1]++;
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux; 
		criaHeap(vet, 0, i-1, qt);
	}
}

void criaHeap(int *vet, int pai, int fim, float *qt){
	int aux = vet[pai];
	int filho = 2*pai + 1; //o elemento que está sendo analisado
	while(filho <= fim){
		qt[0]++;
		if(filho < fim){
			if(vet[filho] < vet[filho+1]){ //1
				filho = filho + 1;
			}
		}
		qt[0]++;
		if(vet[filho] > aux){ //2
			qt[1]++;
			vet[pai] = vet[filho];
			pai = filho;
			filho = 2*pai +1;
		} else {
			filho = fim+1;
		}
	}
	qt[1]++;
	vet[pai] = aux; //3
}

/*
Na heap, uma árvore é simulada. Nessa árvore, o pai tem 2 filhos, e todo pai deve ser maior que os filhos.
Então, para todo pai, verifica qual é o maior filho (1), se esse maior filho for maior que o pai (2), não pode ser uma árvore heap, então COPIA o maior filho para a posição do pai, até achar o lugar certo do valor inicial, que será quando o filho não é maior que o pai ou quando não há filhos, só então é colocado o valor inicial no lugar certo (3)
Faz isso até o fim. A estrutura de quem é filho de quem no vetor é que, dado um elemento i, seus filhos são 2*i + 1 e 2*i + 2, na verdade é por isso que só se verifica (na função heapSort) até a metade do vetor
*/