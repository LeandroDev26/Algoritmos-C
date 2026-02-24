#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*

    Árvore com Altura 2 (Exemplo do enunciado)
    Esta é a árvore mais balanceada possível, onde o elemento mediano (10) é a raiz.

      10
     /  \
    /    \
   4      17
  / \    /  \
 1   5  16  21


    Árvore com Altura 3
    Para aumentar a altura, basta escolher uma raiz que não seja
    a mediana, desbalanceando a árvore levemente.

       16
      /  \
     /    \
    4      17
   / \      \
  1   5      21
     /
    10
   Árvore com Altura 4
   Aumentando ainda mais o desbalanceamento, podemos criar
   um caminho mais longo.

       5
      / \
     /   \
    4     16
   /     /  \
  1     10   17
             \
              21
    Árvore com Altura 5
    Continuando a criar uma estrutura mais "esticada".

      4
     / \
    1   10
       /  \
      5    17
          /  \
         16   21


   Árvore com Altura 6
   Esta é a altura máxima possível com 7 nós, formando uma árvore completamente
   degenerada, similar a uma lista ligada. Isso acontece quando os elementos são
   inseridos em ordem crescente ou decrescente.

    1
     \
      4
       \
        5
         \
          10
           \
            16
             \
              17
               \
                21

    */
}
