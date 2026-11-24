
#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define MAX_CODIGO 20
#define MAX_MERCANCIA 50
#define MAX_BAHIA 20

typedef struct {
    char codigo[MAX_CODIGO];
    float peso;
    char mercancia[MAX_MERCANCIA];
    char bahia[MAX_BAHIA];
} Contenedor;

int agregar_contenedor(Contenedor ***lista, int *cantidad, int *capacidad, const Contenedor *nuevo);

void mostrar_contenedores(Contenedor **lista, int cantidad);

void liberar_contenedores(Contenedor ***lista, int *cantidad, int *capacidad);

#endif


