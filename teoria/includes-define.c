// 🧾 Cheatsheet completo del lenguaje C
#include <ctype.h>    // Clasificación de caracteres
#include <float.h>    // Límites de flotantes
#include <limits.h>   // Límites de tipos enteros
#include <math.h>     // Funciones matemáticas
#include <stdbool.h>  // Tipo booleano
#include <stdio.h>    // Entrada/salida estándar
#include <stdlib.h>   // Utilidades (malloc, atoi, rand, etc.)
#include <string.h>   // Manejo de cadenas
#include <time.h>     // Tiempo y fechas

// 🔧 Constantes y macros
#define PI 3.14159
#define MAX 100
#define CUADRADO(x) ((x) * (x))

// 👨‍🔧 Función propia
void saludar(const char* nombre) { printf("Hola, %s\n", nombre); }

// 🧮 Función matemática
float calcular_area_circulo(float radio) { return PI * CUADRADO(radio); }

// 🧠 Función que recibe punteros
void intercambiar(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 🧱 Estructura
struct Persona {
  char nombre[50];
  int edad;
  float altura;
};

// 🚀 Función principal
int main() {
  // 🔠 Tipos de datos
  int entero = 42;
  float decimal = 3.14;
  double grande = 1.23456789;
  char letra = 'A';
  bool activo = true;

  // 🖨️ Formato con printf
  printf("Entero: %d\n", entero);      // %d: entero
  printf("Decimal: %.2f\n", decimal);  // %f: flotante con 2 decimales
  printf("Double: %.8lf\n", grande);   // %lf: double
  printf("Letra: %c\n", letra);        // %c: carácter
  printf("Booleano: %s\n", activo ? "true" : "false");

  // 🧾 Constantes
  printf("PI: %.5f\n", PI);
  printf("Área de círculo (radio=2): %.2f\n", calcular_area_circulo(2.0));

  // 📚 Cadenas de caracteres
  char saludo[20] = "Hola";
  char nombre[20] = "Mundo";
  strcat(saludo, " ");
  strcat(saludo, nombre);
  printf("Saludo completo: %s\n", saludo);

  // 📐 Arreglos
  int numeros[] = {5, 3, 8, 1, 2};
  int tam = sizeof(numeros) / sizeof(numeros[0]);
  printf("Primer número: %d\n", numeros[0]);

  // 🔁 Bucles
  printf("Números:\n");
  for (int i = 0; i < tam; i++) {
    printf(" - %d\n", numeros[i]);
  }

  // 🧠 Punteros
  int x = 10, y = 20;
  printf("Antes: x=%d, y=%d\n", x, y);
  intercambiar(&x, &y);
  printf("Después: x=%d, y=%d\n", x, y);

  // 🧱 Uso de estructuras
  struct Persona p1;
  strcpy(p1.nombre, "Juan");
  p1.edad = 30;
  p1.altura = 1.75;
  printf("Persona: %s, %d años, %.2fm\n", p1.nombre, p1.edad, p1.altura);

  // 🧠 Memoria dinámica
  int* arreglo = (int*)malloc(MAX * sizeof(int));
  if (arreglo == NULL) {
    printf("Error de memoria.\n");
    return 1;
  }
  arreglo[0] = 123;
  printf("Arreglo dinámico: %d\n", arreglo[0]);
  free(arreglo);  // Liberar memoria

  // 🕒 Tiempo
  time_t ahora = time(NULL);
  printf("Fecha actual: %s", ctime(&ahora));

  // 🧾 Archivos
  FILE* archivo = fopen("datos.txt", "w");
  if (archivo != NULL) {
    fprintf(archivo, "Este es un archivo de prueba.\n");
    fclose(archivo);
  } else {
    printf("No se pudo abrir el archivo.\n");
  }

  // 🔤 Caracteres
  char c = 'g';
  if (isalpha(c)) printf("%c es una letra\n", c);
  if (isdigit(c)) printf("%c es un número\n", c);

  // 🔺 Límites
  printf("INT_MAX: %d\n", INT_MAX);
  printf("FLT_MIN: %e\n", FLT_MIN);

  // ✅ Fin
  return 0;
}
