#ifndef ORDIO_H
#define ORDIO_H

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]);
//Essa função gera qtNumeros números inteiros aleatórios e salva no arquivo nomeArquivo.

void carregaVetor(int vet[], int tam, char nomeArquivo[]);
//Essa função lê o arquivo gerado pela função geraNumerosAleatorios e carrega os números em um vetor;

void imprimeVetor(int vet[], int tam);
//Essa função imprime na tela os valores de um vetor de inteiros
//A saída deve ser em linha. Exemplo : 1 2 3 4 5

int buscaSeq(int vet[], int tam, int elemento);
//Essa função busca sequencialmente um elemento entre 0 e tam dentro do vetor, se encontrar retorna 1, se não retorna 0

int buscaBin(int vet[], int tam, int elemento);
//Essa função busca de forma binária um elemento entre 0 e tam dentro do vetor, se encontrar retorna 1, se não retorna 0

#endif //ORDIO_H