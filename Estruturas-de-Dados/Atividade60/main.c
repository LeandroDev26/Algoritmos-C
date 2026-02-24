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


int contarNosDivisores(No* raiz) {
    // Caso base: arvore vazia.
    if (raiz == NULL) {
        return 0;
    }

    int contador_atual = 0;

    // A condicao so se aplica a nos com DOIS filhos.
    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        // Evita divisao por zero.
        if (raiz->valor != 0) {
            int soma_filhos = raiz->esquerda->valor + raiz->direita->valor;

            // Verifica se o valor do no atual e divisor da soma.
            if (soma_filhos % raiz->valor == 0) {
                contador_atual = 1;
            }
        }
    }

    // O total e o resultado do no atual + os resultados das subarvores.
    return contador_atual + contarNosDivisores(raiz->esquerda) + contarNosDivisores(raiz->direita);
}



int main() {

    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(8); // No com 1 filho, nao conta.
    raiz->esquerda->esquerda = criarNo(2);
    raiz->esquerda->direita = criarNo(8);



    printf("Verificando a arvore...\n");

    int total = contarNosDivisores(raiz);

    printf("Numero de nos que sao divisores da soma de seus filhos: %d\n", total);

    liberarArvore(raiz);
    return 0;
}
