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

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimirEmOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

int alterarParaSomaDosFilhos(No* raiz) {
    // Caso base: subarvore vazia.
    if (raiz == NULL) {
        return 0;
    }

    // Guarda o valor original do no atual.
    int valor_original = raiz->valor;

    // Obtem a soma original das subarvores. As chamadas recursivas
    // ja farao a alteracao nos niveis inferiores.
    int soma_original_esquerda = alterarParaSomaDosFilhos(raiz->esquerda);
    int soma_original_direita = alterarParaSomaDosFilhos(raiz->direita);

    // Altera o valor do no atual se ele tiver dois filhos.
    // Usa os valores originais dos filhos, que estao em suas estruturas.
    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        raiz->valor = raiz->esquerda->valor + raiz->direita->valor;
    }

    // Retorna a soma da subarvore ANTES da alteracao do no atual.
    return valor_original + soma_original_esquerda + soma_original_direita;
}


int main() {

    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(2);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(1);

    printf("Arvore original (em-ordem): ");
    imprimirEmOrdem(raiz);
    printf("\n");

    alterarParaSomaDosFilhos(raiz);

    printf("Arvore modificada (em-ordem): ");
    imprimirEmOrdem(raiz);
    printf("\n");



    liberarArvore(raiz);
    return 0;
}
