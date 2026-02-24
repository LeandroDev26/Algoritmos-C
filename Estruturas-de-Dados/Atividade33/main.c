#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Estrutura para o no da fila
typedef struct FilaNo {
    No* no_da_arvore;
    struct FilaNo* proximo;
} FilaNo;

// Estrutura da Fila com inicio e fim
typedef struct {
    FilaNo* frente;
    FilaNo* tras;
} Fila;

// --- Funcoes Auxiliares da Fila ---

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

// Funcao para obter o tamanho atual da fila
int tamanhoDaFila(Fila* q) {
    int tamanho = 0;
    FilaNo* atual = q->frente;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

int alturaIterativa(No* raiz) {
    if (raiz == NULL) {
        return -1;
    }

    Fila* q = criarFila();
    enfileirar(q, raiz);
    int altura = -1;

    while (!filaVazia(q)) {
        // Pega o numero de nos no nivel atual
        int tamanho_nivel = tamanhoDaFila(q);
        altura++;

        // Processa todos os nos do nivel atual
        for (int i = 0; i < tamanho_nivel; i++) {
            No* no_atual = desenfileirar(q);

            // Enfileira os filhos para o proximo nivel
            if (no_atual->esquerda != NULL) {
                enfileirar(q, no_atual->esquerda);
            }
            if (no_atual->direita != NULL) {
                enfileirar(q, no_atual->direita);
            }
        }
    }

    free(q);
    return altura;
}

// --- Funcoes para o Exemplo de Teste ---
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
    No* raiz = criarNo(15);
    raiz->esquerda = criarNo(10);
    raiz->direita = criarNo(20);
    raiz->esquerda->esquerda = criarNo(5);
    raiz->direita->direita = criarNo(25);
    raiz->esquerda->esquerda->esquerda = criarNo(2);

    printf("Calculando a altura da arvore de forma nao-recursiva...\n");

    int h = alturaIterativa(raiz);
    printf("A altura da arvore e: %d\n", h);

    liberarArvore(raiz);

    return 0;
}
