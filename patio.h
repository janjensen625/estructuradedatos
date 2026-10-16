#ifndef PATIO_H
#define PATIO_H

#include "contenedor.h"

#define CAPACIDAD_PATIO 5

// Estructura del Patio manejado como Pila (LIFO)
typedef struct {
    Contenedor contenedores[CAPACIDAD_PATIO];
    int tope; // Índice del último elemento (-1 si está vacío)
} Patio;

// Prototipos de funciones del patio
void inicializarPatio(Patio *p);
int patioEstaLleno(Patio *p);
int patioEstaVacio(Patio *p);
int ingresarContenedor(Patio *p, Contenedor c);
int retirarContenedor(Patio *p, Contenedor *cRetirado);
void consultarPatio(Patio *p);

#endif