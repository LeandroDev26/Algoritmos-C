#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*

    **Árvore Inicial:**
      20
     /  \
    10   30
        /  \
       25   40

   Nesta árvore, todos os nós estão com fator de balanceamento 0 ou -1, portanto, é uma AVL válida.

   Passo 2: Removendo o Nó e Causando o Desbalanceamento

   Agora, vamos remover o nó **10**. A remoção de um nó folha é simples, mas ao subirmos na árvore para
    atualizar os fatores de balanceamento, encontramos um problema no nó 20.

   A subárvore esquerda do nó 20 se torna vazia (altura -1).
   A subárvore direita do nó 20 (liderada por 30) tem altura 1.
   O fator de balanceamento do nó 20 se torna `(altura_direita - altura_esquerda)` = `1 - (-1)` = `+2`.

   **Árvore Desbalanceada:**
      20 (fator: +2)  <-- DESBALANCEADO
        \
         30 (fator: 0)
        /  \
       25   40

  Temos um desbalanceamento RR no nó 20, pois seu fator é +2 e o fator de seu filho direito (30) é 0.

  Passo 3: Rebalancear a Árvore

  O desbalanceamento do tipo Direita-Direita é corrigido com uma **Rotação Simples à Esquerda** no nó desbalanceado (nó 20).

  **Ação:** O nó 30 "sobe" para se tornar a nova raiz. O nó 20 "desce" para se tornar o filho esquerdo do 30.
   A subárvore esquerda do 30 (o nó 25) se torna a nova subárvore direita do 20.

**Árvore Rebalanceada (Final):**
      30
     /  \
    20   40
     \
      25

  Após a rotação, a árvore volta a ser uma AVL válida, com todos os nós dentro do fator de balanceamento permitido.
    */
}
