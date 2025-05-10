/* 1. Hacer un programa que devuelva el nombre del día de la semana, a
partir del numero de día. (La semana comienza el Domingo ---
1:Domingo, 2:Lunes, … 7:sábado)

*/

#include <stdio.h>

int main() {
  int dia;
  printf("Ingrese un número del 1 al 7: ");
  scanf("%d", &dia);
  switch (dia) {
    case 1:
      printf("Domingo\n");
      break;
    case 2:
      printf("Lunes\n");
      break;
    case 3:
      printf("Martes\n");
      break;
    case 4:
      printf("Miércoles\n");
      break;
    case 5:
      printf("Jueves\n");
      break;
    case 6:
      printf("Viernes\n");
      break;
    case 7:
      printf("Sábado\n");
      break;
    default:
      printf("Error: número no válido. Ingrese un número del 1 al 7.\n");
      break;
  }

  return 0;
}
