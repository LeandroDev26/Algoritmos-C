#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

int encontrarFloor(No* raiz, int x) {
    int floor = INT_MIN;
    No* atual = raiz;

    while (atual != NULL) {
        // Se o valor do no e igual a x, encontramos o floor perfeito.
        if (atual->valor == x) {
            return atual->valor;
        }

        // Se o no atual e maior que x, o floor so pode estar a esquerda.
        if (atual->valor > x) {
            atual = atual->esquerda;
        }
        // Se o no atual e menor que x, ele e um candidato a floor.
        else {
            floor = atual->valor; // Este e o melhor candidato ate agora.
            atual = atual->direita; // Tenta encontrar um candidato melhor (maior) a direita.
        }
    }

    return floor;
}



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


int main() {
    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    // Arvore: 20, 30, 40, 50, 60, 70, 80

    printf("Encontrando o floor para diferentes valores de x...\n");

    // Teste 1: x existe na arvore
    int x1 = 40;
    printf("O floor de %d e: %d\n", x1, encontrarFloor(raiz, x1));

    // Teste 2: x nao existe, mas tem um floor claro
    int x2 = 65;
    printf("O floor de %d e: %d\n", x2, encontrarFloor(raiz, x2));

    // Teste 3: x e maior que todos na arvore
    int x3 = 100;
    printf("O floor de %d e: %d\n", x3, encontrarFloor(raiz, x3));

    // Teste 4: x e menor que todos na arvore (nao ha floor)
    int x4 = 15;
    int res4 = encontrarFloor(raiz, x4);
    if (res4 == INT_MIN) {
        printf("Nao existe floor para o valor %d na arvore.\n", x4);
    } else {
        printf("O floor de %d e: %d\n", x4, res4);
    }

    liberarArvore(raiz);
    return 0;
}
