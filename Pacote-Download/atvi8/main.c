#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dolar;
    float cd , real;
    printf("Qual e o valor de cotacao do dolar?");
    scanf ("%f", &cd);
    printf ("Qual a quantidade de dolar deseja converter?");
     scanf ("%d", &dolar);
     real = cd*dolar;
     system ("pause");
     system ("cls");
      printf (" O valor digitado em dolar convertido para real igual a : %.2f",real );

    return 0;
}
