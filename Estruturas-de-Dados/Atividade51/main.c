#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*
   (a) Quais são os nós folhas?
   Os nós folhas são aqueles que não possuem filhos.
   Resposta: B, F, I, O.

   (b) Quais nós são ancestrais de C?
    Os ancestrais de um nó são todos os nós no caminho da raiz até ele (excluindo o próprio nó).
    O caminho para C é L → G → C.
    Resposta: G, L.

   (c) Quais são os descendentes de C?
   Os descendentes de um nó são todos os nós em suas subárvores.
   Resposta: B, E, F.

   (d) Qual é a altura da árvore?
    A altura é o número de arestas no caminho mais longo da raiz até uma folha. O caminho mais longo é L → G → C → E → F, que possui 4 arestas.
    Resposta: A altura da árvore é 4.

   (e) Quais são os nós com grau 1 e 2?
    O grau de um nó é o seu número de filhos.
    Resposta:
    Grau 1 (um filho): R, E
    Grau 2 (dois filhos): L, G, C

   (f) Quantos caminhos de comprimento três existem?
    um caminho de comprimento três possui 3 arestas (ou 4 nós).

    Resposta: Existem 3 caminhos de comprimento três:
    L → G → C → B
    L → G → C → E
    ssssssG → C → E → F

   */
}
