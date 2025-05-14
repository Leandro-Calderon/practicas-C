/* Dado un array de 10 floats positivos, mostrar por pantalla cuales elementos
 * superan al promedio.
 */
#include <stdio.h>
#define N 10

int main() {
  float A[N], suma = 0, promedio = 0;
  int i;
  for (i = 0; i < N; i++) {
    do {
      printf("Ingrese flotantes positivos\n");
      printf("Carga %d de:", N);
      scanf("%f", &A[i]);
    } while (A[i] <= 0);
    suma += A[i];
  }
  promedio = suma / N;
  printf("El promedio es %.2f", promedio);

  for (i = 0; i < N; i++) {
    if (A[i] > promedio) {
      printf("%.2f \n", A[i]);
    }
  }

  return 0;
}