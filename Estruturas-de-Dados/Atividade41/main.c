#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Reconstrução da Estrutura da Árvore
A partir do percurso em nível fornecido (67 51 87 23 53 82 90 17 31 52 60 16 21), podemos montar
 a estrutura da árvore, que deve ser uma Árvore Binária de Busca.

              67
             /  \
            /    \
           51     87
          /  \    /  \
         23  53  82  90
        / \  / \
       17 31 52 60
      / \
     16 21


Dedução das Cores
Para que a árvore seja uma LLRBT válida, ela deve seguir regras rígidas, principalmente a de balanceamento
 negro perfeito: todo caminho da raiz até uma folha nula deve ter o mesmo número de nós pretos.

O nó raiz (67) é sempre preto.

O caminho mais curto é 67 -> 87 -> 82 (ou 90), com 3 nós. Se todos forem pretos, a altura preta da árvore é 3.

Para que todos os outros caminhos também tenham uma altura preta de 3, alguns nós em caminhos mais longos devem
 ser rubros (vermelhos), pois nós rubros não contam para a altura preta.
Nó 51: A subárvore esquerda (iniciada em 51) é mais alta que a direita (iniciada em 87).
 Para balancear a altura preta na raiz, o nó 51 deve ser rubro. Como é um filho esquerdo, isso é permitido.
Nó 17: Na subárvore iniciada em 23, o caminho pela esquerda (23 -> 17 -> ...) é mais longo que o caminho pela
direita (23 -> 31). Para balancear a altura preta no nó 23, o nó 17 deve ser rubro.
Resultado Final
Os nós identificados como rubros para manter o balanceamento da árvore são 17 e 51.
 Em ordem crescente, as chaves são: 17, 51.

    */
}

