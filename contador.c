#include <stdio.h>

// Función para obtener un número entero positivo del usuario
int obtener_limite() {
  int limite;
  do {
    printf("Ingresa un número entero positivo: ");
    scanf("%d", &limite);
  } while (limite <= 0);
  return limite;
}

// Función para imprimir números impares desde 1 hasta el límite
void imprimir_impares(int limite) {
  printf("Números impares desde 1 hasta %d:\n", limite);
  for (int i = 1; i <= limite; i++) {
    if (i % 2 != 0) {
      printf("%d\n", i);
    }
  }
}

// Función para contar hacia atrás desde el límite hasta 1
void contar_atras(int limite) {
  printf("Contando hacia atrás desde %d hasta 1:\n", limite);
  for (int i = limite; i >= 1; i--) {
    printf("%d\n", i);
  }
}

// Función para imprimir números desde 1 hasta el límite
void imprimir_numeros(int limite) {
  printf("Números desde 1 hasta %d:\n", limite);
  for (int i = 1; i <= limite; i++) {
    printf("%d\n", i);
  }
}

// Función para calcular la suma de números desde 1 hasta el límite
int calcular_suma(int limite) {
  int suma = 0;
  for (int i = 1; i <= limite; i++) {
    suma += i;
  }
  return suma;
}

int main() {
  int limite = obtener_limite();

  imprimir_impares(limite);
  contar_atras(limite);
  imprimir_numeros(limite);

  printf("La suma de los números desde 1 hasta %d es: %d\n", limite,
         calcular_suma(limite));

  return 0;
}
