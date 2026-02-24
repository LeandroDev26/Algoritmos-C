#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ld1, ld2, ld3;
    printf("digite um valor para o  primeiro lado");
    scanf ("%f", &ld1);
    printf("digite um valor para o  segundo lado");
    scanf ("%f", &ld2);
    printf("digite um valor para o  terceiro lado");
    scanf ("%f", &ld3);
    if ((ld1 && ld2 && ld3)<(ld1+ld2) ){
        printf ("E um triangulo");
    }

    if (ld1==ld2==ld3){
        printf ("e um triangulo equilatero");
    }

    if (ld1==ld2 != ld3 || ld2==ld3 != ld1 || ld1==ld3 != ld2){
             printf (" e um triangulo isosceles") ;

    }

    else if(ld1!= ld2 && ld2 != ld3 && ld3!=ld1){
       printf (" E um triangulo escaleno");
    }
    return 0;
}
