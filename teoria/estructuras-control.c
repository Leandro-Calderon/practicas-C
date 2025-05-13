// Librerías estándar comúnmente utilizadas.
// Se recomienda incluir solo las necesarias para cada ejemplo específico al
// compilarlo por separado.
#include <ctype.h>  // Para funciones de manipulación de caracteres (toupper, isdigit, etc.)
#include <float.h>  // Para límites de tipos de datos flotantes (FLT_MAX, DBL_MAX, etc.)
#include <limits.h>  // Para límites de tipos de datos enteros (INT_MAX, INT_MIN, etc.)
#include <stdbool.h>  // Para usar el tipo de dato booleano `bool` y los valores `true`/`false` (C99 en adelante)
#include <stdio.h>    // Para entrada/salida estándar (printf, scanf, etc.)
#include <stdlib.h>   // Para funciones generales (memoria, conversiones, etc.)
#include <string.h>  // Para funciones de manipulación de cadenas (strcpy, strlen, etc.)

/*
========================================================================================================================
* SECCIÓN 1: INTRODUCCIÓN A LAS ESTRUCTURAS DE CONTROL *
========================================================================================================================

Las estructuras de control son fundamentales en la programación. Permiten
alterar el flujo secuencial de ejecución de un programa, es decir, el orden en
que se ejecutan las instrucciones. Sin ellas, los programas se ejecutarían línea
por línea, de principio a fin, sin la capacidad de tomar decisiones, repetir
tareas o saltar a diferentes partes del código.

En C, las estructuras de control se pueden clasificar principalmente en tres
categorías:

1.  **Estructuras de Selección (o Condicionales):**
    Permiten que el programa elija entre diferentes caminos de ejecución basados
en el resultado de una expresión lógica (una condición).
    * `if`
    * `if-else`
    * `if-else if-else` (escalera `if-else`)
    * `switch`
    * Operador condicional ternario (`?:`)

2.  **Estructuras de Iteración (o Bucles):**
    Permiten que el programa repita un bloque de código múltiples veces mientras
se cumpla una condición o durante un número predefinido de veces.
    * `while`
    * `do-while`
    * `for`

3.  **Estructuras de Salto:**
    Permiten transferir el control del programa a un punto diferente de manera
incondicional o bajo ciertas circunstancias dentro de bucles o funciones.
    * `break`
    * `continue`
    * `goto`
    * `return` (aunque también se usa para devolver valores de funciones, actúa
como un salto fuera de la función)

Dominar estas estructuras es crucial para desarrollar algoritmos eficientes y
aplicaciones funcionales. Este archivo explorará cada una de ellas en detalle,
con su sintaxis, semántica, ejemplos prácticos y consideraciones para su uso.

------------------------------------------------------------------------------------------------------------------------
* Flujo Secuencial Básico                                               *
------------------------------------------------------------------------------------------------------------------------
Antes de sumergirnos en las estructuras de control, recordemos el flujo
secuencial. Por defecto, las instrucciones en C se ejecutan una tras otra, en el
orden en que aparecen en el código fuente.
*/

// Ejemplo de Flujo Secuencial (no requiere compilación, es ilustrativo del
// concepto)
void ejemplo_flujo_secuencial() {
  // Instrucción 1
  printf("Esta es la primera instrucción.\n");

  // Instrucción 2
  int a = 10;
  int b = 20;
  int suma = a + b;

  // Instrucción 3
  printf("La suma de %d y %d es: %d\n", a, b, suma);

  // Instrucción 4
  printf("Esta es la última instrucción en secuencia.\n");
}

/*
En el ejemplo `ejemplo_flujo_secuencial`, las llamadas a `printf` y las
operaciones de asignación y suma se ejecutan en el orden exacto en que están
escritas. Las estructuras de control nos permitirán romper esta secuencialidad
para crear programas más dinámicos e inteligentes.
*/

/*
========================================================================================================================
* SECCIÓN 2: ESTRUCTURAS DE SELECCIÓN (CONDICIONALES) *
========================================================================================================================

Estas estructuras permiten ejecutar diferentes bloques de código dependiendo de
si una condición es verdadera (`true`, generalmente cualquier valor distinto de
cero) o falsa (`false`, generalmente cero).

------------------------------------------------------------------------------------------------------------------------
* 2.1. La Sentencia `if`                                         *
------------------------------------------------------------------------------------------------------------------------
Teoría:
La sentencia `if` es la estructura de control condicional más simple. Ejecuta un
bloque de código (una única sentencia o un bloque entre llaves `{}`) solo si la
condición especificada es verdadera.

Sintaxis:
if (condicion) {
    // Bloque de código a ejecutar si la condicion es verdadera
    // Puede ser una o más sentencias
}
// El programa continúa aquí, independientemente de si la condición fue
verdadera o falsa.

Si el bloque de código consta de una sola sentencia, las llaves `{}` son
opcionales, pero se recomienda encarecidamente usarlas siempre para mejorar la
legibilidad y evitar errores, especialmente al modificar el código
posteriormente.

Condición:
La `condicion` es una expresión que se evalúa como verdadera (cualquier valor
numérico distinto de cero) o falsa (cero). Puede ser:
    - Una comparación (e.g., `a > b`, `x == 10`, `opcion != 'S'`).
    - Una variable booleana (e.g., `es_valido`).
    - Una función que devuelve un valor interpretable como verdadero/falso.
    - Combinaciones de expresiones usando operadores lógicos (`&&` - Y lógico,
`||` - O lógico, `!` - NO lógico).

Ejemplo 1: `if` simple con una sentencia (llaves opcionales, pero recomendadas)
*/
void ejemplo_if_simple() {
  printf("\n--- Ejemplo if simple ---\n");
  int edad = 20;
  if (edad >= 18) printf("Eres mayor de edad.\n");  // Esta línea se ejecuta

  edad = 15;
  if (edad >= 18) {  // Se recomienda usar llaves siempre
    printf("Esto no se imprimirá porque la edad es %d.\n", edad);
  }
  printf("Fin del ejemplo if simple.\n");
}

/*
Ejemplo 2: `if` con bloque de sentencias (llaves obligatorias)
*/
void ejemplo_if_bloque() {
  printf("\n--- Ejemplo if con bloque ---\n");
  int numero = -5;
  if (numero < 0) {
    printf("El número %d es negativo.\n", numero);
    numero = -numero;  // Convertirlo a positivo
    printf("Su valor absoluto es %d.\n", numero);
  }
  printf("Fin del ejemplo if con bloque.\n");
}

/*
Ejemplo 3: Uso de operadores lógicos en la condición del `if`
*/
void ejemplo_if_logico() {
  printf("\n--- Ejemplo if con operadores lógicos ---\n");
  int temp = 25;
  bool llueve = false;  // Necesita #include <stdbool.h>

  if (temp > 20 && temp < 30 && !llueve) {
    printf(
        "El clima es agradable: %d grados y no llueve. ¡Perfecto para un "
        "paseo!\n",
        temp);
  }

  char caracter = 'A';
  if (caracter == 'a' || caracter == 'e' || caracter == 'i' ||
      caracter == 'o' || caracter == 'u' || caracter == 'A' ||
      caracter == 'E' || caracter == 'I' || caracter == 'O' ||
      caracter == 'U') {
    printf("El caracter '%c' es una vocal.\n", caracter);
  }
  printf("Fin del ejemplo if con operadores lógicos.\n");
}

/*
Consideraciones para `if`:
-   Anidamiento: Las sentencias `if` pueden anidarse dentro de otras sentencias
`if` (o `if-else`).
-   Error común: Usar el operador de asignación `=` en lugar del operador de
comparación `==` dentro de la condición. Por ejemplo, `if (x = 5)` asignará 5 a
`x` y la condición se evaluará como verdadera (porque 5 es distinto de cero). Lo
correcto sería `if (x == 5)`.

------------------------------------------------------------------------------------------------------------------------
* 2.2. La Sentencia `if-else`                                       *
------------------------------------------------------------------------------------------------------------------------
Teoría:
La sentencia `if-else` permite ejecutar un bloque de código si la condición es
verdadera, y un bloque de código diferente si la condición es falsa. Proporciona
una bifurcación de dos caminos.

Sintaxis:
if (condicion) {
    // Bloque de código A: se ejecuta si la condicion es verdadera
} else {
    // Bloque de código B: se ejecuta si la condicion es falsa
}
// El programa continúa aquí después de ejecutar el bloque A o el bloque B.

Ejemplo 4: `if-else` básico
*/
void ejemplo_if_else_basico() {
  printf("\n--- Ejemplo if-else básico ---\n");
  int numero_ingresado;
  printf("Ingresa un número entero: ");
  scanf("%d", &numero_ingresado);

  if (numero_ingresado % 2 == 0) {
    printf("El número %d es par.\n", numero_ingresado);
  } else {
    printf("El número %d es impar.\n", numero_ingresado);
  }
  printf("Fin del ejemplo if-else básico.\n");
}

