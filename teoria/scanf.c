#include <stdio.h>

int main() {
  int entero;
  float flotante;
  char letra;
  char nombre[50];

  // --- SCANF: Entrada de datos con modificadores ---
  printf("Ingresá un número entero: ");
  scanf("%d", &entero);  // %d para enteros

  printf("Ingresá un número con decimales: ");
  scanf("%f", &flotante);  // %f para float

  printf("Ingresá una letra: ");
  scanf(" %c", &letra);  // espacio antes de %c evita capturar un salto de línea

  printf("Ingresá tu nombre: ");
  scanf("%s", nombre);  // %s para strings sin espacios

  // --- PRINTF: Salida de datos con formato ---
  printf("\n--- Salida formateada ---\n");

  // %d: entero
  printf("Entero: %d\n", entero);

  // %05d: entero rellenado con ceros a la izquierda (5 dígitos)
  printf("Entero con ceros: %05d\n", entero);

  // %f: número flotante
  printf("Flotante: %f\n", flotante);

  // %.2f: flotante con 2 decimales
  printf("Flotante con 2 decimales: %.2f\n", flotante);

  // %10.2f: flotante con 2 decimales, ancho mínimo de 10 caracteres
  printf("Flotante alineado a la derecha: %10.2f\n", flotante);

  // %-10.2f: igual pero alineado a la izquierda
  printf("Flotante alineado a la izquierda: %-10.2f<--\n", flotante);

  // %c: carácter
  printf("Letra: %c\n", letra);

  // %s: cadena
  printf("Nombre: %s\n", nombre);

  // %.3s: solo los primeros 3 caracteres de la cadena
  printf("Nombre truncado a 3 letras: %.3s\n", nombre);

  return 0;
}
