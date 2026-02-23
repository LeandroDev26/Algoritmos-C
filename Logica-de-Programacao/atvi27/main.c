#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tipo_combustivel[20];
    float valor_car, desconto = 0.0;
    printf ("\n");
    printf ("CARANGO");
    printf ("\n");
    printf(" Digite o valor do carro que deseja comprar :\n");
    scanf ("%f", &valor_car);
    printf ("Digite qual e o tipo de combustivel do automovel para seja possivel calcular o desconto :");
     scanf("%s", &tipo_combustivel);
    if (strcmp(tipo_combustivel, "alcool") == 0) {
            desconto = valor_car * 0.25;
             printf ("O desconto e igual a %.2f \n",desconto);
              printf ("O valor a ser pago pelo cliente e igual a : %.2f", valor_car-desconto);
    }
    else if (strcmp(tipo_combustivel, "gasolina") == 0) {
            desconto = valor_car * 0.21;
             printf ("O desconto e igual a %.2f \n",desconto);
              printf ("O valor a ser pago pelo cliente e igual a : %.2f", valor_car-desconto);
    }
    else if (strcmp(tipo_combustivel, "diesel") == 0) {
            desconto = valor_car * 0.14;
            printf ("O desconto e igual a %.2f \n",desconto);
            printf ("O valor a ser pago pelo cliente e igual a : %.2f", valor_car-desconto);


    }

    return 0;
}
