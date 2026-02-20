#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nivel, tot_aulas;
    float salario;
    printf ("Digite o nivel do professor ");
    scanf ("%d", &nivel);
    printf ("Digite quantas aulas voce da :");
    scanf ("%d",&tot_aulas);
    if (nivel == 1){

        salario = tot_aulas *12;
        printf ("O salario do professor e : %.2f", salario);
    }

    else if (nivel == 2){

        salario = tot_aulas *17;
        printf ("O salario do professor e : %.2f", salario);
    }
    else if (nivel == 3){

        salario = tot_aulas * 25;
        printf ("O salario do professor e : %.2f", salario);
    }else{
    printf ("posicao invalida");
    }



    return 0;
}
