#include <stdio.h>

int main() {
  int numero = 123, invertido = 0;
  while (numero > 0) {
    invertido += numero % 10;
    invertido = invertido * 10;
    numero = numero / 10;
  }
  printf("%d", invertido);
  return 0;
}
