#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    char* dado;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Funcoes Auxiliares ---
No* criarNo(int chave, char* dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->dado = dado;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

// Imprime a arvore para verificacao
void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) return;
    imprimirEmOrdem(raiz->esquerda);
    printf("[Chave: %d, Dado: \"%s\"] ", raiz->chave, raiz->dado);
    imprimirEmOrdem(raiz->direita);
}



No* inserirOuAtualizar(No* raiz, int chave, char* novo_dado) {
    // Caso base: Se a arvore e vazia, insere o novo no.
    if (raiz == NULL) {
        return criarNo(chave, novo_dado);
    }

    // Navega para a posicao correta
    if (chave < raiz->chave) {
        raiz->esquerda = inserirOuAtualizar(raiz->esquerda, chave, novo_dado);
    } else if (chave > raiz->chave) {
        raiz->direita = inserirOuAtualizar(raiz->direita, chave, novo_dado);
    } else {
        // Chave duplicada encontrada: atualiza o dado do no existente.
        printf("\n(Aviso: Chave %d ja existe. Atualizando o dado de \"%s\" para \"%s\")\n", chave, raiz->dado, novo_dado);
        raiz->dado = novo_dado;
    }

    return raiz;
}


int main() {
    No* raiz = NULL;

    raiz = inserirOuAtualizar(raiz, 50, "Versao 1");
    raiz = inserirOuAtualizar(raiz, 30, "Versao 1");
    raiz = inserirOuAtualizar(raiz, 70, "Versao 1");

    printf("Estado inicial da arvore:\n");
    imprimirEmOrdem(raiz);
    printf("\n");


    printf("\n--- Tentando inserir chave 30 com novo dado ---\n");
    raiz = inserirOuAtualizar(raiz, 30, "Versao 2 - ATUALIZADO");

    printf("\nEstado da arvore apos a atualizacao:\n");
    imprimirEmOrdem(raiz);
    printf("\n");
s
    printf("\n--- Tentando inserir chave 80 (nova) ---\n");
    raiz = inserirOuAtualizar(raiz, 80, "Versao 1");

    printf("\nEstado final da arvore:\n");
    imprimirEmOrdem(raiz);
    printf("\n");

    liberarArvore(raiz);
    return 0;
}
