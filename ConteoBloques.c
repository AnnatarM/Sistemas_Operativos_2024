#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_FILAS 20
#define MAX_COLUMNAS 20

void generarMatrizAleatoria(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    srand(time(NULL));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (rand() % 100 < 20) ? 1 : 0;
        }
    }
}

int contarBloquesDeDos(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    int bloques = 0;
    bool contador[MAX_FILAS][MAX_COLUMNAS] = {false};
    int direcciones[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (contador[i][j] || matriz[i][j] == 0) continue;

            for (int d = 0; d < 4; d++) {
                int ni = i + direcciones[d][0];
                int nj = j + direcciones[d][1];
                if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas && 
                    matriz[ni][nj] == 1 && !contador[ni][nj]) {
                    contador[i][j] = true;
                    contador[ni][nj] = true;
                    bloques++;
                    break;  
                }
            }
        }
    }

    return bloques;
}

void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas;
    int matriz[MAX_FILAS][MAX_COLUMNAS];

    printf("Ingrese el número de filas (máximo %d): ", MAX_FILAS);
    scanf("%d", &filas);

    printf("Ingrese el número de columnas (máximo %d): ", MAX_COLUMNAS);
    scanf("%d", &columnas);

    if (filas <= 0 || filas > MAX_FILAS || columnas <= 0 || columnas > MAX_COLUMNAS) {
        printf("Dimensiones inválidas. Deben estar entre 1 y %d.\n", MAX_COLUMNAS);
        return 1;
    }

    generarMatrizAleatoria(matriz, filas, columnas);
    printf("\nMatriz generada:\n");
    imprimirMatriz(matriz, filas, columnas);
    int numeroBloques = contarBloquesDeDos(matriz, filas, columnas);
    printf("\nNúmero de bloques de 2 elementos encontrados: %d\n", numeroBloques);

    return 0;
}