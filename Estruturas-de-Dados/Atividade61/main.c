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


No* acharLCA(No* raiz, int n1, int n2) {

    if (raiz == NULL) {
        return NULL;
    }
    if (raiz->valor == n1 || raiz->valor == n2) {
        return raiz;
    }

    // Busca nas subarvores esquerda e direita
    No* lca_esquerda = acharLCA(raiz->esquerda, n1, n2);
    No* lca_direita = acharLCA(raiz->direita, n1, n2);

    // Se ambos os lados retornaram um no, o no atual e o LCA
    if (lca_esquerda != NULL && lca_direita != NULL) {
        return raiz;
    }

    // Caso contrario, o LCA esta no lado que nao retornou nulo
    return (lca_esquerda != NULL) ? lca_esquerda : lca_direita;
}



int main() {

    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(20);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->direita->esquerda = criarNo(15);
    raiz->direita->direita = criarNo(25);

    printf("Encontrando o Ancestral Comum Mais Baixo (LCA)...\n\n");

    // Teste 1: Nos em subarvores diferentes. LCA deve ser a raiz (10).
    No* lca1 = acharLCA(raiz, 3, 25);
    if (lca1 != NULL) {
        printf("LCA de 3 e 25 e: %d\n", lca1->valor);
    }

    // Teste 2: Nos na mesma subarvore. LCA deve ser 5.
    No* lca2 = acharLCA(raiz, 3, 7);
    if (lca2 != NULL) {
        printf("LCA de 3 e 7 e: %d\n", lca2->valor);
    }

    // Teste 3: Um no e ancestral do outro. LCA deve ser o proprio ancestral (5).
    No* lca3 = acharLCA(raiz, 5, 3);
    if (lca3 != NULL) {
        printf("LCA de 5 e 3 e: %d\n", lca3->valor);
    }

    liberarArvore(raiz);
    return 0;
}
