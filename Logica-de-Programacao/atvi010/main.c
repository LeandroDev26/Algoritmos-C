#include <stdio.h>
#include <stdlib.h>

int main()
{
    float pre ,c;
    printf("Digite qual e o valor da sua compra:");
    scanf ("%f", &c);
    pre = c/5;
    printf( "o valor da primeira prestacao e : %.2f \n",pre );
     printf( "o valor da segunda prestacao e : %.2f\n",pre );
      printf( "o valor da terceira prestacao e : %.2f\n",pre );
       printf( "o valor da quarta prestacao e : %.2f \n",pre );
        printf( "o valor da quinta prestacao e : %.2f \n",pre );

    return 0;
}
