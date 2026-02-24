#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b;
    char c;

    // Input the first number
    printf("Digite um numero: ");
    scanf("%f", &a);
    if (a == 0) {
        return 0;
    }

    // Input the second number
    printf("Digite um numero diferente do anterior: ");
    scanf("%f", &b);
    if (b == 0) {
        return 0;
    }

    // Input the operator
    printf("Digite um operador (+, -, *, /): ");
    scanf(" %c", &c); // Note the space before %c

    // Validate the operator and perform the operation
    if (c == '+') {
        printf("Resultado: %f + %f = %f\n", a, b, a + b);
    } else if (c == '-') {
        printf("Resultado: %f - %f = %f\n", a, b, a - b);
    } else if (c == '*') {
        printf("Resultado: %f * %f = %f\n", a, b, a * b);
    } else if (c == '/') {
        if (b != 0) {
            printf("Resultado: %f / %f = %f\n", a, b, a / b);
        } else {
            printf("Erro: divisao por zero nao permitida!\n");
        }
    } else {
        printf("Erro: operador invalido!\n");
    }

    return 0;
}
