
#include "ordenamiento.h"

void bubble_sort(Contenedor **lista, int cantidad, int ascendente) {
    int i, j;
    Contenedor *auxiliar;

    for (i = 0; i < cantidad - 1; i++) {
        for (j = 0; j < cantidad - i - 1; j++) {

            if ((ascendente && lista[j]->peso > lista[j + 1]->peso) ||
                (!ascendente && lista[j]->peso < lista[j + 1]->peso)) {

                auxiliar = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = auxiliar;
            }
        }
    }
}

void selection_sort(Contenedor **lista, int cantidad, int ascendente) {
    int i, j, posicion;
    Contenedor *auxiliar;

    for (i = 0; i < cantidad - 1; i++) {
        posicion = i;

        for (j = i + 1; j < cantidad; j++) {

            if ((ascendente && lista[j]->peso < lista[posicion]->peso) ||
                (!ascendente && lista[j]->peso > lista[posicion]->peso)) {

                posicion = j;
            }
        }

        if (posicion != i) {
            auxiliar = lista[i];
            lista[i] = lista[posicion];
            lista[posicion] = auxiliar;
        }
    }
}

void insertion_sort(Contenedor **lista, int cantidad, int ascendente) {
    int i, j;
    Contenedor *actual;

    for (i = 1; i < cantidad; i++) {
        actual = lista[i];
        j = i - 1;

        while (j >= 0 &&
              ((ascendente && lista[j]->peso > actual->peso) ||
               (!ascendente && lista[j]->peso < actual->peso))) {

            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = actual;
    }
}
