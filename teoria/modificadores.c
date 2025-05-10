#include <stdio.h>

int main() {
  int entero = 42;
  float flotante = 3.14159;
  double doble = 2.718281828;
  char caracter = 'A';
  char cadena[] = "Hola, mundo";

  // %d: entero con signo
  printf("Entero: %d\n", entero);  // salida: 42

  // %f: número flotante (float o double)
  printf("Flotante (float): %.2f\n", flotante);  // salida: 3.14

  // %lf: número flotante de doble precisión
  printf("Doble precisión (double): %.5lf\n", doble);  // salida: 2.71828

  // %c: carácter
  printf("Carácter: %c\n", caracter);  // salida: A

  // %s: cadena de caracteres (string)
  printf("Cadena: %s\n", cadena);  // salida: Hola, mundo

  // %x: número en hexadecimal (minúscula)
  printf("Hexadecimal: %x\n", entero);  // salida: 2a

  // %X: número en hexadecimal (mayúscula)
  printf("Hexadecimal (mayúscula): %X\n", entero);  // salida: 2A

  // %o: octal
  printf("Octal: %o\n", entero);  // salida: 52

  // %u: entero sin signo
  printf("Entero sin signo: %u\n",
         (unsigned int)-1);  // salida: 4294967295 (depende del sistema)

  // %p: dirección de puntero
  printf("Dirección de cadena: %p\n", (void *)cadena);  // salida: 0x...

  // %-10s: alinear a la izquierda en un campo de 10 caracteres
  printf("Cadena alineada: %-10s<--\n", "texto");

  // %10s: alinear a la derecha en un campo de 10 caracteres
  printf("Cadena derecha: %10s<--\n", "texto");

  return 0;
}