/*
Ejemplo 5: `if-else` para validar un rango
*/
void ejemplo_if_else_rango() {
  printf("\n--- Ejemplo if-else para validar rango ---\n");
  int nota = 75;
  if (nota >= 0 && nota <= 100) {
    printf("La nota %d es válida.\n", nota);
    if (nota >= 60) {
      printf("¡Aprobado!\n");
    } else {
      printf("Reprobado.\n");
    }
  } else {
    printf("La nota %d no es válida. Debe estar entre 0 y 100.\n", nota);
  }
  printf("Fin del ejemplo if-else para validar rango.\n");
}

/*
------------------------------------------------------------------------------------------------------------------------
* 2.3. La Escalera `if-else if-else` (o `else-if`) *
------------------------------------------------------------------------------------------------------------------------
Teoría:
Cuando se necesita elegir entre más de dos caminos posibles basados en múltiples
condiciones, se utiliza la estructura `if-else if-else`. El programa evalúa las
condiciones en orden. Tan pronto como una condición es verdadera, se ejecuta el
bloque de código asociado y el resto de la escalera se omite. El bloque `else`
final es opcional y se ejecuta si ninguna de las condiciones anteriores fue
verdadera.

Sintaxis:
if (condicion1) {
    // Bloque de código A: se ejecuta si condicion1 es verdadera
} else if (condicion2) {
    // Bloque de código B: se ejecuta si condicion1 es falsa Y condicion2 es
verdadera } else if (condicion3) {
    // Bloque de código C: se ejecuta si condicion1 y condicion2 son falsas Y
condicion3 es verdadera } // ...pueden haber más bloques else if else {
    // Bloque de código D (opcional): se ejecuta si TODAS las condiciones
anteriores son falsas
}
// El programa continúa aquí.

Ejemplo 6: Escalera `if-else if-else` para categorizar notas
*/
void ejemplo_escalera_if_else() {
  printf("\n--- Ejemplo escalera if-else if-else ---\n");
  int calificacion;
  printf("Ingresa la calificación (0-100): ");
  scanf("%d", &calificacion);

  if (calificacion < 0 || calificacion > 100) {
    printf("Calificación inválida.\n");
  } else if (calificacion >= 90) {
    printf("Calificación: A (Excelente)\n");
  } else if (calificacion >= 80) {
    printf("Calificación: B (Muy Bueno)\n");
  } else if (calificacion >= 70) {
    printf("Calificación: C (Bueno)\n");
  } else if (calificacion >= 60) {
    printf("Calificación: D (Suficiente)\n");
  } else {
    printf("Calificación: F (Reprobado)\n");
  }
  printf("Fin del ejemplo escalera if-else if-else.\n");
}

/*
Ejemplo 7: Menú simple usando `if-else if-else`
*/
void ejemplo_menu_if_else() {
  printf("\n--- Ejemplo menú con if-else if-else ---\n");
  char opcion;
  printf("Selecciona una opción:\n");
  printf("A - Agregar\n");
  printf("E - Editar\n");
  printf("B - Borrar\n");
  printf("S - Salir\n");
  printf("Opción: ");
  scanf(" %c",
        &opcion);  // Espacio antes de %c para consumir el newline anterior

  opcion =
      toupper(opcion);  // Convertir a mayúscula para simplificar comparación

  if (opcion == 'A') {
    printf("Has seleccionado 'Agregar'.\n");
    // Aquí iría el código para agregar
  } else if (opcion == 'E') {
    printf("Has seleccionado 'Editar'.\n");
    // Aquí iría el código para editar
  } else if (opcion == 'B') {
    printf("Has seleccionado 'Borrar'.\n");
    // Aquí iría el código para borrar
  } else if (opcion == 'S') {
    printf("Saliendo del programa...\n");
  } else {
    printf("Opción no válida.\n");
  }
  printf("Fin del ejemplo menú con if-else if-else.\n");
}

/*
Consideraciones para la escalera `if-else if-else`:
-   Orden de las condiciones: El orden es importante. Si una condición más
general se coloca antes que una más específica que también podría cumplirse, la
más específica podría no evaluarse nunca. Por ejemplo, si se verifica
`calificacion >= 60` antes de `calificacion >= 90`, un 95 se clasificaría
incorrectamente solo como "Suficiente".
-   Exclusión mutua: Solo uno de los bloques de código (o ninguno si no hay
`else` final y ninguna condición es verdadera) se ejecutará.

------------------------------------------------------------------------------------------------------------------------
* 2.4. La Sentencia `switch`                                               *
------------------------------------------------------------------------------------------------------------------------
Teoría:
La sentencia `switch` es una estructura de selección múltiple que permite
comparar el valor de una expresión (generalmente una variable entera o un
carácter) con una lista de valores constantes (casos). Cuando se encuentra una
coincidencia, se ejecutan las sentencias asociadas a ese `case`.

Es especialmente útil cuando se tienen múltiples caminos basados en el valor
exacto de una variable, lo que puede resultar más legible que una larga escalera
`if-else if-else`.

Sintaxis:
switch (expresion_control) {
    case valor_constante1:
        // Bloque de código para valor_constante1
        // ...
        break; // Importante: termina la ejecución del switch

    case valor_constante2:
        // Bloque de código para valor_constante2
        // ...
        break;

    case valor_constante3: // Múltiples cases pueden compartir el mismo bloque
    case valor_constante4:
        // Bloque de código para valor_constante3 y valor_constante4
        // ...
        break;

    default: // Opcional
        // Bloque de código si no hay coincidencia con ningún case
        // ...
        // break; // Opcional en default si es el último, pero buena práctica
incluirlo
}
// El programa continúa aquí después del switch.

Componentes Clave:
-   `expresion_control`: Debe ser una expresión que evalúe a un tipo de dato
integral (int, char, enum). No puede ser float, double o string directamente.
-   `case valor_constanteN`: `valor_constanteN` debe ser una constante literal o
una expresión constante del mismo tipo que `expresion_control`. No puede ser una
variable.
-   `break`: La sentencia `break` es crucial. Cuando se ejecuta, transfiere el
control fuera del `switch`. Si se omite un `break` (lo que se conoce como
"fall-through" o "caída"), la ejecución continuará con las sentencias del
siguiente `case` hasta que se encuentre un `break` o se termine el `switch`.
    Esto puede ser útil en casos específicos, pero a menudo es fuente de errores
si se omite por descuido.
-   `default`: El bloque `default` es opcional. Se ejecuta si el valor de
`expresion_control` no coincide con ninguno de los `case`. Si no hay `default` y
no hay coincidencias, el `switch` no hace nada.

Ejemplo 8: `switch` para días de la semana
*/
void ejemplo_switch_dias() {
  printf("\n--- Ejemplo switch días de la semana ---\n");
  int dia;
  printf("Ingresa un número de día (1=Lunes, ..., 7=Domingo): ");
  scanf("%d", &dia);

  switch (dia) {
    case 1:
      printf("Lunes\n");
      break;
    case 2:
      printf("Martes\n");
      break;
    case 3:
      printf("Miércoles\n");
      break;
    case 4:
      printf("Jueves\n");
      break;
    case 5:
      printf("Viernes\n");
      break;
    case 6:
      printf("Sábado\n");
      break;
    case 7:
      printf("Domingo\n");
      break;
    default:
      printf("Número de día inválido.\n");
      // break; // Opcional aquí, pero buena práctica
  }
  printf("Fin del ejemplo switch días.\n");
}

/*
Ejemplo 9: `switch` con caracteres y "fall-through" intencional
*/
void ejemplo_switch_vocales_consonantes() {
  printf("\n--- Ejemplo switch vocales/consonantes (con fall-through) ---\n");
  char letra;
  printf("Ingresa una letra del alfabeto: ");
  scanf(" %c", &letra);
  letra = tolower(letra);  // Convertir a minúscula para simplificar

  switch (letra) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      printf("La letra '%c' es una vocal.\n", letra);
      break;
    case 'b':
    case 'c':
    case 'd':
    case 'f':
    case 'g':
    case 'h':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      printf("La letra '%c' es una consonante.\n", letra);
      break;
    default:
      printf("El caracter '%c' no es una letra del alfabeto o es inválido.\n",
             letra);
  }
  printf("Fin del ejemplo switch vocales/consonantes.\n");
}

