#include <stdio.h>
#include <stdlib.h>

int main()
{
    float N , number , totnum_positivo = 0, totnum_negativo = 0, totnum_zero = 0;
    printf("Digite quantos numeros voce deseja realizar a vereficacao :");
    scanf ("%f", &N);
    for (int i =1 ; i<= N;i++){
         printf("Digite um numero :");
         scanf("%f", &number);

        if (number > 0) {
        printf("%.2f e positivo.\n", number);
        totnum_positivo++;
    } else if (number < 0) {
        printf("%.2f e negativo.\n", number);
        totnum_negativo++;
    } else {
        printf("O numero e igual a %.2f .\n", number);
        totnum_zero++;
    }


    }
    system ("pause");
    system ("cls");
    for (int i =1 ; i<= 1;i++){
    printf ("O total de numeros positivos e : %.2f \n", totnum_positivo);
    printf ("O total de numeros negativos e : %.2f \n ", totnum_negativo);
    printf ("O total de numeros igual a zero e : %.2f \n", totnum_zero);
    }
    return 0;
}
