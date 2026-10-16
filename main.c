#include <stdio.h>
#include <string.h>
#include "contenedor.h"
#include "patio.h"

int main() {
    Patio patio;
    inicializarPatio(&patio);
    int opcion;

    do {
        printf("\n=== TERMINAL MARITIMO - PUERTO DE BUENAVENTURA ===\n");
        printf("1. Ingresar Contenedor\n");
        printf("2. Retirar Contenedor (Ultimo ingresado - LIFO)\n");
        printf("3. Consultar Contenedores en el Patio\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                if (patioEstaLleno(&patio)) {
                    printf("\n[AVISO] El patio de despacho rápido está lleno (Max 5 contenedores). Debe retirar uno antes de ingresar otro.\n");
                } else {
                    Contenedor nuevo;
                    printf("Ingrese codigo (exactamente 4 caracteres): ");
                    scanf("%s", nuevo.codigo);
                    
                    if (strlen(nuevo.codigo) != 4) {
                        printf("\n[ERROR] El codigo debe ser de exactamente 4 caracteres alfanumericos.\n");
                        break;
                    }

                    printf("Ingrese peso en toneladas: ");
                    scanf("%f", &nuevo.peso);

                    printf("Ingrese tipo de mercancia: ");
                    scanf(" %[^\n]", nuevo.tipo); // Lee cadenas con espacios

                    if (ingresarContenedor(&patio, nuevo)) {
                        printf("\n[EXITO] Contenedor registrado correctamente en el patio.\n");
                    } else {
                        printf("\n[ERROR] No se pudo ingresar el contenedor.\n");
                    }
                }
                break;
            }
            case 2: {
                Contenedor retirado;
                if (retirarContenedor(&patio, &retirado)) {
                    printf("\n[RETIRADO] Se despacho el contenedor:\n");
                    mostrarContenedor(retirado);
                } else {
                    printf("\n[ERROR] El patio se encuentra vacío, no hay contenedores para retirar.\n");
                }
                break;
            }
            case 3:
                consultarPatio(&patio);
                break;
            case 4:
                printf("\nSaliendo del sistema de gestion del puerto...\n");
                break;
            default:
                printf("\n[ERROR] Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}