/*
Ejemplo 10: `switch` para un menú de calculadora simple
*/
void ejemplo_switch_calculadora() {
  printf("\n--- Ejemplo switch calculadora ---\n");
  char operacion;
  double num1, num2, resultado;

  printf("Ingresa el primer número: ");
  scanf("%lf", &num1);
  printf("Ingresa el segundo número: ");
  scanf("%lf", &num2);

  printf("Elige una operación (+, -, *, /): ");
  scanf(" %c", &operacion);

  switch (operacion) {
    case '+':
      resultado = num1 + num2;
      printf("%.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
      break;
    case '-':
      resultado = num1 - num2;
      printf("%.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
      break;
    case '*':
      resultado = num1 * num2;
      printf("%.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
      break;
    case '/':
      if (num2 != 0) {
        resultado = num1 / num2;
        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
      } else {
        printf("Error: División por cero no permitida.\n");
      }
      break;
    default:
      printf("Operación inválida '%c'.\n", operacion);
  }
  printf("Fin del ejemplo switch calculadora.\n");
}

/*
Consideraciones para `switch`:
-   Tipos de datos: Recordar que `switch` funciona con tipos integrales. Para
rangos de valores o condiciones más complejas con flotantes o cadenas, se debe
usar `if-else if-else`.
-   Claridad: Para un gran número de comparaciones de igualdad discretas,
`switch` suele ser más claro y a veces más eficiente que `if-else if-else`.
-   `break` es tu amigo (generalmente): La omisión accidental de `break` es un
error común que puede ser difícil de depurar. El "fall-through" debe usarse con
intención y, a menudo, comentarse para indicar que es deliberado.
-   No se pueden declarar variables dentro de un `case` directamente sin un
bloque. Incorrecto: `case 1: int x = 5; ... break;` Correcto: `case 1: { int x =
5; ... } break;` Esto se debe a cómo C maneja los ámbitos y las etiquetas
`case`.

------------------------------------------------------------------------------------------------------------------------
* 2.5. El Operador Condicional Ternario (`?:`) *
------------------------------------------------------------------------------------------------------------------------
Teoría:
El operador condicional ternario es una forma concisa de escribir una sentencia
`if-else` simple que asigna un valor a una variable o devuelve un valor. Se
llama "ternario" porque toma tres operandos.

Sintaxis:
condicion ? expresion_verdadera : expresion_falsa;

Cómo funciona:
1.  Se evalúa `condicion`.
2.  Si `condicion` es verdadera, se evalúa `expresion_verdadera` y su resultado
se convierte en el resultado de toda la expresión ternaria.
3.  Si `condicion` es falsa, se evalúa `expresion_falsa` y su resultado se
convierte en el resultado de toda la expresión ternaria.

`expresion_verdadera` y `expresion_falsa` deben ser del mismo tipo o de tipos
compatibles que puedan ser promovidos a un tipo común.

Ejemplo 11: Operador ternario para asignar el máximo de dos números
*/
void ejemplo_ternario_maximo() {
  printf("\n--- Ejemplo operador ternario máximo ---\n");
  int a = 10, b = 20;
  int maximo;

  // Usando if-else tradicional
  // if (a > b) {
  //     maximo = a;
  // } else {
  //     maximo = b;
  // }

  // Usando operador ternario
  maximo = (a > b) ? a : b;
  printf("El máximo entre %d y %d es %d.\n", a, b, maximo);

  int x = 100, y = 50, z = 150;
  int max_tres =
      (x > y)
          ? ((x > z) ? x : z)
          : ((y > z) ? y : z);  // Ternario anidado (puede ser menos legible)
  printf("El máximo entre %d, %d y %d es %d.\n", x, y, z, max_tres);

  printf("Fin del ejemplo operador ternario máximo.\n");
}

/*
Ejemplo 12: Operador ternario para imprimir un mensaje
*/
void ejemplo_ternario_mensaje() {
  printf("\n--- Ejemplo operador ternario mensaje ---\n");
  int edad = 17;
  char *mensaje;  // Puntero a char para cadena de texto

  mensaje = (edad >= 18) ? "Mayor de edad" : "Menor de edad";
  printf("La persona es: %s.\n", mensaje);

  // También se puede usar directamente en printf
  printf("El número %d es %s.\n", edad, (edad % 2 == 0) ? "par" : "impar");
  printf("Fin del ejemplo operador ternario mensaje.\n");
}

/*
Consideraciones para el operador ternario:
-   Legibilidad: Aunque conciso, el uso excesivo o anidado del operador ternario
puede hacer que el código sea difícil de leer y entender. Es mejor usarlo para
asignaciones o expresiones simples. Para lógica más compleja, `if-else` suele
ser más claro.
-   Efectos secundarios: Las expresiones `expresion_verdadera` y
`expresion_falsa` pueden tener efectos secundarios (como llamar a una función
que modifica una variable global). Solo se evaluará una de las dos expresiones.
-   No es un reemplazo completo de `if-else`: No se puede usar para ejecutar
bloques de múltiples sentencias de la misma manera que `if-else` con llaves. Su
propósito principal es producir un valor.
*/

/*
========================================================================================================================
* SECCIÓN 3: ESTRUCTURAS DE ITERACIÓN (BUCLES) *
========================================================================================================================

Las estructuras de iteración, o bucles, permiten ejecutar repetidamente un
bloque de código. Son esenciales para tareas como procesar colecciones de datos,
realizar cálculos repetitivos, o esperar a que ocurra un evento.

------------------------------------------------------------------------------------------------------------------------
* 3.1. El Bucle `while`                                            *
------------------------------------------------------------------------------------------------------------------------
Teoría:
El bucle `while` es un bucle de "pre-condición" o "entrada controlada". Esto
significa que la condición se evalúa *antes* de cada iteración. Si la condición
es verdadera, el cuerpo del bucle se ejecuta. Si la condición es falsa al
principio, el cuerpo del bucle no se ejecuta ni una sola vez.

Sintaxis:
while (condicion) {
    // Bloque de código a repetir mientras la condicion sea verdadera
    // Es crucial que alguna sentencia dentro del bloque (o una variable externa
    // modificada por el bloque) eventualmente haga que la condicion se vuelva
falsa,
    // de lo contrario, se creará un bucle infinito.
}
// El programa continúa aquí cuando la condicion se vuelve falsa.

Ejemplo 13: Bucle `while` para contar hasta 5
*/
void ejemplo_while_contador() {
  printf("\n--- Ejemplo while contador ---\n");
  int contador = 1;
  while (contador <= 5) {
    printf("Contador: %d\n", contador);
    contador++;  // Importante: modificar la variable de control del bucle
  }
  printf("Fin del bucle while. Contador final: %d\n",
         contador);  // contador será 6
  printf("Fin del ejemplo while contador.\n");
}

/*
Ejemplo 14: Bucle `while` para sumar números ingresados por el usuario hasta que
ingrese 0
*/
void ejemplo_while_suma_usuario() {
  printf("\n--- Ejemplo while suma hasta cero ---\n");
  int numero_ingresado;
  int suma = 0;

  printf("Ingresa números para sumar (ingresa 0 para terminar):\n");
  scanf("%d", &numero_ingresado);  // Lectura inicial antes del bucle

  while (numero_ingresado != 0) {
    suma += numero_ingresado;
    printf("Suma actual: %d. Ingresa otro número (0 para terminar): ", suma);
    scanf("%d", &numero_ingresado);  // Lectura dentro del bucle para la
                                     // siguiente iteración
  }
  printf("Suma total: %d\n", suma);
  printf("Fin del ejemplo while suma hasta cero.\n");
}

/*
Ejemplo 15: Bucle `while` para encontrar el primer divisor de un número (simple)
*/
void ejemplo_while_divisor() {
  printf("\n--- Ejemplo while encontrar divisor ---\n");
  int numero = 91;  // Por ejemplo, 7 * 13
  int divisor = 2;
  int primer_divisor_encontrado = -1;

  if (numero <= 1) {
    printf(
        "%d no tiene divisores mayores que 1 o no es un número válido para "
        "este ejemplo.\n",
        numero);
  } else {
    while (
        divisor <=
        numero /
            2) {  // Optimización: no es necesario chequear más allá de numero/2
      if (numero % divisor == 0) {
        primer_divisor_encontrado = divisor;
        break;  // Salir del bucle `while` una vez encontrado (veremos `break`
                // más adelante)
      }
      divisor++;
    }

    if (primer_divisor_encontrado != -1) {
      printf("El primer divisor de %d (aparte de 1) es %d.\n", numero,
             primer_divisor_encontrado);
    } else {
      printf("%d es un número primo.\n", numero);
    }
  }
  printf("Fin del ejemplo while encontrar divisor.\n");
}

/*
Consideraciones para `while`:
-   Bucle infinito: Si la condición nunca se vuelve falsa, el bucle se ejecutará
indefinidamente. Esto es un error común y puede hacer que el programa se
"cuelgue". Asegúrate de que la variable de control del bucle se modifique
correctamente dentro del cuerpo del bucle.
-   Inicialización: La variable de control de la condición debe estar
inicializada antes de que el bucle `while` comience.
-   Cuándo usarlo: `while` es ideal cuando el número de iteraciones no se conoce
de antemano y depende de una condición que puede cambiar durante la ejecución.

------------------------------------------------------------------------------------------------------------------------
* 3.2. El Bucle `do-while`                                           *
------------------------------------------------------------------------------------------------------------------------
Teoría:
El bucle `do-while` es un bucle de "post-condición" o "salida controlada". Esto
significa que la condición se evalúa *después* de cada iteración. Como
resultado, el cuerpo del bucle `do-while` siempre se ejecuta al menos una vez,
incluso si la condición es falsa desde el principio.

Sintaxis:
do {
    // Bloque de código a repetir
    // Al igual que con `while`, algo aquí debe eventualmente hacer que la
condicion se vuelva falsa. } while (condicion); // ¡No olvidar el punto y coma
aquí!

// El programa continúa aquí cuando la condicion se vuelve falsa.

Ejemplo 16: Bucle `do-while` para contar (similar al `while`, pero garantiza una
ejecución)
*/
void ejemplo_dowhile_contador() {
  printf("\n--- Ejemplo do-while contador ---\n");
  int contador = 1;
  do {
    printf("Contador (do-while): %d\n", contador);
    contador++;
  } while (contador <= 5);
  printf("Fin del bucle do-while. Contador final: %d\n",
         contador);  // contador será 6

  // Caso donde la condición es falsa inicialmente
  contador = 100;
  printf("Iniciando do-while con contador = 100 y condición contador <= 5\n");
  do {
    printf("Esto se ejecuta al menos una vez. Contador: %d\n", contador);
    contador++;
  } while (contador <= 5);  // La condición 100 <= 5 es falsa, pero el bloque ya
                            // se ejecutó una vez.
  printf("Contador después del segundo do-while: %d\n",
         contador);  // contador será 101

  printf("Fin del ejemplo do-while contador.\n");
}

/*
Ejemplo 17: Bucle `do-while` para un menú de opciones hasta que el usuario elija
salir Este es un uso muy común para `do-while`, ya que generalmente quieres
mostrar el menú al menos una vez.
*/
void ejemplo_dowhile_menu() {
  printf("\n--- Ejemplo do-while menú ---\n");
  char opcion;
  do {
    printf("\n** MENÚ PRINCIPAL **\n");
    printf("1. Ver Saldo\n");
    printf("2. Depositar Dinero\n");
    printf("3. Retirar Dinero\n");
    printf("4. Salir\n");
    printf("Selecciona una opción: ");
    scanf(" %c", &opcion);  // Espacio para consumir newline

    switch (opcion) {
      case '1':
        printf("Tu saldo es: $1,000.00\n");
        break;
      case '2':
        printf("Ingresa monto a depositar: ...\n");
        // Lógica de depósito
        break;
      case '3':
        printf("Ingresa monto a retirar: ...\n");
        // Lógica de retiro
        break;
      case '4':
        printf("Gracias por usar nuestros servicios. Saliendo...\n");
        break;
      default:
        printf("Opción inválida. Por favor, intenta de nuevo.\n");
    }
  } while (opcion != '4');  // Continuar mientras la opción no sea 'Salir'
  printf("Fin del ejemplo do-while menú.\n");
}

/*
Ejemplo 18: Validación de entrada con `do-while`
Asegurar que el usuario ingrese un valor dentro de un rango específico.
*/
void ejemplo_dowhile_validacion_entrada() {
  printf("\n--- Ejemplo do-while validación de entrada ---\n");
  int edad_usuario;
  do {
    printf("Por favor, ingresa tu edad (debe ser entre 1 y 120): ");
    scanf("%d", &edad_usuario);
    if (edad_usuario < 1 || edad_usuario > 120) {
      printf("Edad inválida. Inténtalo de nuevo.\n");
    }
  } while (edad_usuario < 1 ||
           edad_usuario > 120);  // Repetir si la edad es inválida

  printf("Gracias. Tu edad ingresada es: %d\n", edad_usuario);
  printf("Fin del ejemplo do-while validación de entrada.\n");
}

/*
Consideraciones para `do-while`:
-   Ejecución garantizada: Siempre se ejecuta al menos una vez. Esto lo hace
ideal para situaciones donde una acción inicial debe realizarse antes de
verificar la condición de continuación (como mostrar un menú).
-   Punto y coma: Un error común es olvidar el punto y coma (`;`) después de la
condición `while()`.
-   Bucle infinito: Similar al `while`, si la condición nunca se vuelve falsa
después de la primera ejecución, se producirá un bucle infinito.

------------------------------------------------------------------------------------------------------------------------
* 3.3. El Bucle `for`                                              *
------------------------------------------------------------------------------------------------------------------------
Teoría:
El bucle `for` es ideal cuando se conoce de antemano el número de veces que se
debe repetir un bloque de código, o cuando se necesita una inicialización y una
actualización explícita de una variable de control en cada iteración. Es un
bucle de "pre-condición".

Sintaxis:
for (inicializacion; condicion; actualizacion) {
    // Bloque de código a repetir
}
// El programa continúa aquí después de que la condicion se vuelve falsa.

Componentes del `for`:
1.  `inicializacion`: Se ejecuta una sola vez, al principio del bucle.
Típicamente se usa para declarar e inicializar una variable de control del bucle
(contador). Se pueden declarar múltiples variables separadas por comas (ej: `int
i = 0, j = 10`).
2.  `condicion`: Se evalúa *antes* de cada iteración (incluida la primera,
después de la inicialización). Si es verdadera, el cuerpo del bucle se ejecuta.
Si es falsa, el bucle termina.
3.  `actualizacion`: Se ejecuta *después* de cada iteración del cuerpo del
bucle, y justo antes de volver a evaluar la `condicion`. Típicamente se usa para
incrementar o decrementar la variable de control. Se pueden tener múltiples
expresiones de actualización separadas por comas.

Cualquiera de estas tres partes (`inicializacion`, `condicion`, `actualizacion`)
puede omitirse, pero los puntos y comas (`;`) deben permanecer.
    -   Si se omite `condicion`, se considera siempre verdadera, creando un
bucle infinito a menos que se use `break` para salir. `for (;;)` es la forma
canónica de un bucle infinito con `for`.

Ejemplo 19: Bucle `for` para contar de 0 a N e imprimir tabla de multiplicar
*/
void ejemplo_for_tabla_multiplicar() {
  printf("\n--- Ejemplo for tabla de multiplicar ---\n");
  int numero_tabla;
  printf("Ingresa un número para ver su tabla de multiplicar (del 1 al 10): ");
  scanf("%d", &numero_tabla);

  printf("Tabla de multiplicar del %d:\n", numero_tabla);
  for (int i = 1; i <= 10; i++) {  // i se declara e inicializa aquí (C99+)
    printf("%d x %d = %d\n", numero_tabla, i, numero_tabla * i);
  }
  // 'i' ya no existe fuera del bucle for si se declaró dentro de él (C99+).
  // Si 'i' se declara antes del for, su valor después del bucle sería 11.

  // Ejemplo de cuenta regresiva
  printf("\nCuenta regresiva:\n");
  for (int j = 5; j >= 0; j--) {
    printf("%d...\n", j);
    if (j == 0) printf("¡Despegue!\n");
  }
  printf("Fin del ejemplo for tabla de multiplicar.\n");
}

/*
Ejemplo 20: Bucle `for` para recorrer un array (cadena de caracteres)
*/
void ejemplo_for_recorrer_array() {
  printf("\n--- Ejemplo for recorrer array (cadena) ---\n");
  char mensaje[] = "Hola Mundo!";  // Array de caracteres (cadena)
  int longitud = strlen(mensaje);  // Necesita #include <string.h>

  printf("El mensaje es: %s\n", mensaje);
  printf("Recorriendo el mensaje caracter por caracter:\n");
  for (int i = 0; i < longitud; i++) {
    printf("Caracter en índice %d: %c\n", i, mensaje[i]);
  }

  // Otro ejemplo: Sumar elementos de un array de enteros
  int numeros[] = {10, 20, 30, 40, 50};
  int suma_array = 0;
  // sizeof(numeros) da el tamaño total en bytes del array
  // sizeof(numeros[0]) da el tamaño en bytes de un elemento
  // La división da el número de elementos.
  int cantidad_elementos = sizeof(numeros) / sizeof(numeros[0]);

  for (int i = 0; i < cantidad_elementos; i++) {
    suma_array += numeros[i];
  }
  printf("La suma de los elementos del array es: %d\n", suma_array);
  printf("Fin del ejemplo for recorrer array.\n");
}

/*
Ejemplo 21: Bucles `for` anidados para imprimir un patrón
*/
void ejemplo_for_anidado_patron() {
  printf("\n--- Ejemplo for anidado patrón (triángulo) ---\n");
  int filas;
  printf("Ingresa el número de filas para el triángulo: ");
  scanf("%d", &filas);

  for (int i = 1; i <= filas; i++) {  // Bucle externo controla las filas
    for (int j = 1; j <= i;
         j++) {  // Bucle interno controla las columnas (asteriscos por fila)
      printf("* ");
    }
    printf("\n");  // Nueva línea después de cada fila
  }
  printf("Fin del ejemplo for anidado patrón.\n");
}

/*
Ejemplo 22: Bucle `for` con múltiples inicializaciones y actualizaciones
*/
void ejemplo_for_multiple() {
  printf(
      "\n--- Ejemplo for con múltiples inicializaciones/actualizaciones ---\n");
  // Mover 'i' hacia adelante y 'j' hacia atrás hasta que se encuentren
  for (int i = 0, j = 10; i <= j; i++, j--) {
    printf("i = %d, j = %d\n", i, j);
  }
  printf(
      "Fin del ejemplo for con múltiples inicializaciones/actualizaciones.\n");
}

/*
Ejemplo 23: Bucle `for` sin alguna de sus partes o un bucle `for` infinito
*/
void ejemplo_for_variaciones() {
  printf(
      "\n--- Ejemplo for variaciones (incluyendo infinito conceptual) ---\n");
  int k = 0;
  // Bucle for sin inicialización (k ya está inicializada)
  printf("Bucle for sin inicialización explícita en la cabecera:\n");
  for (; k < 3; k++) {
    printf("k = %d\n", k);
  }

  // Bucle for sin actualización (actualización dentro del cuerpo)
  printf("\nBucle for sin actualización explícita en la cabecera:\n");
  for (int m = 0; m < 3;) {
    printf("m = %d\n", m);
    m++;  // Actualización manual
  }

  /*
  // Bucle for infinito (descomentar para probar, necesitarás Ctrl+C para parar)
  printf("\nIniciando bucle for infinito (usa Ctrl+C para detener):\n");
  int contador_infinito = 0;
  for (;;) { // Equivalente a while(1) o while(true)
      printf("Iteración infinita número: %d\n", contador_infinito++);
      if (contador_infinito > 10) { // Condición de salida artificial para no
  colgar indefinidamente printf("Saliendo del bucle infinito
  artificialmente.\n"); break; // Se necesita break para salir
      }
      // Podrías añadir un pequeño retraso si es necesario para observar la
  salida
      // #include <unistd.h> // para sleep() en sistemas POSIX
      // sleep(1); // Espera 1 segundo
  }
  */
  printf("Fin del ejemplo for variaciones.\n");
}

/*
Consideraciones para `for`:
-   Flexibilidad: Aunque comúnmente usado para contar, el bucle `for` es muy
flexible debido a que sus tres componentes pueden ser cualquier expresión
válida.
-   Ámbito de la variable de control: Si la variable de control se declara
dentro de la parte de `inicializacion` (e.g., `for (int i = 0; ...)`), su ámbito
está limitado al bucle `for` (esto es estándar en C99 y posteriores). Si se
declara antes, su ámbito es el que la rodea.
-   Claridad: Cuando el número de iteraciones es conocido o se sigue un patrón
claro de conteo, `for` suele ser la opción más clara y concisa.

Comparación rápida de Bucles:
-   `while`: Usar cuando el número de iteraciones es desconocido y depende de
una condición que se verifica al inicio. El cuerpo podría no ejecutarse nunca.
-   `do-while`: Usar cuando el número de iteraciones es desconocido, pero el
cuerpo del bucle debe ejecutarse al menos una vez. La condición se verifica al
final.
-   `for`: Usar cuando el número de iteraciones es conocido o se sigue un patrón
de inicialización, condición y actualización claro. La condición se verifica al
inicio.

Todos los bucles son, en teoría, intercambiables (un `for` puede reescribirse
como `while` y viceversa), pero se elige uno u otro por claridad y conveniencia
según el problema.
*/

/*
========================================================================================================================
* SECCIÓN 4: ESTRUCTURAS DE SALTO                                            *
========================================================================================================================

Las estructuras de salto alteran el flujo de control del programa de manera
incondicional, transfiriendo la ejecución a otra parte del código.

------------------------------------------------------------------------------------------------------------------------
* 4.1. La Sentencia `break`                                         *
------------------------------------------------------------------------------------------------------------------------
Teoría:
La sentencia `break` tiene dos usos principales en C:
1.  Dentro de un bucle (`while`, `do-while`, `for`): Termina inmediatamente la
ejecución del bucle más interno en el que se encuentra. El control pasa a la
primera sentencia después del bucle.
2.  Dentro de una sentencia `switch`: Termina la ejecución del `switch`. El
control pasa a la primera sentencia después del `switch`. (Ya se vio en la
sección de `switch`).

Sintaxis:
break;

Ejemplo 24: `break` en un bucle `for`
Buscar un elemento en un array y salir del bucle tan pronto como se encuentre.
*/
void ejemplo_break_for() {
  printf("\n--- Ejemplo break en bucle for ---\n");
  int numeros[] = {10, 25, 13, 42, 57, 33, 78};
  int cantidad = sizeof(numeros) / sizeof(numeros[0]);
  int valor_a_buscar = 42;
  bool encontrado = false;
  int indice_encontrado = -1;

  for (int i = 0; i < cantidad; i++) {
    printf("Comparando con %d...\n", numeros[i]);
    if (numeros[i] == valor_a_buscar) {
      encontrado = true;
      indice_encontrado = i;
      printf("¡Valor %d encontrado en el índice %d!\n", valor_a_buscar,
             indice_encontrado);
      break;  // Salir del bucle for, ya no es necesario seguir buscando.
    }
  }

  if (encontrado) {
    printf("El valor %d fue hallado.\n", valor_a_buscar);
  } else {
    printf("El valor %d no fue encontrado en el array.\n", valor_a_buscar);
  }
  printf("Fin del ejemplo break en bucle for.\n");
}

/*
Ejemplo 25: `break` en un bucle `while` (simulando un límite de intentos)
*/
void ejemplo_break_while() {
  printf("\n--- Ejemplo break en bucle while ---\n");
  int pin_correcto = 1234;
  int pin_ingresado;
  int intentos_restantes = 3;

  while (intentos_restantes > 0) {
    printf("Ingresa tu PIN (te quedan %d intentos): ", intentos_restantes);
    scanf("%d", &pin_ingresado);

    if (pin_ingresado == pin_correcto) {
      printf("PIN correcto. Acceso concedido.\n");
      break;  // Salir del bucle while
    } else {
      printf("PIN incorrecto.\n");
      intentos_restantes--;
    }
  }

  if (intentos_restantes == 0 && pin_ingresado != pin_correcto) {
    printf("Has agotado tus intentos. Acceso denegado.\n");
  }
  printf("Fin del ejemplo break en bucle while.\n");
}

/*
Consideraciones para `break`:
-   Solo afecta al bucle más interno: Si tienes bucles anidados, `break` solo
saldrá del bucle en el que está contenido directamente. Para salir de múltiples
niveles de bucles, se pueden usar técnicas como una variable `flag` o, con mucha
precaución, `goto`.
-   Claridad: Usar `break` para salir de un bucle por una condición especial
puede ser útil, pero abusar de él puede hacer que la lógica del bucle sea más
difícil de seguir. A veces, es mejor reestructurar la condición del bucle.

------------------------------------------------------------------------------------------------------------------------
* 4.2. La Sentencia `continue`                                        *
------------------------------------------------------------------------------------------------------------------------
Teoría:
La sentencia `continue` se usa dentro de bucles (`while`, `do-while`, `for`).
Cuando se ejecuta, omite el resto de las sentencias en la iteración actual del
cuerpo del bucle y transfiere el control directamente al inicio de la siguiente
iteración.
    - En un bucle `while` y `do-while`: Se salta directamente a la evaluación de
la `condicion`.
    - En un bucle `for`: Se salta primero a la parte de `actualizacion`, y luego
a la `condicion`.

Sintaxis:
continue;

Ejemplo 26: `continue` en un bucle `for` para imprimir solo números impares
*/
void ejemplo_continue_for_impares() {
  printf("\n--- Ejemplo continue en for (imprimir impares) ---\n");
  printf("Números impares del 1 al 10:\n");
  for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {  // Si el número es par
      continue;  // Omitir el printf y pasar a la siguiente iteración (i++)
    }
    printf("%d ", i);  // Esta línea solo se ejecuta para números impares
  }
  printf("\nFin del ejemplo continue en for.\n");
}

/*
Ejemplo 27: `continue` en un bucle `while` para procesar solo datos válidos
*/
void ejemplo_continue_while_datos_validos() {
  printf("\n--- Ejemplo continue en while (procesar datos válidos) ---\n");
  int numeros_a_procesar[] = {10, -5, 20, 0, 30, -15, 40};
  int cantidad = sizeof(numeros_a_procesar) / sizeof(numeros_a_procesar[0]);
  int i = 0;
  int suma_positivos = 0;

  printf("Procesando array: ");
  for (int k = 0; k < cantidad; ++k) printf("%d ", numeros_a_procesar[k]);
  printf("\n");

  while (i < cantidad) {
    if (numeros_a_procesar[i] <= 0) {  // Si el número no es positivo
      printf("Omitiendo %d (no positivo).\n", numeros_a_procesar[i]);
      i++;       // Incrementar el índice para la próxima iteración
      continue;  // Saltar el resto del cuerpo del bucle
    }
    printf("Procesando %d...\n", numeros_a_procesar[i]);
    suma_positivos += numeros_a_procesar[i];
    i++;
  }
  printf("Suma de números positivos: %d\n", suma_positivos);
  printf("Fin del ejemplo continue en while.\n");
}

/*
Consideraciones para `continue`:
-   Evitar complejidad: Al igual que `break`, un uso excesivo de `continue`
puede hacer que el flujo del bucle sea confuso. A veces, una estructura `if` que
englobe la lógica principal puede ser más clara que usar `continue`.
-   Actualización en `for`: Recordar que en `for`, `continue` salta a la parte
de `actualizacion`, lo cual es generalmente el comportamiento deseado para no
omitir el incremento/decremento del contador. En `while` o `do-while`, hay que
asegurarse de que la variable de control se actualice antes del `continue` si es
necesario para evitar bucles infinitos.

------------------------------------------------------------------------------------------------------------------------
* 4.3. La Sentencia `goto`                                           *
------------------------------------------------------------------------------------------------------------------------
Teoría:
La sentencia `goto` transfiere incondicionalmente el control a una sentencia
etiquetada dentro de la misma función. Una etiqueta es un identificador seguido
de dos puntos (`:`).

Sintaxis:
goto etiqueta;
// ...
// otras sentencias
// ...
etiqueta:
    // sentencias a ejecutar después del goto

Uso Controvertido:
El uso de `goto` es altamente desaconsejado en la programación estructurada
moderna. Puede llevar a código "espagueti", que es difícil de leer, entender,
depurar y mantener, ya que rompe el flujo estructurado de arriba hacia abajo y
la modularidad.

En la mayoría de los casos (si no todos), la lógica implementada con `goto`
puede reescribirse de manera más clara y estructurada utilizando `if`, `switch`,
bucles, `break`, `continue`, o dividiendo el código en funciones más pequeñas.

Posibles (raros y debatibles) casos de uso:
-   Salir de bucles profundamente anidados: Aunque a menudo se puede usar una
variable `flag`.
-   Manejo de errores centralizado al final de una función, para liberar
recursos.
-   En código generado automáticamente o en situaciones de muy bajo nivel donde
la estructura es menos prioritaria que la eficiencia extrema (aunque los
compiladores modernos son muy buenos optimizando código estructurado).

Ejemplo 28: `goto` para salir de bucles anidados (ilustrativo, no recomendado
como práctica general)
*/
void ejemplo_goto_anidado() {
  printf(
      "\n--- Ejemplo goto para salir de bucles anidados (NO RECOMENDADO) "
      "---\n");
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      printf("i=%d, j=%d\n", i, j);
      if (i == 2 && j == 2) {
        printf("Condición de salida alcanzada. Usando goto...\n");
        goto salida_bucles;  // Saltar fuera de ambos bucles
      }
    }
  }
  // Esta etiqueta no se alcanzaría si el goto no se ejecuta.
  // El compilador podría advertir sobre código inaccesible si el goto siempre
  // se ejecuta.

salida_bucles:  // Etiqueta de destino
  printf("Control transferido a la etiqueta 'salida_bucles'.\n");
  printf("Fin del ejemplo goto anidado.\n");
}

