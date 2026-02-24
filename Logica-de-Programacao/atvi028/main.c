#include <stdio.h>

int main() {
    int num_funcionarios = 4;  // Número total de funcionários
    float salario_minimo;        // Valor do salário mínimo
    float aumento_total = 0.0;   // Para acumular o aumento total da folha de pagamento

    // Variáveis para armazenar dados de cada funcionário
    char nome[50];
    float salario, salario_reajustado, reajuste;

    // Lendo o valor do salário mínimo
    printf("Digite o valor do salario minimo: ");
    scanf("%f", &salario_minimo);

    // Loop para processar cada um dos 584 funcionários
    for (int i = 0; i < num_funcionarios; i++) {
        printf("\nDigite o nome do funcionario %d: ", i + 1);
        scanf(" %[^\n]%*c", nome);  // Lê o nome do funcionário com espaços

        printf("Digite o salario do funcionario %d: ", i + 1);
        scanf("%f", &salario);

        // Calcular o reajuste de acordo com o critério
        if (salario < 3 * salario_minimo) {
            // Critério A: 50% de reajuste para quem ganha menos de 3 salários mínimos
            reajuste = salario * 0.50;
        } else if (salario >= 3 * salario_minimo && salario <= 10 * salario_minimo) {
            // Critério B: 20% de reajuste para quem ganha entre 3 e 10 salários mínimos
            reajuste = salario * 0.20;
        } else if (salario > 10 * salario_minimo) {
            // Critério C: 15% de reajuste para quem ganha acima de 10 salários mínimos
            reajuste = salario * 0.15;
        } else {
            // Critério D: 10% de reajuste para os demais
            reajuste = salario * 0.10;
        }

        // Calcular o novo salário
        salario_reajustado = salario + reajuste;

        // Acumular o aumento total na folha de pagamento
        aumento_total += reajuste;

        // Exibir o nome do funcionário, o reajuste e o novo salário
        printf("\nFuncionario: %s\n", nome);
        printf("Reajuste: %.2f\n", reajuste);
        printf("Novo salario: %.2f\n", salario_reajustado);
    }

    // Exibir o aumento total da folha de pagamento
    printf("\nAumento total na folha de pagamento: %.2f\n", aumento_total);

    return 0;
}
