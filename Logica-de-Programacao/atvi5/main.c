#include <stdio.h>
#include <stdlib.h>

int main()
{   float nota1 , nota2, nota3;
    char nome[20];
    float media;
    printf("Digite o seu nome :");
    gets(nome );
    printf ("Digite a nota da primeira prova :");
    scanf ("%f", &nota1);
    printf ("Digite a nota da segunda prova :");
    scanf ("%f", &nota2);
    printf ("Digite a nota da terceira prova :");
    scanf ("%f", &nota3);
    system (" pause");
    system ("cls");
    printf (" Nome : %s\n", nome);
    media = (nota1 + nota2 + nota3) /3;
    printf ("A media obtida de suas notas e : %.2f ",media);
   printf ("\n");
    return 0;
}
