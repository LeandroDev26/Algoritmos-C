#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Estado Inicial da Árvore
  A árvore AVL original do exercício é:

          8
         / \
        /   \
       5     10
      / \   /  \
     3   6 9    12
    / \   \    /
   2   4   7  11
  /
 1

  Remoção do Nó 8
  A primeira tarefa é remover o nó 8, que é a raiz da árvore e possui dois filhos.

  a) Substituição pela Sucessora

  Para remover um nó com dois filhos em uma ABB (e, por consequência, em uma AVL), primeiro
  encontramos seu sucessor em ordem (o menor nó da subárvore direita). Neste caso, o sucessor de 8 é o nó 9.
  O valor do sucessor (9) é copiado para o nó que estamos removendo (a raiz).

  Agora, o problema se resume a remover o nó 9 de sua posição original. Como o nó 9 é uma folha, seu pai (nó 10)
  simplesmente aponta para NULL.
  Árvore após a substituição e antes do rebalanceamento:
Neste ponto, a árvore fica com a seguinte estrutura, e precisamos verificar os fatores de balanceamento subindo
 a partir do pai do nó removido (nó 10).

          9  <-- Raiz atualizada
         / \
        /   \
       5     10 (fator: +2) <-- DESBALANCEADO
      / \      \
     3   6      12
    / \   \    /
   2   4   7  11
  /
 1

  Ao verificar os fatores, descobrimos que o nó 10 ficou desbalanceado com um fator de +2.

  b) Rebalanceamento

  Tipo de Desbalanceamento: O nó 10 tem fator +2, e seu filho direito (nó 12) tem fator -1 (pois só tem filho à esquerda). Isso caracteriza um desbalanceamento do tipo Direita-Esquerda (RL).
  Ação Corretiva: É necessária uma Rotação Dupla Direita-Esquerda.
  Primeiro, uma Rotação à Direita no filho (nó 12).
  Depois, uma Rotação à Esquerda no nó desbalanceado (nó 10).
  Árvore após a remoção do 8 e o rebalanceamento:
  Após a rotação dupla, a subárvore direita é reorganizada, resultando na seguinte árvore AVL válida:

          9
         / \
        /   \
       5     11
      / \   /  \
     3   6 10   12
    / \   \
   2   4   7
  /
 1

   Adição do Nó 9
   A segunda tarefa é "adicionar um nó com valor 9" à árvore resultante da etapa anterior.

  No entanto, como o nó 9 já existe na árvore (ele se tornou a nova raiz), a operação de inserção em uma Árvore
   de Busca Binária padrão simplesmente não faria nada, pois chaves duplicadas não são inseridas.

  Portanto, a estrutura da árvore não se altera após a tentativa de inserir o 9 novamente.

  Desenho da Árvore Final
  A árvore resultante final, após ambas as operações, é a mesma que resultou do rebalanceamento da remoção:

          9
         / \
        /   \
       5     11
      / \   /  \
     3   6 10   12
    / \   \
   2   4   7
  /
 1


    */
}
