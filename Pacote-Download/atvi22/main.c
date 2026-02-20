#include <stdio.h>

int main() {
    float preco_custo, preco_venda, soma_custo = 0, soma_venda = 0;
    float media_custo, media_venda;
    int n = 40;  // Quantidade de produtos (pode ser alterada)

    for (int i = 1; i <= n; i++) {
        printf("Produto %d:\n", i);
        printf("Digite o preco de custo: ");
        scanf("%f", &preco_custo);
        printf("Digite o preco de venda: ");
        scanf("%f", &preco_venda);

        // Verificar lucro, empate ou prejuízo
        if (preco_venda > preco_custo) {
            printf("Houve lucro\n");
        } else if (preco_venda == preco_custo) {
            printf("Houve empate\n");
        } else {
            printf("Houve prejuizo\n");
        }

        // Acumular valores para cálculo da média
        soma_custo += preco_custo;
        soma_venda += preco_venda;
    }

    // Cálculo das médias
    media_custo = soma_custo / n;
    media_venda = soma_venda / n;

    // Exibição dos resultados
    printf("\nA media de custo e: %.2f\n", media_custo);
    printf("A media de venda e: %.2f\n", media_venda);

    return 0;
}
