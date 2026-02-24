#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Funcoes Auxiliares (criar, inserir, liberar) ---
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

// --- Funcao Principal a ser Testada (Iterativa) ---
int acharMaximoBST(No* raiz) {
    No* atual = raiz;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual->valor;
}


int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 90); // Este sera o valor maximo
    inserir(raiz, 80);

    printf("Procurando o valor maximo na Arvore de Busca Binaria...\n");

    // E uma boa pratica verificar se a arvore nao esta vazia antes de chamar a funcao.
    if (raiz == NULL) {
        printf("A arvore esta vazia!\n");
    } else {
        int maximo = acharMaximoBST(raiz);
        printf("O valor maximo na arvore e: %d\n", maximo);
    }

    liberarArvore(raiz);
    return 0;
}
