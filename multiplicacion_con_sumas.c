#include <stdio.h>
int multiplicacion(int a, int b) {
    if (b == 0) {
        return 0; 
    }
    return a + multiplicacion(a, b - 1);
}

int potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    }
    return multiplicacion(base, potencia(base, exponente - 1));
}

int main() {
    int base = 3, exponente = 4;
    int resultado = potencia(base, exponente);
    printf("Resultado de %d^%d = %d\n", base, exponente, resultado);
    return 0;
}