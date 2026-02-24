#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[20];
    float nota1, nota2, nota3, media;
    printf("Digite o nome :");
    gets(nome);
    printf ("Digite a nota da primeira prova :");
    scanf ("%f",&nota1 );
    printf ("Digite a nota da segunda  prova :");
    scanf ("%f",&nota2 );
    printf ("Digite a nota da terceira prova :");
    scanf ("%f",&nota3 );
    media = (nota1 + nota2 + nota3)/3;
    printf ("A media das notas e : %.2f\n", media);
    if (media>=7){
      printf("Nome: %s foi aprovado!! ",nome);

    }

    if (media<=5){
        printf("Nome: %s foi  Reprovado!! ",nome);
    }
    if(media>5 && media<7){
        printf("Nome: %s esta de Recuperacao!! ",nome);
    }
    return 0;
}
