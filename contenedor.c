
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contenedor.h"

void leerTexto(const char *mensaje, char *destino, int capacidad) {
    int c;
    printf("%s", mensaje);

    if (fgets(destino, capacidad, stdin) != NULL) {
        size_t longitud = strlen(destino);

        if (longitud > 0 && destino[longitud - 1] == '\n') {
            destino[longitud - 1] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    } else {
        destino[0] = '\0';
    }
}

void registrarContenedor(Contenedor *contenedor) {
    char entrada[64];

    leerTexto("Codigo unico: ", contenedor->codigo, MAX_CODIGO);
    leerTexto("Tipo de mercancia: ", contenedor->tipoMercancia, MAX_TIPO);
    leerTexto("Bahia asignada: ", contenedor->bahia, MAX_BAHIA);

    while (1) {
        leerTexto("Peso en toneladas: ", entrada, sizeof entrada);

        char *fin;
        float peso = strtof(entrada, &fin);

        if (fin != entrada && *fin == '\0' && peso >= 0.0f) {
            contenedor->peso = peso;
            break;
        }

        printf("Peso no valido. Intente nuevamente.\n");
    }
}

void mostrarContenedor(const Contenedor *contenedor) {
    printf("%-12s | %10.2f | %-22s | %-12s\n",
           contenedor->codigo,
           contenedor->peso,
           contenedor->tipoMercancia,
           contenedor->bahia);
}

void listarContenedores(const Contenedor *contenedores, int cantidad) {
    if (cantidad == 0) {
        printf("No hay contenedores registrados.\n");
        return;
    }

    printf("\n%-12s | %10s | %-22s | %-12s\n",
           "CODIGO", "PESO (t)", "MERCANCIA", "BAHIA");

    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        mostrarContenedor(&contenedores[i]);
    }
}