#include <stdio.h>
#include <stdlib.h>

int main()
{
    float c, f;
    printf("digite uma temperatura(Celsius):");
    scanf ("%f", &c);
    f =(9*c + 160)/5;
    printf ("convertida para (fahrenreit) e : %.2f", f);
    return 0;
}
