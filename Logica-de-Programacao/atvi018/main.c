#include <stdio.h>
#include <stdlib.h>

int main()
{

    int idade[75];
    for(int i= 1;i <=75;i++){
    printf("Digite a idade:");
    scanf ("%d",&idade[i]);

    }
    for (int i = 1; i < 75; i++) {
        if (idade[i] >= 18 ) {
           printf("Pessoa %d e maior de idade!!\n",i);
        }
        if (idade[i]< 18){
            printf ( " Pessoa %d e menor de idade!!\n",i);
        }
    }


}