/*
Ejemplo 29: `goto` para manejo de errores (también ilustrativo, existen
alternativas)
*/
void ejemplo_goto_errores() {
  printf(
      "\n--- Ejemplo goto para manejo de errores (alternativas suelen ser "
      "mejores) ---\n");
  FILE *archivo = NULL;
  char *buffer = NULL;
  int error_status = 0;

  archivo = fopen("archivo_inexistente.txt", "r");
  if (archivo == NULL) {
    printf("Error: No se pudo abrir el archivo.\n");
    error_status = 1;
    goto cleanup;
  }

  buffer = (char *)malloc(1024 * sizeof(char));
  if (buffer == NULL) {
    printf("Error: No se pudo asignar memoria para el buffer.\n");
    error_status = 2;
    goto cleanup;
  }

  // ... (Operaciones con el archivo y el buffer) ...
  printf("Operaciones realizadas con éxito (simulado).\n");

cleanup:  // Etiqueta para limpieza
  printf("Iniciando sección de limpieza...\n");
  if (buffer != NULL) {
    free(buffer);
    printf("Buffer liberado.\n");
  }
  if (archivo != NULL) {
    fclose(archivo);
    printf("Archivo cerrado.\n");
  }

  if (error_status != 0) {
    printf("Proceso terminado con error %d.\n", error_status);
  } else {
    printf("Proceso terminado con éxito.\n");
  }
  printf("Fin del ejemplo goto para manejo de errores.\n");
}

