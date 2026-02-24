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


int acharMinimoAVL(No* raiz) {
    No* atual = raiz;

    // Navega para a esquerda ate o ultimo no
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual->valor;
}




int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20); // <-- Menor valor
    inserir(raiz, 40);
    inserir(raiz, 10); // <-- Novo menor valor

    printf("Buscando o menor valor na arvore AVL...\n");


    if (raiz == NULL) {
        printf("A arvore esta vazia!\n");
    } else {
        int menor = acharMinimoAVL(raiz);
        printf("O menor valor na arvore e: %d\n", menor);
    }

    liberarArvore(raiz);
    return 0;
}
