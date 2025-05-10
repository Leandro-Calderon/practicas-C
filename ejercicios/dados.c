#include <stdio.h>
#include <stdlib.h> //srand & rand
#include <unistd.h> //getpid
#define N 1500

int main() {
    int dados[N] = {0};
    int sumas[6] = {0}; // sumas[0] 1s    sumas[1] 2s..... sumas[5] 6s
    int i, j;
    int max, min;
    srand(getpid());

    for (i = 0; i < N; i++) {
        dados[i] = (rand() % 6) + 1; // es es un numero entre 1...6

        sumas[dados[i] - 1]++; // a++   a=a+1
        //  }

        // for(i=0; i<N; i++) {
        printf("%d ", dados[i]);
    }

    max = sumas[0]; // sumas[0] guarda cantida de 1s
    min = N + 1;

    for (i = 0; i < 6; i++) {
        printf("\nAparecio %d veces el numero %d \n", sumas[i], i + 1);
        for (j = 0; j < sumas[i]; j++) {
            printf("*");
        }
        if (sumas[i] > max)
            max = sumas[i];
        if (sumas[i] < min)
            min = sumas[i];
    }

    printf("\nLa cantidad maxima de apariciones es %d\n", max);
    printf("Y los numeros con esa cantidad de apariciones son..");
    for (i = 0; i < 6; i++) {
        if (sumas[i] == max)
            printf("%d ", i + 1);
    }
    printf("\nLa cantidad minima de apariciones es %d\n", min);
    printf("Y los numeros con esa cantidad de apariciones son..");
    for (i = 0; i < 6; i++) {
        if (sumas[i] == min)
            printf("%d ", i + 1);
    }

    return 0;
}