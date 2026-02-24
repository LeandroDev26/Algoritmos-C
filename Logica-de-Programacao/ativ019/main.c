#include <stdio.h>
#include <string.h>

// Definindo uma estrutura para armazenar os dados das pessoas
typedef struct {
    char nome[50];
    char sexo[20];
} Pessoa;

int main() {
    Pessoa pessoas[56];
    int total_homens = 0 , total_mulheres = 0;// Vetor para armazenar os dados de 4 pessoas

    // Entrada de dados
    for (int i = 0; i < 56; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        gets (pessoas[i].nome);

        printf("Digite o sexo da pessoa %d (MASCULINO/FEMININO): ", i + 1);
       gets(pessoas[i].sexo);
        if (strcasecmp(pessoas[i].sexo, "MASCULINO") == 0) {
            total_homens++;
        } else if (strcasecmp(pessoas[i].sexo, "FEMININO") == 0) {
            total_mulheres++;
        } else {
            printf("Sexo inválido para a pessoa %d. Não será contado.\n", i + 1);
        }

    }

    // Exibição dos dados
    printf("\n--- Dados Cadastrados ---\n");
    for (int i = 0; i < 56; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Sexo: %s\n", pessoas[i].sexo);
    }
    printf("\nTotal de Homens: %d\n", total_homens);
    fflush(stdin);
    printf("Total de Mulheres: %d\n", total_mulheres);

    return 0;
}
