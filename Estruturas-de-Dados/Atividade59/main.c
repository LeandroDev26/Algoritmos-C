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


void imprimirNivel(No* raiz, int nivel) {

    if (raiz == NULL) {
        return;
    }


    if (nivel == 0) {
        printf("%d ", raiz->valor);
    }

    else if (nivel > 0) {
        imprimirNivel(raiz->esquerda, nivel - 1);
        imprimirNivel(raiz->direita, nivel - 1);
    }
}



int main() {

    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(20);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->direita->esquerda = criarNo(15);

    printf("Imprimindo nos por nivel:\n");

    printf("Nivel 0: ");
    imprimirNivel(raiz, 0);
    printf("\n");

    printf("Nivel 1: ");
    imprimirNivel(raiz, 1);
    printf("\n");

    printf("Nivel 2: ");
    imprimirNivel(raiz, 2);
    printf("\n");

    printf("Nivel 3 (vazio): ");
    imprimirNivel(raiz, 3);
    printf("\n");

    liberarArvore(raiz);

    return 0;
}
