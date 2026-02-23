#include <stdio.h>

int main() {
    int tipoCliente;
    float consumo, valorConta;

    // Entrada dos dados
    printf("Digite o tipo de cliente (1-Residência, 2-Comércio, 3-Indústria): ");
    scanf("%d", &tipoCliente);

    printf("Digite o consumo de energia em kWh: ");
    scanf("%f", &consumo);

    // Cálculo do valor da conta de luz
    if (tipoCliente == 1) {
        valorConta = consumo * 0.60; // Residência
        printf("Valor da conta de luz: R$ %.2f\n", valorConta);
    } else if (tipoCliente == 2) {
        valorConta = consumo * 0.48; // Comércio
        printf("Valor da conta de luz: R$ %.2f\n", valorConta);
    } else if (tipoCliente == 3) {
        valorConta = consumo * 1.29; // Indústria
        printf("Valor da conta de luz: R$ %.2f\n", valorConta);
    } else {
        printf("Tipo de cliente inválido.\n");
    }

    return 0;
}
