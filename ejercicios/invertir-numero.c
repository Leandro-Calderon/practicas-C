#include <stdio.h>

int main() {
  int numero = 123782, invertido = 0;
  while (numero > 10) {
    invertido += numero % 10;
    invertido = invertido * 10;
    numero = numero / 10;
  }
  printf("%d\n", invertido + numero % 10);
  return 0;
}
