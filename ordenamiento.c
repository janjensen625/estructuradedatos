
#include "ordenamiento.h"

static int debeIntercambiar(float a, float b, int ascendente) {
    return ascendente ? (a > b) : (a < b);
}

static void intercambiar(Contenedor *a, Contenedor *b) {
    Contenedor temporal = *a;
    *a = *b;
    *b = temporal;
}

void ordenarBurbuja(Contenedor *contenedores, int cantidad, int ascendente) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - 1 - i; j++) {
            if (debeIntercambiar(contenedores[j].peso,
                                 contenedores[j + 1].peso, ascendente)) {
                intercambiar(&contenedores[j], &contenedores[j + 1]);
            }
        }
    }
}

void ordenarSeleccion(Contenedor *contenedores, int cantidad, int ascendente) {
    for (int i = 0; i < cantidad - 1; i++) {
        int indice = i;

        for (int j = i + 1; j < cantidad; j++) {
            if (ascendente
                ? contenedores[j].peso < contenedores[indice].peso
                : contenedores[j].peso > contenedores[indice].peso) {
                indice = j;
            }
        }

        if (indice != i) {
            intercambiar(&contenedores[i], &contenedores[indice]);
        }
    }
}

void ordenarInsercion(Contenedor *contenedores, int cantidad, int ascendente) {
    for (int i = 1; i < cantidad; i++) {
        Contenedor actual = contenedores[i];
        int j = i - 1;

        while (j >= 0 &&
               (ascendente ? contenedores[j].peso > actual.peso
                           : contenedores[j].peso < actual.peso)) {
            contenedores[j + 1] = contenedores[j];
            j--;
        }

        contenedores[j + 1] = actual;
    }
}
