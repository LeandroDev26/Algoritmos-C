#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;


typedef struct FilaNo {
    No* no_da_arvore;
    struct FilaNo* proximo;
} FilaNo;

typedef struct {
    FilaNo* frente;
    FilaNo* tras;
} Fila;


Fila* criarFila() {
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q->frente = q->tras = NULL;
    return q;
}

bool filaVazia(Fila* q) {
    return q->frente == NULL;
}

void enfileirar(Fila* q, No* no) {
    FilaNo* novo = (FilaNo*)malloc(sizeof(FilaNo));
    novo->no_da_arvore = no;
    novo->proximo = NULL;
    if (filaVazia(q)) {
        q->frente = q->tras = novo;
    } else {
        q->tras->proximo = novo;
        q->tras = novo;
    }
}

No* desenfileirar(Fila* q) {
    if (filaVazia(q)) return NULL;
    FilaNo* temp = q->frente;
    No* no_retornado = temp->no_da_arvore;
    q->frente = q->frente->proximo;
    if (q->frente == NULL) {
        q->tras = NULL;
    }
    free(temp);
    return no_retornado;
}


void percursoEmNivel(No* raiz) {
    if (raiz == NULL) {
        printf("A arvore esta vazia.\n");
        return;
    }

    Fila* q = criarFila();
    enfileirar(q, raiz);

    while (!filaVazia(q)) {
        No* atual = desenfileirar(q);
        printf("%d ", atual->valor);

        // Adiciona os filhos na fila para serem visitados depois
        if (atual->esquerda != NULL) {
            enfileirar(q, atual->esquerda);
        }
        if (atual->direita != NULL) {
            enfileirar(q, atual->direita);
        }
    }
    free(q);
}

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

int main() {

    No* raiz = criarNo(10);
    raiz->esquerda = criarNo(5);
    raiz->direita = criarNo(20);
    raiz->esquerda->esquerda = criarNo(3);
    raiz->esquerda->direita = criarNo(7);
    raiz->direita->esquerda = criarNo(15);

    printf("Percurso em Nivel (Largura): ");
    percursoEmNivel(raiz);
    printf("\n");

    liberarArvore(raiz);

    return 0;
}
