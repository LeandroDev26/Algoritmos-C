#include <stdio.h>

int main() {
    char nome[50], sexo;
    float altura, pesoIdeal;
    int idade;

    // Entrada dos dados
    printf("Digite o nome: ");
    scanf("%s", nome);

    printf("Digite o sexo (M para masculino, F para feminino): ");
    scanf(" %c", &sexo);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    printf("Digite a idade: ");
    scanf("%d", &idade);

    // Cálculo do peso ideal
    if (sexo == 'M' || sexo == 'm') { // Masculino
        if (altura >= 1.70) {
            if (idade <= 20) {
                pesoIdeal = (72.7 * altura) - 58;
            } else if (idade <= 40) {
                pesoIdeal = (72.7 * altura) - 55;
            } else {
                pesoIdeal = (72.7 * altura) - 50;
            }
        } else { // Altura < 1.70
            if (idade <= 35) {
                pesoIdeal = (62.1 * altura) - 44.7;
            } else {
                pesoIdeal = (62.1 * altura) - 40;
            }
        }
    } else if (sexo == 'F' || sexo == 'f') { // Feminino
        if (altura >= 1.50) {
            if (idade <= 35) {
                pesoIdeal = (62.1 * altura) - 44.7;
            } else {
                pesoIdeal = (62.1 * altura) - 40;
            }
        } else { // Altura < 1.50
            if (idade <= 35) {
                pesoIdeal = (62.1 * altura) - 40;
            } else {
                pesoIdeal = (62.1 * altura) - 35;
            }
        }
    } else {
        printf("Sexo inválido.\n");
        return 1; // Encerra o programa se o sexo for inválido
    }

    // Saída dos dados
    printf("Nome: %s\n", nome);
    printf("Peso Ideal: %.2f kg\n", pesoIdeal);

    return 0;
}
