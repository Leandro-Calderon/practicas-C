#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 20
// busqueda lineal o secuencial, si el elemento esta?, cuantas veces?, en que
// posicion esta?

int main() {
  int A[N], i, elemento, veces = 0;
  srand(getpid());
  for (i = 0; i < N; i++) {
    A[i] = (rand() % 1000) + 1;
  }
  for (i = 0; i < N; i++) {
    printf("el array tiene el numero: %d\n", A[i]);
  }

  do {
    printf("Ingrese un entero entre [1,2000]: ");
    scanf("%d", &elemento);

  } while (elemento < i || elemento > 2000);

  for (i = 0; i < N; i++) {
    if (elemento == A[i]) {
      veces++;
      printf("%d aparece en la posicion: %d\n", elemento, i);
    }
  }
  if (veces == 0) {
    printf("%d no pertenece!\n", elemento);
  } else {
    printf("%d aparece %d veces \n", elemento, veces);
  }

  return 0;
}