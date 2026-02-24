#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Estrutura do no da arvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// --- Estrutura e Funcoes da Pilha (necessarias para a iteracao) ---
typedef struct PilhaNo {
    No* no_da_arvore;
    struct PilhaNo* proximo;
} PilhaNo;

typedef struct {
    PilhaNo* topo;
} Pilha;

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
    if (pilhaVazia(p)) return NULL;
    PilhaNo* temp = p->topo;
    No* no_retornado = temp->no_da_arvore;
    p->topo = temp->proximo;
    free(temp);
    return no_retornado;
}

int acharMenorNaoOrdenada_iterativo(No* raiz) {
    // Caso a arvore seja vazia
    if (raiz == NULL) {
        return INT_MAX; // Valor especial para indicar que nao ha menor valor
    }

    Pilha* p = criarPilha();
    empilhar(p, raiz);

    int menor_valor = raiz->valor;

    while (!pilhaVazia(p)) {
        No* atual = desempilhar(p);

        // Compara e atualiza o menor valor
        if (atual->valor < menor_valor) {
            menor_valor = atual->valor;
        }

        // Empilha os filhos para continuar a busca
        if (atual->direita != NULL) {
            empilhar(p, atual->direita);
        }
        if (atual->esquerda != NULL) {
            empilhar(p, atual->esquerda);
        }
    }

    free(p);
    return menor_valor;
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
    // Montando uma arvore NAO ordenada de exemplo:

    No* raiz = criarNo(15);
    raiz->esquerda = criarNo(100);
    raiz->direita = criarNo(-5);
    raiz->esquerda->esquerda = criarNo(2);
    raiz->esquerda->direita = criarNo(25);

    printf("Buscando o menor valor na arvore nao ordenada...\n");

    int menor = acharMenorNaoOrdenada_iterativo(raiz);

    if (menor != INT_MAX) {
        printf("O menor valor na arvore e: %d\n", menor);
    } else {
        printf("A arvore esta vazia.\n");
    }

    liberarArvore(raiz);
    return 0;
}
