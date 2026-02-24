#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Funcao auxiliar para criar um novo no
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void espelharArvore(No* raiz) {
    // 1. Caso Base: Se o no e nulo, nao faz nada.
    if (raiz == NULL) {
        return;
    }

    // 2. Troca os ponteiros dos filhos esquerdo e direito.
    No* temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;

    // 3. Chama recursivamente a funcao para as subarvores filhas.
    espelharArvore(raiz->esquerda);
    espelharArvore(raiz->direita);
}

// Funcao para imprimir a arvore em-ordem (esquerda, raiz, direita)
void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimirEmOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

// Funcao para liberar a memoria da arvore
void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    // Montando a arvore de exemplo:
    //      4
    //     / \
    //    2   6
    //   /   / \
    //  1   5   7
    No* raiz = criarNo(4);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(6);
    raiz->esquerda->esquerda = criarNo(1);
    raiz->direita->esquerda = criarNo(5);
    raiz->direita->direita = criarNo(7);

    printf("Arvore original (percurso em-ordem): ");
    imprimirEmOrdem(raiz);
    printf("\n");

    // Chama a funcao para espelhar a arvore
    espelharArvore(raiz);

    printf("Arvore espelhada (percurso em-ordem): ");
    imprimirEmOrdem(raiz);
    printf("\n");

    liberarArvore(raiz);

    return 0;
}
