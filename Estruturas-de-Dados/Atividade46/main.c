#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;


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

bool ehEstritamenteBinaria(No* raiz) {
    // 1. Uma arvore vazia e considerada estritamente binaria.
    if (raiz == NULL) {
        return true;
    }

    // 2. Se um no e folha (0 filhos), ele e valido.
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return true;
    }

    // 3. Se um no tem dois filhos, a validade depende de suas subarvores.
    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        return ehEstritamenteBinaria(raiz->esquerda) && ehEstritamenteBinaria(raiz->direita);
    }

    // 4. Se chegou aqui, o no tem exatamente um filho, o que e invalido.
    return false;
}




int main() {
    // Arvore 1: VALIDA (todos os nos tem 0 ou 2 filhos)
    //      20
    //     /  \
    //    10   30
    No* arvore_valida = criarNo(20);
    arvore_valida->esquerda = criarNo(10);
    arvore_valida->direita = criarNo(30);

    // Arvore 2: INVALIDA (o no 30 tem apenas 1 filho)
    //      20
    //     /  \
    //    10   30
    //         /
    //        25
    No* arvore_invalida = criarNo(20);
    arvore_invalida->esquerda = criarNo(10);
    arvore_invalida->direita = criarNo(30);
    arvore_invalida->direita->esquerda = criarNo(25);

    printf("Verificando as arvores...\n\n");

    bool res1 = ehEstritamenteBinaria(arvore_valida);
    printf("A Arvore 1 e estritamente binaria? %s\n", res1 ? "Sim" : "Nao");

    bool res2 = ehEstritamenteBinaria(arvore_invalida);
    printf("A Arvore 2 e estritamente binaria? %s\n", res2 ? "Sim" : "Nao");

    // Liberando a memoria
    liberarArvore(arvore_valida);
    liberarArvore(arvore_invalida);

    return 0;
}
