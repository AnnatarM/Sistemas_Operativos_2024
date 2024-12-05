#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int prioridad;
    int valor;
} Elemento;

typedef struct {
    Elemento heap[MAX];
    int tamano;
} ColaPrioridad;

void inicializarCola(ColaPrioridad *cp);
void insertar(ColaPrioridad *cp, int valor, int prioridad);
Elemento extraerMinimo(ColaPrioridad *cp);
void ajustarArriba(ColaPrioridad *cp, int indice);
void ajustarAbajo(ColaPrioridad *cp, int indice);
void imprimirCola(ColaPrioridad *cp);

int main() {
    ColaPrioridad cp;
    inicializarCola(&cp);

    insertar(&cp, 10, 2);
    insertar(&cp, 20, 1);
    insertar(&cp, 30, 3);
    insertar(&cp, 40, 0);

    printf("Estado de la cola de prioridad:\n");
    imprimirCola(&cp);

    printf("\nExtrayendo elementos según prioridad:\n");
    while (cp.tamano > 0) {
        Elemento min = extraerMinimo(&cp);
        printf("Valor: %d, Prioridad: %d\n", min.valor, min.prioridad);
    }

    return 0;
}

void inicializarCola(ColaPrioridad *cp) {
    cp->tamano = 0;
}

void insertar(ColaPrioridad *cp, int valor, int prioridad) {
    if (cp->tamano >= MAX) {
        printf("Error: La cola está llena.\n");
        return;
    }
    cp->heap[cp->tamano].valor = valor;
    cp->heap[cp->tamano].prioridad = prioridad;
    cp->tamano++;
    ajustarArriba(cp, cp->tamano - 1);
}

Elemento extraerMinimo(ColaPrioridad *cp) {
    if (cp->tamano <= 0) {
        printf("Error: La cola está vacía.\n");
        exit(1);
    }
    Elemento min = cp->heap[0];
    cp->heap[0] = cp->heap[cp->tamano - 1];
    cp->tamano--;
    ajustarAbajo(cp, 0);
    return min;
}

void ajustarArriba(ColaPrioridad *cp, int indice) {
    int padre = (indice - 1) / 2;
    while (indice > 0 && cp->heap[padre].prioridad > cp->heap[indice].prioridad) {
        Elemento temp = cp->heap[padre];
        cp->heap[padre] = cp->heap[indice];
        cp->heap[indice] = temp;
        indice = padre;
        padre = (indice - 1) / 2;
    }
}

void ajustarAbajo(ColaPrioridad *cp, int indice) {
    int menor = indice;
    int izquierdo = 2 * indice + 1;
    int derecho = 2 * indice + 2;

    if (izquierdo < cp->tamano && cp->heap[izquierdo].prioridad < cp->heap[menor].prioridad) {
        menor = izquierdo;
    }
    if (derecho < cp->tamano && cp->heap[derecho].prioridad < cp->heap[menor].prioridad) {
        menor = derecho;
    }
    if (menor != indice) {
        Elemento temp = cp->heap[menor];
        cp->heap[menor] = cp->heap[indice];
        cp->heap[indice] = temp;
        ajustarAbajo(cp, menor);
    }
}

void imprimirCola(ColaPrioridad *cp) {
    for (int i = 0; i < cp->tamano; i++) {
        printf("Valor: %d, Prioridad: %d\n", cp->heap[i].valor, cp->heap[i].prioridad);
    }
}
