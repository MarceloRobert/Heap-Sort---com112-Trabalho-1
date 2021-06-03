#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordIO.h"
#include "heap.h"
#include "sorts.h"

/*
double tempo;
tempo = clock();
tempo = (clock()-tempo)/(CLOCKS_PER_SEC);
*/
/*
FALTA:
-colocar as outras ordenações
-marcar as trocas e comparações do heap
organizar os arquivos de resultado
pedir se quer o teste com números aleatórios ou com números ordenados ou decrescentes
*/

int main(void) {
  char nome[100] = "arq.txt";
	int quantidade, i, vezes;
	/*printf("Dê o nome do arquivo:\n");
	scanf("%s", nome);
	printf("Dê a quantidade:\n");
	scanf("%d", &quantidade);*/
	printf("c");
	scanf("%d", &vezes);

	double tempo;
	int elemento;
	int *vetor;

	//inicialização dos dados
	float is[13], me[13], qu[13], he[13];
	for(i=0; i<4; i++){
		is[i] = 0;
		me[i] = 0;
		qu[i] = 0;
		he[i] = 0;
	}
	for(i=8; i<13; i++){
		is[i] = 0;
		me[i] = 0;
		qu[i] = 0;
		he[i] = 0;
	}
	is[4] = is[5] = -1;
	me[4] = me[5] = -1;
	qu[4] = qu[5] = -1;
	he[4] = he[5] = -1;
	is[6] = is[7] = 1000000000;
	me[6] = me[7] = 1000000000;
	qu[6] = qu[7] = 1000000000;
	he[6] = he[7] = 1000000000;
	/*
		0 - atual comparação
		1 - atual troca
		2 - média comparação
		3 - média troca
		4 - maior comparação
		5 - maior troca
		6 - menor comparação
		7 - menor troca
		8 - total comparação
		9 - total troca
		10 - total tempo
		11 - atual tempo
		12 - média tempo
	*/

	//métricas para as buscas
	float buscaS[2], buscaB[2];
	buscaS[0] = buscaS[1] = 0;
	buscaB[0] = buscaB[1] = 0;
	/*
		0 - total e atual tempo
		1 - média tempo
	*/

	//definição de uma variável de arquivo para escrever e automatizar os resultados
	FILE *arquivo;
	//resetando os arquivos
	arquivo = fopen("Resultados_Sequencial.txt", "w");
	fclose(arquivo);
	arquivo = fopen("Resultados_Binaria.txt", "w");
	fclose(arquivo);

	printf("b");

	int j, k, l, qtdTestes;//novas variáveis para fazer laço
	for(j=0; j<2; j++){ //testes variando o tamanho do vetor, de 100 à 1 milhão
		if(j==0){
			quantidade = 100;
		} else {
			if(j==1){
				quantidade = 10000;
			} else {
				quantidade = (j-1)*100000;
			}
		}
		//quantidade = 100; //apenas para testes
		
		//inicialização do vetor
		vetor = (int*) malloc(quantidade*sizeof(int));
		geraNumerosAleatorios(quantidade, nome);
		carregaVetor(vetor, quantidade, nome);
		
		arquivo = fopen("Resultados_Sequencial.txt", "a");
		fprintf(arquivo, "-----Vetor de tamanho %d-----\n", quantidade);
		fclose(arquivo);

		for(k=0; k<4; k++){ //quatro testes sequenciais
			switch(k){
				case 0:
					qtdTestes=1; //1 elemento
					break;
				case 1:
					qtdTestes = quantidade/10; //10%
					break;
				case 2:
					qtdTestes = (quantidade*3)/10; //30%
					break;
				case 3:
					qtdTestes = quantidade/2; //50%
					break;
				default:
					qtdTestes = 0;
					break;
			}

			buscaS[0] = 0;
			for(l=0; l<qtdTestes; l++){ //faz as buscas
				printf("\n%d", l);
				//system("sleep 1"); //precisa esperar 1 segundo para que os valores aleatórios gerados não sejam iguais
				elemento = rand()%quantidade; //gera o elemento a ser buscado

				//busca sequencial
				tempo = clock();
				buscaSeq(vetor, quantidade, elemento);
				tempo = (clock()-tempo)/(CLOCKS_PER_SEC);
				buscaS[0] += tempo;
			}

			buscaS[1] = buscaS[0]/qtdTestes; //faz a média

			//coloca no arquivo de resultado
			arquivo = fopen("Resultados_Sequencial.txt", "a");
			fprintf(arquivo, "\n");
			fprintf(arquivo, "\nTeste %d\nTotal: %f\nMédia: %f", (k+1), buscaS[0], buscaS[1]);
			fclose(arquivo);
		}

		printf("a");

		/*for(i=0; i<vezes; i++){ //30 vezes para números aleatórios
			geraNumerosAleatorios(quantidade, nome);
			carregaVetor(vetor, quantidade, nome);			

			//heap sort
			he[0] = he[1] = he[11] = 0;
			tempo = clock();	
			heapSort(vetor, quantidade, he);
			tempo = (clock()-tempo)/(CLOCKS_PER_SEC);
			he[11] = tempo;
			he[8] += he[0];
			he[9] += he[1];
			he[10] += he[11];

			//quick sort
			carregaVetor(vetor, quantidade, nome);
			qu[0] = qu[1] = qu[11] = 0;
			tempo = clock();	
			quickSort(vetor, 0, quantidade-1, qu);
			tempo = (clock()-tempo)/(CLOCKS_PER_SEC);
			qu[11] = tempo;
			qu[8] += qu[0];
			qu[9] += qu[1];
			qu[10] += qu[11];

			//merge sort
			carregaVetor(vetor, quantidade, nome);
			me[0] = me[1] = me[11] = 0;
			tempo = clock();	
			mergeSort(vetor, 0, quantidade-1, me);
			tempo = (clock()-tempo)/(CLOCKS_PER_SEC);
			me[11] = tempo;
			me[8] += me[0];
			me[9] += me[1];
			me[10] += me[11];

			//insertion sort
			carregaVetor(vetor, quantidade, nome);
			is[0] = is[1] = is[11] = 0;
			tempo = clock();
			insercao(vetor, quantidade, is);
			tempo = (clock()-tempo)/(CLOCKS_PER_SEC);
			is[11] = tempo;
			is[8] += is[0];
			is[9] += is[1];
			is[10] += is[11];

			//verificação do maior, menor, troca, comparação, merge, insertion, quick, heap
				if(me[0] > me[4])
					me[4] = me[0];
				if(me[0] < me[6])
					me[6] = me[0];
				if(me[1] > me[5])
					me[5] = me[1];
				if(me[1] < me[7])
					me[7] = me[1];

				if(is[0] > is[4])
					is[4] = is[0];
				if(is[0] < is[6])
					is[6] = is[0];
				if(is[1] > is[5])
					is[5] = is[1];
				if(is[1] < is[7])
					is[7] = is[1];

				if(qu[0] > qu[4])
					qu[4] = qu[0];
				if(qu[0] < qu[6])
					qu[6] = qu[0];
				if(qu[1] > qu[5])
					qu[5] = qu[1];
				if(qu[1] < qu[7])
					qu[7] = qu[1];

				if(he[0] > he[4])
					he[4] = he[0];
				if(he[0] < he[6])
					he[6] = he[0];
				if(he[1] > he[5])
					he[5] = he[1];
				if(he[1] < he[7])
					he[7] = he[1];
			//

			system("sleep 1"); //precisa esperar 1 segundo para que os valores aleatórios gerados não sejam iguais

		} //fim ordenação*/

		heapSort(vetor, quantidade, he);

		//após ordenar o vetor, fazer os testes com busca binária
		arquivo = fopen("Resultados_Binaria.txt", "a");
		fprintf(arquivo, "-----Vetor de tamanho %d-----\n", quantidade);
		fclose(arquivo);
		
		for(k=0; k<4; k++){ //quatro testes binários
			switch(k){
				case 0:
					qtdTestes=1; //1 elemento
					break;
				case 1:
					qtdTestes = quantidade/10; //10%
					break;
				case 2:
					qtdTestes = (quantidade*3)/10; //30%
					break;
				case 3:
					qtdTestes = quantidade/2; //50%
					break;
				default:
					qtdTestes = 0;
					break;
			}

			buscaB[0] = 0;
			for(l=0; l<qtdTestes; l++){ //faz as buscas
				printf("\n-%d", l);
				//system("sleep 1"); //precisa esperar 1 segundo para que os valores aleatórios gerados não sejam iguais
				elemento = rand()%quantidade; //gera o elemento a ser buscado

				//busca sequencial
				tempo = clock();
				buscaBin(vetor, quantidade, elemento);
				tempo = (clock()-tempo)/(CLOCKS_PER_SEC);
				buscaB[0] += tempo;
			}

			buscaB[1] = buscaB[0]/qtdTestes; //faz a média

			//coloca no arquivo de resultado
			arquivo = fopen("Resultados_Binaria.txt", "a");
			fprintf(arquivo, "\n");
			fprintf(arquivo, "\nTeste %d\nTotal: %f\nMédia: %f", (k+1), buscaB[0], buscaB[1]);
			fclose(arquivo);
		} //fim testes binários

		getchar();
		getchar();
	


		/*printf("\nImprimir no arquivo ordenado e decrescente? (1, 0)\n");
		scanf("%d", &j);
		if(j){
			FILE *ordenado = fopen("ord.txt", "w");
			FILE *decrescente = fopen("dec.txt", "w");
			for(i=0; i<quantidade; i++){
				fprintf(ordenado, "%d ", vetor[i]);
				fprintf(decrescente, "%d ", vetor[(quantidade-1)-i]);
			}
			fclose(ordenado);
			fclose(decrescente);
		}*/

		//fazendo a média
		me[2] = me[8]/vezes;
		me[3] = me[9]/vezes;
		me[12] = me[10]/vezes;
		is[2] = is[8]/vezes;
		is[3] = is[9]/vezes;
		is[12] = is[10]/vezes;
		qu[2] = qu[8]/vezes;
		qu[3] = qu[9]/vezes;
		qu[12] = qu[10]/vezes;
		he[2] = he[8]/vezes;
		he[3] = he[9]/vezes;
		he[12] = he[10]/vezes;

		//FALTA ARRUMAR AQUI PARA QUE OS RESULTADOS SEJAM COLOCADOS EM UM ARQUIVO

		printf("\nTotal de comparações:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[8], me[8], is[8], qu[8]);
		printf("\nTotal de trocas:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[9], me[9], is[9], qu[9]);
		printf("\nMédia de comparações:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[2], me[2], is[2], qu[2]);
		printf("\nMédia de trocas:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[3], me[3], is[3], qu[3]);
		printf("\nMaior comparação:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[4], me[4], is[4], qu[4]);
		printf("\nMaior troca:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[5], me[5], is[5], qu[5]);
		printf("\nMenor comparação:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[6], me[6], is[6], qu[6]);
		printf("\nMenor troca:");
		printf("\nHeap: %.0f\nMerge: %.0f\nInserção: %.0f\nQuick: %.0f\n", he[7], me[7], is[7], qu[7]);
		printf("\nTotal de tempo (em segundos):");
		printf("\nHeap: %f\nMerge: %f\nInserção: %f\nQuick: %f\n", he[10], me[10], is[10], qu[10]);
		printf("\nMédia de tempo (em segundos):");
		printf("\nHeap: %f\nMerge: %f\nInserção: %f\nQuick: %f\n", he[12], me[12], is[12], qu[12]);

	} //fim todos os testes


  return 0;
}