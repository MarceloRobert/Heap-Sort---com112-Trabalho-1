#ifndef INC_5_QUICKSORT_QUICKSORT_H
#define INC_5_QUICKSORT_QUICKSORT_H

void quickSort(int vet[], int inicio, int fim, float qt[]);
//Função quickSort que divide recursivamente o vetor e chama a função particiona.

int particiona(int vet[], int inicio, int fim, float qt[]);
//Função que encontra a posição correta do pivô no vetor e retorna essa posição.

void mergeSort(int vet[], int inicio, int fim, float qt[]);
//Função mergesort que divide recursivamente o vetor e chama a função merge.

void merge(int vet[], int inicio, int meio, int fim, float qt[]);
//Função que une vetores previamente ordenados em um vetor auxiliar.
//Ao final copia o vetor auxiliar para o vetor original

void insercao(int vet[], int tam, float qt[]);
//Essa função recebe o vetor que foi carregado pela função carregaVetor e o ordena
// usando o algoritmo insercao.

#endif //INC_5_QUICKSORT_QUICKSORT_H