/*
Alternativa al `goto` para manejo de errores (usando `if-else` y estructura):
*/
void ejemplo_sin_goto_errores() {
  printf("\n--- Ejemplo SIN goto para manejo de errores ---\n");
  FILE *archivo = NULL;
  char *buffer = NULL;
  int error_status = 0;

  archivo = fopen("otro_archivo_inexistente.txt", "r");
  if (archivo == NULL) {
    printf("Error: No se pudo abrir el archivo.\n");
    error_status = 1;
  } else {
    buffer = (char *)malloc(1024 * sizeof(char));
    if (buffer == NULL) {
      printf("Error: No se pudo asignar memoria para el buffer.\n");
      error_status = 2;
    } else {
      // ... (Operaciones con el archivo y el buffer) ...
      printf("Operaciones realizadas con éxito (simulado).\n");
      // La liberación del buffer iría aquí si la operación fue exitosa y ya no
      // se necesita free(buffer); buffer = NULL; // Buena práctica después de
      // free
    }
    // La clausura del archivo iría aquí si se abrió con éxito
    // fclose(archivo);
    // archivo = NULL; // Buena práctica
  }

  // Sección de limpieza unificada al final, independientemente de dónde ocurrió
  // el error
  printf("Iniciando sección de limpieza...\n");
  if (buffer != NULL) {
    free(buffer);
    printf("Buffer liberado.\n");
  }
  if (archivo != NULL) {
    fclose(archivo);
    printf("Archivo cerrado.\n");
  }

  if (error_status != 0) {
    printf("Proceso terminado con error %d.\n", error_status);
  } else {
    printf(
        "Proceso terminado con éxito (o sin errores detectados en la "
        "simulación).\n");
  }
  printf("Fin del ejemplo SIN goto para manejo de errores.\n");
}

