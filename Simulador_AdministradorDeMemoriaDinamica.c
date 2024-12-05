#include <stdio.h>
#include <stdlib.h>

typedef struct Particion {
    int id;
    int tamaño;
    int ocupado;
    struct Particion* siguiente;
} Particion;

Particion* crearParticion(int tamaño) {
    Particion* nueva = (Particion*)malloc(sizeof(Particion));
    nueva->id = 0;
    nueva->tamaño = tamaño;
    nueva->ocupado = 0;
    nueva->siguiente = NULL;
    return nueva;
}

void mostrarEstado(Particion* cabeza) {
    printf("\nEstado de la memoria:\n");
    printf("===================================\n");
    Particion* actual = cabeza;
    int contador = 1;
    while (actual != NULL) {
        printf("Partición %d: Tamaño = %d, %s\n",
               contador,
               actual->tamaño,
               actual->ocupado ? "Ocupado" : "Libre");
        actual = actual->siguiente;
        contador++;
    }
    printf("===================================\n");
}

void asignarProceso(Particion* cabeza, int idProceso, int tamañoProceso) {
    Particion* actual = cabeza;
    while (actual != NULL) {
        if (!actual->ocupado && actual->tamaño >= tamañoProceso) {
            actual->ocupado = 1;
            actual->id = idProceso;

            if (actual->tamaño > tamañoProceso) {
                Particion* nuevaParticion = crearParticion(actual->tamaño - tamañoProceso);
                nuevaParticion->siguiente = actual->siguiente;
                actual->siguiente = nuevaParticion;
                actual->tamaño = tamañoProceso;
            }

            printf("Proceso %d asignado a una partición de tamaño %d.\n", idProceso, tamañoProceso);
            return;
        }
        actual = actual->siguiente;
    }
    printf("No hay particiones disponibles para el proceso %d.\n", idProceso);
}

void liberarParticion(Particion* cabeza, int idProceso) {
    Particion* actual = cabeza;
    while (actual != NULL) {
        if (actual->id == idProceso && actual->ocupado) {
            actual->ocupado = 0;
            actual->id = 0;
            printf("Partición liberada del proceso %d.\n", idProceso);
            if (actual->siguiente != NULL && !actual->siguiente->ocupado) {
                Particion* temp = actual->siguiente;
                actual->tamaño += temp->tamaño;
                actual->siguiente = temp->siguiente;
                free(temp);
            }
            return;
        }
        actual = actual->siguiente;
    }
    printf("No se encontró el proceso %d en ninguna partición.\n", idProceso);
}

int main() {
    int tamañoMemoria;
    printf("Ingrese el tamaño total de la memoria: ");
    scanf("%d", &tamañoMemoria);

    Particion* memoria = crearParticion(tamañoMemoria);

    int opcion;
    do {
        printf("\nMenú:\n");
        printf("1. Asignar un proceso a una partición\n");
        printf("2. Liberar una partición\n");
        printf("3. Mostrar estado de la memoria\n");
        printf("4. Salir\n");
        printf("Seleccione una opción porfavor: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int idProceso, tamañoProceso;
                printf("Ingrese el ID del proceso: ");
                scanf("%d", &idProceso);
                printf("Ingrese el tamaño del proceso: ");
                scanf("%d", &tamañoProceso);
                asignarProceso(memoria, idProceso, tamañoProceso);
                break;
            }
            case 2: {
                int idProceso;
                printf("Ingrese el ID del proceso a liberar: ");
                scanf("%d", &idProceso);
                liberarParticion(memoria, idProceso);
                break;
            }
            case 3:
                mostrarEstado(memoria);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    Particion* actual = memoria;
    while (actual != NULL) {
        Particion* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    return 0;
}
