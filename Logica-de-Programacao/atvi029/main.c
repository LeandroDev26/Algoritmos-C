#include <stdio.h>
#include <stdlib.h>

int main()
{

    int opc;
    printf ("digite o numero do mes :");
    scanf ("%d", &opc);
    switch(opc){

  case 1:
   printf ("Janeiro");

    break;
     case 2:
    ("Fevereiro");

    break;
case 3:
  printf ("Marco");

    break;
 case 4:

printf ("abril");
    break;
case 5:
printf ("Maio");

    break;

     case 6:
printf ("Junho");

    break;
     case 7:

printf ("Julho");
    break;
     case 8:

printf ("Agosto");
    break;
     case 9:
printf ("Setembro");

    break;
     case 10:
 printf ("outubro");

    break;
     case 11:
printf ("Novembro");

    break;
     case 12:

printf ("Dezembro");
    break;


     default:
        printf ("Esse mes nao existe!!");
        break;
    }
    printf("");
    return 0;
}