/*
Consideraciones para `goto`:
-   Usar con extrema precaución: Si consideras usar `goto`, primero piensa si
hay una forma más estructurada y clara de lograr el mismo resultado. En el 99.9%
de los casos, la hay.
-   Ámbito: `goto` solo puede saltar a etiquetas dentro de la misma función. No
puede saltar fuera de una función o dentro de otra.
-   Inicialización de variables: Saltar sobre la declaración de una variable con
inicialización puede llevar a comportamiento indefinido si la variable se usa
después. Los compiladores modernos suelen advertir sobre esto.

------------------------------------------------------------------------------------------------------------------------
* 4.4. La Sentencia `return`                                         *
------------------------------------------------------------------------------------------------------------------------
Teoría:
La sentencia `return` tiene dos propósitos principales:
1.  Terminar la ejecución de la función actual: Cuando se encuentra `return`, la
función inmediatamente deja de ejecutarse y el control vuelve al punto donde la
función fue llamada (el "llamador").
2.  Devolver un valor (opcional): Si la función tiene un tipo de retorno
distinto de `void`, la sentencia `return` se usa para especificar el valor que
la función devuelve al llamador. El tipo del valor devuelto debe ser compatible
con el tipo de retorno declarado para la función.

Sintaxis:
Para funciones `void` (que no devuelven valor):
return; // Opcional si es la última sentencia de la función void

Para funciones que devuelven un valor:
return expresion; // expresion debe evaluar a un valor compatible con el tipo de
retorno de la función

Ejemplo 30: `return` en una función `void` para salir prematuramente
*/
void procesar_numero_void(int num) {
  printf("\n--- Ejemplo return en función void ---\n");
  printf("Procesando número: %d\n", num);
  if (num < 0) {
    printf("Número negativo. No se procesará más.\n");
    return;  // Salida temprana de la función
  }
  if (num == 0) {
    printf("Número es cero.\n");
    return;
  }
  printf("El número es positivo. Calculando su cuadrado: %d\n", num * num);
  // return; // Implícito al final de una función void
  printf("Fin de procesar_numero_void para %d.\n", num);
}

