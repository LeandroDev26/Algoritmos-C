#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

int ehPrimo(int n) {
    if (n <= 1) return 0; // false
    if (n <= 3) return 1; // true
    if (n % 2 == 0 || n % 3 == 0) return 0; // false

    // Testa apenas os divisores impares
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0; // false
    }
    return 1; // true
}


int contarPrimos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    // Se ehPrimo retornar 1 (true), contador_atual sera 1, senao 0.
    int contador_atual = ehPrimo(raiz->valor) ? 1 : 0;

    // Soma o resultado do no atual com os resultados das subarvores.
    return contador_atual + contarPrimos(raiz->esquerda) + contarPrimos(raiz->direita);
}

// --- Funcao Principal para Teste ---
int main() {
    No* raiz = NULL;
    // Inserindo numeros primos e nao primos
    raiz = inserir(raiz, 15); // Nao primo
    inserir(raiz, 7);  // Primo
    inserir(raiz, 23); // Primo
    inserir(raiz, 4);  // Nao primo
    inserir(raiz, 10); // Nao primo
    inserir(raiz, 19); // Primo
    inserir(raiz, 29); // Primo

    // Primos na arvore: 7, 19, 23, 29 (Total = 4)

    printf("Contando a quantidade de numeros primos na arvore...\n");

    int total_primos = contarPrimos(raiz);

    printf("A arvore possui %d no(s) com numeros primos.\n", total_primos);

    liberarArvore(raiz);
    return 0;
}
