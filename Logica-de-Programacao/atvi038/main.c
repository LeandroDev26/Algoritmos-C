#include <stdio.h>

int main() {
    float lab, semestral, exame, notaFinal;

    // Entrada das notas
    printf("Digite a nota do trabalho de laboratório (0 a 10): ");
    scanf("%f", &lab);

    printf("Digite a nota da avaliação semestral (0 a 10): ");
    scanf("%f", &semestral);

    printf("Digite a nota do exame final (0 a 10): ");
    scanf("%f", &exame);

    // Verifica se as notas estão no intervalo válido
    if ((lab < 0 || lab > 10) || (semestral < 0 || semestral > 10) || (exame < 0 || exame > 10)) {
        printf("Erro: Todas as notas devem estar entre 0 e 10.\n");
        return 1; // Encerra o programa
    }

    // Cálculo da média ponderada
    notaFinal = (lab * 2 + semestral * 3 + exame * 5) / 10;

    // Saída do resultado
    printf("A nota final do estudante é: %.2f\n", notaFinal);

    return 0;
}
