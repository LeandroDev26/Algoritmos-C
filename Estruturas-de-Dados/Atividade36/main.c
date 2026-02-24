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



int contarNosComUmFilho(No* raiz) {

    if (raiz == NULL) {
        return 0;
    }

    int contador_atual = 0;

    // Verifica se o no atual tem exatamente um filho
    if ((raiz->esquerda != NULL && raiz->direita == NULL) ||
        (raiz->esquerda == NULL && raiz->direita != NULL)) {
        contador_atual = 1;
    }

    // Soma o resultado do no atual com os resultados das subarvores.
    return contador_atual + contarNosComUmFilho(raiz->esquerda) + contarNosComUmFilho(raiz->direita);
}


// --- Funcao Principal para Teste ---

int main() {

    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 80);
    inserir(raiz, 10);
    // Nos com 1 filho: 30, 70, 20 (total = 3)

    printf("Contando o numero de nos com apenas um filho...\n");

    int total_nos = contarNosComUmFilho(raiz);

    printf("A arvore possui %d no(s) com apenas um filho.\n", total_nos);

    liberarArvore(raiz);
    return 0;
}
