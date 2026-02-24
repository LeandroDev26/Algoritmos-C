#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Funcao auxiliar recursiva que faz a verificacao com intervalo
bool ehValidaBST(No* no, int min, int max) {
    // 1. Uma arvore vazia e uma BST valida.
    if (no == NULL) {
        return true;
    }

    // 2. Se o valor do no esta fora do intervalo permitido, a arvore e invalida.
    if (no->valor <= min || no->valor >= max) {
        return false;
    }

    // 3. Verifica as subarvores, atualizando os limites do intervalo.
    return ehValidaBST(no->esquerda, min, no->valor) &&
           ehValidaBST(no->direita, no->valor, max);
}


bool ehABB(No* raiz) {
    // Inicia a verificacao recursiva com o intervalo maximo possivel.
    return ehValidaBST(raiz, INT_MIN, INT_MAX);
}

// --- Funcoes para o Exemplo de Teste ---
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    // --- Teste 1: Arvore que E uma BST VALIDA ---
    No* raiz_valida = criarNo(20);
    raiz_valida->esquerda = criarNo(10);
    raiz_valida->direita = criarNo(30);
    raiz_valida->esquerda->direita = criarNo(15);

    // --- Teste 2: Arvore que NAO E uma BST (o exemplo da armadilha) ---
    No* raiz_invalida = criarNo(20);
    raiz_invalida->esquerda = criarNo(10);
    raiz_invalida->esquerda->direita = criarNo(25); // Viola a regra!

    printf("Verificando as arvores...\n\n");

    bool res1 = ehABB(raiz_valida);
    printf("A primeira arvore e uma ABB? %s\n", res1 ? "Sim" : "Nao");

    bool res2 = ehABB(raiz_invalida);
    printf("A segunda arvore e uma ABB? %s\n", res2 ? "Sim" : "Nao");

    // Liberando a memoria
    liberarArvore(raiz_valida);
    liberarArvore(raiz_invalida);

    return 0;
}
