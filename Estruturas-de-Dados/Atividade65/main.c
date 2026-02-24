#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;


No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int somarNiveisImparesRecursivo(No* no, int nivel) {

    if (no == NULL) {
        return 0;
    }

    // Soma das subarvores esquerda e direita no proximo nivel.
    int soma_filhos = somarNiveisImparesRecursivo(no->esquerda, nivel + 1) +
                      somarNiveisImparesRecursivo(no->direita, nivel + 1);

    // Se o nivel atual for impar, adiciona o valor do no atual a soma.
    if (nivel % 2 != 0) {
        return no->valor + soma_filhos;
    }

    // Se o nivel for par, retorna apenas a soma dos filhos.
    return soma_filhos;
}


int somarNiveisImpares(No* raiz) {
    // Inicia a chamada recursiva a partir da raiz no nivel 0.
    return somarNiveisImparesRecursivo(raiz, 0);
}

int main() {
    // Montando a arvore de exemplo:
    // Nivel 0 (par):     10
    // Nivel 1 (impar):   /  \
    //                   5    20
    // Nivel 2 (par):    / \
    //                  3   7
    // Nivel 3 (impar):     \
    //                      8
    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(20);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->esquerda->direita->direita = criarNo(8);

    // Nos nos niveis impares:
    // Nivel 1: 5, 20
    // Nivel 3: 8
    // Soma esperada: 5 + 20 + 8 = 33

    printf("Somando os valores dos nos em niveis impares...\n");

    int soma = somarNiveisImpares(raiz);

    printf("A soma dos nos nos niveis impares e: %d\n", soma);

    liberarArvore(raiz);

    return 0;
}
