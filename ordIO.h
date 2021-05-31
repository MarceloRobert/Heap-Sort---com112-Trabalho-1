#ifndef ORDIO_H
#define ORDIO_H

void geraNumerosAleatorios(int qtNumeros, char nomeArquivo[]);
//Essa função gera qtNumeros números inteiros aleatórios e salva no arquivo nomeArquivo.

void carregaVetor(int vet[], int tam, char nomeArquivo[]);

//Essa função lê o arquivo gerado pela função geraNumerosAleatorios e carrega os números em um vetor;

void imprimeVetor(int vet[], int tam);
//Essa função imprime na tela os valores de um vetor de inteiros
//A saída deve ser em linha. Exemplo : 1 2 3 4 5

#endif //ORDIO_H