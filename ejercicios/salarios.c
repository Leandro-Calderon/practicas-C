// 3. Hacer un programa que ayude a una empresa a incrementar los
// salarios de los trabajadores de la siguiente manera:
// Tipo de salario Incremento Salarial
// [ % ]
// De 0 hasta $9000 20%
// De $9000 hasta $15000 10%
// De $15000 hasta $20000 5%
// Mas de $20000 3%

#include <stdio.h>

int main() {
  float salario, nuevo_salario;

  printf("Ingrese el salario para saber el aumento correspondiente: ");
  scanf("%f", &salario);

  if (salario <= 0) {
    printf("Error: El salario debe ser un número positivo mayor que cero.\n");
    return 1;
  }

  if (salario > 20000) {
    nuevo_salario = salario * 1.03;
    printf("Se aplica un aumento del 3%%.\n");
  } else if (salario >= 15000) {
    nuevo_salario = salario * 1.05;
    printf("Se aplica un aumento del 5%%.\n");
  } else if (salario >= 9000) {
    nuevo_salario = salario * 1.10;
    printf("Se aplica un aumento del 10%%.\n");
  } else {
    nuevo_salario = salario * 1.20;
    printf("Se aplica un aumento del 20%%.\n");
  }

  printf("El salario con aumento es de: %.2f\n", nuevo_salario);

  return 0;
}