/*
Ejemplo 31: `return` en una función que devuelve un valor
*/
int encontrar_maximo(int a, int b) {
  // No hay un printf de inicio de función aquí para mantenerla enfocada en su
  // tarea
  if (a > b) {
    return a;  // Devuelve 'a' si es mayor
  } else {
    return b;  // Devuelve 'b' si es mayor o igual
  }
  // Cualquier código después de un return en todas las rutas es inaccesible.
  // printf("Esto nunca se imprimirá.\n");
}

char obtener_calificacion_letra(int puntaje) {
  if (puntaje < 0 || puntaje > 100) {
    printf("Error: Puntaje inválido %d. Devolviendo 'I' (Inválido).\n",
           puntaje);
    return 'I';  // Valor especial para indicar error
  }
  if (puntaje >= 90) return 'A';
  if (puntaje >= 80) return 'B';
  if (puntaje >= 70) return 'C';
  if (puntaje >= 60) return 'D';
  return 'F';
}

void demostracion_funciones_con_return() {
  printf("\n--- Demostración de funciones con return ---\n");
  procesar_numero_void(10);
  procesar_numero_void(-5);
  procesar_numero_void(0);

  int num1 = 25, num2 = 50;
  int max = encontrar_maximo(num1, num2);
  printf("El máximo entre %d y %d es: %d\n", num1, num2, max);

  printf("Máximo entre 100 y 100 es: %d\n", encontrar_maximo(100, 100));

  int mi_puntaje = 85;
  char mi_letra = obtener_calificacion_letra(mi_puntaje);
  printf("Con un puntaje de %d, la calificación es: %c\n", mi_puntaje,
         mi_letra);

  mi_puntaje = 55;
  mi_letra = obtener_calificacion_letra(mi_puntaje);
  printf("Con un puntaje de %d, la calificación es: %c\n", mi_puntaje,
         mi_letra);

  mi_puntaje = 105;  // Inválido
  mi_letra = obtener_calificacion_letra(mi_puntaje);
  printf("Con un puntaje de %d, la calificación es: %c\n", mi_puntaje,
         mi_letra);

  printf("Fin de la demostración de funciones con return.\n");
}

/*
Consideraciones para `return`:
-   Obligatorio en funciones no `void`: Si una función declara un tipo de
retorno (e.g., `int`, `float`, `char*`), debe tener al menos una sentencia
`return` que devuelva un valor de ese tipo en cada posible ruta de ejecución. No
hacerlo puede llevar a comportamiento indefinido (el compilador suele advertir
sobre esto: "control reaches end of non-void function").
-   Múltiples `return`: Una función puede tener múltiples sentencias `return`.
Tan pronto como una se ejecuta, la función termina. Esto es útil para salidas
tempranas basadas en condiciones.
-   `main()` es especial: La función `main` típicamente devuelve un `int`.
`return 0;` al final de `main` indica que el programa terminó exitosamente. Un
valor distinto de cero (e.g., `return 1;` o `return EXIT_FAILURE;` de
`<stdlib.h>`) indica que ocurrió un error.

========================================================================================================================
* SECCIÓN 5: MEJORES PRÁCTICAS Y CONSIDERACIONES ADICIONALES *
========================================================================================================================

1.  **Legibilidad y Mantenimiento:**
    -   Usa sangría (indentación) consistentemente para mostrar la estructura de
anidamiento de tus bloques de control. Un estilo común es usar 4 espacios por
nivel de sangría.
    -   Usa llaves `{}` consistentemente, incluso para bloques de una sola
sentencia. Esto previene errores si se añaden más sentencias al bloque después
(el "dangling else problem" es un ejemplo clásico de error evitado con llaves).
        Ejemplo de "dangling else":
        // if (cond1)
        //     if (cond2)
        //         sentenciaA;
        // else // Este else se asocia con el if(cond2) más cercano, no con
if(cond1)
        //         sentenciaB;
        // Uso correcto de llaves para asociar el else con el primer if:
        // if (cond1) {
        //    if (cond2)
        //        sentenciaA;
        // } else {
        //    sentenciaB;
        // }
    -   Escribe comentarios claros para explicar la lógica compleja o las
decisiones de diseño relacionadas con las estructuras de control.
    -   Evita anidamientos excesivamente profundos. Si tienes más de 2 o 3
niveles de anidamiento, considera refactorizar el código, quizás extrayendo
parte de la lógica a una nueva función.

2.  **Eficiencia:**
    -   Los compiladores modernos son muy buenos optimizando código.
Generalmente, prioriza la claridad y correctitud sobre micro-optimizaciones
prematuras.
    -   En condiciones de bucles, si una parte de la condición es costosa de
evaluar y su valor no cambia dentro del bucle, evalúala una vez fuera del bucle
si es posible.
    -   El orden de las condiciones en una escalera `if-else if-else` puede
afectar ligeramente el rendimiento si algunas condiciones son mucho más
probables que otras (colocar las más probables primero). Sin embargo, la
claridad suele ser más importante.

3.  **Evitar Errores Comunes:**
    -   `=` vs `==`: `if (x = 0)` asigna 0 a `x` y la condición es falsa. `if (x
== 0)` compara `x` con 0. Una técnica para ayudar a prevenir esto es escribir
las comparaciones con constantes a la izquierda: `if (0 == x)`. Si
accidentalmente escribes `if (0 = x)`, el compilador generará un error porque no
puedes asignar a un literal. Esto se conoce como "Yoda conditions".
    -   Punto y coma después de `if` o `while`:
        // if (condicion); // Error: el ; termina la sentencia if, el bloque
siguiente no es condicional
        // {
        //    // Este bloque SIEMPRE se ejecuta
        // }
        // while (condicion); // Error si se espera un cuerpo: crea un bucle
vacío que puede ser infinito
    -   Olvido de `break` en `switch`.
    -   Bucles infinitos por no actualizar la variable de control o por una
condición siempre verdadera.

4.  **Elegir la Estructura Correcta:**
    -   Para decisiones binarias simples: `if-else` o el operador ternario (si
es una asignación simple).
    -   Para múltiples condiciones excluyentes: Escalera `if-else if-else`.
    -   Para seleccionar entre muchos valores discretos de una variable
integral: `switch`.
    -   Para iterar un número desconocido de veces (condición al inicio):
`while`.
    -   Para iterar al menos una vez, luego un número desconocido de veces
(condición al final): `do-while`.
    -   Para iterar un número conocido de veces o con una estructura clara de
contador: `for`.

5.  **Combinación de Estructuras:**
    Las estructuras de control se pueden anidar y combinar de formas complejas
para modelar la lógica de cualquier algoritmo. Por ejemplo, un bucle `for` puede
contener una sentencia `switch`, que a su vez puede tener `if-else` dentro de
sus `case`.

    Ejemplo de combinación: Procesar comandos de un juego.
*/
void ejemplo_combinacion_estructuras() {
  printf("\n--- Ejemplo combinación de estructuras (juego simple) ---\n");
  char input_comando;
  bool juego_activo = true;
  int posicion_x = 0, posicion_y = 0;

  printf(
      "Juego simple de movimiento. Comandos: W (arriba), A (izquierda), S "
      "(abajo), D (derecha), Q (salir)\n");

  do {
    printf("Posición actual: (%d, %d). Ingresa comando: ", posicion_x,
           posicion_y);
    scanf(" %c", &input_comando);
    input_comando = toupper(input_comando);

    switch (input_comando) {
      case 'W':
        posicion_y++;
        printf("Movido hacia arriba.\n");
        break;
      case 'A':
        posicion_x--;
        printf("Movido hacia la izquierda.\n");
        break;
      case 'S':
        if (posicion_y > 0) {  // Ejemplo de if dentro de un case
          posicion_y--;
          printf("Movido hacia abajo.\n");
        } else {
          printf("No se puede mover más hacia abajo.\n");
        }
        break;
      case 'D':
        posicion_x++;
        printf("Movido hacia la derecha.\n");
        break;
      case 'Q':
        printf("Confirmar salida (S/N): ");
        char confirmar;
        scanf(" %c", &confirmar);
        if (toupper(confirmar) == 'S') {
          juego_activo = false;
          printf("Saliendo del juego...\n");
        } else {
          printf("Salida cancelada.\n");
        }
        break;
      default:
        printf("Comando '%c' no reconocido.\n", input_comando);
    }

    // Simular un límite del mapa
    for (int i = 0; i < 1; i++) {  // Bucle for solo para usar break/continue si
                                   // fuera necesario en lógica más compleja
      if (posicion_x > 10) {
        printf("Has llegado al límite este del mapa.\n");
        posicion_x = 10;
      } else if (posicion_x < -10) {
        printf("Has llegado al límite oeste del mapa.\n");
        posicion_x = -10;
      }
      // Similar para posicion_y si fuera necesario
    }

  } while (juego_activo);

  printf("Juego terminado. Posición final: (%d, %d)\n", posicion_x, posicion_y);
  printf("Fin del ejemplo combinación de estructuras.\n");
}

