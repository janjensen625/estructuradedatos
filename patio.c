#include <stdio.h>
#include <string.h>
#include "patio.h"

void inicializarPatio(Patio *p) {
    p->tope = -1;
}

int patioEstaLleno(Patio *p) {
    return p->tope >= CAPACIDAD_PATIO - 1;
}

int patioEstaVacio(Patio *p) {
    return p->tope == -1;
}

int ingresarContenedor(Patio *p, Contenedor c) {
    if (patioEstaLleno(p)) {
        return 0; // Patio lleno (bloqueo)
    }
    p->tope++;
    p->contenedores[p->tope] = c;
    return 1; // Éxito
}

int retirarContenedor(Patio *p, Contenedor *cRetirado) {
    if (patioEstaVacio(p)) {
        return 0; // Patio vacío
    }
    *cRetirado = p->contenedores[p->tope];
    p->tope--;
    return 1; // Éxito
}

void consultarPatio(Patio *p) {
    if (patioEstaVacio(p)) {
        printf("\nEl patio de almacenamiento está vacío.\n");
        return;
    }
    printf("\n--- ESTADO ACTUAL DEL PATIO DE CONTENEDORES ---\n");
    for (int i = p->tope; i >= 0; i--) {
        printf("Posicion %d -> ", i + 1);
        mostrarContenedor(p->contenedores[i]);
    }
    printf("-----------------------------------------------\n");
}