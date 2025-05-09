#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 20

int main()
{
  int dados[N] = {0};
  int sumas[6] = {0}; // Para contar cuántas veces salió cada número del 1 al 6

  srand(getpid()); // Semilla para números aleatorios
  
  // Tirar el dado N veces
  for (int i = 0; i < N; i++)
  {
    dados[i] = (rand() % 6) + 1; // Guardar el valor del dado (1 a 6)
    sumas[dados[i] - 1]++;       // Incrementar el contador correspondiente
  }

  // Mostrar los valores obtenidos
  printf("Tiradas:\n");
  for (int i = 0; i < N; i++)
  {
    printf("%d ", dados[i]);
  }

  // Mostrar cuántas veces salió cada número
  printf("\n\nFrecuencias:\n");
  for (int i = 0; i < 6; i++)
  {
    printf("Número %d: %d veces\n", i + 1, sumas[i]);
  }

  return 0;
}
