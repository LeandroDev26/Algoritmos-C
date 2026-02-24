#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar 'true' e 'false'

// Estrutura do no da arvore
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

bool saoSimilares(No* raiz1, No* raiz2) {
    // Caso 1: Se ambas as arvores (ou subarvores) sao vazias, elas sao similares.
    if (raiz1 == NULL && raiz2 == NULL) {
        return true;
    }

    // Caso 2: Se apenas uma delas e vazia, elas tem estruturas diferentes.
    if (raiz1 == NULL || raiz2 == NULL) {
        return false;
    }

    // Caso 3 (Recursivo): Se ambas existem, a similaridade depende de suas
    // subarvores. Os valores dos nos (raiz1->valor e raiz2->valor) sao ignorados.
    return saoSimilares(raiz1->esquerda, raiz2->esquerda) &&
           saoSimilares(raiz1->direita, raiz2->direita);
}

// Funcao para liberar a memoria da arvore
void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {

    No* arvore1 = criarNo(10);
    arvore1->esquerda = criarNo(5);
    arvore1->direita = criarNo(15);

    // Arvore 2: Mesma estrutura, valores diferentes. Deve ser SIMILAR.

    No* arvore2 = criarNo(99);
    arvore2->esquerda = criarNo(1);
    arvore2->direita = criarNo(1000);

    // Arvore 3: Estrutura diferente. NAO deve ser similar.

    No* arvore3 = criarNo(10);
    arvore3->esquerda = criarNo(5);

    printf("Verificando similaridade das arvores...\n\n");

    bool res1_vs_2 = saoSimilares(arvore1, arvore2);
    printf("Arvore 1 e Arvore 2 sao similares? %s\n", res1_vs_2 ? "Sim" : "Nao");

    bool res1_vs_3 = saoSimilares(arvore1, arvore3);
    printf("Arvore 1 e Arvore 3 sao similares? %s\n", res1_vs_3 ? "Sim" : "Nao");

    // Liberando a memoria
    liberarArvore(arvore1);
    liberarArvore(arvore2);
    liberarArvore(arvore3);

    return 0;
}
