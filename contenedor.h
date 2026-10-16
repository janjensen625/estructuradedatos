
#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define MAX_CONTENEDORES 100
#define MAX_CODIGO 20
#define MAX_TIPO 50
#define MAX_BAHIA 20

typedef struct {
    char codigo[MAX_CODIGO];
    float peso;
    char tipoMercancia[MAX_TIPO];
    char bahia[MAX_BAHIA];
} Contenedor;

void leerTexto(const char *mensaje, char *destino, int capacidad);
void registrarContenedor(Contenedor *contenedor);
void mostrarContenedor(const Contenedor *contenedor);
void listarContenedores(const Contenedor *contenedores, int cantidad);

#endif
