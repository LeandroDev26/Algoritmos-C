#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[4];
    for(int i= 0;i <=80;i++){
    printf("Digite um numero:");
    scanf ("%d",&num[i]);

    }
    for (int i = 0; i < 80; i++) {
        if (num[i] >= 10 && num[i] <= 150) {
           printf("%d\n", num[i]);
        }
    }

    return 0;
}
