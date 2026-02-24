#include <stdio.h>
#include <string.h>

int main() {
    int n, idade, aptos = 0, inaptos = 0;
    char nome[50], sexo, saude;

    printf("Digite o numero de pessoas a serem avaliadas: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // Entrada de dados
        printf("\nPessoa %d:\n", i + 1);
        printf("Digite o nome: ");
        scanf(" %[^\n]s", nome);  // Lê string com espaços
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);
        printf("Digite a idade: ");
        scanf("%d", &idade);
        printf("Digite a saude (B para Boa, R para Ruim): ");
        scanf(" %c", &saude);

        // Verificação de aptidão
        if (idade >= 18 && idade <= 45 && (sexo == 'M' || sexo == 'm') && (saude == 'B' || saude == 'b')) {
            aptos++;
            printf("Resultado: APTO para o serviço militar.\n");
        } else {
            inaptos++;
            printf("Resultado: INAPTO para o serviço militar.\n");
        }
    }

    // Exibição dos totais
    printf("\nTotal de pessoas aptas: %d\n", aptos);
    printf("Total de pessoas inaptas: %d\n", inaptos);

    return 0;
}
