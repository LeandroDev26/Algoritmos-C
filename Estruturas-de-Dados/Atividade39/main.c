#include <stdio.h>
#include <stdlib.h>

#define MAX_ALTURA 100


typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Funcoes Auxiliares ---
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


void imprimirCaminhosRecursivo(No* no, int caminho[], int tamanho_caminho) {

    if (no == NULL) {
        return;
    }

    // Adiciona o no atual ao caminho
    caminho[tamanho_caminho] = no->valor;
    tamanho_caminho++;

    // Se for um no folha, imprime o caminho armazenado
    if (no->esquerda == NULL && no->direita == NULL) {
        printf("Caminho: ");
        for (int i = 0; i < tamanho_caminho; i++) {
            printf("%d ", caminho[i]);
        }
        printf("\n");
    } else {
        // Se nao for folha, continua a busca nos filhos
        imprimirCaminhosRecursivo(no->esquerda, caminho, tamanho_caminho);
        imprimirCaminhosRecursivo(no->direita, caminho, tamanho_caminho);
    }
}

void imprimirCaminhos(No* raiz) {
    if (raiz == NULL) {
        printf("A arvore esta vazia.\n");
        return;
    }
    int caminho[MAX_ALTURA];
    imprimirCaminhosRecursivo(raiz, caminho, 0);
}


int main() {

    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(20);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->direita->direita = criarNo(25);

    printf("Imprimindo todos os caminhos da raiz ate cada folha:\n");
    imprimirCaminhos(raiz);

    liberarArvore(raiz);
    return 0;
}