/*
========================================================================================================================
* SECCIÓN 6: EJERCICIOS Y DESAFÍOS ALGORÍTMICOS                                *
========================================================================================================================

Para solidificar tu comprensión, intenta resolver los siguientes problemas
utilizando las estructuras de control adecuadas.

1.  **Calculadora de Factorial:**
    Escribe un programa que pida al usuario un número entero no negativo y
calcule su factorial. Usa un bucle `for` o `while`. Recuerda que 0! = 1. Maneja
entradas negativas.

2.  **Serie de Fibonacci:**
    Genera los primeros N términos de la serie de Fibonacci, donde N es
ingresado por el usuario. La serie comienza con 0 y 1, y cada término
subsiguiente es la suma de los dos anteriores (0, 1, 1, 2, 3, 5, 8...).

3.  **Verificador de Números Primos:**
    Pide un número entero positivo al usuario y determina si es un número primo.
Un número primo es mayor que 1 y solo tiene dos divisores: 1 y él mismo.

4.  **Adivina el Número:**
    Genera un número aleatorio entre 1 y 100. Pide al usuario que adivine el
número. Dale pistas como "demasiado alto" o "demasiado bajo". Cuenta el número
de intentos. Usa un bucle `do-while`. (Necesitarás `#include <time.h>` y
`srand(time(NULL));` para la generación aleatoria).

5.  **Menú Bancario Mejorado:**
    Expande el ejemplo del menú bancario (`ejemplo_dowhile_menu`) para incluir
realmente las operaciones de depósito y retiro, actualizando un saldo. Asegura
que no se pueda retirar más dinero del que hay en la cuenta. Valida las
entradas.

6.  **Impresión de Patrones:**
    Pide al usuario un tamaño N y luego imprime diferentes patrones usando
bucles anidados: a.  Un cuadrado de N x N asteriscos. b.  Un triángulo
rectángulo (como en `ejemplo_for_anidado_patron`). c.  Un triángulo invertido.
    d.  Una pirámide.
    e.  Un diamante.

7.  **Procesador de Cadenas Simple:**
    Pide al usuario una cadena de texto. Luego:
    a.  Cuenta el número de vocales y consonantes.
    b.  Convierte la cadena a mayúsculas o minúsculas.
    c.  Invierte la cadena.
    Usa bucles `for` o `while` y sentencias `if` o `switch`.

Estos ejercicios te ayudarán a practicar la lógica de control y a pensar
algorítmicamente.
*/

//----------------------------------------------------------------------------------------------------------------------
// Función main principal para llamar a los ejemplos.
// Para probar un ejemplo específico, puedes descomentar su llamada o copiar el
// código del ejemplo a un nuevo archivo y compilarlo por separado.
//----------------------------------------------------------------------------------------------------------------------
int main() {
  printf(
      "======================================================================"
      "\n");
  printf("* ARCHIVO MAESTRO DE ESTRUCTURAS DE CONTROL EN C - DEMO         *\n");
  printf(
      "======================================================================"
      "\n");
  printf(
      "Descomenta las llamadas a las funciones de ejemplo en el código "
      "main()\n");
  printf(
      "para probar cada sección, o copia los fragmentos a archivos "
      "separados.\n");
  printf("Recuerda que muchos ejemplos piden entrada del usuario.\n\n");

  // --- SECCIÓN 2: ESTRUCTURAS DE SELECCIÓN ---
  // ejemplo_if_simple();
  // ejemplo_if_bloque();
  // ejemplo_if_logico();
  // ejemplo_if_else_basico(); // Requiere entrada del usuario
  // ejemplo_if_else_rango();
  // ejemplo_escalera_if_else(); // Requiere entrada del usuario
  // ejemplo_menu_if_else(); // Requiere entrada del usuario
  // ejemplo_switch_dias(); // Requiere entrada del usuario
  // ejemplo_switch_vocales_consonantes(); // Requiere entrada del usuario
  // ejemplo_switch_calculadora(); // Requiere entrada del usuario
  // ejemplo_ternario_maximo();
  // ejemplo_ternario_mensaje();

  // --- SECCIÓN 3: ESTRUCTURAS DE ITERACIÓN ---
  // ejemplo_while_contador();
  // ejemplo_while_suma_usuario(); // Requiere entrada del usuario
  // ejemplo_while_divisor();
  // ejemplo_dowhile_contador();
  // ejemplo_dowhile_menu(); // Requiere entrada del usuario
  // ejemplo_dowhile_validacion_entrada(); // Requiere entrada del usuario
  // ejemplo_for_tabla_multiplicar(); // Requiere entrada del usuario
  // ejemplo_for_recorrer_array();
  // ejemplo_for_anidado_patron(); // Requiere entrada del usuario
  // ejemplo_for_multiple();
  // ejemplo_for_variaciones(); // Contiene un bucle infinito comentado

  // --- SECCIÓN 4: ESTRUCTURAS DE SALTO ---
  // ejemplo_break_for();
  // ejemplo_break_while(); // Requiere entrada del usuario
  // ejemplo_continue_for_impares();
  // ejemplo_continue_while_datos_validos();
  // ejemplo_goto_anidado();
  // ejemplo_goto_errores();
  // ejemplo_sin_goto_errores();
  // demostracion_funciones_con_return();

  // --- SECCIÓN 5: COMBINACIÓN DE ESTRUCTURAS ---
  // ejemplo_combinacion_estructuras(); // Requiere entrada del usuario

  printf(
      "\n======================================================================"
      "\n");
  printf("* FIN DE LA DEMOSTRACIÓN PRINCIPAL                     *\n");
  printf(
      "======================================================================"
      "\n");

  return 0;  // Indica terminación exitosa del programa
}
