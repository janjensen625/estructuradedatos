
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contenedor.h"
#include "ordenamiento.h"

void registrar(Contenedor ***lista, int *cantidad, int *capacidad) {
    Contenedor nuevo;
    int i;

    printf("\n===== REGISTRAR CONTENEDOR =====\n");

    printf("Codigo del contenedor: ");
    scanf("%19s", nuevo.codigo);

    for (i = 0; i < *cantidad; i++) {
        if (strcmp((*lista)[i]->codigo, nuevo.codigo) == 0) {
            printf("El codigo ya existe.\n");
            return;
        }
    }

    printf("Peso en toneladas: ");
    scanf("%f", &nuevo.peso);

    while (nuevo.peso <= 0) {
        printf("Ingrese un peso mayor que cero: ");
        scanf("%f", &nuevo.peso);
    }

    printf("Tipo de mercancia: ");
    scanf(" %49[^\n]", nuevo.mercancia);

    printf("Bahia asignada: ");
    scanf(" %19[^\n]", nuevo.bahia);

    if (agregar_contenedor(lista, cantidad, capacidad, &nuevo)) {
        printf("\nContenedor registrado correctamente.\n");
    } else {
        printf("\nError al registrar el contenedor.\n");
    }
}

void menu_ordenamiento(Contenedor **lista, int cantidad) {
    int metodo, orden;

    if (cantidad < 2) {
        printf("\nDebe registrar al menos dos contenedores.\n");
        return;
    }

    printf("\n===== METODOS DE ORDENAMIENTO =====\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Seleccione un metodo: ");
    scanf("%d", &metodo);

    printf("\n1. Menor a mayor\n");
    printf("2. Mayor a menor\n");
    printf("Seleccione el orden: ");
    scanf("%d", &orden);

    if (orden != 1 && orden != 2) {
        printf("Orden no valido.\n");
        return;
    }

    switch (metodo) {
        case 1:
            bubble_sort(lista, cantidad, orden == 1);
            printf("\nOrdenamiento Bubble Sort realizado.\n");
            break;

        case 2:
            selection_sort(lista, cantidad, orden == 1);
            printf("\nOrdenamiento Selection Sort realizado.\n");
            break;

        case 3:
            insertion_sort(lista, cantidad, orden == 1);
            printf("\nOrdenamiento Insertion Sort realizado.\n");
            break;

        default:
            printf("\nMetodo no valido.\n");
            return;
    }

    mostrar_contenedores(lista, cantidad);
}

int main() {
    Contenedor **lista = NULL;
    int cantidad = 0;
    int capacidad = 0;
    int opcion;

    // Funcion main para ejecutar los métodos de ordenamientos base #NoBorrar.

    do {
        printf("\n====================================\n");
        printf(" SISTEMA PORTUARIO DE BUENAVENTURA\n");
        printf("====================================\n");
        printf("1. Registrar contenedor\n");
        printf("2. Mostrar contenedores\n");
        printf("3. Ordenar contenedores\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrar(&lista, &cantidad, &capacidad);
                break;

            case 2:
                mostrar_contenedores(lista, cantidad);
                break;

            case 3:
                menu_ordenamiento(lista, cantidad);
                break;

            case 4:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion incorrecta.\n");
        }

    } while (opcion != 4);

    liberar_contenedores(&lista, &cantidad, &capacidad);

    printf("Memoria liberada correctamente.\n");

    return 0;
}

