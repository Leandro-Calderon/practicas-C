// 2. Hacer un programa calculador que reciba una operación de la forma A
// (op) B.
// Donde A es el primer operando, B es el segundo operando y op es el
// operador ( + - / * %).
// Ej: 7*11.


#include <stdio.h>


int main() {
  float primer_numero;
  float segundo_numero;
  char operador;

  printf("Ingresa el primer número:\n");
  scanf("%f", &primer_numero);

  printf("Ingresa el segundo número:\n");
  scanf("%f", &segundo_numero);

  printf("Ingresa el operador (+, -, *, /):\n");
  scanf(" %c", &operador);  // Espacio para evitar leer el '\n'

  switch (operador) {
    case '+':
      printf("Resultado: %.2f\n", primer_numero + segundo_numero);
      break;
    case '-':
      printf("Resultado: %.2f\n", primer_numero - segundo_numero);
      break;
    case '*':
      printf("Resultado: %.2f\n", primer_numero * segundo_numero);
      break;
    case '/':
      if (segundo_numero != 0)
        printf("Resultado: %.2f\n", primer_numero / segundo_numero);
      else
        printf("Error: división por cero.\n");
      break;
    default:
      printf("Operador no válido.\n");
      break;
  }

  return 0;
}
