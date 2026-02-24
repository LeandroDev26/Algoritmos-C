#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Estrutura para o no da pilha
typedef struct PilhaNo {
    No* no_da_arvore;
    struct PilhaNo* proximo;
} PilhaNo;

// A Pilha em si e apenas um ponteiro para o topo
typedef struct {
    PilhaNo* topo;
} Pilha;


// --- Funcoes Auxiliares da Pilha ---

Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

bool pilhaVazia(Pilha* p) {
    return p->topo == NULL;
}

void empilhar(Pilha* p, No* no) {
    PilhaNo* novo = (PilhaNo*)malloc(sizeof(PilhaNo));
    novo->no_da_arvore = no;
    novo->proximo = p->topo;
    p->topo = novo;
}

No* desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        return NULL;
    }
    PilhaNo* temp = p->topo;
    No* no_retornado = temp->no_da_arvore;
    p->topo = temp->proximo;
    free(temp);
    return no_retornado;
}


// --- Implementacoes Nao Recursivas (Iterativas) ---

void preOrdemIterativo(No* raiz) {
    if (raiz == NULL) return;

    Pilha* p = criarPilha();
    empilhar(p, raiz);

    while (!pilhaVazia(p)) {
        No* atual = desempilhar(p);
        printf("%d ", atual->valor);

        // Empilha o direito primeiro, para que o esquerdo seja processado antes
        if (atual->direita != NULL) {
            empilhar(p, atual->direita);
        }
        if (atual->esquerda != NULL) {
            empilhar(p, atual->esquerda);
        }
    }
    free(p);
}

void emOrdemIterativo(No* raiz) {
    if (raiz == NULL) return;

    Pilha* p = criarPilha();
    No* atual = raiz;

    while (atual != NULL || !pilhaVazia(p)) {
        // Alcanca o no mais a esquerda da subarvore atual
        while (atual != NULL) {
            empilhar(p, atual);
            atual = atual->esquerda;
        }

        // 'atual' e nulo neste ponto. Processa o no no topo da pilha.
        atual = desempilhar(p);
        printf("%d ", atual->valor);

        // Agora, visita a subarvore direita
        atual = atual->direita;
    }
    free(p);
}

void posOrdemIterativo(No* raiz) {
    if (raiz == NULL) return;

    Pilha* p1 = criarPilha();
    Pilha* p2 = criarPilha(); // Pilha para guardar a ordem final

    empilhar(p1, raiz);

    while (!pilhaVazia(p1)) {
        No* atual = desempilhar(p1);
        empilhar(p2, atual); // Adiciona na pilha do resultado

        if (atual->esquerda != NULL) {
            empilhar(p1, atual->esquerda);
        }
        if (atual->direita != NULL) {
            empilhar(p1, atual->direita);
        }
    }

    // Imprime o resultado final que esta na segunda pilha
    while (!pilhaVazia(p2)) {
        No* atual = desempilhar(p2);
        printf("%d ", atual->valor);
    }

    free(p1);
    free(p2);
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

    printf("--- Testando Percursos Nao Recursivos ---\n");

    printf("Percurso em Pre-ordem Iterativo: ");
    preOrdemIterativo(raiz);
    printf("\n");

    printf("Percurso em Em-ordem Iterativo:  ");
    emOrdemIterativo(raiz);
    printf("\n");

    printf("Percurso em Pos-ordem Iterativo: ");
    posOrdemIterativo(raiz);
    printf("\n");

    // Libera toda a memoria alocada para a arvore
    liberarArvore(raiz);
    printf("\nMemoria da arvore liberada com sucesso.\n");

    return 0;
}
