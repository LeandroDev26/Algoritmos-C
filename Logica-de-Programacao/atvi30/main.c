#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sexo[20];
    char nome[20];
    int idade;
    float salario = 0, salario_liquido = 0;
    printf("Digite o seu nome :");
    scanf("%s",nome);
    printf("Digite o seu sexo (MASCULINO/FEMININO) :");
    scanf("%s",sexo);
    printf("Digite a sua idade :");
    scanf("%d", &idade);
    printf("Digite a seu salario :");
    scanf("%f", &salario);
    if (strcmp(sexo, "masculino") == 0 && idade >= 30)
    {
        salario_liquido = salario + 100.00;
        printf ("Nome : %s \n", nome);
        printf ("O salario liquido e %.2f \n", salario_liquido);
    }
    else if (strcmp(sexo, "masculino") == 0 && idade < 30)
    {
        salario_liquido = salario + 50.00;
        printf ("Nome : %s \n", nome);
        printf ("O salario liquido e %.2f \n", salario_liquido);
    }
    else if (strcmp(sexo, "feminino") == 0 && idade >= 30)
    {
        salario_liquido = salario + 200.00;
        printf ("Nome : %s \n", nome);
        printf ("O salario liquido e %.2f \n", salario_liquido);
    }
    else if (strcmp(sexo, "feminino") == 0 && idade < 30)
    {
        salario_liquido = salario + 80.00;
        printf ("Nome : %s \n", nome);
        printf ("O salario liquido e %.2f \n", salario_liquido);
    }





    return 0;
}
