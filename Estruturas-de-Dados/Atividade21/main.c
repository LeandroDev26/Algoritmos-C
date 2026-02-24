#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*

    As principais diferenças é que enquanto uma Árvore Binária de Busca (ABB) comum pode se tornar "torta" e lenta se os dados forem inseridos
    em ordem, a AVL possui um mecanismo de auto-balanceamento. A cada inserção ou remoção, a AVL verifica sua
    própria estrutura e, se necessário, realiza "rotações" para se reorganizar e manter uma altura equilibrada.
     Essa organização forçada garante que as operações de busca na AVL sejam sempre extremamente rápidas, um benefício
     que a ABB comum não pode prometer, já que seu desempenho depende da sorte na ordem de inserção dos dados.

    A escolha entre uma ABB e uma AVL depende das exigências da aplicação. Uma ABB é mais simples de implementar
     e mais rápida em inserções e remoções isoladas, sendo adequada para cenários onde os dados de entrada são
     naturalmente aleatórios ou onde um desempenho de pior caso ocasional não é crítico. Por outro lado, a Árvore AVL é a
      escolha ideal quando a velocidade e a previsibilidade da busca são prioridades absolutas, como em bancos de dados,
      sistemas de indexação e outras aplicações de alta performance, onde o custo adicional para manter a árvore balanceada
      é um preço pequeno a se pagar pela garantia de eficiência constante.

    }
