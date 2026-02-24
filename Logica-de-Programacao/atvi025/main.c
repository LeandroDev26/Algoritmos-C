#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1 , num2;
    printf("Digite um valor para o primeiro numero :");
    scanf ("%f", &num1);
    printf("Digite um valor para o segundo numero :");
    scanf ("%f", &num2);
    if (num1==num2){

        printf (" Os numeros sao iguais!!");
    }
    if (num1!=num2 && num1>num2){
        printf ("O primeiro numero digitado e o maior ");
    }
    if (num1!=num2 && num1<num2){
        printf ("O segundo numero digitado e o maior ");
    }


    return 0;
}
