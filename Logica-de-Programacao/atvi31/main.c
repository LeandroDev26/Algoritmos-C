#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, num3;

    // Input numbers
    printf("iDigite um numero: ");
    scanf("%d", &num1);
    printf("Digite um numero diferente do anterior: ");
    scanf("%d", &num2);
    printf("Digite um numero diferente dos anteriores: ");
    scanf("%d", &num3);

    // Sort and print numbers in ascending order
    if (num1 <= num2 && num1 <= num3) {
        if (num2 <= num3) {
            printf("%d %d %d\n", num1, num2, num3);
        } else {
            printf("%d %d %d\n", num1, num3, num2);
        }
    } else if (num2 <= num1 && num2 <= num3) {
        if (num1 <= num3) {
            printf("%d %d %d\n", num2, num1, num3);
        } else {
            printf("%d %d %d\n", num2, num3, num1);
        }
    } else {
        if (num1 <= num2) {
            printf("%d %d %d\n", num3, num1, num2);
        } else {
            printf("%d %d %d\n", num3, num2, num1);
        }
    }

    return 0;
}
