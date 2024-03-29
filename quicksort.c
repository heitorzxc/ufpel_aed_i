#include <stdio.h>
#include "quicksort.h"

// Função que faz o swap entre duas variáveis:
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Particiona o array e retorna o índice do pivô:
int particionar(int array[], int inicio, int fim) {
    int pivo = array[fim]; // Escolhendo o último elemento como pivô
    int i = inicio - 1; // Índice do menor elemento

    for (int j = inicio; j < fim; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (array[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(&array[i], &array[j]); // Troca array[i] e array[j]
        }
    }
    trocar(&array[i + 1], &array[fim]); // Coloca o pivô na posição correta
    return (i + 1); // Retorna o índice do pivô
}

// Função principal do QuickSort:
void quicksort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        // Obtém o índice do pivô:
        int pi = particionar(array, inicio, fim);

        // Ordena os elementos antes e depois do pivô:
        quicksort(array, inicio, pi - 1);
        quicksort(array, pi + 1, fim);
    }
}

// Função para imprimir um array:
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", array[i]);
    printf("\n");
}