#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    int ano, total_ate_2000 = 0, total_geral = 0;
    float preco, desconto, valor_final;
    char continuar;

    do {
        // Entrada de dados
        printf("Digite o ano do veiculo: ");
        scanf("%d", &ano);
        printf("Digite o preco do veiculo: ");
        scanf("%f", &preco);

        // Cálculo do desconto
        if (ano <= 2000) {
            desconto = preco * 0.12;  // 12% de desconto
            total_ate_2000++;        // Contar carro até 2000
        } else {
            desconto = preco * 0.07;  // 7% de desconto
        }

        // Calcular valor final a ser pago
        valor_final = preco - desconto;
        total_geral++;  // Contar total geral de carros

        // Exibir informações
        printf("Desconto: R$ %.2f\n", desconto);
        printf("Valor a ser pago: R$ %.2f\n", valor_final);

        // Perguntar se deseja continuar
        printf("Deseja calcular para outro veiculo? (S/N): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);  // Converter para maiúsculo para facilitar a comparação

    } while (continuar != 'N');  // Enquanto o usuário não digitar "N", continua o loop

    // Exibir totais
    printf("\nTotal de carros com ano ate 2000: %d\n", total_ate_2000);
    printf("Total geral de carros: %d\n", total_geral);

    return 0;
}


