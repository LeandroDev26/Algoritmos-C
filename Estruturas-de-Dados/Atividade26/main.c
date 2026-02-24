#include <stdio.h>
#include <stdlib.h>

// Estrutura do no da arvore
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


int acharMenorBST_iterativo(No* raiz) {
    No* atual = raiz;

    // Navega para a esquerda ate o ultimo no
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual->valor;
}


// --- Funcao Principal para Teste ---

int main() {

    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20); // <-- Menor valor
    inserir(raiz, 40);
    inserir(raiz, 90);
    inserir(raiz, 80);

    printf("Buscando o menor valor na Arvore Binaria de Busca...\n");

    if (raiz == NULL) {
        printf("A arvore esta vazia!\n");
    } else {
        int menor = acharMenorBST_iterativo(raiz);
        printf("O menor valor na ABB e: %d\n", menor);
    }

    liberarArvore(raiz);
    return 0;
}
