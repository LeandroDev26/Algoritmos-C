#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Passo 1: Criando a Condição de Desbalanceamento

  Vamos inserir os números **10**, **30** e **20**, nesta ordem.

 1.  **Inserir 10**: A árvore tem apenas a raiz.

      10


  2.  **Inserir 30**: `30 > 10`, é inserido à direita. A árvore continua balanceada.

      10 (fator: +1)
       \
        30 (fator: 0)


  3.  **Inserir 20**: `20 < 30`, é inserido à esquerda de 30. Após essa inserção, o desbalanceamento ocorre.

    **Árvore Desbalanceada:**

      10 (fator: +2)  <-- DESBALANCEADO
       \
        30 (fator: -1)
       /
      20 (fator: 0)

    O nó **10** ficou com um fator de +2 e seu filho direito (30) tem um fator de -1,
    caracterizando o desbalanceamento Direita-Esquerda.

    Passo 2: Rebalancear a Árvore (Rotação Dupla)

    Este tipo de desbalanceamento é corrigido com uma **Rotação Dupla Direita-Esquerda**.
    Ela consiste em duas rotações simples:

    a) Rotação à Direita no filho (nó 30)

  Primeiro, uma rotação à direita é aplicada no filho direito do nó desbalanceado (no nó 30).
  O nó 20 sobe, e o 30 desce para se tornar seu filho direito.

  **Árvore no estado intermediário:**

      10 (fator: +2)
       \
        20
         \
          30
   Isso transforma o problema em um desbalanceamento simples do tipo **Direita-Direita**.

   b) Rotação à Esquerda no nó original (nó 10)

   Agora, aplicamos uma rotação simples à esquerda no nó que estava originalmente desbalanceado (o nó 10).

  **Árvore Rebalanceada (Final):**

      20 (fator: 0)
     /  \
    10   30
   (fator: 0) (fator: 0)

   Após a rotação dupla, a árvore volta a ser uma AVL válida e perfeitamente balanceada.
    */
}
