#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salariofinal;
    char nome[20];
    float salario;
    int totvend;
    printf ("Digite o nome :");
    scanf ("%s", &nome);
    printf ("digite o salrio fixo :");
    scanf ("%f",&salario);
    fflush(stdin);
    printf(" Digite o total de vendas :");
    scanf ("%d", &totvend);
    system("pause");
    system ("cls");
    printf(" Nome : %s \n", nome);
    printf (" O salario Fixo e : %.2f \n", salario);
    salariofinal = salario + (totvend *0.15);
    printf (" O salario final e : %.2f\n", salariofinal);
    return 0;
}
