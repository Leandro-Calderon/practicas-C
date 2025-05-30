#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 10

void cargarandom(int[]);
void muestra(int[]);
void anulapares(int[]);

int main() {
  int A[N];
  cargarandom(A);
  muestra(A);
  anulapares(A);
  muestra(A);
  return 0;
}

void anulapares(int V[]) {
  int i;
  for (i = 0; i < N; i++) {
    if (V[i] % 2 == 0) {
      V[i] = 0;
    }
  }
}

void muestra(int W[]) {
  int i;
  for (i = 0; i < N; i++) {
    printf("%2d\t", W[i]);
  }
  printf("\n");
}

void cargarandom(int V[]) {
  int i;
  srand(getpid());
  for (i = 0; i < N; i++) {
    V[i] = rand() % 101;
  }
}
