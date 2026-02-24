#include <stdio.h>
#include <stdlib.h>

int main()
{
    float custo_fabrica;
    printf("Digite o custo de de fabrica de um carro :");
       scanf ("%f",&custo_fabrica );
       custo_fabrica += (custo_fabrica * 0.45) ;
       custo_fabrica += (custo_fabrica * 0.28);
       printf ("O custo ao consumidor de um carro novo e : %.2f", custo_fabrica);
    return 0;
}
