
#include <stdio.h>
#include <stdlib.h>
#include "contenedor.h"
#include "ordenamiento.h"

/* Funcion main para ejecutar los métodos de ordenamientos base #CP. */
/* Funcion main para ejecutar los métodos de ordenamientos base #NoBorrar. */

static int leerEntero(const char *mensaje, int minimo, int maximo) {
    char entrada[64];

    while (1) {
        char *fin;

        printf("%s", mensaje);

        if (fgets(entrada, sizeof entrada, stdin) == NULL) {
            return minimo;
        }

        long valor = strtol(entrada, &fin, 10);

        while (*fin == ' ' || *fin == '\t' || *fin == '\n') {
            fin++;
        }

        if (fin != entrada && *fin == '\0' &&
            valor >= minimo && valor <= maximo) {
            return (int)valor;
        }

        printf("Opcion no valida. Intente nuevamente.\n");
    }
}

int main(void) {
    Contenedor contenedores[MAX_CONTENEDORES];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n=== SISTEMA DE GESTION PORTUARIA - BUENAVENTURA ===\n");
        printf("1. Registrar contenedor\n");
        printf("2. Listar contenedores\n");
        printf("3. Ordenar por peso (menor a mayor)\n");
        printf("4. Ordenar por peso (mayor a menor)\n");
        printf("5. Salir\n");

        opcion = leerEntero("Seleccione una opcion: ", 1, 5);

        switch (opcion) {
            case 1:
                if (cantidad >= MAX_CONTENEDORES) {
                    printf("Se alcanzo la capacidad maxima.\n");
                } else {
                    registrarContenedor(&contenedores[cantidad]);
                    cantidad++;
                    printf("Contenedor registrado correctamente.\n");
                }
                break;

            case 2:
                listarContenedores(contenedores, cantidad);
                break;

            case 3:
            case 4:
                if (cantidad < 2) {
                    printf("Registre al menos dos contenedores para ordenar.\n");
                    break;
                }

                printf("\nMetodos de ordenamiento:\n");
                printf("1. Bubble Sort (burbuja)\n");
                printf("2. Selection Sort (seleccion)\n");
                printf("3. Insertion Sort (insercion)\n");

                {
                    int metodo = leerEntero("Seleccione el metodo: ", 1, 3);
                    int ascendente = (opcion == 3);

                    if (metodo == 1) {
                        ordenarBurbuja(contenedores, cantidad, ascendente);
                    } else if (metodo == 2) {
                        ordenarSeleccion(contenedores, cantidad, ascendente);
                    } else {
                        ordenarInsercion(contenedores, cantidad, ascendente);
                    }

                    printf("\nContenedores despues del ordenamiento:\n");
                    listarContenedores(contenedores, cantidad);
                }
                break;

            case 5:
                printf("Programa finalizado. Buen trabajo.\n");
                break;
        }

    } while (opcion != 5);

    return 0;
}
