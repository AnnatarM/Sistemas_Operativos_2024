#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTICIONES 100

typedef struct {
    int id_particion;
    int tamano;
    int ocupado; // 0: libre, 1: ocupado
    int id_proceso; // ID del proceso asignado (si ocupado)
} Particion;

void mostrarEstado(Particion particiones[], int num_particiones) {
    printf("\nEstado de la memoria:\n");
    printf("Partición\tTamaño\tEstado\t\tProceso\n");
    for (int i = 0; i < num_particiones; i++) {
        printf("%d\t\t%d\t%s\t\t%s\n", particiones[i].id_particion, particiones[i].tamano,
               particiones[i].ocupado ? "Ocupado" : "Libre",
               particiones[i].ocupado ? "Proceso " : "Ninguno");
    }
}

void asignarProceso(Particion particiones[], int num_particiones, int id_proceso, int tamano_proceso) {
    for (int i = 0; i < num_particiones; i++) {
        if (!particiones[i].ocupado && particiones[i].tamano >= tamano_proceso) {
            particiones[i].ocupado = 1;
            particiones[i].id_proceso = id_proceso;
            printf("Proceso %d asignado a la partición %d.\n", id_proceso, particiones[i].id_particion);
            return;
        }
    }
    printf("No se encontró una partición disponible para el proceso %d.\n", id_proceso);
}

void liberarProceso(Particion particiones[], int num_particiones, int id_proceso) {
    for (int i = 0; i < num_particiones; i++) {
        if (particiones[i].ocupado && particiones[i].id_proceso == id_proceso) {
            particiones[i].ocupado = 0;
            particiones[i].id_proceso = -1;
            printf("Proceso %d liberado de la partición %d.\n", id_proceso, particiones[i].id_particion);
            return;
        }
    }
    printf("No se encontró el proceso %d en la memoria.\n", id_proceso);
}

int main() {
    Particion particiones[MAX_PARTICIONES];
    int num_particiones, tamano_memoria;

    printf("Ingrese el tamaño total de la memoria: ");
    scanf("%d", &tamano_memoria);
    printf("Ingrese el número de particiones: ");
    scanf("%d", &num_particiones);

    int tamano_particion = tamano_memoria / num_particiones;
    for (int i = 0; i < num_particiones; i++) {
        particiones[i].id_particion = i + 1;
        particiones[i].tamano = tamano_particion;
        particiones[i].ocupado = 0;
        particiones[i].id_proceso = -1;
    }

    int opcion;
    do {
        printf("\n--- Menú ---\n");
        printf("1. Mostrar estado de la memoria\n");
        printf("2. Asignar proceso\n");
        printf("3. Liberar proceso\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            mostrarEstado(particiones, num_particiones);
            break;
        case 2: {
            int id_proceso, tamano_proceso;
            printf("Ingrese el ID del proceso: ");
            scanf("%d", &id_proceso);
            printf("Ingrese el tamaño del proceso: ");
            scanf("%d", &tamano_proceso);
            asignarProceso(particiones, num_particiones, id_proceso, tamano_proceso);
            break;
        }
        case 3: {
            int id_proceso;
            printf("Ingrese el ID del proceso a liberar: ");
            scanf("%d", &id_proceso);
            liberarProceso(particiones, num_particiones, id_proceso);
            break;
        }
        case 4:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
