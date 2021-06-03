#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

void quickSort(int vet[], int inicio, int fim, float qt[]){
	int posPivo;
	qt[0]++;
	if(inicio < fim){
		posPivo = particiona(vet, inicio, fim, qt);
		quickSort(vet, inicio, (posPivo-1), qt);
		quickSort(vet, (posPivo+1), fim, qt);
	}

	return;
}

int particiona(int vet[], int inicio, int fim, float qt[]){
	//não será usado a variável pivô, vai ser usado o vet[inicio] mesmo
	int pos = inicio;
	int aux, i=inicio+1;
	for(i=i; i<=fim; i++){
		qt[0]++;
		if(vet[i] < vet[inicio]){
			pos++;
			qt[0]++;
			if(i != pos){
				qt[1]++;
				aux = vet[i];
				vet[i] = vet[pos];
				vet[pos] = aux;
			}
		}
	}
	qt[1]++;
	aux = vet[inicio];
	vet[inicio] = vet[pos];
	vet[pos] = aux;

	
		

	return pos;
}

void mergeSort(int vet[], int inicio, int fim, float qt[]){
	int meio;
	if(inicio < fim){
		meio = (inicio+fim)/2;
		mergeSort(vet, inicio, meio, qt);
		mergeSort(vet, meio+1, fim, qt);
		merge(vet, inicio, meio, fim, qt);
	}
	
	return;
}

void merge(int vet[], int inicio, int meio, int fim, float qt[]){
	int m1 = inicio;
	int m2 = meio+1;
	int aux[(fim-inicio)+1];
	int i=0, k;

	for(i=0; m1<=meio && m2<=fim; i++){
		qt[0]++;
		if(vet[m1] <= vet[m2]){
			qt[1]++;
			aux[i] = vet[m1];
			m1++;
		} else {
			qt[1]++;
			aux[i] = vet[m2];
			m2++;
		}
	}
	//qt[0]++;
	if(m1 == meio+1){
		for(i=i; m2<=fim; i++, m2++){
			qt[1]++;
			aux[i] = vet[m2];
		}
	} else {
		for(i=i; m1<=meio; i++, m1++){
			qt[1]++;
			aux[i] = vet[m1];
		}
	}

	for(i=0, k=inicio; k<=fim; i++, k++){
		vet[k] = aux[i];
	}	

}

//função de ordenação insertion
void insercao(int vet[], int tam, float qt[]){
	int marcador, pos, aux, atual;

	for(marcador=1; marcador<tam; marcador++){

		atual = vet[marcador];
		//troca do while por for, continua igual
		qt[0]++;
		for(pos=marcador; atual < vet[pos-1] && pos >= 0; pos--){
			qt[0]++;
			qt[1]++;
			vet[pos] = vet[pos-1];
		}
		vet[pos] = atual;
	}
}