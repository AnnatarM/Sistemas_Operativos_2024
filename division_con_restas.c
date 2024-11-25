#include <stdio.h>
int division(int dividendo, int divisor) {
    
    if (dividendo < divisor) {
        return 0;
    }
    return 1 + division(dividendo - divisor, divisor);
}

int main() {
    int dividendo = 20, divisor = 3;
    int resultado = division(dividendo, divisor);
    printf("Resultado de %d / %d = %d\n", dividendo, divisor, resultado);
    return 0;
}