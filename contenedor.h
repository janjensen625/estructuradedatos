#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define MAX_CODIGO 5

// Estructura que define un contenedor
typedef struct {
    char codigo[MAX_CODIGO]; // Alfanumérico de 4 caracteres + terminador '\0'
    float peso;              // Peso en toneladas
    char tipo[30];           // Tipo de mercancía
} Contenedor;

// Prototipos de funciones del contenedor
void mostrarContenedor(Contenedor c);

#endif