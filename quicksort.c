//================================================================
// Nome Do Arquivo: quicksort.c
//
// Descrição:
// Implementação do algoritmo quicksort
// Análise de Projeto de Algoritmos
// Universidade Federal do Pará
//================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define MAX 10 // Tamanho do Vetor
 
// Protótipo da função de ordenação
void quick_sort(int *vetor, int esquerda, int direita);
 
// Função main
int main(int argc, char** argv)
{
 int MAX = 0; //Define o tamanho do vetor
 printf("Tamanho do vetor: ");
 scanf("%d", &MAX);

 int i, vet[MAX];
 srand(time(NULL)); //Inicializa a função randômica
 
 // Lê MAX e insere os 100 valores randomicamente
 for(i = 0; i < MAX; i++){
  //printf("Digite um valor: ");
  int vet_entrada = rand()%10000;
  vet[i] = vet_entrada;
 }
 
 printf("\nVetor de Entrada: ");
 for(i = 0; i < MAX; i++){
  printf("%d ", vet[i]);
 }
 printf("\n\n");
 
 // Ordena os valores
 clock_t t; //inicia contagem do tempo
 t = clock();
 quick_sort(vet, 0, MAX - 1);
 t = clock() - t; //finaliza contagem do tempo
 
 // Imprime os valores ordenados
 printf("Vetor Ordenado: ");
 for(i = 0; i < MAX; i++){
  printf("%d ", vet[i]);
 }
 printf("\n\n");
 printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
 printf("\n\n");
 return 0;
}
 
// Função de Ordenação do QuickSort
void quick_sort(int *vetor, int esquerda, int direita) {

    int i, j, pivo, aux;
     
    i = esquerda;
    j = direita;
    pivo = vetor[(esquerda + direita) / 2]; //Elemento central como pivô
     
    while(i <= j) {
        while(vetor[i] < pivo && i < direita) {
            i++;
        }
        while(vetor[j] > pivo && j > esquerda) {
            j--;
        }
        if(i <= j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        quick_sort(vetor, esquerda, j);
    }
    if(i < direita) {
        quick_sort(vetor, i, direita);
    }
}