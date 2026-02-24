#include <stdio.h>
#include <stdlib.h>

int main()
{
    float vac, acr, valorv;
    printf("Digite o valor de custo do produto:");
    scanf ("%f",&vac);
    printf ("digite o acrescimo percentual para definir o custo de venda : ");
    scanf ("%f",&acr);
    system("pause");
    system ("cls");
    valorv = vac+(vac *acr);
    printf (" O custo de venda e igual a : %.2f", valorv);
    return 0;
}
