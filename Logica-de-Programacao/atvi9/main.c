#include <stdio.h>
#include <stdlib.h>

int main()
{
    float dep, rend;
    printf("Digite o valor do deposito :");
    scanf ("%f", &dep);
    rend = dep * 0.007;
    printf ("O valor do deposito e rendimento apos um mes e : %.2f \n",dep+rend);

    return 0;
}
