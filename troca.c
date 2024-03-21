#include <stdio.h>

// a operação dereferenciação (*x) retorna o valor que o ponteiro armazena
// a operação referenciação (&x) retorna o endereço de memória do ponteiro

void troca (int *x, int *y) { 
  int aux; 
  aux = *x;   // aux recebe o valor de x (*x)
  *x = *y;    // o valor de x (*x) recebe o valor de y (*y)
  *y = aux;   // o valor de y (&y) recebe o valor de aux
}

int main (int argc, char **argv) { 
  int a = 10;
  int b = 20;
  troca (&a, &b);
  printf("Valor de a: %d \n", a);
  printf("Valor de b: %d \n", b);
  return(0);
}