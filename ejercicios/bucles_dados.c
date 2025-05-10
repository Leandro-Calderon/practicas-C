#include <stdio.h>
#include <stdlib.h>  // srand()   seed semilla       rand()
#include <unistd.h>
#define N 1000
// emular el lanzamiento de un dado 10 veces
//  al final contar cuantas veces salio 6

int main() {
  int i;
  int puntos_dado;
  int cuantos6 = 0;

  srand(getpid());

  for (i = 1; i <= N; i++) {
    // printf("\nLance el dado!: ");
    // scanf("%d", &puntos_dado);
    puntos_dado = (rand() % 6) + 1;
    printf("%d ", puntos_dado);

    if (puntos_dado == 6) {
      cuantos6++;
    }
  }

  printf("\nHan salido %d veces el numero 6\n", cuantos6);

  return 0;
}