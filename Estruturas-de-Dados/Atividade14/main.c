#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar 'true' e 'false'

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Funcao auxiliar para criar um novo no
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

bool saoIguais(No* raiz1, No* raiz2) {
    // Caso 1: Se ambas sao vazias, sao iguais.
    if (raiz1 == NULL && raiz2 == NULL) {
        return true;
    }

    // Caso 2: Se ambas existem e seus valores sao iguais...
    if (raiz1 != NULL && raiz2 != NULL && raiz1->valor == raiz2->valor) {
        // ...a igualdade depende da igualdade de suas subarvores.
        return saoIguais(raiz1->esquerda, raiz2->esquerda) &&
               saoIguais(raiz1->direita, raiz2->direita);
    }

    // Se qualquer uma das condicoes acima nao for atendida, elas nao sao iguais.
    return false;
}

// Funcao para liberar a memoria da arvore
void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    // Arvore 1
    No* arvore1 = criarNo(20);
    arvore1->esquerda = criarNo(10);
    arvore1->direita = criarNo(30);

    // Arvore 2: Estrutura e valores identicos. Deve ser IGUAL.
    No* arvore2 = criarNo(20);
    arvore2->esquerda = criarNo(10);
    arvore2->direita = criarNo(30);

    // Arvore 3: Mesma estrutura, valor diferente. NAO deve ser igual.
    No* arvore3 = criarNo(20);
    arvore3->esquerda = criarNo(10);
    arvore3->direita = criarNo(99); // Valor diferente

    printf("Verificando igualdade das arvores...\n\n");

    bool res1_vs_2 = saoIguais(arvore1, arvore2);
    printf("Arvore 1 e Arvore 2 sao iguais? %s\n", res1_vs_2 ? "Sim" : "Nao");

    bool res1_vs_3 = saoIguais(arvore1, arvore3);
    printf("Arvore 1 e Arvore 3 sao iguais? %s\n", res1_vs_3 ? "Sim" : "Nao");

    // Liberando a memoria
    liberarArvore(arvore1);
    liberarArvore(arvore2);
    liberarArvore(arvore3);

    return 0;
}
