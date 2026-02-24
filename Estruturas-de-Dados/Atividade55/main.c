#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Passo 1: Criando a Condição de Desbalanceamento
    Vamos inserir os números 10, 20 e 30, nesta ordem.

   Inserir 10: A árvore tem apenas a raiz.
    10
   Inserir 20: 20 > 10, então é inserido à direita. A árvore continua balanceada.

   10 (fator: +1)
    \
     20 (fator: 0)

   Inserir 30: 30 > 20, então é inserido à direita de 20. Após essa inserção, subimos na árvore atualizando os fatores de balanceamento e detectamos um problema.

   Árvore Desbalanceada:

    10 (fator: +2)  <-- DESBALANCEADO
     \
      20 (fator: +1)
       \
        30 (fator: 0)

       O nó 10 ficou com um fator de balanceamento de +2, caracterizando o desbalanceamento.

       Passo 2: Rebalancear a Árvore
       O desbalanceamento do tipo Direita-Direita é corrigido com uma Rotação Simples à Esquerda
       no nó desbalanceado (nó 10).

       Ação: O filho direito (20) "sobe" para se tornar o novo pai, e o antigo pai (10) "desce" para
        se tornar seu filho esquerdo.

   Árvore Rebalanceada:

      20 (fator: 0)
     /  \
    10   30
   (fator: 0) (fator: 0)

   Após a rotação, a árvore volta a ser uma AVL válida, com os fatores de balanceamento de todos os nós em 0.
    */
}
