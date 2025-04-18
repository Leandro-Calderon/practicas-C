#include <stdio.h>

int main() {
    int cantidad_alumnos;

    // Solicitar la cantidad de alumnos
    printf("¿Cuántos alumnos hay? ");
    if (scanf("%d", &cantidad_alumnos) != 1) {
        fprintf(stderr, "Error al leer la cantidad de alumnos.\n");
        return 1; // Indicar error
    }

    // Validar que la cantidad de alumnos sea no negativa
    if (cantidad_alumnos < 0) {
        fprintf(stderr, "La cantidad de alumnos no puede ser negativa.\n");
        return 1; // Indicar error
    }

    // Mostrar el resultado
    printf("Ok, hay %d alumnos.\n", cantidad_alumnos);

    return 0; // Éxito
}