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
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}


bool saoIguais(No* raiz1, No* raiz2) {
    // 1. Se ambos sao nulos, sao iguais.
    if (raiz1 == NULL && raiz2 == NULL) {
        return true;
    }

    // 2. Se ambos existem e seus valores sao iguais...
    if (raiz1 != NULL && raiz2 != NULL) {
        return (
            raiz1->valor == raiz2->valor &&
            saoIguais(raiz1->esquerda, raiz2->esquerda) &&
            saoIguais(raiz1->direita, raiz2->direita)
        );
    }


    return false;
}


int main() {
    // Arvore 1
    No* arvore1 = criarNo(20);
    arvore1->esquerda = criarNo(10);
    arvore1->direita = criarNo(30);

    // Arvore 2: Estrutura e valores identicos a Arvore 1. Deve ser IGUAL.
    No* arvore2 = criarNo(20);
    arvore2->esquerda = criarNo(10);
    arvore2->direita = criarNo(30);

    // Arvore 3: Mesma estrutura da Arvore 1, mas valor diferente. NAO deve ser igual.
    No* arvore3 = criarNo(20);
    arvore3->esquerda = criarNo(10);
    arvore3->direita = criarNo(99);

    printf("Comparando se as arvores sao iguais...\n\n");

    // Teste 1: Duas arvores identicas
    bool res1 = saoIguais(arvore1, arvore2);
    printf("Arvore 1 e Arvore 2 sao iguais? %s\n", res1 ? "Sim" : "Nao");

    // Teste 2: Duas arvores com estrutura igual mas valores diferentes
    bool res2 = saoIguais(arvore1, arvore3);
    printf("Arvore 1 e Arvore 3 sao iguais? %s\n", res2 ? "Sim" : "Nao");

    // Liberando a memoria
    liberarArvore(arvore1);
    liberarArvore(arvore2);
    liberarArvore(arvore3);

    return 0;
}
