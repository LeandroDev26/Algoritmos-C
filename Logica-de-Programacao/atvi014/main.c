#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("digite o primeiro numero : ");
    scanf ("%d", &num1);
    printf("digite um numero diferente do primeiro numero : ");
    scanf ("%d", &num2);
    if (num1>num2){
        printf (" O primeiro numero e o maior !!\n");
    }else{
     printf (" O segundo numero e o maior !!\n");
    }

    return 0;
}
