#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* A inserção de elementos já ordenados (como o alfabeto em ordem) em uma Árvore Binária de Busca (ABB)
    resulta em um caso de performance desfavorável, criando uma árvore completamente desbalanceada.
    A: O primeiro elemento, A, se torna a raiz.
    B: Como B > A, é inserido à direita de A.
    C: Como C > A e C > B, é inserido à direita de B.
    D, E, F... Z: Cada letra subsequente é sempre maior que a anterior. Por isso, o algoritmo de inserção
    sempre percorrerá o caminho mais à direita da árvore para encontrar um local vazio.
    O resultado é uma estrutura degenerada que se assemelha a uma lista ligada, onde cada nó possui apenas
    um filho à direita.

    Exemplo de Árvore resultante
    A
 \
  B
   \
    C
     \
      D
       \
        E
         \
          F
           \
            G
             \
              H
               \
                I
                 \
                  J
                   \
                    K
                     \
                      L
                       \
                        M
                         \
                          N
                           \
                            O
                             \
                              P
                               \
                                Q
                                 \
                                  R
                                   \
                                    S
                                     \
                                      T
                                       \
                                        U
                                         \
                                          V
                                           \
                                            W
                                             \
                                              X
                                               \
                                                Y
                                                 \
                                                  Z

                                                  */

}
