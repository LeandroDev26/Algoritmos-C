#include <stdio.h>
#include <stdlib.h>

int main()
{
    float totcar, totcomb;
    printf(" Digite a distancia total percorrida com o carro (Km):");
    scanf ("%f", &totcar);
    printf(" Digite o total de combustivel gasto (em litros):");
    scanf ("%f", &totcomb);
    printf ("O consumo medio e : %.2f km/l" ,totcar/totcomb);

    return 0;
}
