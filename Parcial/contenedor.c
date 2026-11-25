
#include <stdio.h>
#include <stdlib.h>
#include "contenedor.h"

int agregar_contenedor(Contenedor ***lista, int *cantidad, int *capacidad, const Contenedor *nuevo) {
    Contenedor *copia;

    if (*cantidad == *capacidad) {
        int nueva_capacidad = (*capacidad == 0) ? 2 : (*capacidad * 2);

        Contenedor **temporal = realloc(*lista, nueva_capacidad * sizeof(Contenedor *));

        if (temporal == NULL) {
            return 0;
        }

        *lista = temporal;
        *capacidad = nueva_capacidad;
    }

    copia = malloc(sizeof(Contenedor));

    if (copia == NULL) {
        return 0;
    }

    *copia = *nuevo;
    (*lista)[*cantidad] = copia;
    (*cantidad)++;

    return 1;
}

void mostrar_contenedores(Contenedor **lista, int cantidad) {
    int i;

    if (cantidad == 0) {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\n========== MANIFIESTO PORTUARIO ==========\n");
    printf("%-15s %-15s %-25s %-15s\n",
           "CODIGO", "PESO (TON)", "MERCANCIA", "BAHIA");

    for (i = 0; i < cantidad; i++) {
        printf("%-15s %-15.2f %-25s %-15s\n",
               lista[i]->codigo,
               lista[i]->peso,
               lista[i]->mercancia,
               lista[i]->bahia);
    }

    printf("\nTotal de contenedores: %d\n", cantidad);
}

void liberar_contenedores(Contenedor ***lista, int *cantidad, int *capacidad) {
    int i;

    for (i = 0; i < *cantidad; i++) {
        free((*lista)[i]);
    }

    free(*lista);

    *lista = NULL;
    *cantidad = 0;
    *capacidad = 0;
}
