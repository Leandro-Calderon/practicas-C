#include <stdio.h>
#define N 10

int main() {
  int A[N] = {11, 32, 5, 78, 9, 1, 40, 22, 98, 2};
  int izq = 0, der = N - 1, temp;

  // Imprimir array original
  printf("Array original:\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  // Reorganizar: pares al principio, impares al final
  while (izq < der) {
    while (izq < der && A[izq] % 2 == 0)
      izq++;  // buscar impar desde la izquierda
    while (izq < der && A[der] % 2 != 0) der--;  // buscar par desde la derecha

    if (izq < der) {
      temp = A[izq];
      A[izq] = A[der];
      A[der] = temp;
      izq++;
      der--;
    }
  }

  // Imprimir array modificado
  printf("Array modificado (pares al inicio, impares al final):\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
