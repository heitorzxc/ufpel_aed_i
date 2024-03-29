#include <stdio.h>

// Função que faz o swap entre duas variáveis:
void trocar(int* a, int* b);

// Particiona o array e retorna o índice do pivô:
int particionar(int array[], int inicio, int fim);

// Função principal do QuickSort:
void quicksort(int array[], int inicio, int fim);

// Função para imprimir um array:
void imprimirArray(int array[], int tamanho);