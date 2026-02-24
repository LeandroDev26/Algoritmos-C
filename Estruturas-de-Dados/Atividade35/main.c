#include <stdio.h>
#include <stdlib.h>

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Funcoes Auxiliares ---
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

// Funcao de insercao para criar a ABB de exemplo
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}


int contarFolhas(No* raiz) {
    // 1. Uma arvore vazia nao tem folhas.
    if (raiz == NULL) {
        return 0;
    }

    // 2. Se o no atual nao tem filhos, ele e uma folha.
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }

    // 3. Se nao e folha, soma as folhas das subarvores.
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}


// --- Funcao Principal para Teste ---

int main() {

    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("Contando o numero de folhas na arvore...\n");

    int total_folhas = contarFolhas(raiz);

    printf("A arvore possui %d folha(s).\n", total_folhas);

    liberarArvore(raiz);
    return 0;
}
