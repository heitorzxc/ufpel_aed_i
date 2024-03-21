#include <stdio.h>
#include <stdlib.h>

// Tarefa: Implementar o método de troca
void troca(int *v, int *i) {
  int aux = *v;
  *v = *i;
  *i = aux;
}

void bubbleSort(int *v, int n) {
  if (n <= 1) return;
  for (int i = 0; i < n-1; ++i)
    if (v[i] > v[i+1])
      troca(&v[i], &v[i+1]);
  bubbleSort(v, n-1);
}

int main(int argc, char **argv) {

  int vetor[10];

  // Preenchendo com aleatórios de 0 a 100
  for (int i = 0; i < 10; ++i)
    vetor[i] = rand() % 100;

  printf("Vetor original: \n");
  for (int i = 0; i < 10; ++i)
    printf("%d ", vetor[i]);
  printf("\n");

  // Ordenando...
  bubbleSort(vetor, 10);

  printf("Vetor ordenado: \n");
  for (int i = 0; i < 10; ++i)
    printf("%d ", vetor[i]);
  printf("\n");

  return(0);
}
